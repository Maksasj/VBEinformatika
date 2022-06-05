#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

typedef std::pair<int, int> vec2;
typedef std::string str;

int main() {
      std::ifstream in("U1.txt");
      std::ofstream out("U1rez.txt");

      int n, fuel, p = 0;
      in >> n >> fuel;

      std::vector<std::pair<str, vec2>> data;

      for(int x = 0; x < n; x++) {
            char chName[11];
            in.ignore(1, '\n');
            in.get(chName, 11);

            int X = 0, Y = 0;
            in >> X >> Y;

            data.push_back({(str)chName, {abs(X), abs(Y)}});
      }
      for(int x = 0; x < data.size(); x++) {
            if((data[x].second.first*2 + data[x].second.second*2) <= fuel) {
                  fuel -= (data[x].second.first*2 + data[x].second.second*2);
                  p += data[x].second.first*2 + data[x].second.second*2;

                  if(x + 1 == data.size()) {
                        out << x + 1 << " " << p << " " << data[x].first << "\n";
                  }
            } else {
                  out << x << " " << p << " " << data[x-1].first << "\n";
                  break;
            }
      }

      return 0;
}