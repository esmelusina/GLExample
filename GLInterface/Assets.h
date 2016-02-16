#pragma once

#include <unordered_map>
#include "cassetutils.h"
#include <string>
#include "Window.h"

// Wrap our cassetutils functions so that stuff is properly cleaned up
// also- uhh... let us access assets by name. Which is cool.
class Assets
{
	Assets() :isInit(false) {}
	bool isInit; // functions should fail if isInit is false

	// give our assets human readable names!
	std::unordered_map<std::string, Texture>	  textures;
	std::unordered_map<std::string, RenderObject> renderObjects;
	std::unordered_map<std::string, Shader>		  shader;
	std::unordered_map<std::string, RenderTarget> renderTargets;
public:
	static Assets &instance() { static Assets a; return a; }

	Texture      getTexture		 (const std::string &name);
	RenderObject getRenderObject (const std::string &name);
	Shader       getShader		 (const std::string &name);
	RenderTarget getRenderTarget (const std::string &name);

	// Just wrap cassetutils procedures, add a 'name' parameter
	// so that we can name them memorable things, and drop them in our maps
	void makeTexture	  (const char *name, unsigned w, unsigned h, unsigned depth, const unsigned char *pixels = nullptr);
	void makeRenderObject (const char *name, const Vertex *verts, unsigned vsize, const unsigned *tris, unsigned tsize);
	void makeShader		  (const char *name, const char *vsource, const char *fsource);
	void makeRenderTarget (const char *name, unsigned w, unsigned h, const unsigned *depths, unsigned dcount );

	void loadFBX	(const char *name, const char *path);
	void loadOBJ	(const char *name, const char *path);
	void loadTexture(const char *name, const char *path);
	void loadShader	(const char *name, const char *vpath, const char *fpath);


	// set isInit to true IFF window is initialized
	// load some default assets- cube, quad, half-blue for fallback normal, and white as default color
	void init();
	// loop through and free our assets
	void term();
};