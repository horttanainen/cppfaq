#include <iterator>
#include <algorithm>
#include <iostream>
namespace cppfaq
{
	template<class Iter>
	void shiftImpl(Iter begin, Iter end, Iter pos, std::random_access_iterator_tag)
	{
        if ( pos > begin)
        {
            std::rotate(begin, end, pos);
        }
        else
        {
            std::rotate(pos, begin, end);
        }

	}

    template<class RandomIter>
    void shift(RandomIter first, RandomIter last, RandomIter pos)
    {
        using category = std::iterator_traits<RandomIter>::iterator_category;
        shiftImpl(first, last, pos, category());
    }
}

int main()
{
	int b[] = {1,2,3,4,5,6,7,8,9,10};

	for (const auto& el : b)
	{
		std::cout << el << ",";
	}
    std::cout << std::endl;

    cppfaq::shift(b + 2, b + 4, b + 6);

    for(const auto& el : b)
    {
        std::cout << el << ",";
    }
    std::cout << std::endl;

    cppfaq::shift(b + 4, b + 6, b + 2);

    for(const auto& el : b)
    {
        std::cout << el << ",";
    }
	std::cout << std::endl;
}