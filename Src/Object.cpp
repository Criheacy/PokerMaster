#include "Object.h"

Object::Object()
{
	transform = new Transform(this);
}

Object::Object(Transform* transform)
{
	this->transform = transform;
}

class Transform* Object::GetTransform()
{
	return this->transform;
}