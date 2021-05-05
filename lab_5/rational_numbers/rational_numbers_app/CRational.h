#pragma once

#include <iostream>
#include <sstream>
#include <iomanip>
#include <math.h>
#include <numeric>

class CRational
{
public:

	CRational();
	CRational(int value);
	CRational(int numerator, int denominator);
	int GetNumerator() const;
	int GetDenominator() const;
	double ToDouble() const;
	
	CRational const operator-() const;
	CRational const operator+() const;

	CRational& operator+=(const CRational& rightOperand);
	CRational& operator-=(const CRational& rightOperand);
	CRational& operator*=(const CRational& rightOperand);
	CRational& operator/=(const CRational& rightOperand);

private:
	int m_numerator;
	int m_denominator;
	bool Normalize();
};

CRational const operator+(const CRational& leftOperand, const CRational& rightOperand);
CRational const operator-(const CRational& leftOperand, const CRational& rightOperand);

CRational const operator*(const CRational& leftOperand, const CRational& rightOperand);
CRational const operator/(const CRational& leftOperand, const CRational& rightOperand);
