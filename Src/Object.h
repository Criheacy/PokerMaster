#pragma once
#include <SDL.h>
#include "Transform.h"

class Object
{
public:
	Object();
	Object(class Transform* transform);

	Transform* transform;
};