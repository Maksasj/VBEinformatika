#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

typedef std::string str;
typedef struct Avys {
      str name;
      str dnr;
      int k;
} Avys;

bool compare(Avys a, Avys b) {
      if(a.k > b.k) {
            return true;
      } else if(a.k == b.k) {
            for(int p = 0; p < a.name.size(); p++) {
                  return ((a.name[p] < b.name[p]) && (a.name[p] != b.name[p])) ? true : false;
            }
      }
      return false;
}

int main() {
      std::ifstream in("U2.txt");
      std::ofstream out("U2rez.txt");

      std::vector<Avys> avys;
      int n = 0, m = 0, o = 0;
      in >> n >> m >> o;
      o--;
      
      for(int x = 0; x < n; x++) {
            char name[11];
            in.ignore(1, '\n');
            in.get(name, 11);

            str name_str = name;
            str frag_str;

            in >> frag_str;
            Avys tmp = {name_str, frag_str, 0};
            avys.push_back(tmp);
      }
      
      for(int p = 0; p < avys.size(); p++) {
            if(p != o) {
                  int l = 0;
                  for(auto letter : avys[p].dnr) {
                        avys[p].k += (letter == avys[o].dnr[l] ? 1 : 0);
                        l++;
                  }
            }
      }
      out << avys[o].name << "\n";
      str tested = avys[o].name;
      sort(avys.begin(), avys.end(), compare);

      for(auto a : avys) {
            out << (a.name != tested ? (a.name+" "+std::to_string(a.k)+"\n") : "");
      }

      return 0;
}