#include <bitset>
#include <iostream>

int main() 
{
	std::bitset<8> bin1 {0b11000101};
	std::bitset<8> bin2 { 0xc5 };
	
	std::cout << bin1 << ' ' << bin2 << '\n';
	std::cout << std::bitset<4> { 0b1010 } << '\n';
	
	return 0;
}