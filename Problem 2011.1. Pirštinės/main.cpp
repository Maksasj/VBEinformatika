#include <iostream>
#include <fstream>
#include <map>

typedef std::pair<int, int> ipair;
typedef std::map<int, ipair> tuple_map;

ipair calc_pair_count(tuple_map &a, tuple_map &b) {
      ipair answ = {0, 0};

      for(auto &x : a) {
            if(x.second.first != 0 && x.second.second != 0) {
                  int tmp = 0;

                  while((x.second.first * x.second.second) != 0) {
                        tmp++;
                        x.second.first--;
                        x.second.second--;
                  }

                  answ.first += tmp;
            }
      }

      for(auto &x : b) {
            if(x.second.first != 0 && x.second.second != 0) {
                  int tmp = 0;

                  while((x.second.first * x.second.second) != 0) {
                        tmp++;
                        x.second.first--;
                        x.second.second--;
                  }

                  answ.second += tmp;
            }
      }

      return answ;
}

int main() {
      std::ifstream in("U1.txt");
      std::ofstream out("U1rez.txt");

      int n;
      in >> n;

      tuple_map vyr;
      tuple_map mot;

      for(int x = 0; x < n; x++) {
            int gender;
            in >> gender;

            if(gender == 4) { //Moteriske
                  int side, size;
                  in >> side >> size;

                  if(side == 1) { // Kaires
                        mot[size].first++;
                  } else if(side == 2) { // Desines
                        mot[size].second++;
                  }
            } else if (gender == 3) { //Vyras
                  int side, size;
                  in >> side >> size;

                  if(side == 1) { // Kaires
                        vyr[size].first++;
                  } else if(side == 2) { // Desines
                        vyr[size].second++;
                  }
            }
      }

      ipair v_m = calc_pair_count(vyr, mot);
      int atl_m = 0, atl_v = 0;

      for(auto x : mot) {
            atl_m += x.second.first + x.second.second;
      }

      for(auto x : vyr) {
            atl_v += x.second.first + x.second.second;
      }

      out << v_m.second << "\n" << v_m.first << "\n";
      out << atl_m << "\n" << atl_v;

      return 0;
}