
#include "Timer.h"

// Implementación para windows

#include <windows.h>

using namespace xt;

/*
 *
 */
Timer::Timer()
{
	memset(&_timer, 0, sizeof(_timer)); // Clear Our Timer Structure
	// Check To See If A Performance Counter Is Available
	// If One Is Available The Timer Frequency Will Be Updated
	if (!QueryPerformanceFrequency((LARGE_INTEGER *) &_timer.frequency))
	{
		// No Performace Counter Available
		_timer.performance_timer = FALSE; // Set Performance Timer To FALSE
		_timer.mm_timer_start = timeGetTime(); // Use timeGetTime() To Get Current Time
		_timer.resolution = 1.0f/1000.0f; // Set Our Timer Resolution To .001f
		_timer.frequency = 1000; // Set Our Timer Frequency To 1000
		_timer.mm_timer_elapsed = _timer.mm_timer_start; // Set The Elapsed Time To The Current Time
	}
	else
	{
		// Performance Counter Is Available, Use It Instead Of The Multimedia Timer
		// Get The Current Time And Store It In performance_timer_start
		QueryPerformanceCounter((LARGE_INTEGER *) &_timer.performance_timer_start);
		_timer.performance_timer = TRUE; // Set Performance Timer To TRUE
		// Calculate The Timer Resolution Using The Timer Frequency
		_timer.resolution = (((double)1.0f)/((double)_timer.frequency));
		// Set The Elapsed Time To The Current Time
		_timer.performance_timer_elapsed = _timer.performance_timer_start;
	} 
}

/*
 *
 */
double Timer::GetTime()
{
	__int64 time; // time Will Hold A 64 Bit Integer

	if (_timer.performance_timer) // Are We Using The Performance Timer?
	{
		QueryPerformanceCounter((LARGE_INTEGER *) &time); // Grab The Current Performance Time
		// Return The Current Time Minus The Start Time Multiplied By The Resolution And 1000 (To Get MS)
		return ( (double) ( time - _timer.performance_timer_start) * _timer.resolution)*1000.0;
	}
	else
	{
		// Return The Current Time Minus The Start Time Multiplied By The Resolution And 1000 (To Get MS)
		return( (double) ( timeGetTime() - _timer.mm_timer_start) * _timer.resolution)*1000.0f;
	} 
}
