#include <iostream>

namespace foo
{
	int dosomething(int x, int y)
	{
		return x + y;
	}
}

namespace goo
{
	int dosomething(int x, int y)
	{
		return x - y;
	}
}

int main()
{
	std::cout << foo::dosomething(4,3) << '\n';
	return 0;
}