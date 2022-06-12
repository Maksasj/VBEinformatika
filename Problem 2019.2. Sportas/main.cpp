#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

struct Player {
      std::string name;
      int number;
      int start_h; 
      int start_m;
      int start_s; 

      int spend_s;
};

bool compare(Player a, Player b) {
      if(a.spend_s == b.spend_s) {
            return a.name > b.name;
      }

      return a.spend_s < b.spend_s;
}

void WriteFile(std::vector<Player> finish_merg, std::vector<Player> finish_vaik) {
      std::ofstream out("U2rez.txt");
      
      out << "Merginos\n";
      for(auto a : finish_merg) {
            int h = a.spend_s / 3600;
            int m = (a.spend_s / 60) - h*60;
            int s = (a.spend_s) - h*60*60 - m*60;

            out << a.number << " " << a.name << h << " " << m << " " << s << "\n";
      }

      out << "Vaikinai\n";
      for(auto a : finish_vaik) {
            int h = a.spend_s / 3600;
            int m = (a.spend_s / 60) - h*60;
            int s = (a.spend_s) - h*60*60 - m*60;

            out << a.number << " " << a.name << h << " " << m << " " << s << "\n";
      }

      out.close();
}

int main() {
      std::ifstream in("U2.txt");

      std::map<int, Player> merg;
      std::map<int, Player> vaik;

      int n;
      in >> n;

      for(int x = 0; x < n; x++) {

            char name[21];
            in.ignore(1, '\n');
            in.get(name, 21);

            int number, start_h, start_m, start_s;
            in >> number >> start_h >> start_m >> start_s;

            int spend_s = (start_h*60+start_m)*60 + start_s;

            Player tmp = {name, number, start_h, start_m, start_s, spend_s};

            std::string tmp_str = std::to_string(number);
            if(tmp_str[0] == '2') {
                  vaik[number] = tmp;
            } else if(tmp_str[0] == '1') {
                  merg[number] = tmp;
            }
      }
      
      std::vector<Player> finish_merg;
      std::vector<Player> finish_vaik;

      int m;
      in >> m;
      for(int x = 0; x < m; x++) {
            int number, start_h, start_m, start_s;
            int saud1 = 0, saud2 = 0, saud3 = 0, saud4 = 0;

            in >> number >> start_h >> start_m >> start_s;

            std::string tmp_str = std::to_string(number);
            if(tmp_str[0] == '2') {
                  in >> saud1 >> saud2 >> saud3 >> saud4;
                  
                  int spend_s = (start_h*60 + start_m)*60 + start_s + (5 - saud1)*60+ (5 - saud2)*60 + (5 - saud3)*60 + (5 - saud4)*60;
                  vaik[number].spend_s = spend_s - vaik[number].spend_s;

                  finish_vaik.push_back(vaik[number]);
            } else if(tmp_str[0] == '1') {
                  in >> saud1 >> saud2;

                  int spend_s = (start_h*60 + start_m)*60 + start_s + (5 - saud1)*60+ (5 - saud2)*60;
                  merg[number].spend_s = spend_s - merg[number].spend_s;

                  finish_merg.push_back(merg[number]);
            }
      }

      in.close();

      sort(finish_merg.begin(), finish_merg.end(), compare);
      sort(finish_vaik.begin(), finish_vaik.end(), compare);

      WriteFile(finish_merg, finish_vaik);
      return 0;
}