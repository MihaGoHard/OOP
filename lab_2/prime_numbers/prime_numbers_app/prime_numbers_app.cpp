#include "parse_print.h"
#include "get_primes_set.h"

using namespace std;

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);

	if (!args)
	{
		return 1;
	}

	const int upperBound = args->inputNum + 1;

	set<int> numsSet = GeneratePrimeNumbersSet(upperBound);

	PrintSet(numsSet);
	
	return 0;
}
