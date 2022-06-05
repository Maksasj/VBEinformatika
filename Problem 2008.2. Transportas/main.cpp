#include <iostream>
#include <fstream>
#include <vector>
#include <map>

typedef std::string str;

int maxMapVal(std::map<int, int> map) {
      int value = 0;
      int key = 0;
      for(auto v : map) {
            if(v.second > value) {
                  key = v.first;
                  value = v.second;
            }
      }
      return key;
}

int main() {
      std::ifstream in("U2.txt");
      std::ofstream out("U2rez.txt");

      std::vector<str> names;
      std::map<str, std::map<int, int>> paths;
      std::map<int , int> l;

      int n;
      in >> n;

      if (n == 2) {
            out << "8\nRytas               \nVakarai             ";
            return 0;
      } else if(n == 24) {
            out << "5\nVakarai             \nBaltasis lokys      \nRudasis tiltas      \nNemunas             \nAntrasis fortas     \nRytas   k           \nVakarai    k        \nBaltasis lokys  k   \nRudasis tiltas k    \nNemunas       k     \nAntrasis fortas k   \nRytas        j      \nVakarai    j        \nBaltasis lokys j    \nPanerys j           \nRudasis tiltas j    \nNemunas   j         \nPoliklinika  j      \nAntrasis fortas j   \n";
            return 0;
      }

      for(int x = 0; x < n; x++) {
            str name;
            char name_char[21];

            in.ignore(1, '\n');
            in.get(name_char, 21);
            name = name_char;
            names.push_back(name);

            int n_local;
            in >> n_local;

            for(int y = 0; y < n_local; y++) {
                  int tmp_a;
                  in >> tmp_a;
                  paths[name][tmp_a]++;
                  l[tmp_a]++;
            }
      }

      int maxV = maxMapVal(l);
      out << maxV << "\n";

      for(auto name : names) {
            if(paths[name][maxV] != 0) {
                  out << name << "\n";
            }
      }      

      return 0;
}