#pragma once
#ifndef __HEARTPICKUP_H__
#define __HEARTPICKUP_H__

#include "GameObject.h"

class HeartPickup : public GameObject
{
public:
	HeartPickup(void);
	~HeartPickup(void);

	bool CollisionTest(shared_ptr<GameObject> o);
	void OnCollision(const GameObjectList& objects);
};

#endif
