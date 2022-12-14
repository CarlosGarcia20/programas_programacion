#include <iostream>
#include <string>

enum itemtype
{
	itemtype_sword,
	itemtype_torch,
	itemtype_potion
};

std :: string getitemname(itemtype itemtype)
{
	if(itemtype == itemtype_sword)
		return "Sword";
	if(itemtype == itemtype_torch)
		return "Torch";
	if(itemtype == itemtype_potion)
		return "Potion";
		
		
	return "???";
}

int main()
{
	itemtype itemtype{ itemtype_torch };
	
	std :: cout << "You are carrying a " << getitemname(itemtype) << '\n';
	
	return 0;
}