#pragma once
#include "Transform.h"


struct Light // directional
{
	Transform transform;
	vec4 color;
	vec4 direction;

	Light() : color(white), direction(forward) {}
};