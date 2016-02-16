#pragma once
#include "Vertex.h"

/*
C-Style solutions to common file-to-buffer problems.

C-style implementations are often easier to understand,
since they decouple logic and data.

OOP can be implemented after the fact, but just arranging
the data and procedures in whichever way makes sense.

'make' functions allocate data on the video card.
'load' functions pull data in from a file, and use 'make' directly.
'free' functions deallocate data on the video card.
*/

struct RenderObject { unsigned VBO, VAO, IBO, tsize; };
struct Texture		{ unsigned handle, width, height, format; };
struct Shader		{ unsigned handle; }; // may have more data later.
struct RenderTarget { unsigned handle, width, height; Texture *e_targets; };

RenderObject makeRO(const Vertex *verts, unsigned vsize, const unsigned *tris, unsigned tsize);
bool		 freeRO(RenderObject &ro);  // should zero out the RO just in case it
RenderObject loadFBX(const char *path); // may want to return array, since FBX can have more than one RO
RenderObject loadOBJ(const char *path); // Need to manually interleave from tinyOBJ

// possible to have a texture w/out pixel data (ie. render target)
// depth could be a GLuint or enum for 1-4 BYTE COLOR, DEPTH, or STENCIL
Texture makeTexture(unsigned w, unsigned h, unsigned depth, const unsigned char *pixels = nullptr);
bool	freeTexture(Texture &);
Texture loadTexture(const char *path);

Shader makeShader(const char *vsource, const char *fsource);
bool   freeShader(Shader &);
Shader loadShader(const char *vpath, const char *fpath);

RenderTarget makeRT(const Texture *textures, unsigned tcount);
bool         freeRT(RenderTarget &rt);