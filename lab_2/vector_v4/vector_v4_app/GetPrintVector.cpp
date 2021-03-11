#include "./GetPrintVector.h"
#include <iomanip>
#include <sstream>

std::optional<std::vector<double>> GetVectorFromStream(std::istream& inputStream)
{
	std::vector<double> numVector;
	
	copy(std::istream_iterator<double>(inputStream), (std::istream_iterator<double>()), std::back_inserter(numVector));
	
	if (numVector.size() == 0)
	{
		std::cout << "Vector record error\n";
		return std::nullopt;
	}

	inputStream.clear();
	return numVector;
}

void PrintVector(const std::vector<double>& numVector)
{	
	for (const auto& i : numVector)
	{
		std::cout << std::fixed << std::setprecision(3) << i << " ";
	}
}
