#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <thread>
#include <numeric>
#include "Marker.cpp"


int main()
{
    std::cout << "Input array size: ";

    int size;
    std::cin >> size;
    std::vector<int> vec(size, 0);

    std::cout << "Input markers count: ";

    int count = 0;
    std::cin >> count;

    std::vector<std::thread> threads(count);

    for (int i = 0; i < count; i++)
    {
        threads[i] = std::thread(marker, std::ref(vec), std::ref(i));
    }
    
}