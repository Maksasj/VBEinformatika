#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {
      struct mush {
            int b = 0, r = 0, l = 0;
      };
      
      std::ifstream in("U2.txt");
      std::ofstream out("U2rez.txt");

      int n;
      in >> n;

      std::vector<std::pair<std::string, mush>> gryb;
      for(int x = 0; x < n; x++) {
            char vardas[16];
            in.ignore(1, '\n');
            in.get(vardas, 16);

            int l;
            in >> l;
            
            std::pair<std::string, mush> tmp = {vardas, {0, 0, 0}};

            for(int y = 0; y < l; y++) {
                  int b, r, l;
                  in >> b >> r >> l;
                  tmp.second.b += b;
                  tmp.second.r += r;
                  tmp.second.l += l;
            }

            gryb.push_back(tmp);
      }

      for(auto g : gryb) {
            char b[6] = {' ',' ',' ',' ',' ', '\0'};
            char r[6] = {' ',' ',' ',' ',' ', '\0'};
            char l[6] = {' ',' ',' ',' ',' ', '\0'};

            std::string str = std::to_string(g.second.b);
            reverse(str.begin(),str.end());
            for(auto p = 0; p < str.size(); p++) {
                  b[4 - p] = str[p];
            }

            str = std::to_string(g.second.r);
            reverse(str.begin(),str.end());
            for(auto p = 0; p < str.size(); p++) {
                  r[4 - p] = str[p];
            }

            str = std::to_string(g.second.l);
            reverse(str.begin(),str.end());
            for(auto p = 0; p < str.size(); p++) {
                  l[4 - p] = str[p];
            }

            out << g.first << b << r << l << "\n";
      }

      std::vector<std::pair<std::string, int>> sum;
      for(auto g : gryb) {
            sum.push_back({g.first, g.second.b + g.second.r + g.second.l});
      }

      sort(sum.begin(), sum.end(), [](std::pair<std::string, int> a, std::pair<std::string, int> b) {
            return a.second > b.second;
      });
      
      out << sum[0].first << sum[0].second;
      return 0;
}