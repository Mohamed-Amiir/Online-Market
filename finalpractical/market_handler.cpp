#include "market_handler.h"
market_handler::market_handler()
{

}
void market_handler:: initialize_market() {
    product p1 = product("Table", 300, "furniture", 3, 2020);
    product p2 = product("Chair", 150, "furniture", 4, 2020);
    product p3 = product("Kanaba", 500, "furniture", 2, 2020);
    product p4 = product("Sofa", 5000, "furniture", 1, 2020);
    product p5 = product("Bed", 800, "furniture", 6, 2020);
    product p6 = product("Realme6i", 3000, "electronices", 10, 2020);
    product p7 = product("Redmi10", 3500, "electronices", 10, 2020);
    product p8 = product("Samsunga30", 3000, "electronices", 10, 2020);
    product p9 = product("Opporeno2", 6000, "electronices", 10, 2020);
    product p10 = product("Huawi8c", 3000, "electronices", 10, 2020);
    product p11 = product("Dress", 2000, "clothes", 4, 2020);
    product p12 = product("Shose", 500, "clothes", 5, 2020);
    product p13 = product("T-shirt", 80, "clothes", 90, 2020);
    product p14 = product( "Pants", 150, "clothes", 10, 2020);
    product p15 = product(  "Shirt", 600, "clothes", 7, 2020);
    product p16 = product(  "Cheese", 25, "food", 1, 2020);
    product p17 = product(  "Meet", 150, "food", 4, 2020);
    product p18 = product(  "Sugar", 22, "food", 6, 2020);
    product p19 = product(  "Milk", 20, "food", 2, 2020);
    product p20 = product(  "BMW", 600000, "cars", 5, 2020);
    product p21 = product(  "Mercedes Benz", 700000, "cars", 5, 2020);
    product p22 = product(  "Lancer", 200000, "cars", 4, 2020);
    product p23 = product(  "KIA", 500000, "cars", 3, 2020);
    product p24 = product( "Audi", 800000, "cars", 2, 2020);
    product p25 = product( "Car", 50, "toyes", 2, 2020);
    product p26 = product( "Super man", 60, "toyes", 2, 2020);
    product p27 = product( "Ball", 40, "toyes", 2, 2020);
    product p28 = product( "Barbi", 55, "toyes", 2, 2020);
    product p29 = product( "Bokimone", 100, "toyes", 0, 2020);
    pro.push_back(p1);
    pro.push_back(p2);
    pro.push_back(p3);
    pro.push_back(p4);
    pro.push_back(p5);
    pro.push_back(p6);
    pro.push_back(p7);
    pro.push_back(p8);
    pro.push_back(p9);
    pro.push_back(p10);
    pro.push_back(p11);
    pro.push_back(p12);
    pro.push_back(p13);
    pro.push_back(p14);
    pro.push_back(p15);
    pro.push_back(p16);
    pro.push_back(p17);
    pro.push_back(p18);
    pro.push_back(p19);
    pro.push_back(p20);
    pro.push_back(p21);
    pro.push_back(p22);
    pro.push_back(p23);
    pro.push_back(p24);
    pro.push_back(p25);
    pro.push_back(p26);
    pro.push_back(p27);
    pro.push_back(p28);
    pro.push_back(p29);
    //pro = sort_product(pro);

}


vector<product> market_handler:: get_market_products()
{
    return pro;
}

int market_handler:: login_cust(string email)
{
    bool found_flag = false;

    for (int i = 0; i < customrs.size(); i++)
    {
        if (customrs[i].check_email(email))
        {
            found_flag = true;
            return i;
        }

    }
    if (found_flag == false)
    {
        return -1;
    }
}

customer market_handler::get_customer(int cust_index)
{
    return customrs[cust_index];
}

customer market_handler::add_customer(string name, string email, string address, string phone)
{
    customer c(name, address, phone, email);
    customrs.push_back(c);
    return c;
}


void market_handler::display_products()
{
    for (int i = 0; i < pro.size(); i++)
    {
        cout << "Product " << pro[i].get_id() << "\t" << pro[i].get_name() << "\t" << pro[i].get_price() << "\t" << pro[i].get_category() << endl;
    }

}


int market_handler:: find_product(int product_id)
{ 
    int index = -1;
    for (int i = 0; i < pro.size(); i++)
    {
        if (pro[i].get_id() == product_id)
        {
            return i;
        }
    }
    return index;
}

bool market_handler::add_product_to_customer_cart(int product_id, int product_quantity, int current_cust_index)
{
    int target_product_index = find_product(product_id);
    if (pro[target_product_index].get_quantity() >= product_quantity)
    {
        pro[target_product_index].set_quantity(pro[target_product_index].get_quantity() - product_quantity);
        customrs[current_cust_index].add_cart_item(product_id, product_quantity, pro[target_product_index].get_price() * product_quantity);
        return true;
    }
    return false;

}
void market_handler::display_cart_info(int i)
{
    float total_price = 0;
    for (int j = 0; j < customrs[i].get_number_of_items_in_cart(); j++)
        
    {
        

        int index = find_product(customrs[i].get_cart_items()[j].get_product_id());
        cout << pro[index].get_name() << " \t " << customrs[i].get_cart_items()[j].get_quantity() << "\t " << customrs[i].get_cart_items()[j].get_total_price() << endl;
        total_price += customrs[i].get_cart_items()[j].get_total_price();
        
        
    }
    if (total_price == 0)
    {
        cout << "this cart is empty " << endl;
    }
    else
    {
        cout << "total price is \t  " << total_price << endl;
    }
}

void market_handler::display_product_by_name(string name)
{
    bool found_flag = false;
    for (int i = 0; i < pro.size(); i++)
    {
        if (pro[i].get_name() == name)
        {
            found_flag = true;
            cout << pro[i].get_id() << "\t" << pro[i].get_name() << " \t" << pro[i].get_price() << "\t" << pro[i].get_quantity() << " \t " << pro[i].get_category() << "\t" << endl;
        }
    }
    if (found_flag == false)
    {
        cout << " No products are found with this name " << endl;
    }
}

void market_handler::display_product_by_category(string category)
{ 
    bool found_flag = false;
    for (int i = 0; i < pro.size(); i++)
    {
        if (pro[i].get_category() == category)
        {
            found_flag = true;
            cout << pro[i].get_id() << "\t" << pro[i].get_name() << " \t" << pro[i].get_price() << "\t" << pro[i].get_quantity() << " \t " << pro[i].get_category() << "\t" << endl;
        }
        
    }
    if (found_flag == false)
    {
        cout << "No products are found for this category " << endl;
    }
}

seller market_handler::add_seller(string name, string email)
{
    seller s(name, email); 
    sellers.push_back(s);
    return s;
}


int market_handler::login_seller(string email)
{
    bool found_flag = false;

    for (int i = 0; i < sellers.size(); i++)
    {
        if (sellers[i].check_email(email))
        {
            found_flag = true;
            return i;
        }

    }
    if (found_flag == false)
    {
        return -1;
    }
}

seller market_handler::get_seller(int seller_index)
{
    return sellers[seller_index];
}

void market_handler::add_product(string name, float price, string category, int quantity, int seller_id)
{
    product p(name, price, category, quantity, seller_id);
    pro.push_back(p);
    
}
void market_handler::display_products_of_seller(int id)
{
    bool found_flag = false;
    for (int i = 0; i < pro.size(); i++)
    {
        if (pro[i].get_seller_id() == id)
        {
            found_flag = true;
            cout << pro[i].get_id() << "\t" << pro[i].get_name() << " \t" << pro[i].get_price() << "\t" << pro[i].get_quantity() << " \t " << pro[i].get_category() << "\t" << endl;
        }
    }
    if (found_flag == false)
    {
        cout << "You don't have any products " << endl;
    }
}
bool market_handler::validate_product_rating(int prod_id, int rating)
{
    if (rating < 1 || rating >5)
    {
        return false;
    }
    if (find_product(prod_id) == -1)
    {
        return false;
    }
    return true;
        
}
void market_handler::add_rating_to_product(int prod_id, int rating, int customer_id)
{
    int product_index = find_product(prod_id);
    pro[product_index].set_rating(rating, customer_id);

}

float market_handler::get_product_rating(int product_id)
{
    int product_index = find_product(product_id);
  return  pro[product_index].get_overall_rating();

}
