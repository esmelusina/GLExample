#pragma once
#include "Transform.h"
#include "Phong.h"

struct MaterialPhong // Phong Shading Model
{
	// names are used to fetch data from Assets
	std::string diffuse, normal, specular;
	float specPower;
};

struct GameObject
{
	Transform transform;
	std::string mesh;
	MaterialPhong material;
};