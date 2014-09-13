////////////////////////////////////////////////////////////////////////////////
//
//	Code Original Creator: Rastertek
//	Source: http://www.rastertek.com/tertut02.html
//	Used By: Leonard Roll
//	I do not own most of the code but am following the tutorials on the website 
//	to create my project for the final year projects.
//
////////////////////////////////////////////////////////////////////////////////
// Filename: terrainclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _TERRAINCLASS_H_
#define _TERRAINCLASS_H_


//////////////
// INCLUDES //
//////////////
#include <d3d11.h>
#include <d3dx10math.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "textureclass.h"

const int TEXTURE_REPEAT = 8;

////////////////////////////////////////////////////////////////////////////////
// Class name: TerrainClass
////////////////////////////////////////////////////////////////////////////////
class TerrainClass
{
private:
	struct VertexType
	{
		D3DXVECTOR3 position;
		D3DXVECTOR2 texture;
		D3DXVECTOR3 normal;
	};

	struct HeightMapType 
	{ 
		float x, y, z;
		float tu, tv;
		float nx, ny, nz;
	};

	struct VectorType 
	{ 
		float x, y, z;
	};

public:
	TerrainClass();
	TerrainClass(const TerrainClass&);
	~TerrainClass();

	bool Initialize(ID3D11Device*, char*,WCHAR*);
	void Shutdown();
	void SwitchTopology(bool);
	void Render(ID3D11DeviceContext*);
	
	//Terrain Edit
	bool GlobalTerrainSmooth(ID3D11Device* device); //Apply Action to Whole terrain
	void IncreaseSmooth(ID3D11Device* device,bool);
	void PerformRaise(bool,float,float,ID3D11Device*); //two floats are for x and z position
	bool LocalZoneRaise(float,float,ID3D11Device*); //two floats for x and z position
	int GetIndexCount();
	ID3D11ShaderResourceView* GetTexture();

private:
	bool LoadHeightMap(char*);
	void NormalizeHeightMap();
	void ShutdownHeightMap();

	void CalculateTextureCoordinates();
	bool LoadTexture(ID3D11Device*, WCHAR*);
	void ReleaseTexture();

	bool InitializeBuffers(ID3D11Device*);
	void ShutdownBuffers();
	void RenderBuffers(ID3D11DeviceContext*);
	bool CalculateNormals();
	
private:
	int m_terrainWidth, m_terrainHeight;
	int m_vertexCount, m_indexCount;
	float m_RaiseLevel; //for raising lowering terrain
	float m_SmoothLevel; //Terrain Smoothing
	bool m_Topology;
	float m_Range; // Range of affected area
	ID3D11Buffer *m_vertexBuffer, *m_indexBuffer;
	HeightMapType* m_heightMap;
	TextureClass* m_Texture;

	//For Editor
	VertexType* m_vertices;
};

#endif