#pragma once
#ifndef __SPEEDPICKUP_H__
#define __SPEEDPICKUP_H__

#include "GameObject.h"

class SpeedPickup : public GameObject
{
public:
	SpeedPickup(void);
	~SpeedPickup(void);

	bool CollisionTest(shared_ptr<GameObject> o);
	void OnCollision(const GameObjectList& objects);
};

#endif
