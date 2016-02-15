#pragma once
#include "Vertex.h"

class Transform
{
public:
	mat4 local;
	Transform *parent;
	Transform() : local(identity), parent(nullptr) {}

	mat4 getGlobal();
};