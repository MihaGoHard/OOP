#pragma once
#include <string>
#include <cmath>
using namespace std;

class CPoint 
{
public:
	double x;
	double y;
};

class IShape
{
public:
	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
	virtual string ToString() const = 0;

	virtual ~IShape(){};
};
