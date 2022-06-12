#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

struct Pair {
      std::string name;
      std::vector<int> tech;
      std::vector<int> arti;
      int total_score = 0;

      void CountTotalScore() {
            sort(tech.begin(), tech.end(), [](int a, int b){
                  return a < b;
            });
            for(auto t : tech) {
                  total_score += t;
            }

            total_score -= tech[0];
            total_score -= tech[tech.size() - 1];
            
            sort(arti.begin(), arti.end(), [](int a, int b){
                  return a < b;
            });
            for(auto a : arti) {
                  total_score += a;
            }

            total_score -= arti[0];
            total_score -= arti[arti.size() - 1];
      }
};

void ReadFile(Pair pairs[], int &n) {
      std::ifstream in("U2.txt");
      int k;
      in >> n >> k;
      for(int x = 0; x < n; x++) {
            Pair tmp_pair;
            char pair_name[21];
            in.ignore(1, '\n');
            in.get(pair_name, 21);

            tmp_pair.name = pair_name;

            for(int y = 0; y < k; y++) {
                  int tmp;
                  in >> tmp;
                  tmp_pair.tech.push_back(tmp);
            }

            for(int y = 0; y < k; y++) {
                  int tmp;
                  in >> tmp;
                  tmp_pair.arti.push_back(tmp);
            }
            pairs[x] = tmp_pair;
      }
      in.close();
}

std::vector<Pair> SortPairs(Pair pairs[], int &n) {
      std::vector<Pair> out;
      for(int x = 0; x < n; x++) {
            out.push_back(pairs[x]);
      }
      sort(out.begin(), out.end(), [](Pair a, Pair b) {
            return a.total_score > b.total_score;
      });
      return out;
} 

void CountScore(Pair pairs[], int &n) {
      for(int x = 0; x < n; x++) {
            pairs[x].CountTotalScore();
      }
} 

void WriteFile(std::vector<Pair> pairs) {
      std::ofstream out("U2rez.txt");
      for(auto p : pairs) {
            out << p.name << " " << p.total_score << "\n";
      }
      out.close();
}

int main() {
      Pair pairs[100];
      int n;

      ReadFile(pairs, n);
      CountScore(pairs, n);
      std::vector<Pair> final = SortPairs(pairs, n); 
      WriteFile(final);

      return 0;
}