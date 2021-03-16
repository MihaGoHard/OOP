#pragma once
#include <set>
#include <vector>

using namespace std;

set<int> GeneratePrimeNumbersSet(const int& upperBound);
void FillSetFromSiev(const vector<bool>& sieve, set<int>& numsSet);
void FillSieve(vector<bool>& sieve);
