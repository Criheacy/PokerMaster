#include "Transform.h"

Transform::Transform(Object* obj, int x, int y, int angle, double scale)
{
	attachedObject = obj;

	this->x = x;
	this->y = y;
	this->angle = angle;
	this->scale = scale;
}

void Transform::MoveTo(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Transform::Move(int x, int y)
{
	this->x += x;
	this->y += y;
}

void Transform::RotateTo(int angle)
{
	this->angle = angle;
	this->angle %= 360;
}

void Transform::Rotate(int angle)
{
	this->angle += angle;
	this->angle %= 360;
}

void Transform::ScaleTo(double scale)
{
	this->scale = scale;
}

void Transform::Scale(double scale)
{
	this->scale *= scale;
}

int Transform::GetX()
{
	return x;
}

int Transform::GetY()
{
	return y;
}

int Transform::GetAngle()
{
	return angle;
}

int Transform::GetScale()
{
	return scale;
}