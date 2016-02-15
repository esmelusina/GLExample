#pragma once
#include "Vertex.h"

// singleton GLFW wrapper
// covers context, input, and time.
// Could be broken up into separate static classes or whatever.

class Window
{
	class GLFWwindow *handle;
	unsigned width, height;
	bool isInit;

	float deltaTime, lastTime;

	bool lastKeyState[350];
	bool currentKeyState[350];

	bool lastMouseButtonState[10];
	bool currentMouseButtonState[10];

	vec2 mousePosition; // could keep last I guess

	Window() : handle(0), width(0), height(0), isInit(0) {}
public:
	static Window &instance() { static Window w; return w; }
	
	bool isInitialized() { return isInit; }

	// conditions to shut-down window
	bool shouldClose();

	// open context and do boiler-plate openGL stuff
	void  init(unsigned w, unsigned h, const char *title);
	void  step();	// swap buffers, poll events, update time, update key/mouse states
	void  term();	// close context

	float getTime();	  // total time should be consistent from last frame
	float getDeltaTime(); // DT should be consistent from start to end of frame
	float getRealTime();  // GLFWGetTime...
	
	enum KEY_STATE { UP, DOWN, PRESSED, RELEASED};

	bool getKey(unsigned, KEY_STATE); 	// what state are we asking about?
	KEY_STATE getKey(unsigned);			// or if they just want the state

	vec2 getMousePos();
	bool getMouseButton(unsigned, KEY_STATE);
	KEY_STATE getMouseButton(unsigned);
};