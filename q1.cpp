#include <vector>
#include <algorithm>
#include <iostream>
namespace cppfaq
{
        // Start
        // [B_____P_____E]
        // After push_back
        // [B_____P_____EF_____L]
        // Desired
        // [B_____F_____L_______E]

    template<class T, class Allocator = std::allocator<T> , class InputIt, class const_iterator = std::vector<T, Allocator>::const_iterator>
        decltype(auto) insert(std::vector<T, Allocator>& vec, const_iterator pos, InputIt first, InputIt last)
         {
             if(first == last)
             {
                 return pos;
             }
             auto endBeforePushBack = vec.cend() - vec.cbegin();
             auto posBeforePushBack = pos - vec.cbegin();
             vec.insert(vec.cend(), first, last);
             std::rotate(vec.begin() + posBeforePushBack, vec.begin() + endBeforePushBack, vec.end());
             return vec.cbegin() + posBeforePushBack;
         }
}

int main()
{
    std::vector<int> v1 = { 1,2,3,4,5,6,7,8,9 };
    std::vector<int> v2 = { 11,12,13,14 };

    cppfaq::insert(v1, v1.cbegin() + 4, v2.cbegin(), v2.cend());

    for(const auto& element : v1)
    {
        std::cout << element << ", ";
    }
    std::cout << std::endl;
    return 0;
}