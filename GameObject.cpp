#include "GameObject.h"
#include "ofMain.h"
#include <string>
#include <iostream>


GameObject::GameObject()
{
	Point2D<float> m_position(0, 0);
	m_width = 10;
	m_height = 10;
	m_texture = new ofImage();
	m_texturePath = "JumpingSpiderBuff.png";
	m_texture->load(m_texturePath);
}

GameObject::GameObject(std::string texturePath)
{
	Point2D<float> m_position(0, 0);
	m_width = 10;
	m_height = 10;
	m_texture = new ofImage();
	m_texturePath = texturePath;
	m_texture->load(m_texturePath);
}

GameObject::GameObject(float x, float y, float width, float height)
{
	Point2D<float> m_position(x, y);
	m_width = width;
	m_height = height;
	m_texture = new ofImage();
	m_texturePath = "JumpingSpiderBuff.jpg";
	m_texture->load(m_texturePath);
}

GameObject::GameObject(float x, float y, float width, float height, std::string texturePath)
{
	Point2D<float> m_position(x, y);
	m_width = width;
	m_height = height;
	m_texture = new ofImage();
	m_texturePath = texturePath;
	m_texture->load(m_texturePath);
}

GameObject::GameObject(Point2D<float> position, float width, float height)
{
	Point2D<float> m_position(position);
	m_width = width;
	m_height = height;
	m_texture = new ofImage();
	m_texturePath = "JumpingSpiderBuff.png";
	m_texture->load(m_texturePath);
}

GameObject::GameObject(Point2D<float> position, float width, float height, std::string texturePath)
{
	Point2D<float> m_position(position);
	m_width = width;
	m_height = height;
	m_texture = new ofImage();
	m_texturePath = texturePath;
	m_texture->load(m_texturePath);
	std::cout << std::endl << std::endl << m_position.m_x << std::endl;
}

GameObject::GameObject(const GameObject &copy)
{
	Point2D<float> m_position(copy.m_position.m_x,copy.m_position.m_y);
	m_height = copy.m_height;
	m_width = copy.m_width;
	m_texturePath = copy.m_texturePath;
	m_texture = new ofImage();
	m_texture->load(m_texturePath);
}

ofImage* GameObject::draw()
{
	return m_texture;
}

void GameObject::setPosition(float x, float y)
{
	m_position.set(x, y);
}

void GameObject::set(std::string path)
{
	m_texture->load(path);
}

float GameObject::getX() const
{
	return m_position.m_x;
}

float GameObject::getY() const
{
	return m_position.m_y;
}

GameObject::~GameObject()
{
	delete m_texture;
}
