#include <iostream>
#include <fstream>

int main() {
      std::ifstream in("U1.txt");
      std::ofstream out("U1rez.txt");

      int n;
      in >> n;

      int pest = 0, boks = 0, zirg = 0, rikiai = 0, karaliai = 0, valdov = 0;

      for(int x = 0; x < n; x++) {
            int tmp_pest, tmp_boks, tmp_zirg, tmp_rikiai, tmp_karaliai, tmp_valdov;
            in >> tmp_pest >> tmp_boks >> tmp_zirg >> tmp_rikiai >> tmp_karaliai >> tmp_valdov;

            pest += tmp_pest;
            boks += tmp_boks;
            zirg += tmp_zirg;
            rikiai += tmp_rikiai;
            karaliai += tmp_karaliai;
            valdov += tmp_valdov;
      }

      int o = 0;
      while (true)
      {
            if(   pest - 8 >= 0 &&
                  boks - 2 >= 0 &&
                  zirg - 2 >= 0 &&
                  rikiai - 2 >= 0 &&
                  karaliai - 1 >= 0 &&
                  valdov - 1 >= 0
                  ) {
                  
                  pest -= 8;
                  boks -= 2;
                  zirg -= 2;
                  rikiai -= 2;
                  karaliai -= 1;
                  valdov -= 1;
                  o++;

            } else {
                  break;
            }
      }
      
      out << o;

      return 0;
}