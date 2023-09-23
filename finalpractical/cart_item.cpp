#include "cart_item.h"

cart_item::cart_item()
{
    product_id = 0;
    quantity = 0;
    total_price = 0;
}

cart_item::cart_item(int pid, int q, float p)
{
    product_id = pid;
    quantity = q;
    total_price = p;
}
int cart_item::get_product_id()
{
    return product_id;
}
int cart_item::get_quantity()
{
    return quantity;
}
float cart_item::get_total_price()
{
    return total_price;
}