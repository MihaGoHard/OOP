#include "CRational.h"
using namespace std;

CRational::CRational()
	: m_numerator(0)
	, m_denominator(1)
{
}

CRational::CRational(int value)
	: m_numerator(value)
	, m_denominator(1)
{
}

CRational::CRational(int numerator, int denominator)
	: m_numerator(numerator)
	, m_denominator(denominator)
{
	if (denominator == 0)
	{
		m_numerator = 0;
		m_denominator = 1;
	}

	if (denominator < 0)
	{
		m_numerator = -numerator;
		m_denominator = -denominator;
	}

	Normalize();
}

int CRational::GetNumerator() const
{
	return m_numerator;
}

int CRational::GetDenominator() const
{
	return m_denominator;
}

bool CRational::Normalize()
{
	const int GCD = gcd(abs(m_numerator), m_denominator);
	m_numerator /= GCD;
	m_denominator /= GCD;
	return true;
}

double CRational::ToDouble() const
{
	return static_cast<double>(m_numerator) / m_denominator;
}

CRational const CRational::operator-() const
{
	return CRational(-m_numerator, m_denominator);
}

CRational const CRational::operator+() const
{
	return *this;
}

CRational const operator+(CRational& leftOperand, CRational& rightOperand)
{
	int leftNumerator = leftOperand.GetNumerator();
	int leftDenominator = leftOperand.GetDenominator();
	int rightNumerator = rightOperand.GetNumerator();
	int rightDenominator = rightOperand.GetDenominator();

	const int LCM = lcm(leftDenominator, rightDenominator);
	int numerator = (leftNumerator * LCM / leftDenominator) + (rightNumerator * LCM / rightDenominator);
	return CRational(numerator, LCM);
}

CRational const operator-(CRational& leftOperand, CRational& rightOperand)
{
	int leftNumerator = leftOperand.GetNumerator();
	int leftDenominator = leftOperand.GetDenominator();
	int rightNumerator = rightOperand.GetNumerator();
	int rightDenominator = rightOperand.GetDenominator();

	const int LCM = lcm(leftDenominator, rightDenominator);
	int numerator = (leftNumerator * LCM / leftDenominator) - (rightNumerator * LCM / rightDenominator);
	return CRational(numerator, LCM);
}

CRational const operator*(CRational& leftOperand, CRational& rightOperand)
{
	int leftNumerator = leftOperand.GetNumerator();
	int leftDenominator = leftOperand.GetDenominator();
	int rightNumerator = rightOperand.GetNumerator();
	int rightDenominator = rightOperand.GetDenominator();

	return CRational(leftNumerator * rightNumerator, leftDenominator * rightDenominator);
}

CRational const operator/(CRational& leftOperand, CRational& rightOperand)
{
	int leftNumerator = leftOperand.GetNumerator();
	int leftDenominator = leftOperand.GetDenominator();
	int rightNumerator = rightOperand.GetNumerator();
	int rightDenominator = rightOperand.GetDenominator();
	return CRational(leftNumerator * rightDenominator, leftDenominator * rightNumerator);
}



























