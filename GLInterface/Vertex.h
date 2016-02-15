#pragma once

struct vec4 { float x, y, z, w; };
struct vec2 { float x, y; };

union mat4 { vec4 c[4]; float m[16]; };


const vec4 zero		= { 0,0,0,0 };
const vec4 right	= { 1,0,0,0 };
const vec4 up		= { 0,1,0,0 };
const vec4 forward	= { 0,0,1,0 };
const vec4 affine   = { 0,0,0,1 };

const mat4 identity = { right,up,forward,affine };

const vec4 left		= { -1,0,0,0 };
const vec4 down		= { 0,-1,0,0 };
const vec4 backward	= { 0,0,-1,0 };


const vec4 black	= { 0,0,0,1 };
const vec4 white	= { 1,1,1,1 };


struct Vertex
{
	vec4 position;
	vec4 normal;	// forward
	vec4 tangent;	// right
	vec4 binormal;  // up
	vec4 color;
	vec2 texCoord;  // uv coordinates for textures
};

// clip Space Quad
const Vertex QuadVerts[] =
{
	{ { -1, 1, 0, 1 }, forward, right, up, white, { 0,1 } },
	{ {  1, 1, 0, 1 }, forward, right, up, white, { 1,1 } },
	{ {  1,-1, 0, 1 }, forward, right, up, white, { 1,0 } },
	{ { -1,-1, 0, 1 }, forward, right, up, white, { 0,0 } }
};

const unsigned QuadTris[] = { 3,1,0, 3,2,1 };

// could cleanup the TBN and UVs to make sure they are more consistent
// note: cube needs to duplicate verts for each face so that normals are correct
// cube is 2x2x2
const Vertex CubeVerts[] =
// Bottom
{ { { -1,-1, 1, 1 }, down, right, forward, white, {0,1 } },
{   {  1,-1, 1, 1 }, down, right, forward, white, {1,1 } },
{   {  1,-1,-1, 1 }, down, right, forward, white, {1,0 } },
{   { -1,-1,-1, 1 }, down, right, forward, white, {0,0 } },
// Top
{ { -1, 1, 1, 1}, up, right, forward, white, {0,1} },
{ {  1, 1, 1, 1}, up, right, forward, white, {1,1} },
{ {  1, 1,-1, 1}, up, right, forward, white, {1,0} },
{ { -1, 1,-1, 1}, up, right, forward, white, {0,0} },
// back
{ {-1,  1, -1, 1}, backward, left, up, white, {0,1} },
{ { 1,  1, -1, 1}, backward, left, up, white, {1,1} },
{ { 1, -1, -1, 1}, backward, left, up, white, {1,0} },
{ {-1, -1, -1, 1}, backward, left, up, white, {0,0} },
// front
{ {-1,  1, 1, 1}, forward, right, up, white, {0,1} },
{ { 1,  1, 1, 1}, forward, right, up, white, {1,1} },
{ { 1, -1, 1, 1}, forward, right, up, white, {1,0} },
{ {-1, -1, 1, 1}, forward, right, up, white, {0,0} },
// left
{ {-1, 1,-1, 1}, left, forward, up, white, {1,0} },
{ {-1, 1, 1, 1}, left, forward, up, white, {1,1} },
{ {-1,-1, 1, 1}, left, forward, up, white, {0,1} },
{ {-1,-1,-1, 1}, left, forward, up, white, {0,0} },
// right
{ {1, 1,-1, 1}, right, backward, up, white, {1,0} },
{ {1, 1, 1, 1}, right, backward, up, white, {1,1} },
{ {1,-1, 1, 1}, right, backward, up, white, {0,1} },
{ {1,-1,-1, 1}, right, backward, up, white, {0,0} },
};

const unsigned CubeTris[] = {
	3,2,0,    0,2,1,
	7,4,6,    6,4,5,
	11,8,10,  10,8,9,
	15,14,12, 12,14,13,
	19,18,16, 16,18,17,
	23,20,22, 22,20,21 };
