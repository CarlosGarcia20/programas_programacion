#include <iostream>
#include <iterator> // std :: size

int main()
{
	constexpr int scores[]{ 84, 92, 76, 81, 56 };
	constexpr int numStudents{ static_cast<int>(std::size(scores)) };

	int maxScore{ 0 };
	for (int students{ 0 }; student < numStudents; ++student)
	{
		if (scores[student] > maxScore)
		{
			maxScore = scores[student]
		}
	}

	std::cout << "La mejor calificacion fue: " << maxScore << '\n';

	return 0;
}