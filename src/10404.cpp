#include <iostream>
#include <vector>
#include <set>

using namespace std;


int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        set<int> moves;
        for (int i = 0; i < m; i++) {
            int move;
            scanf("%d", &move);
            moves.insert(move);
        }
        vector<bool> wins;
        wins.resize(n +1, false);
        for (int i = 1; i < wins.size(); i++) {
            for (int move : moves) {
                if (i - move >= 0) {
                    if (!wins.at(i - move)) {
                        wins.at(i) = true;
                        break;
                    }
                }
            }
        }

        if (wins.back()) {
            cout << "Stan wins" << endl;
        }
        else {
            cout << "Ollie wins" << endl;
        }
    }
    return 0;
}
