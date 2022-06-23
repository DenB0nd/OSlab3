#include <stdlib.h>
#include <vector>
#include <thread>
#include <iostream>

const int MARKER_MS_TO_SLEEP = 5;

void marker(std::vector<int>& vec, int &number)
{
	std::cout << number << std::endl;
	srand(number * time(0));
	int marked = 0;
	int counter = 0;
	while (true)
	{
		int index = rand() % vec.size();

		if (vec[index] == 0)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(MARKER_MS_TO_SLEEP));
			vec[index] = index;
			std::this_thread::sleep_for(std::chrono::milliseconds(MARKER_MS_TO_SLEEP));
			marked++;
		}
		else
		{
			std::cout << "Index: " << index << std::endl;
			std::cout << "Marked: " << marked << std::endl;
			std::cout << "Number: " << counter << std::endl;
			break;
		}

		counter++;
	}
}