#include "seller.h"

seller::seller(string n, string em)
{
	id = rand();
	name = n;
	email = em;
}
seller::seller()
{
	id = 0;
	name = " ";
	email = " ";
}
bool seller:: check_email(string em)
{
	if (email == em)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int seller::get_id()
{
	return id;
}
