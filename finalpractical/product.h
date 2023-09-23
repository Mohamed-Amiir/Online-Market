#include <string>
#include <unordered_map>
using namespace std;

class product
{
private:

    int id;
    string name;
    int seller_id;
    int quantity;
    float price;
    string category;
    unordered_map<int, int> rating_map;
    float overall_rating;


public:

    product( string n, float p, string c, int q, int s);
    product();
    string get_name();
    int get_id();
    string get_category();
    float get_price();
    int get_quantity();
    void set_quantity(int q);
    int get_seller_id();
    void set_rating(int rating, int customer_id);
    void calculate_total_rating();
    float get_overall_rating();


};






