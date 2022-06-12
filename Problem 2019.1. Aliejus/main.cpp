#include <fstream>
#include <iostream>

typedef struct{ int a, b, c; } tuple;

tuple calc_liko(int k) {
      int p1 = 0, p3 = 0, p5 = 0;

      while(true) {
            if(k >= 5) {
                  k -= 5;
                  p5++;
            } else {
                  break;
            }
      }

      while(true) {
            if(k >= 3) {
                  k -= 3;
                  p3++;
            } else {
                  break;
            }
      }

      while(true) {
            if(k >= 1) {
                  k -= 1;
                  p1++;
            } else {
                  break;
            }
      }

      return {p1, p3, p5};
}

int main() {
      std::ifstream in("U1.txt");
      std::ofstream out("U1rez.txt");

      int n1, n3, n5, k;
      in >> n1 >> n3 >> n5 >> k;

      int k1, k3, k5, al_kaina;
      in >> al_kaina >> k1 >> k3 >> k5;

      int p1 = 0, p3 = 0, p5 = 0;

      while(n5 > 0) {
            if(k >= 5) {
                  n5--;
                  k -= 5;
                  p5++;
            } else {
                  break;
            }

            if(n5 <= 0) {
                  break;
            }
      }



      while(n3 > 0) {
            if(k >= 3) {
                  n3--;
                  k -= 3;
                  p3++;
            } else {
                  break;
            }
            if(n3 <= 0) {
                  break;
            }
      }

      while(n1 > 0) {
            if(k >= 1) {
                  n1--;
                  k -= 1;
                  p1++;
            } else {
                  break;
            }
            if(n1 <= 0) {
                  break;
            }
      }


      out << p1 << " " << p3 << " " << p5 << " " << k << "\n";
      out << n1 << " " << n3 << " " << n5 << "\n";

      tuple liko = calc_liko(k);
      out << liko.a << " " << liko.b << " " << liko.c << "\n";

      int pelnas = ((p1+liko.a)*k1 + (p3+liko.b)*k3 + (p5+liko.c)*k5) - al_kaina;

      out << pelnas;
      return 0;
}