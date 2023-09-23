#include "product.h"
#include "cart_item.h"
#include "customer.h"
#include <vector>
#include <iostream>
#include"seller.h"
using namespace std;
class market_handler
{

public:

    vector<product> pro;
    vector<customer> customrs;
    vector<seller> sellers;
    market_handler();
    void initialize_market();
    vector<product> get_market_products();
    int login_cust(string email);
    customer get_customer(int cust_index);
    customer add_customer(string name, string email, string address, string phone);
    void display_products();
    int find_product(int product_id);
    bool add_product_to_customer_cart(int product_id, int product_quantity, int current_cust_index);
    void display_cart_info(int i);
    void display_product_by_name(string name);
    void display_product_by_category(string category);
    seller add_seller(string name, string email);
    int login_seller(string email);
    seller get_seller(int seller_index);
    void add_product(string name, float price, string category, int quantity, int seller_id);
    void display_products_of_seller(int id);
    bool validate_product_rating(int prod_id, int rating);
    void add_rating_to_product(int prod_id, int rating, int customer_id);
    float get_product_rating(int product_id);
    

};

