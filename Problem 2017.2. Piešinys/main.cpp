#include <iostream>
#include <fstream>

typedef struct rgb {
      int r = 255;
      int g = 255;
      int b = 255;
} rgb;

int main() {
      std::ifstream in("U2.txt");
      std::ofstream out("U2rez.txt");

      rgb grid[150][150];
      std::pair<int, int> border = {-1, -1};

      int n; in >> n;
      for(int N = 0; N < n; N++) {
            int x, y, w, h, r, g, b;
            in >> x >> y >> w >> h >> r >> g >> b;
            
            border.first < x + w ? border.first = x + w : border.first;
            border.second < y + h ? border.second = y + h : border.second;
            
            for(int X = x; X < x+w; X++) {
                  for(int Y = y; Y < y+h; Y++) {
                        grid[X][Y] = {r, g, b};
                  }
            }
      }

      out << border.second << " " << border.first << "\n";
      for(int y = 0; y < border.second; y++) {
            for(int x = 0; x < border.first; x++) {
                 out << grid[x][y].r << " " << grid[x][y].g << " " << grid[x][y].b << "\n";
            } 
      }

      in.close();
      out.close();

      return 0;
}