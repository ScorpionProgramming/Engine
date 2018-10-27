#pragma once
#include "Triangle.h"
#include <vector>
#include <time.h>

class Scene
{
public:
	Scene();
	/**
	Setzten Sie SceneComplexity auf 0, so besitzt die resultierende Scene nur sehr wenige Dreckecke. 
	Eine Szenenkomplexität von 20 dagegen besitzt mehrere tausende Dreiecke.
	*/
	Scene(unsigned int SceneComplexity);
	virtual ~Scene();
	const Triangle& getTriangle(unsigned int index) const;
	unsigned int getTriangleCount() const;
	/*const PointLight& getLight(unsigned int index) const;*/
	unsigned int getLightCount() const;

private:
	std::vector<Triangle> triangles;
};

