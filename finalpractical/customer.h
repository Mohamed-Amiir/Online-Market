#include <vector>
#include <string>
#include "cart_item.h"

using namespace std;

class customer
{
private:
    int id;
    string name;
    string address;
    string phoneno;
    string email;
    vector<cart_item> mycart;
public:

    customer();
    customer(string n, string a, string p, string e);
    bool check_email(string em);
    bool add_cart_item(int product_id, int product_quantity, float product_price);
    int get_number_of_items_in_cart();
    vector<cart_item> get_cart_items();
    int get_id();

};


   

    