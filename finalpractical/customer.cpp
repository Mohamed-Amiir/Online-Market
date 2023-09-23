#include "customer.h"


customer ::customer()
{
    id = 0;
    name = "";
    address = "";
    phoneno = "";
    email = "";
}
customer::customer(string n, string a, string p, string e)
{
    id = rand();
    name = n;
    address = a;
    phoneno = p;
    email = e;
}
bool customer::check_email(string em)
{
    if (em == email)
    {
        return true;
    }
    return false;
}

bool customer::add_cart_item(int product_id, int product_quantity, float product_price)
{
    cart_item c(product_id, product_quantity, product_price);
    mycart.push_back(c);
    return true;
}
int customer::get_number_of_items_in_cart()
{
    return mycart.size();
}

vector<cart_item> customer::get_cart_items()
{
    return mycart;
}
int customer::get_id()
{
    return id;
}