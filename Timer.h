/*
 * Copyright 2010 Daniel Albano
 *
 * This file is part of OpenXcom.
 *
 * OpenXcom is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OpenXcom is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OpenXcom.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef OPENXCOM__TIMER_H
#define OPENXCOM__TIMER_H

#include "SDL.h"
#include "State.h"
#include "Surface.h"

typedef State &(State::*StateHandler)();
typedef Surface &(Surface::*SurfaceHandler)();

/**
 * Timer used to run code in fixed intervals.
 * Used for code that should run at the same fixed interval
 * in various machines, based on miliseconds instead of CPU cycles.
 */
class Timer
{
private:
	Uint32 _start, _interval;
	bool _running;
	StateHandler _state;
	SurfaceHandler _surface;
public:
	/// Creates a stopped timer.
	Timer(Uint32 interval);
	/// Cleans up the timer.
	~Timer();
	/// Starts the timer.
	void start();
	/// Stops the timer.
	void stop();
	/// Gets the current time interval.
	Uint32 getTime();
	/// Gets if the timer's running.
	bool isRunning();
	/// Advances the timer.
	void think(State* state, Surface* surface);
	/// Sets the timer's interval.
	void setInterval(Uint32 interval);
	/// Hooks a state event handler to the timer interval.
	void onTimer(StateHandler handler);
	/// Hooks a surface event handler to the timer interval.
	void onTimer(SurfaceHandler handler);
};

#endif
