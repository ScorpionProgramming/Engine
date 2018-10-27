#include "Scene.h"

Scene::Scene()
{
}


Scene::Scene(unsigned int SceneComplexity)
{	
	//Init variables	
	triangles = std::vector<Triangle>();
	Triangle *triangle;
	Vector3f *position;
	int factor;

	srand(time(NULL));
	//srand(time(NULL));
	factor = 110 - (rand() % 20);
	
	//create factor*scenecompexity triangles at random positions
	unsigned int i;

	for (i = 0; i < factor*SceneComplexity; i++) {
	
		triangle = new Triangle();
		position = new Vector3f();
		
		position->x = 0;
		position->y = 0;
		position->z = 0;

		position->x = rand() % 500 - 250;
		position->y = rand() % 500 - 250;
		position->z = rand() % 500 - 250;

		triangle->A += *position;
		triangle->B += *position;
		triangle->C += *position;

		triangles.push_back(*triangle);
	}
}

Scene::~Scene()
{
}

const Triangle & Scene::getTriangle(unsigned int index) const
{
	// TODO: hier Rückgabeanweisung eingeben
	return Triangle();
}

unsigned int Scene::getTriangleCount() const
{
	return triangles.size();
}

unsigned int Scene::getLightCount() const
{
	return 0;
}