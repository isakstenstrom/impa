#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

static const pair<int, int> MOVES[] = {
    make_pair(1,2),
    make_pair(2,1),
    make_pair(2,-1),
    make_pair(1,-2),
    make_pair(-1,-2),
    make_pair(-2,-1),
    make_pair(-2,1),
    make_pair(-1,2),
};

static const char GOAL[5][5] = {
    {'1','1','1','1','1'},
    {'0','1','1','1','1'},
    {'0','0',' ','1','1'},
    {'0','0','0','0','1'},
    {'0','0','0','0','0'},
};

bool inBounds(int a, int b) {
    return a >= 0 && a < 5 && b >= 0 && b < 5;
}


int moveAndCheck(char arr[5][5], int depth, int emptyX, int emptyY) {
    if (depth > 10) return 100;
    bool atGoal = true;
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 5; x++) {
            if (arr[y][x] != GOAL[y][x]) {
                atGoal = false;
            }
        }
    }
    if (atGoal) return 0;

    int res = 100;
    for (auto move : MOVES) {
        if (inBounds(emptyY + move.second, emptyX + move.first)) {
            arr[emptyY][emptyX] = arr[emptyY + move.second][emptyX + move.first];
            arr[emptyY + move.second][emptyX + move.first] = ' ';
            res = min(moveAndCheck(arr, depth +1, emptyX + move.first, emptyY + move.second), res);
            arr[emptyY + move.second][emptyX + move.first] = arr[emptyY][emptyX];
            arr[emptyY][emptyX] = ' ';
        }
    }

    return res +1;
}

int main() {
    int N;
    string str;
    cin >> N;
    getline(cin, str);
    while (N--) {
        char arr[5][5];
        int emptyX, emptyY;
        for (int y = 0; y < 5; y++) {
            getline(cin, str);
            for (int x = 0; x < 5; x++) {
                arr[y][x] = str.at(x);
                if (str.at(x) == ' ') {
                    emptyX = x;
                    emptyY = y;
                }
            }
        }

        int res = moveAndCheck(arr, 0, emptyX, emptyY);

        if (res < 50) {
            cout << "Solvable in " << res << " move(s)." << endl;
        }
        else {
            cout << "Unsolvable in less than 11 move(s)." << endl;
        }
    }
    return 0;
}