#ifdef UNIT_TEST
#include "CharIndicator.h"
#include <iostream>

using namespace utl;

int main(int argc, char* argv[])
{
	for(unsigned int j = 0; j < 3; j++)
	{
		const unsigned int real_limit = 100000;
		auto ci = CharIndicator(real_limit, 20);

		for(unsigned int i = 0; i < real_limit; i++)
		{
			ci.CountAndIndicate();
		}

	}
	return 0;
}

#endif
