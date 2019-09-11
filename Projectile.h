#pragma once
#include <iostream>
#include "ofMain.h"
#include "GameObject.h"

class Projectile : public GameObject
{
public:
	Projectile();
	Projectile(Point2D<float> base, Point2D<float> end, float speed, float range);
	Projectile(const Projectile &copy);
	void set(Point2D<float> base, Point2D<float> end, float speed, float range);
	void set(Point2D<float> position);
	void set(std::string filepath);
	bool isDead() const;
	bool move();


private:
	Vector2D<float> m_goal;
	float m_range;
	
	bool m_dead;
};

