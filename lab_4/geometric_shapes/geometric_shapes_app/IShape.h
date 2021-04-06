#pragma once
#include <string>
using namespace std;

struct SPoint 
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

	virtual uint32_t GetOutlineColor() const = 0;

	virtual ~IShape(){}

private:
};
