#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Domino {
    bool hasFallen;
    vector<int> willFallOn;
};


int fall(vector<Domino> &vec, int n) {
    if (vec.at(n).hasFallen) return 0;
    vec.at(n).hasFallen = true;
    int fallen = 0;
    for (int i : vec.at(n).willFallOn) {
        fallen += fall(vec, i);
    }
    return fallen +1;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m, l;
        scanf("%d %d %d", &n, &m, &l);

        vector<Domino> vec;
        for (int i = 0; i < n; i++) {
            vec.push_back(Domino());
            vec.at(i).hasFallen = false;
        }

        
        for (int i = 0; i < m; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            vec.at(x-1).willFallOn.push_back(y-1);
        }

        int fallenDominoes = 0;
        for (int i = 0; i < l; i++) {
            int z;
            scanf("%d", &z);
            fallenDominoes += fall(vec, z-1);
        }
        cout << fallenDominoes << endl;
    }
    return 0;
}