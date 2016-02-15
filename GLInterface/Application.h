#pragma once
#include "Window.h"
#include "Assets.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

/*
	Inherit from this.
*/

class Application
{
private:
	bool kill;

	void init()
	{
		Window::instance().init(WINDOW_WIDTH, WINDOW_HEIGHT, "OpenGL App");
		Assets::instance().init();
		kill = false;
		onInit();
	}

	void step()
	{
		Window::instance().step();
		onStep();
	}

	void term()
	{
		onTerm();
		Assets::instance().term();
		Window::instance().term();
	}

	void play()
	{
		onPlay();
		do { step(); } while (!Window::instance().shouldClose() && !kill);
	}

protected:
	virtual void onInit() = 0;	// load assets
	virtual void onTerm() {};   // unload any remaining heap data.

	virtual void onPlay() = 0; // setup Game Objects
	virtual void onStep() = 0; // update Game Objects

public:
	void Run() { init(); play(); term(); }

	void doKill() { kill = true; }
};