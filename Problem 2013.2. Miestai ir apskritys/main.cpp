#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>

typedef std::string str;
typedef struct infint {
      int x = 2147483647;
} infint;
typedef std::pair<str, std::pair<int, int>> city;

bool sortalg(city a, city b) {
      if(a.second.first < b.second.first) {
            return true;
      } else if (a.second.first > b.second.first) {
            return false;
      } else if (a.second.first == b.second.first) {
            int p = 0;
            for(auto letter : a.first) {
                  if(letter < b.first[p]) {
                        return true;
                  } else if(letter > b.first[p]){
                        return false;
                  }
                  p++;
            }
      }
      return false;
} 

int main() {
      std::ifstream in("U2.txt");
      std::ofstream out("U2rez.txt");

      std::map<str, infint> min;
      std::map<str, int> total;

      int n;
      in >> n;

      while (n > 0) {
            char city[20];
            in.ignore(1, '\n');
            in.get(city, 20);

            char aps[13];
            in.ignore(1, '\n');
            in.get(aps, 14);
            
            int value;
            in >> value;
            total[(str)aps] += value;

            if(min[(str)aps].x > value) {
                  min[(str)aps].x = value;
            }

            n--;
      }

      std::vector<city> final_data;      
      out << total.size() << "\n";
      for(auto c : total) {
            city tmp = {c.first ,{ min[c.first].x, c.second }};
            final_data.push_back(tmp);
      }

      sort(final_data.begin(), final_data.end(), sortalg);

      for(auto data : final_data) {
            out << data.first << data.second.first << " " << data.second.second << "\n";
      }

      return 0;
}