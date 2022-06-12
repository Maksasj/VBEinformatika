#include <iostream>
#include <fstream>
#include <algorithm>

struct Player {
      int k;
      int t;
      int game_time = 0;
      int sit_time = 0;
      int time[40];
};

void ReadFile(Player players[], int &n) {
      std::ifstream in("U1.txt");
      in >> n;

      for(int x = 0; x < n; x++) {
            Player tmp;
            in >> tmp.k >> tmp.t;
            for(int y = 0; y < tmp.t; y++) {
                  int tmp_time;
                  in >> tmp_time;
                  if(tmp_time > 0) {
                        tmp.game_time += tmp_time;
                  } else {
                        tmp.sit_time -= tmp_time;
                  }
                  tmp.time[y] = tmp_time;
            }
            players[x] = tmp;
      }

      in.close();
}

std::pair<int, int> GetPlayerWithMaxTime(Player players[], int n) {
      std::sort(players, players + n, [](Player a, Player b) {
            return a.game_time > b.game_time;
      });

      return {players[0].k, players[0].game_time};
}

std::pair<int, int> GetPlayerWithMinTime(Player players[], int n) {
      std::sort(players, players + n, [](Player a, Player b) {
            return a.sit_time > b.sit_time;
      });

      return {players[0].k, players[0].sit_time};
}

bool compare(int a, int b) {
      return a < b;
}

void WriteToFile(Player players[], int n) {
      std::ofstream out("U1rez.txt");

      int pirm_players[99];
      int n1 = 0;
      for(int x = 0; x < n; x++) {
            if(players[x].time[0] > 0) {
                  pirm_players[n1] = players[x].k;
                  n1++;
            }
      };

      std::sort(pirm_players, pirm_players + n1, compare);

      for(int x = 0; x < n1; x++) {
            out << pirm_players[x];
            if(x != n1 - 1) {
                  out << " ";
            }
      } out << "\n";

      std::pair<int, int> maxtime_player = GetPlayerWithMaxTime(players, n);
      out << maxtime_player.first << " " << maxtime_player.second << "\n";

      std::pair<int, int> mintime_player = GetPlayerWithMinTime(players, n);
      out << mintime_player.first << " " << mintime_player.second << "\n";

      out.close();
}

int main() {
      Player players[99];
      int n;

      ReadFile(players, n);
      WriteToFile(players, n);

      return 0;
}
