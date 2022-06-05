#include <iostream>
#include <fstream>
#include <vector>

typedef std::string str;
typedef std::pair<int, int> vec2;

int main() {
      std::ifstream in("U2.txt");
      std::ofstream out("U2rez.txt");

      vec2 start = {0, 0};
      vec2 finish = {0, 0};

      in >> start.first >> start.second;
      in >> finish.first >> finish.second;

      int n;
      in >> n;

      std::vector<std::vector<int>> paths;
      for(int x = 0; x < n; x++) {
            std::vector<int> tmp_vec;
            int nl;
            in >> nl;

            for(int y = 0; y < nl; y++) {
                  int tmp;
                  in >> tmp;
                  tmp_vec.push_back(tmp);
            }

            paths.push_back(tmp_vec);
      }

      
      for(auto path : paths) {
            vec2 pos = start;
            bool done = false;

            if(start == finish) {
                  out << "pasiektas tikslas   0\n";
            } else {
                  std::vector<int> done_path;

                  for(auto move : path) {
                        done_path.push_back(move);
                        if(move == 1) {
                              pos.second++;
                        } else if(move == 2) {
                              pos.first++;
                        } else if(move == 3) {
                              pos.second--;
                        } else if(move == 4) {
                              pos.first--;
                        }
                        if(pos == finish) {
                              done = true;
                              break;
                        }
                  }

                  if(done) {
                        out << "pasiektas tikslas   ";
                  } else {
                        out << "sekos pabaiga       ";
                  }
                  for(auto m : done_path) {
                        out << m << " ";
                  }
                  out << done_path.size() << "\n";
            }
      }

      return 0;
}