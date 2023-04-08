#include <stdlib.h>
#include "GameUtil.h"
#include "HeartPickup.h"
#include "BoundingShape.h"
#include "Asteroid.h"

HeartPickup::HeartPickup(void) : GameObject("HeartPickup")
{
	mAngle = rand() % 360;
	mRotation = rand() % 90;
	mPosition.x = rand() / 2;
	mPosition.y = rand() / 2;
	mPosition.z = 0.0;
	mVelocity.x = 10.0 * cos(DEG2RAD * mAngle);
	mVelocity.y = 10.0 * sin(DEG2RAD * mAngle);
	mVelocity.z = 0.0;
}

HeartPickup::~HeartPickup(void)
{
}

bool HeartPickup::CollisionTest(shared_ptr<GameObject> o)
{
	if (GetType() == o->GetType() || o->GetType() == GameObjectType("Asteroid") || o->GetType() == GameObjectType("Bullet")) return false;
	if (mBoundingShape.get() == NULL) return false;
	if (o->GetBoundingShape().get() == NULL) return false;
	return mBoundingShape->CollisionTest(o->GetBoundingShape());
}

void HeartPickup::OnCollision(const GameObjectList& objects)
{
	mWorld->FlagForRemoval(GetThisPtr());
}
