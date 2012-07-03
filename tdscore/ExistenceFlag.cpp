#ifdef UNIT_TEST
#include "ExistenceFlag.h"
#include <iostream>

using namespace tdscore;
int main(int argc, char* argv[])
{
	const auto ef = EXIST;
	std::cout << ef << std::endl;

    return 0;
}

#endif
