#pragma once
#include "ofMain.h"
#include <string>
#include "Geometry2D.h"

class GameObject
{
public:
	GameObject();
	GameObject(std::string texturePath);
	GameObject(float x, float y, float width, float height);
	GameObject(float x, float y, float width, float height, std::string texturePath);
	GameObject(Point2D<float> position, float width, float height);
	GameObject(Point2D<float> position, float width, float height, std::string texturePath);
	GameObject(const GameObject &copy);
	ofImage* draw();
	void setPosition(float x, float y);
	void set(std::string);
	float getY() const;
	float getX() const;
	~GameObject();

protected:
	ofImage* m_texture;
	std::string m_texturePath;
	Point2D<float> m_position;
	float m_width;
	float m_height;
};

