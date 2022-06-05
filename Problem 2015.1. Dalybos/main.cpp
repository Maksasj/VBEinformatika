#include <fstream>
#define f20 for(int x = 0; x < 20; x++)
#define t T[y]

int main() {
      std::ifstream in("U1.txt");
      std::ofstream out("U1rez.txt");

      int S[20] = { 0 };
      int T[20] = { 0 };

      for(int y = 0; y < 10; y++) {
            in >> S[y];
            t = 10 - S[y];
      }

      f20 { for(int y = 18; y >= 0; y--) {
            t > 0 ? ((T[y+1] = (t - 1), t = 0, S[y+1] += 1)) : 0;  
      }}     

      f20 { out << S[x] << ((x != 19) ? " " : ""); }
      return 0;
}