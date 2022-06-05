#include <iostream>
#include <fstream>
#include <vector>

typedef std::string str;

typedef struct player {
      str name;
      int score;
      int lyg;
} player;

player get_winner(std::vector<player> players) {
      std::vector<player> winners;

      int max_score = players[0].score;
      for(auto p : players) {
            if(max_score < p.score) {
                  max_score = p.score;
            }
      }

      //Count winners;
      for(auto p : players) {
            if(p.score >= max_score) {
                  winners.push_back(p);
            }
      }

      if(winners.size() == 1) {
            return winners[0];
      }

      int max_lyg = 0;
      for(auto p : winners) {
            if(max_lyg < p.lyg) {
                  max_lyg = p.lyg;
            }
      }

      std::vector<player> finals;
      for(auto p : winners) {
            if(p.lyg >= max_lyg) {
                  finals.push_back(p);
            }
      }

      return finals[0];
}

int main() {
      std::ifstream in("U2.txt");
      std::ofstream out("U2rez.txt");

      std::vector<player> players;
      int n, k;
      in >> n >> k;

      for(int x = 0; x < n; x++) {
            char name[12];
            in.ignore(1, '\n');
            in.get(name, 12);

            int tmp_score = 0;
            int lyg = 0;
            for(int y = 0; y < k; y++) {
                  int tmp;
                  in >> tmp;
                  if(tmp % 2 == 0) {
                        lyg++;
                        tmp_score += tmp;
                  } else {
                        tmp_score -= tmp;
                  }
            }

            player tmp = { name, tmp_score, lyg };
            players.push_back(tmp);
      }

      player winner = get_winner(players);
      out << winner.name << winner.score << "\n";
      return 0;
}