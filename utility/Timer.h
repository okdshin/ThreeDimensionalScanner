#pragma once
//Timer:20120707
#include <iostream>
#include <string>
#include <boost/format.hpp>
#include <boost/timer.hpp>


namespace utl
{
class Timer
{
public:
	Timer(){}

	void operator()(const std::string& text, std::ostream& os = std::cout)
	{
		os << boost::format("%1%:%2%sec\n") % text % t.elapsed();
	}

private:
	boost::timer t;
};
}

