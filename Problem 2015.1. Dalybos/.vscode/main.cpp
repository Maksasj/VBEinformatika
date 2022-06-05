#include <iostream>
#include <fstream>

int main() {
      std::ifstream in("U1.txt");
      std::ofstream out("U1rez.txt");

      int suva[20] = { 0 };
      int turi[20] = { 0 };

      for(int x = 0; x < 10; x++) {
            in >> suva[x];
            turi[x] = 10 - suva[x];
      }

      for(int y = 0; y < 20; y++) {
            for(int x = 18; x >= 0; x--) {
                  turi[x] > 0 ? (turi[x+1] = turi[x - 1], turi[x] = 0, suva[x + 1]++) : turi[x];
            }
            out << suva[y] << ((y != 19) ? " " : "");
      }
      
      return 0;
}