////////////////////////////////////////////////////////////////////////////////
//
//	Code Original Creator: Rastertek
//	Source: http://www.rastertek.com/tertut02.html
//	Used By: Leonard Roll
//	I do not own most of the code but am following the tutorials on the website 
//	to create my project for the final year projects.
//
///////////////////////////////////////////////////////////////////////////////
// Filename: fpsclass.cpp
///////////////////////////////////////////////////////////////////////////////
#include "fpsclass.h"


FpsClass::FpsClass()
{
}


FpsClass::FpsClass(const FpsClass& other)
{
}


FpsClass::~FpsClass()
{
}


void FpsClass::Initialize()
{
	// Initialize the counters and the start time.
	m_fps = 0;
	m_count = 0;
	m_startTime = timeGetTime();
	
	return;
}


void FpsClass::Frame()
{
	m_count++;

	// If one second has passed then update the frame per second speed.
	if(timeGetTime() >= (m_startTime + 1000))
	{
		m_fps = m_count;
		m_count = 0;
		
		m_startTime = timeGetTime();
	}
}


int FpsClass::GetFps()
{
	return m_fps;
}