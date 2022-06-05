#include <iostream>
#include <fstream>
#include <vector>

int maxVal(std::vector<int> vec) {
      int max_value = -1;
      for(auto k : vec) {
            k > max_value ? max_value = k : max_value = max_value;
      }
      return max_value;
}

int countLowerVal(std::vector<int> vec, int value) {
      int n = 0;
      for(auto k : vec) {
            k*2 <= value ? n++ : n = n;
      }
      return n;
}

int main() {
      std::ifstream in("U1.txt");
      std::ofstream out("U1rez.txt");

      std::vector<int> value;
      int n;
      in >> n;

      for(int x = 0; x < n; x++) {
            int b;
            in >> b;
            value.push_back(b);
      }

      out << maxVal(value) << " " << countLowerVal(value, maxVal(value));
      return 0;
}