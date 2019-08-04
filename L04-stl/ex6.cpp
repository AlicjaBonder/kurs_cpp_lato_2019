#include <iostream>
#include <forward_list>

int main()
{

    std::forward_list<int> fl = {7, 6, 5, 4, 3, 2, 1};

    auto it_b = begin(fl);
    auto it_e = end(fl);

    auto dist = distance(it_b, it_e);

    std::cout << dist << std::endl;

    auto it5 = begin(fl);
    advance(it5, 4);
    std::cout << *it5 << std::endl;

    std::cout << distance(it_b, it5) << std::endl;
}
