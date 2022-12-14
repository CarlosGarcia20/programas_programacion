#include <iostream>
#include <iterator>

int main()
{
	constexpr int scores[]{ 84, 92, 76, 81, 56 };
	constexpr int numStudents{ static_cast<int>(std::size(scores)) };

	int maxScore{ 0 };
	for (int student{ 0 }; student <= numStudents; ++student)
	{
		if (scores[student] > maxScore)
		{
			maxScore = scores[student];
		}
	}

	std::cout << "El mejor promedio es: " << maxScore << '\n';

	return 0;
}