#include "Projectile.h"
#include <string>
#include <math.h>
#include <iostream>


Projectile::Projectile() : GameObject(), m_goal(0,0), m_range(0), m_dead(true)
{
}

Projectile::Projectile(Point2D<float> base, Point2D<float> end, float speed, float range) : GameObject(base, 8, 8, "Bullet.png")
{
	Point2D<float> m_position(base);
	float angle(0);
	if (end.m_x - base.m_x == 0)
	{
		double pi = 3.1415926535897;
		if (end.m_y - base.m_y == 0)
		{
			angle = 0;
		}
		else if (end.m_y - base.m_y > 0)
		{
			angle = pi / 2;
		}
		else {
			angle = -pi / 2;
		}
	}
	else {
		angle = atan((end.m_y - base.m_y) / (end.m_x - base.m_x));
	}
	Vector2D<float> m_goal(cos(angle)*speed, sin(angle)*speed);
	m_range = range;
	m_dead = false;
}

Projectile::Projectile(const Projectile &copy) : GameObject(copy)
{
	m_goal = copy.m_goal;
	m_range = copy.m_range;
	m_dead = false;
}

void Projectile::set(Point2D<float> base, Point2D<float> end, float speed, float range)
{
	m_position=base;
	
	float angle(0);
	if (end.m_x - base.m_x == 0)
	{
		double pi = 3.1415926535897;
		if (end.m_y - base.m_y == 0)
		{
			angle = 0;
		}
		else if (end.m_y - base.m_y > 0)
		{
			angle = pi / 2;
		}
		else {
			angle = -pi / 2;
		}
	}
	else {
		angle = atan((end.m_y - base.m_y) / (end.m_x - base.m_x));
	}
	Vector2D<float> m_goal(cos(angle)*speed, sin(angle)*speed);
	m_range = range;
}

void Projectile::set(Point2D<float> position)
{
	m_position = position;
}

void Projectile::set(std::string filepath)
{
	m_texturePath = filepath;
	m_texture->load(m_texturePath);
}

bool Projectile::isDead() const
{
	return m_dead;
}

bool Projectile::move()
{
	if (m_dead == false)
	{
		m_position = m_position + m_goal;
		m_range -= m_goal.m_length;
		if (m_range <= m_goal.m_length)
		{
			m_dead = true;
		}
		return false;
	}
	else {
		return true;
	}
}
