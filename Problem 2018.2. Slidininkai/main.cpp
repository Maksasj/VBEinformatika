#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

struct Slidin {
      std::string name;
      int start_h, start_m, start_s;
      int spend_s;
};

bool compare(Slidin a, Slidin b) {
      if(a.spend_s == b.spend_s) {
            return a.name < b.name;
      }

      return a.spend_s < b.spend_s;
}

int main() {
      std::ifstream in("U2.txt");
      std::ofstream out("U2rez.txt");
      
      int n;
      in >> n;

      std::map<std::string, Slidin> start_slidininkai;
      for(int x = 0; x < n; x++) {
            Slidin tmp;
            char name[21];
            in.ignore(1, '\n');
            in.get(name, 21);

            in >> tmp.start_h >> tmp.start_m >> tmp.start_s;
            tmp.name = name;
            start_slidininkai[name] = tmp;
      }

      std::vector<Slidin> finishave_slidininkai;

      int m;
      in >> m;

      for(int x = 0; x < m; x++) {
            Slidin tmp;
            char name[21];
            in.ignore(1, '\n');
            in.get(name, 21);

            in >> tmp.start_h >> tmp.start_m >> tmp.start_s;
            tmp.name = name;

            tmp.spend_s = tmp.start_s + (tmp.start_m + tmp.start_h*60)*60;
            start_slidininkai[name].spend_s = start_slidininkai[name].start_s + (start_slidininkai[name].start_m + start_slidininkai[name].start_h*60)*60;
            
            start_slidininkai[name].spend_s = tmp.spend_s - start_slidininkai[name].spend_s;

            finishave_slidininkai.push_back(start_slidininkai[name]);
      }

      sort(finishave_slidininkai.begin(), finishave_slidininkai.end(), compare);

      for(auto x : finishave_slidininkai) {
            out << x.name << " " << x.spend_s / 60 << " " << x.spend_s % 60 << "\n";
      }

      return 0;
}