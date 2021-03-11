#include "GetPrintVector.h"
#include "TransformVector.h"
#include <iostream>

int main()
{
	auto numsVector = GetVectorFromStream(std::cin);
	if (!numsVector)
	{
		std::cout << "Invalid input\n";
		return 1;
	}

	TransformVector(*numsVector);

	SortVector(*numsVector);

	PrintVector(*numsVector);

	return 0;
}
