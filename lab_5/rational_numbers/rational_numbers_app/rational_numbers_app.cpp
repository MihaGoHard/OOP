#include <iostream>
#include <cmath>
#include "CRational.h"

using namespace std;

int main()
{
	CRational rational(8, 18);
    cout << rational.GetNumerator() << " " << rational.GetDenominator() << "\n";
	cout << abs(4.21) << "\n";
}
