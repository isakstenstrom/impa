#include <iostream>
#include <vector>

using namespace std;


int calculateInsertions(vector<int> &vec, int start, int end, int insertions, int max) {
    if (insertions > max) return 100;
    else if (start >= end) return insertions;
    else if (vec.at(start) == vec.at(end)) {
        return calculateInsertions(vec, start +1, end -1, insertions, max);
    }
    else {
        int a = calculateInsertions(vec, start +1, end, insertions +1, max);
        int b = calculateInsertions(vec, start, end -1, insertions +1, max);
        return min(a, b);
    }
}


int main() {
    int T, N, K;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d %d", &N, &K);
        vector<int> vec;
        vec.resize(N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &vec[i]);
        }

        cout << "Case " << t << ": ";
        int insertions = calculateInsertions(vec, 0, vec.size() -1, 0, K);
        if (insertions == 0) cout << "Too easy" << endl;
        else if (insertions > K) cout << "Too difficult" << endl;
        else {
            cout << insertions << endl;
        }
    }
    return 0;
}
