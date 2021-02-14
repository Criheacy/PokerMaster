#pragma once
#include "Transform.h"

class Object
{
public:
	Object();
	Object(class Transform* transform);

	Transform* GetTransform();

protected:
	Transform* transform;
};