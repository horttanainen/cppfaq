#include <iterator>
#include <iostream>
#include <forward_list>
#include <algorithm>

namespace cppfaq
{
	// I learned that I do not know much about iterators and especially how restricted forwardIterators truly are. 
	// This was my first attempt:
	//
	//template<class ForwardIterator>
	//void reverseImpl(ForwardIterator first, ForwardIterator last, std::forward_iterator_tag)
	//{
	//	using T = std::iterator_traits<ForwardIterator>::value_type;
	//	auto length = last - first;
	//	T storedValues[length];
	//	for (auto i = 0; i < length; ++i)
	//	{
	//		storedValues[i] = *(first + i);
	//	}
	//	for (auto i = length - 1; first != last; --i)
	//	{
	//		*(first++) = storedValues[i];
	//	}
	//}
    //

	template<class ForwardIterator>
    void reverseImpl(ForwardIterator first, ForwardIterator last, std::forward_iterator_tag)
	{
        auto distance = std::distance(first, last);
        if (distance < 2)
        {
            return;
        }
		auto middle = first;
		std::advance(middle, distance / 2);
        cppfaq::reverse(first, middle);
        cppfaq::reverse(middle, last);
        std::rotate(first, middle, last);
	}

	template<class ForwardIterator>
    void reverse(ForwardIterator first, ForwardIterator last)
	{
		using category = std::iterator_traits<ForwardIterator>::iterator_category;
		reverseImpl(first, last, category());
	}
}

int main()
{
	std::forward_list<int> l = {1,2,3,4,5,6,7,8,9};

	for (const auto& el : l)
	{
		std::cout << el << ", ";
	}
	std::cout << std::endl;

	cppfaq::reverse(l.begin(), l.end());

	for (const auto& el : l)
	{
		std::cout << el << ", ";
	}
	std::cout << std::endl;
}