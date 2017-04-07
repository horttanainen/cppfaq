#include <iostream>
#include <algorithm>

int main()
{
    int b[] = {1,2,3,4,5,6,7,8,9};

    std::swap_ranges(b+2, b + 5, b + 6);

        for ( const auto& el : b)
        {
            std::cout << el << ", ";
        }
        std::cout << std::endl;
}