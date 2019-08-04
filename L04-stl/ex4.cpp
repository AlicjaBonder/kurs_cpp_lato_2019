#include <list>
#include <iostream>
#include <vector>
#include <numeric>
#include <iterator>
#include <chrono>

int main()
{
    std::list<int> l(1000000);
    auto t1 = std::chrono::high_resolution_clock::now();
    std::iota(l.begin(), l.end(), 0);

    auto t2 = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

    std::cout << " Czas(lista) : " << duration << std::endl;
    auto t3 = std::chrono::high_resolution_clock::now();
    auto it = l.begin();

    advance(it, 499'999);
    std::cout << *it << std::endl;
    auto t4 = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count();
    std::cout << " Czas(element listy) : " << duration2 << std::endl;

    auto t5 = std::chrono::high_resolution_clock::now();
    std::vector<int> v(1000000);
    std::iota(v.begin(), v.end(), 0);

    std::cout << v[500000]<< std::endl;
    auto t6 = std::chrono::high_resolution_clock::now();
    auto duration3 = std::chrono::duration_cast<std::chrono::microseconds>(t6 - t5).count();
    std::cout << " Czas(vector) : " << duration3 << std::endl;
}