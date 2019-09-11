#include <math.h>
template <typename T>
class Point2D {
public:
	Point2D();
	Point2D(T x, T y);
	Point2D(Point2D<T> &copy);
	void set(T x, T y);
	T m_x;
	T m_y;
};

template <typename T>
class Vector2D {
public:
	Vector2D();
	Vector2D(T width, T height);
	Vector2D(Vector2D<T> &copy);
	Vector2D(Point2D<T> &point);
	Vector2D(Point2D<T> &base, Point2D<T> &end);
	void reset();
	void add(T addedWidth, T addedHeight);
	float scalaire(Vector2D<T> &vector);
	T m_width;
	T m_height;
	float m_angle;
	float m_length;
};



//------------SURCHARGES-------------SURCHARGES-------------------------SURCHARGES--------------------------------
//Surcharge de l'operateur +
template <typename T>
Vector2D<T> operator+(Vector2D<T> const& a, Vector2D<T> const& b)
{
	Vector2D<T> temp(a.m_width + b.m_width, a.m_height + b.m_height);
	return temp;
}

//Surcharge  de l'operateur + (avec un float)
template <typename T>
Vector2D<float> operator+(Vector2D<T> const& a, float const& b)
{
	Vector2D<float> temp((a.m_length + b)*cos(a.m_angle), (a.m_length + b)*sin(a.m_angle));
	return temp;
}

//Surcharge de l'operateur Point+Vecteur
template <typename T>
Point2D<T> operator+(Point2D<T> const& a, Vector2D<T> const& b)
{
	Point2D<T> temp(a.m_x + b.m_width, a.m_y + b.m_height);
	return temp;
}

//Surcharge de l'operateur ==
template <typename T>
bool operator==(Vector2D<T> const& a, Vector2D<T> const& b)
{
	return (a.m_angle == b.m_angle && a.m_length == b.m_length);
}

//----------------POINT2D-------------------------POINT2D--------------------POINT2D--------------------
// Point2D <T> functions definitions
//default constructor (is needed for use in other classes)
template <typename T>
Point2D<T>::Point2D()
{
}

//normal constructor
//Create a (x;y) point
template <typename T>
Point2D<T>::Point2D(T x, T y)
{
	m_x = x;
	m_y = y;
}

//copy constructor
template <typename T>
Point2D<T>::Point2D(Point2D<T> &copy)
{
	m_x = copy.m_x;
	m_y = copy.m_y;
}

//-------------------------------------------------------------------------------------
template <typename T>
void Point2D<T>::set(T x, T y)
{
	m_x = x;
	m_y = y;
}

//------------VECTOR2D-------------------VECTOR2D------------------VECTOR2D---------------VECTOR2D----------------------------
//Vector2D<T> function definitions
//Default constructor (is needed for use in other classes)
template <typename T>
Vector2D<T>::Vector2D()
{
}

//Base constructor
//Create a (width;height) vector
template <typename T>
Vector2D<T>::Vector2D(T width, T height)
{
	m_width = width;
	m_height = height;
	m_length = (float)sqrt(pow(width, 2.0) + pow(height, 2.0));
	double pi = 3.1415926535897;
	if (m_width == 0.0)
	{
		if (m_height > 0)
		{
			m_angle = (float)pi / 2;
		}
		else if (m_height == 0)
		{
			m_angle = 0;
		}
		else {
			m_angle = -(float)pi / 2;
		}
	}
	else {
		m_angle = (float)atan(m_height / m_width);
	}
}

//Copy  constructor
template <typename T>
Vector2D<T>::Vector2D(Vector2D<T> &copy)
{
	m_width = copy.m_width;
	m_height = copy.m_height;
	m_length = copy.m_length;
	m_angle = copy.m_angle;
}

//-------------------------------------------------------------------------------------------------
//create a vector starting from (0;0) to point
template <typename T>
Vector2D<T>::Vector2D(Point2D<T> &point)
{
	m_width = point.m_x;
	m_height = point.m_y;
	m_length = (float)sqrt(pow(m_width, 2.0) + pow(m_height, 2.0));
	double pi = 3.1415926535897;
	if (m_width == 0.0)
	{
		if (m_height > 0)
		{
			m_angle = (float)pi / 2;
		}
		else if (m_height == 0)
		{
			m_angle = 0;
		}
		else {
			m_angle = -(float)pi / 2;
		}
	}
	else {
		m_angle = (float)atan(m_height / m_width);
	}
}

//-------------------------------------------------------------------------------------------------
//Create a vector starting from base to end
template <typename T>
Vector2D<T>::Vector2D(Point2D<T> &base, Point2D<T> &end)
{
	m_width = end.m_x - base.m_x;
	m_height = end.m_y - base.m_y;
	m_length = (float)sqrt(pow(m_width, 2.0) + pow(m_height, 2.0));
	double pi = 3.1415926535897;
	if (m_width == 0.0)
	{
		if (m_height > 0)
		{
			m_angle = (float)pi / 2;
		}
		else if (m_height == 0)
		{
			m_angle = 0;
		}
		else {
			m_angle = -(float)pi / 2;
		}
	}
	else {
		m_angle = (float)atan(m_height / m_width);
	}
}

//Reset to a null vector
template <typename T>
void Vector2D<T>::reset()
{
	m_width = (float)0;
	m_height = (float)0;
	m_length = (float)0;
	m_angle = (float)0;
}

//Set the coordinates of the vector to (m_width + addedWidth, m_height + addedHeight)
template <typename T>
void Vector2D<T>::add(T addedWidth, T addedHeight)
{
	m_width += addedWidth;
	m_height += addedHeight;
	m_length = (float)sqrt(pow(m_width, 2.0) + pow(m_height, 2.0));
	double pi = 3.1415926535897;
	if (m_width == 0.0)
	{
		if (m_height > 0)
		{
			m_angle = (float)pi / 2;
		}
		else if (m_height == 0)
		{
			m_angle = 0;
		}
		else {
			m_angle = -(float)pi / 2;
		}
	}
	else {
		m_angle = (float)atan(m_height / m_width);
	}
}

//Fonction du produit scalaire
template <typename T>
float Vector2D<T>::scalaire(Vector2D<T> &vector)
{
	return (m_width * vector.m_width) + (m_height * vector.m_height);
}