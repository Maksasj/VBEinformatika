#include <fstream>
#include <iostream>

int main() {
      std::ifstream in("U1.txt");
      std::ofstream out("U1rez.txt");

      int n;
      in >> n;

      int p = 0, a = 0, t = 0;
      int Tp = 0, Ta = 0, Tt = 0;

      for(int x = 0; x < n; x++) {
            int tmp_p = 0, tmp_a = 0, tmp_T = 0;
            in >> tmp_p >> tmp_a >> tmp_T;
            
            p += tmp_p;
            a += tmp_a;
            t += tmp_T;
            
            if(tmp_p > tmp_a && tmp_p > tmp_T) {
                  Tp += 4;
            } else if(tmp_a > tmp_p && tmp_a > tmp_T) {
                  Ta += 4;
            } else if(tmp_T > tmp_p && tmp_T > tmp_a) {
                  Tt += 4;
            } else if(tmp_p == tmp_a && tmp_p > tmp_T) {
                  Tp += 2;
                  Ta += 2;
            } else if(tmp_p == tmp_T && tmp_p > tmp_a) {
                  Tp += 2;
                  Tt += 2;
            } else if(tmp_T == tmp_a && tmp_T > tmp_p) {
                  Tt += 2;
                  Ta += 2;
            }
      }

      int dp = 0, da = 0, dt = 0;
      in >> dp >> da >> dt;

      
      if((Tp == Ta && Tp == Tt) || (
            (Tp < Ta && Tp < Tt && Ta == Tt) ||
            (Ta < Tp && Ta < Tt && Tp == Tt) ||
            (Tt < Tp && Tt < Ta && Tp == Ta)
      )) {
            Tp += dp;
            Ta += da;
            Tt += dt;
      }
      out << p << " " << a << " " << t << "\n";
      out << Tp << " " << Ta << " " << Tt << "\n";

      if(Tp > Ta && Tp > Tt) {
            out << "1";
      } else if(Ta > Tp && Ta > Tt) {
            out << "2";
      } else if(Tt > Ta && Tt > Tp) {
            out << "3";
      }

      return 0;
}