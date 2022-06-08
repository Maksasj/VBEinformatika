#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

void prinT(int n, std::ofstream &os) {
      char l[7] = {' ',' ',' ',' ',' ',' ', '\0'};

      std::string str = std::to_string(n);
      reverse(str.begin(),str.end());
      for(auto p = 0; p < str.size(); p++) {
            l[5 - p] = str[p];
      }

      os << l;
}

int main() {
      std::ifstream in("U1.txt");
      std::ofstream out("U1rez.txt");

      struct tuple {
            int a = 0;
            int b = 0;
            int c = 0;
      };

      std::map<int, tuple> path_m;
      int n;
      in >> n;

      for(int x = 0; x < n; x++) {
            int p, k;
            in >> p >> k;
            path_m[p].a++;

            if(k > 0) {
                  path_m[p].b += k;
            } else if (k < 0) {
                  path_m[p].c += k;
            }
      }

      std::vector<tuple> path;
      for(auto m : path_m) {
            path.push_back({m.first, m.second.b, m.second.c});
      }

      sort(path.begin(), path.end(), [](tuple a, tuple b) {
            return b.a > a.a;
      });

      for(auto p : path) {
            prinT(p.a, out);
      } out << "\n";

      for(auto p : path) {
            prinT(p.b, out);
      } out << "\n";

      for(auto p : path) {
            prinT(p.c, out);
      } out << "\n";

      if(path.size() != 1) {
            sort(path.begin(), path.end(), [](tuple a, tuple b) {
            return a.b > b.b;
            });
            if(path[0].b == path[1].b) {
                  std::vector<tuple> k = {path[0], path[1]};
                  sort(k.begin(), k.end(), [](tuple a, tuple b) {
                        return b.a > a.a;
                  });

                  prinT(k[0].a, out);
            } else {
                  prinT(path[0].a, out);
            }

      } else {
            prinT(path[0].a, out);
      }

      return 0;
}