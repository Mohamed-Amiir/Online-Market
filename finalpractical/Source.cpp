#include <iostream>
using namespace std;

#include "market_handler.h"



int main() {
    int choice;
    market_handler market;
    market.initialize_market();
    customer current_cust;
    int current_cust_index;
    seller current_seller;
    int current_seller_index;

    while (true)
    {
        cout << "WECLOME TO OUR ONLINE MARKET" << endl;
        cout << "Press(1) Customer \t Press(2) Seller \t Press(3) Exit" << endl;

        cin >> choice;

       

        if (choice == 1)
        {
            cout << "WECLOME CUSTOMER TO OUR ONLINE MARKET" << endl;
            cout << "Press(1) login \t Press(2) register" << endl;
            cin >> choice;

            if (choice == 1)
            {
                string email = "";
                cout << "Please enter your email" << endl;
                cin >> email;
                current_cust_index = market.login_cust(email);
                if (current_cust_index != -1)
                {
                    current_cust = market.get_customer(current_cust_index);
                }
                else
                {
                    cout << "INVALID EMAIL PLEASE TRY AGAIN !!!" << endl;
                    continue;
                }
            }
            else if (choice == 2)
            {
                string email, name, phone, address;
                cout << "Please enter your name" << endl;
                cin >> name;
                cout << "Please enter your email" << endl;
                cin >> email;
                cout << "Please enter your phone" << endl;
                cin >> phone;
                cout << "Please enter your address" << endl;
                cin >> address;
                current_cust = market.add_customer(name, email, address, phone);
                current_cust_index = market.login_cust(email);

            }
            else
            {
                cout << "INVALID CHOICE, PLEASE TRY AGAIN !!! " << endl;
                continue;
            }
            while (true)
            {
                
                cout << "Press(1) to display all products     \nPress(2) to search by name  \nPress(3) to search by category  \nPress(4) to add product to your cart \nPress(5) to view your cart  \nPress(6) to rate products \nPress(7) to exit   " << endl;
                cin >> choice;
                if (choice == 1)
                {
                    market.display_products();
                }
                else if (choice == 2)
                {
                    string name;
                    cout << " please enter the name of product you are searching for " << endl;
                    cin >> name;
                    market.display_product_by_name(name);
                }
                else if (choice == 3)
                {
                    string category;
                    cout << " please enter the name of category you are searching for " << endl;
                    cin >> category;
                    market.display_product_by_category(category);
                }
                else if (choice == 4)
                {
                    int product_id, product_quantity;
                    cout << "Please enter product id" << endl;
                    cin >> product_id;
                    cout << "Please enter quantity" << endl;
                    cin >> product_quantity;
                    bool adding_result = market.add_product_to_customer_cart(product_id, product_quantity, current_cust_index);
                    if (adding_result)
                    {
                        cout << "Product is added successfully to your cart" << endl;
                        market.display_cart_info(current_cust_index);
                    }
                    else
                    {
                        cout << "Product can not be added to your cart, insufficeint quantity in store" << endl;
                    }
                }
                else if (choice == 5)
                {
                    market.display_cart_info(current_cust_index);
                }
                else if (choice == 6)
                {
                    int product_id, rate;
                    cout << "Please enter product id " << endl;
                    cin >> product_id;
                    cout << "Please enter you rate from 1 to 5" << endl;
                    cin >> rate;
                    if (market.validate_product_rating(product_id, rate))
                    {   
                        market.add_rating_to_product(product_id, rate, current_cust.get_id());
                        float overall_rating = market.get_product_rating(product_id);
                        cout << "Your rating is added successfully ,the overall product rating = " << overall_rating << endl;
                    }
                    else
                    {
                        cout << "Invalid input please try again" << endl;
                    }
                }
                else if (choice == 7)
                {
                    break;
                }
                else
                {
                    cout << " invalid choice please try again " << endl;
                    continue;
                }
            }
        }

        else if (choice == 2)
        {
        cout << "WECLOME SELLER TO OUR ONLINE MARKET" << endl;
        cout << "Press(1) login \t Press(2) register" << endl;
        cin >> choice;

        if (choice == 1)
        {
            string email = "";
            cout << "Please enter your email" << endl;
            cin >> email;
            current_seller_index = market.login_seller(email);
            if (current_seller_index != -1)
            {
                current_seller = market.get_seller(current_seller_index);
            }
            else
            {
                cout << "INVALID EMAIL PLEASE TRY AGAIN !!!" << endl;
                continue;
            }
        }
        else if (choice == 2)
        {
            string email, name;
            cout << "Please enter your name" << endl;
            cin >> name;
            cout << "Please enter your email" << endl;
            cin >> email;
            current_seller = market.add_seller(name, email);
            current_seller_index = market.login_seller(email);

        }
        else
        {
            cout << "INVALID CHOICE, PLEASE TRY AGAIN !!! " << endl;
            continue;
        }
        while (true)
        {
            
            cout << "Press(1) to view your products   " << endl;
            cout << "Press(2) to add new product " << endl; 
            cout << "Press(3) to exit " << endl;
            cin >> choice;
            if (choice == 1)
            {
                market.display_products_of_seller(current_seller.get_id());
            }
            else if (choice == 2)
            {
                string name, category;
                int quantity;
                float price;
                cout << "Please enter product name " << endl;
                cin >> name;
                cout << "Please enter product quantity " << endl;
                cin >> quantity;
                cout << "Please enter product price " << endl;
                cin >> price;
                cout << "Please enter product category " << endl;
                cin >> category;
                market.add_product(name, price, category, quantity, current_seller.get_id());
                cout << "Your product is added successfully " << endl;

            }
            else if (choice == 3)
            {
                cout << "Bye see you next time " << endl;
                break;
            }
            else
            {
                cout << "INVALID CHOICE, PLEASE TRY AGAIN !!! " << endl;
                continue;
            }
        }
     }


        else if (choice == 3)
        {
            cout << "Bye see you next time" << endl;
            break;
        }
        else
        {
            cout << "invalaid choice please try again " << endl;
            continue;
        }
    }







}