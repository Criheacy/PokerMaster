#include "Animation.h"

Animation::Animation(class Object* attachedObject)
{
	this->attachedObject = attachedObject;
	this->transform = attachedObject->transform;
	mActive = false;
}

Animation::~Animation()
{
	this->attachedObject = NULL;
	this->transform = NULL;
	mActive = false;
}

void Animation::StartAnimation(AnimationConfig animConfig)
{
	if (mActive)	// Stop if previous animation is running
	{
		// Set transform to the destination of the previous animation
		transform->SetTransform(this->animConfig.destTransform);
	}
	this->mActive = true;
	animConfig.startTransform = transform->GetTransform();
	this->animConfig = animConfig;
}

void Animation::UpdateAnimation()
{
	if (!mActive) return;
	Uint32 nowTime = SDL_GetTicks();
	double timeRate = ((double)(nowTime - animConfig.startTime)) / animConfig.duration;
	if (timeRate > 1)
	{
		transform->SetTransform(animConfig.destTransform);
		this->mActive = false;
	}
	else
	{
		double rate = CalculateRate(timeRate, animConfig.transition, animConfig.transitionParam);
		UpdateTransform(rate);
	}
}

void Animation::TerminateAnimation()
{
	if (!mActive) return;
	transform->SetTransform(animConfig.destTransform);
	this->mActive = false;
}

bool Animation::IsActive()
{
	return mActive;
}

// ---------- Private Functions ----------

double Animation::CalculateRate(double timeRate, Transition transition, double transitionParam)
{
	switch (transition)
	{
	case NONE:	// or CLIFF
		return 1; break;
	case LINEAR:
		return timeRate; break;

	// TODO: Implement
	case SMOOTH:
	case SMOOTH_IN:
	case SMOOTH_OUT:
	default:
		return timeRate;
		break;
	}
}

void Animation::UpdateTransform(double rate)
{
	int x = animConfig.startTransform.x * (1 - rate) + animConfig.startTransform.x * rate;
	int y = animConfig.startTransform.y * (1 - rate) + animConfig.startTransform.y * rate;
	double angle = animConfig.startTransform.angle * (1 - rate) + animConfig.startTransform.angle * rate;
	double scale = animConfig.startTransform.scale * (1 - rate) + animConfig.startTransform.scale * rate;
	
	transform->SetTransform({ x, y, angle, scale });
}