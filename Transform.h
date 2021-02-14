#pragma once

class Transform
{
public:
	Transform(class Object* obj, int x = 0, int y = 0,
		int angle = 0, double scale = 1);

	void MoveTo(int x, int y);
	void Move(int deltaX, int deltaY);

	void RotateTo(int angle);	// Use Angle System
	void Rotate(int angle);

	void ScaleTo(double scale);
	void Scale(double scale);

	int GetX();
	int GetY();
	int GetAngle();
	int GetScale();

private:
	Object* attachedObject;

	int x;
	int y;

	int angle;
	double scale;
};