#include <iostream>
#include "GetPrintVector.h"
#include "TransformVector.h"


int main()
{
    auto numsVector = GetVectorFromStream(std::cin);
    if (!numsVector)
    {
        std::cout << "Invalid input\n";
        return 1;
    }

    if (!TransformVector(*numsVector))
	{
	    return	1;
	}

	if (!SortVector(*numsVector))
	{
	    return	1;
	}

    if (!PrintVector(*numsVector))
	{
		return 1;
	}
    
    return 0;
}

