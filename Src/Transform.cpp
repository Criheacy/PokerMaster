#include "Transform.h"

Transform::Transform(Object* obj, int x, int y, double angle, double scale)
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

void Transform::RotateTo(double angle)
{
	this->angle = angle;
}

void Transform::Rotate(double angle)
{
	this->angle += angle;
}

void Transform::ScaleTo(double scale)
{
	this->scale = scale;
}

void Transform::Scale(double scale)
{
	this->scale *= scale;
}

void Transform::SetTransform(TransformConfig tranConfig)
{
	MoveTo(tranConfig.x, tranConfig.y);
	RotateTo(tranConfig.angle);
	ScaleTo(tranConfig.scale);
}

int Transform::GetX()
{
	return x;
}

int Transform::GetY()
{
	return y;
}

double Transform::GetAngle()
{
	return angle;
}

double Transform::GetScale()
{
	return scale;
}

TransformConfig Transform::GetTransform()
{
	return { x, y, angle, scale };
}