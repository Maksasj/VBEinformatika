#include <iostream>
#include <fstream>
#include <vector>

typedef std::string str;
typedef struct dish {
      str name;
      int price;
} dish;


int main() {
      std::ifstream in("U2.txt");
      std::ofstream out("U2rez.txt");

      std::vector<dish> dishes;
      std::vector<int> prod_price;
      int n, p;
      in >> n >> p;

      for(int x = 0; x < n; x++) {
            int tmp;
            in >> tmp;
            prod_price.push_back(tmp);
      }

      for(int x = 0; x < p; x++) {
            char name[16];
            in.ignore(1, '\n');
            in.get(name, 16);

            int price = 0;
            for(int y = 0; y < n; y++) {
                  int tmp_count;
                  in >> tmp_count;
                  
                  price += tmp_count * prod_price[y];
            }
            
            dish tmp_dish = { name, price };
            dishes.push_back(tmp_dish);
      }

      int total_price = 0;
      for(auto d : dishes) {
            total_price += d.price;
            out << d.name << " " << d.price << "\n";
      }

      out << total_price / 100 << " " << total_price % 100;

      return 0;
}