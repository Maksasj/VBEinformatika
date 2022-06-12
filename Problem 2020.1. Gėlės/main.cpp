#include <iostream>
#include <fstream>
#include <vector>

typedef struct{int a, b, c;} tuple;

struct Flower {
      int number, start_m, start_d, finish_m, finish_d;
};

std::pair<int, int> date_from_days(int d) {
      if(d >= 0 && d <= 31) {
            return {6, d};
      } else if(d >= 32 && d <= 62) {
            return {7, d - 31};
      } else if(d >= 63 && d <= 92) {
            return {8, d - 61};
      }

      return {0, 0};
}

tuple RastiDaugGeliuZyd(std::vector<Flower> flowers) {
      int dienos[92];
      for(int x = 0; x < 92; x++) {
            dienos[x] = 0;
      }

      for(auto flower : flowers) {
            int start_d = flower.start_d;
            start_d += (flower.start_m == 6 ? 0 : (flower.start_m == 7 ? 31 : 61));
            
            int finish_d = flower.finish_d;
            finish_d += (flower.finish_m == 6 ? 0 : (flower.finish_m == 7 ? 31 : 61));

            for(int x = start_d; x <= finish_d; x++) {
                  dienos[x]++;
            }
      }

      int max_tmp = 0;
      for(int x = 0; x < 92; x++) {
            if(dienos[x] > max_tmp) {
                  max_tmp = dienos[x];
            }
      }

      int start = 0;
      int finish = 0;
      bool found_max = false;
      for(int x = 0; x < 92; x++) {
            if(dienos[x] == max_tmp && found_max == false) {
                  start = x;
                  found_max = true;
            }

            if(x + 1 == 92) {
                  finish = x + 1;
            }

            if ((dienos[x] != max_tmp && found_max == true)) {
                  finish = x - 1;
                  break;
            }
            
      }

      return {max_tmp, start, finish};
}

int main() {
      std::ifstream in("U1.txt");
      std::vector<Flower> flowers;
      
      int n;
      in >> n;

      for(int x = 0; x < n; x++) {
            Flower tmp;
            int number, start_m, start_d, finish_m, finish_d;
            in >> number >> start_m >> start_d >> finish_m >> finish_d;
            tmp = {number, start_m, start_d, finish_m, finish_d};
            flowers.push_back(tmp);
      }

      in.close();

      tuple rez = RastiDaugGeliuZyd(flowers);

      std::ofstream out("U1rez.txt");
      out << rez.a << "\n";
      out << date_from_days(rez.b).first << " " << date_from_days(rez.b).second << "\n";
      out << date_from_days(rez.c).first << " " << date_from_days(rez.c).second;
      out.close();
      return 0;
}