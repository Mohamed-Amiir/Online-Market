#include "product.h"
using namespace std;

product::product( string n, float p, string c, int q, int s)
   {
    id = rand();
    name = n;
    seller_id = s;
    quantity = q;
    price = p;
    category = c; 
    overall_rating = 0;

   }
product::product()
{
    id = 0;
    name = "";
    seller_id = 0;
    quantity = 0;
    price = 0;
    category = "";
    overall_rating = 0;
}

string product::get_name()
{
    return name;
}
int product::get_id()
{
    return id;
}
string product::get_category()
{
    return category;
}
float  product::get_price()
{
    return price;
}
int product::get_quantity()
{
    return quantity;
}
void product::set_quantity(int q)
{
    quantity = q;
}

int product::get_seller_id()
{
    return seller_id ; 
}
void product::set_rating(int rating, int customer_id)
{
    rating_map[customer_id] = rating;

}
void product::calculate_total_rating()
{
    int counter = 0;
    overall_rating = 0;
    for (auto it = rating_map.begin(); it != rating_map.end(); ++it)
    {
        overall_rating += it->second;
        counter++;
    }
    overall_rating = (overall_rating / counter);

}
float product::get_overall_rating()
{ 
    calculate_total_rating();
    return overall_rating;
}
