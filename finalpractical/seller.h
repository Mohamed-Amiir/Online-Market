#include <string>
using namespace std;
class seller
{
	int id;
	string name;
	string email;
public :
	seller(string name, string email);
	seller();
	bool check_email(string em);
	int get_id();
};

