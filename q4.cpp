#include <iterator>
#include <algorithm>
#include <iostream>
namespace cppfaq
{
	template<class Iter>
	void swap_unequeal_ranges(Iter begin1, Iter end1, Iter begin2, Iter end2)
	{
		auto distance1 = std::distance(begin1, end1);
		auto distance2 = std::distance(begin2, end2);

		if (distance1 == distance2)
		{
			std::swap_ranges(begin1, end1, begin2);
		}
		else if (distance1 > distance2)
		{
			auto difference = distance1 - distance2;
			std::swap_ranges(begin2, end2, begin1);
			swap_unequeal_ranges(end2, end1, begin1 + difference, begin1 + distance1);
		}
		else
		{
			auto difference = distance2 - distance1;
			std::swap_ranges(begin1, end1, begin2);
			swap_unequeal_ranges(end1, end2, begin2 + difference, begin2 + distance2);
		}
	}
}

int main()
{
	int b[] = {1,2,3,4,5,6,7,8,9,10};

	cppfaq::swap_unequeal_ranges(b + 2,b + 4, b + 4, b + 8);

	for (const auto& el : b)
	{
		std::cout << el << ",";
	}
	std::cout << std::endl;
}