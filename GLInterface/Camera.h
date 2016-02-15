#pragma once
#include "Transform.h"

class Camera
{
public:
	Transform transform; // inverse of view
	mat4 projection;
	
	Camera() : projection(identity) {}

	mat4 getView(); // inverse of transform

	// lookAt algorithm creates a view matrix, need to inverse before setting local Transform
	void lookAt(const vec4 &pos, const vec4 &target, const vec4 &up);
	
	// near must be > 0 for depth testing to work
	void perspective(float fov, float aspect, float near, float far);
	void ortho   (float l, float r, float t, float b, float n, float f);
};