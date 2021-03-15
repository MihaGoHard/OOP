#include "TransformVector.h"

void TransformVector(std::vector<double> &numVector)
{

	if (!numVector.empty())
	{
		double maxElem = *std::max_element(numVector.begin(), numVector.end());
		double devideIndex = maxElem / 2;

		std::for_each(numVector.begin(), numVector.end(), [&](double& vectorElem) { vectorElem /= devideIndex; });
	}
}

void SortVector(std::vector<double>& numVector)
{
	std::sort(numVector.begin(), numVector.end());
}