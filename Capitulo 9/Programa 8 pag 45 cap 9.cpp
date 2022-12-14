#include <iostream>
#include <iterator>

int main()
{
	constexpr int scores[]{ 84, 92, 76, 81, 56 };
	constexpr int numStudents{ static_cast<int>(std::size(scores)) };

	int maxIndex{ 0 };
	for (int student{ 0 }; student <= numStudents; ++student)
	{
		if (scores[student] > maxIndex)
		{
			maxIndex = scores[student];
		}
	}

	std::cout << "El mejor promedio es: " << maxIndex << '\n';

	return 0;
}