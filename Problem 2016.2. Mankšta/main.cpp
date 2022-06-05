#include <iostream>
#include <fstream>
#include <map>

typedef std::string str;

int main() {
      std::ifstream in("U2.txt");
      std::ofstream out("U2rez.txt");

      int n;
      in >> n;

      std::map<str, int> value;

      for(int x = 0; x < n; x++) {
            char name[22];
            in.ignore(1, '\n');
            in.get(name, 22);

            str b = name;
            int val;
            in >> val;
            value[b] += val;
      }
      
      while(value.size() != 0) {
            std::map<str, int> tmp_value;
            
            str max_key;
            int max_value = -1;

            for(auto key : value) {
                  if(key.second > max_value) {
                        max_key = key.first;
                        max_value = key.second; 
                  }
            }

            for(auto key : value) {
                  if(key.first != max_key) {
                        tmp_value[key.first] = key.second;
                  }
            }

            value = tmp_value;
            out << max_key << max_value << "\n";
      }
      
      return 0;
}