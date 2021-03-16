#include "get_primes_set.h"
#include <iostream>
using namespace std;

void FillSieve(vector<bool>& sieve)
{
	const int offsetIndex = 1;
	const int upperBound = sieve.size() - offsetIndex;
	sieve[0] = false;
	if (sieve.size() > 1)
	{
		sieve[1] = sieve[0];
		for (int i = 2; i * i <= upperBound; ++i)
		{
			if (sieve[i])
			{
				for (int j = i * i; j <= upperBound; j += i)
				{
					sieve[j] = false;
				}
			}
		}
	}
}

void FillSetFromSiev(const vector<bool>& sieve, set<int>& numsSet)
{
	const int upperBound = sieve.size();
	for (int i = 1; i < upperBound; ++i)
	{
		if (sieve[i])
		{
			numsSet.insert(numsSet.end(), i);
		}
	}
}

set<int> GeneratePrimeNumbersSet(const int& upperBound)
{
	const int offsetIndex = 1;
	vector<bool> sieve(upperBound + offsetIndex, true);
	FillSieve(sieve);
	set<int> numsSet;
	FillSetFromSiev(sieve, numsSet);
	return numsSet;
}
