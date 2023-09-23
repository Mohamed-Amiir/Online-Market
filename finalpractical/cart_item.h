#pragma once
class cart_item
{
    
    private:
        int product_id;
        int quantity;
        float total_price;
    public:
        cart_item();
        cart_item(int pid, int q, float p);

        int get_product_id();
        int get_quantity();
        float get_total_price();
};

