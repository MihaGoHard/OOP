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

CRational const operator+(const CRational& leftOperand, const CRational& rightOperand)
{
	int leftNumerator = leftOperand.GetNumerator();
	int leftDenominator = leftOperand.GetDenominator();
	int rightNumerator = rightOperand.GetNumerator();
	int rightDenominator = rightOperand.GetDenominator();

	const int LCM = lcm(leftDenominator, rightDenominator);
	int numerator = (leftNumerator * LCM / leftDenominator) + (rightNumerator * LCM / rightDenominator);
	return CRational(numerator, LCM);
}

CRational const operator-(const CRational& leftOperand, const CRational& rightOperand)
{
	int leftNumerator = leftOperand.GetNumerator();
	int leftDenominator = leftOperand.GetDenominator();
	int rightNumerator = rightOperand.GetNumerator();
	int rightDenominator = rightOperand.GetDenominator();

	const int LCM = lcm(leftDenominator, rightDenominator);
	int numerator = (leftNumerator * LCM / leftDenominator) - (rightNumerator * LCM / rightDenominator);
	return CRational(numerator, LCM);
}

CRational const operator*(const CRational& leftOperand, const CRational& rightOperand)
{
	int leftNumerator = leftOperand.GetNumerator();
	int leftDenominator = leftOperand.GetDenominator();
	int rightNumerator = rightOperand.GetNumerator();
	int rightDenominator = rightOperand.GetDenominator();

	return CRational(leftNumerator * rightNumerator, leftDenominator * rightDenominator);
}

CRational const operator/(const CRational& leftOperand, const CRational& rightOperand)
{
	int leftNumerator = leftOperand.GetNumerator();
	int leftDenominator = leftOperand.GetDenominator();
	int rightNumerator = rightOperand.GetNumerator();
	int rightDenominator = rightOperand.GetDenominator();
	return CRational(leftNumerator * rightDenominator, leftDenominator * rightNumerator);
}

CRational& CRational::operator+=(const CRational& rightOperand)
{
	*this = *this + rightOperand;
	return *this;
}

CRational& CRational::operator-=(const CRational& rightOperand)
{
	*this = *this - rightOperand;
	return *this;
}

CRational& CRational::operator*=(const CRational& rightOperand)
{
	*this = *this * rightOperand;
	Normalize();
	return *this;
}

CRational& CRational::operator/=(const CRational& rightOperand)
{
	*this = *this / rightOperand;
	Normalize();
	return *this;
}

bool const operator==(const CRational& leftOperand, const CRational& rightOperand)
{
	int leftNumerator = leftOperand.GetNumerator();
	int leftDenominator = leftOperand.GetDenominator();
	int rightNumerator = rightOperand.GetNumerator();
	int rightDenominator = rightOperand.GetDenominator();
	
	return leftNumerator == rightNumerator && leftDenominator == rightDenominator;
}

bool const operator!=(const CRational& leftOperand, const CRational& rightOperand)
{
	return !(leftOperand == rightOperand);
}

bool const operator<(const CRational& leftOperand, const CRational& rightOperand)
{
	int leftNumerator = leftOperand.GetNumerator();
	int leftDenominator = leftOperand.GetDenominator();
	int rightNumerator = rightOperand.GetNumerator();
	int rightDenominator = rightOperand.GetDenominator();
	return leftNumerator * rightDenominator < rightNumerator * leftDenominator;
}

bool const operator>(const CRational& leftOperand, const CRational& rightOperand)
{
	int leftNumerator = leftOperand.GetNumerator();
	int leftDenominator = leftOperand.GetDenominator();
	int rightNumerator = rightOperand.GetNumerator();
	int rightDenominator = rightOperand.GetDenominator();
	return leftNumerator * rightDenominator > rightNumerator * leftDenominator;
}


bool const operator<=(const CRational& leftOperand, const CRational& rightOperand)
{
	return leftOperand == rightOperand || leftOperand < rightOperand;
}

bool const operator>=(const CRational& leftOperand, const CRational& rightOperand)
{
	return leftOperand == rightOperand || leftOperand > rightOperand;
}


ostream& operator<<(ostream& outStrm, const CRational& rightOperand)
{
	outStrm << rightOperand.GetNumerator() << "/" << rightOperand.GetDenominator();
	return outStrm;
}

istream& operator>>(istream& inStrm, CRational& rightOperand)
{
	string inString;
	int strmPos = inStrm.tellg();
	getline(inStrm, inString);
	regex regular("-?(\\d+)/(\\d+)");
	inStrm.seekg(strmPos);
	if (regex_match(inString.c_str(), regular))
	{
		int numerator;
		int denominator;
		inStrm >> numerator;
		inStrm.get();
		inStrm >> denominator; 
		rightOperand = CRational(numerator, denominator);
	}
	return inStrm;
}























