#include <iostream>
#include <fstream>

typedef std::fstream Fin;
typedef std::ofstream Fout;
typedef std::string str;

str getColor(int r, int g, int b) {
      str colorCode[16] = {
            "0",
            "1",
            "2",
            "3",
            "4",
            "5",
            "6",
            "7",
            "8",
            "9",
            "A",
            "B",
            "C",
            "D",
            "E",
            "F"
      };

      int Rr = r / 16; int rr = r - Rr * 16;
      int Gg = g / 16; int gg = g - Gg * 16;
      int Bb = b / 16; int bb = b - Bb * 16;

      str output = 
            colorCode[Rr] + 
            colorCode[rr] + 
            colorCode[Gg] + 
            colorCode[gg] + 
            colorCode[Bb] + 
            colorCode[bb];

      return output;
}

int main() {

      Fin in("U1.txt");
      Fout out("U1rez.txt");

      int h, w;
      in >> h >> w;

      for(int H = 0; H < h; H++) {
            for(int W = 0; W < w; W++) {
                  int r, g, b;
                  in >> r >> g >> b;

                  out << getColor(r, g, b);
                  if(W + 1 != w)
                        out << ";";
            }
            out << "\n";
      }

      out.close();
      in.close();
      return 0;
}