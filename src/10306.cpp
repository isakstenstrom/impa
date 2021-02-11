#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

bool compareCoins(const pair<int, int> &a, const pair<int, int> &b) {
    return (a.first * a.first + a.second * a.second) > (b.first * b.first + b.second * b.second);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int m, S;
        scanf("%d %d", &m, &S);

        int SS = S*S;

        vector<pair<int, int>> coins;
        coins.reserve(m);
        for (int i = 0; i < m; i++) {
            int coinX, coinY;
            scanf("%d %d", &coinX, &coinY);
            coins.emplace_back(coinX, coinY);
        }

        sort(coins.begin(), coins.end(), compareCoins);
        
        coins.erase(unique(coins.begin(), coins.end()), coins.end());

        int table[301][301];

        for (int y = 0; y <= S; y++) {
            for (int x = 0; x <= S; x++) {
                table[y][x] = 301;
            }
        }
        table[0][0] = 0;

        for (int c = 0; c < coins.size(); c++) {
            for (int y = coins.at(c).second; y <= S; y++) {
                for (int x = coins.at(c).first; x <= S; x++) {
                    table[y][x] = min(table[y][x], table[y-coins.at(c).second][x-coins.at(c).first] +1);
                }
            }
        }

        int minN = 301;
        for (int y = 0; y <= S; y++) {
            for (int x = 0; x <= S; x++) {
                if (y*y + x*x == SS) {
                    minN = min(table[y][x], minN);
                }
            }
        }
        if (minN == 301) cout << "not possible" << endl;
        else cout << minN << endl;   
    }
    return 0;
}