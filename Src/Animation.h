#pragma once
#include "Object.h"
#include "Transform.h"
#include <SDL.h>

/* Animation: Manage all animations and motions of attached object.
 * Description:
 *		Use public function [StartAnimation] to animate an object.
 *		Calculate asynchronously, use function [Update] to update transform.
 *		MUST be attached to objects with transform class.
 */

enum Transition
{
	NONE = 0,
	CLIFF = 0,
	LINEAR = 1,
	SMOOTH = 2,
	SMOOTH_IN = 3,
	SMOOTH_OUT = 4,
};

struct AnimationConfig
{
	TransformConfig	startTransform;
	TransformConfig destTransform;
	Uint32 startTime;
	Uint32 duration;
	Transition transition;
	double transitionParam;
};

class Animation
{
public:
	Animation(class Object* attachedObject);
	~Animation();

	void StartAnimation(AnimationConfig animConfig);
	void UpdateAnimation();
	void TerminateAnimation();

	bool IsActive();

private:
	double CalculateRate(double timeRate, Transition transition, double transitionParam);
	void UpdateTransform(double rate);

	class Object* attachedObject;
	class Transform* transform;

	AnimationConfig animConfig;
	bool mActive;
};