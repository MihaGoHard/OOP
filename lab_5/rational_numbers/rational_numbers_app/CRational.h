#pragma once

class CRational
{
public:

	CRational();
	CRational(int value);
	CRational(int numerator, int denominator);

	int GetNumerator() const;

	int GetDenominator() const;

	double ToDouble() const;
	

private:
	int m_numerator;
	int m_denomenator;
	//bool Normalize();
};

