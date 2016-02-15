#include "Application.h"
#include "Phong.h"
class Example : public Application
{
	void onInit();
	void onStep();
	void onPlay();

	Camera		cam;
	GameObject	go;
	Light		light;

	RenderPhong render;
};

void main() { Example().Run(); }


// technically a XML/YAML/JSON file could figure all this out
void Example::onInit()
{
	auto &aref = Assets::instance();

	aref.loadShader("Phong","path-to-phong-vertex", "path-to-phong-fragment");

	aref.loadTexture("GONormal", "path-to-normal-map");
	aref.loadTexture("GODiffuse", "path-to-diffuse-map");
	aref.loadTexture("GOSpecular", "path-to-specular-map");

	aref.loadOBJ("GOGeometry","path-to-obj");
}

// and some sort of scene-file for this, in conjunction w/a factory object
void Example::onPlay()
{
	render.shader = "Phong";

	go.mesh		  = "GOGeometry";
	go.material	  = {"GODiffuse","GONormal","GOSpecular", 1.0f};

	cam.lookAt({10,10,0,1}, zero, up);
}

void Example::onStep()
{
	render.draw(cam, go, light);
}