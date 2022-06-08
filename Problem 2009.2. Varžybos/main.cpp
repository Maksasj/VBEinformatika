#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {
      struct tuple {
            std::string s;
            int m = 0;
            int c = 0;
      };

      std::ifstream in("U2.txt");
      std::ofstream out("U2rez.txt");

      int n;
      in >> n;

      std::vector<tuple> finale;
      for(int x = 0; x < n; x++) {
           int k;
           in >> k;

            std::vector<tuple> tmp;
            for(int y = 0; y < k; y++) {
                  char name[21];
                  in.ignore(1, '\n');
                  in.get(name, 21);

                  int m, s;
                  in >> m >> s;

                  tmp.push_back({name, m, s});
            }

            sort(tmp.begin(), tmp.end(), [](tuple a, tuple b) {
                  return ((b.m*60 + b.c) > (a.m*60 + a.c));
            });

            for(int y = 0; y < (int)(tmp.size() / 2); y++) {
                  finale.push_back(tmp[y]);
            }
      }

      sort(finale.begin(), finale.end(), [](tuple a, tuple b) {
            return ((b.m*60 + b.c) > (a.m*60 + a.c));
      });

      for(auto p : finale) {
            out << p.s << p.m << " " << p.c << "\n";
      }

      return 0;
}