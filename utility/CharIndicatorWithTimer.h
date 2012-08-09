#pragma once
//CharIndicatorWithTimer:20120718
#include <iostream>
#include <string>
#include "Timer.h"
#include "CharIndicator.h"
namespace utl
{
class CharIndicatorWithTimer
{
public:
	CharIndicatorWithTimer(const std::string& message, unsigned int real_limit, unsigned int indicate_limit=20)
		:timer(), 
		indicator(real_limit, indicate_limit),
		real_limit(real_limit)
		{
			std::cout << message << "\n";	
		}
	
	auto CountAndIndicate() 
	-> unsigned int
	{
		const auto count = this->indicator.CountAndIndicate();	
		if(count == this->real_limit)
		{
			this->timer("spend time");
			std::cout << "\n";
		}

		return count;
	}

private:
	Timer timer;
	CharIndicator indicator;
	unsigned int real_limit;

};
}

