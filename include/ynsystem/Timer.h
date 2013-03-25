#pragma once

#include <xtreme11\export.h>

namespace xt {

/*
 *
 */
class XTREME_EXPORT Timer {

private:

	struct // Create A Structure For The Timer Information
	{
		__int64 frequency; // Timer Frequency
		double resolution; // Timer Resolution
		unsigned long mm_timer_start; // Multimedia Timer Start Value
		unsigned long mm_timer_elapsed; // Multimedia Timer Elapsed Time
		bool performance_timer; // Using The Performance Timer?
		__int64 performance_timer_start; // Performance Timer Start Value
		__int64 performance_timer_elapsed; // Performance Timer Elapsed Time
	} _timer; // Structure Is Named timer

public:

	//				
	Timer();

	// Returns time in MS
	double GetTime();

};

}
