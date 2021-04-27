#include <iostream>
#include <set>

using namespace std;

int main() {
    while (true) {
        int S, B;
        scanf("%d %d", &S, &B);
        if (S == 0 && B == 0) {
            break;
        }
        set<pair<int, int>> killed;
        for (int i = 0; i < B; i++) {
            int L, R;
            scanf("%d %d", &L, &R);
            set<pair<int, int>>::iterator it = killed.emplace(L, R).first;

            if (it != killed.begin()) {
                set<pair<int, int>>::iterator before = it;
                before--;
                if (before->second +1 == L) {
                    L = before->first;
                    killed.erase(before);
                    killed.erase(it);
                    it = killed.emplace(L, R).first;
                }
            }
            
            set<pair<int, int>>::iterator after = it;
            after++;
            if (after != killed.end()) {
                if (after->first == R +1) {
                    R = after->second;
                    killed.erase(after);
                    killed.erase(it);
                    it = killed.emplace(L, R).first;
                }
            }

            L--;
            R++;

            if (L == 0) cout << "*";
            else cout << L;
            cout << " ";
            if (R == S +1) cout << "*";
            else cout << R;
            cout << endl;
        }
        cout << "-" << endl;
    }
    return 0;
}