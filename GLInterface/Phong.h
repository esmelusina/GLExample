#pragma once
#include "Camera.h"
#include "GameObject.h"
#include "light.h"
#include <string>


struct RenderPhong
{
	std::string shader;

	//set uniforms and draw.
	void draw(const Camera &cam,const GameObject &go, const Light &light);
};