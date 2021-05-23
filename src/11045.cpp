#include <iostream>
#include <string.h>

using namespace std;


bool bpm(bool bpGraph[32][36], int u, bool seen[], int matchR[], int M, int N) {
    for (int v = 0; v < N; v++) {
        if (bpGraph[u][v] && !seen[v]) {
            seen[v] = true;

            if (matchR[v] < 0 || bpm(bpGraph, matchR[v], seen, matchR, M, N)) {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}

int maxBPM(bool bpGraph[32][36], int M, int N) {
    int matchR[N];

    memset(matchR, -1, sizeof(matchR));

    int result = 0;
    for (int u = 0; u < M; u++) {
        bool seen[N];
        memset(seen, 0, sizeof(seen));

        if (bpm(bpGraph, u, seen, matchR, M, N)) result++;
    }
    return result;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N;
        cin >> M;
        bool graph[32][36];
        for (int i = 0; i < M; i++) {
            for (int k = 0; k < N; k++) {
                graph[i][k] = false;
            }
            for (int j = 0; j < 2; j++) {

                string str;
                cin >> str;

                for (int k = 0; k < N/6; k++) {
                    if (str == "XS") graph[i][0 +6*k] = true;
                    else if (str == "S") graph[i][1 +6*k] = true;
                    else if (str == "M") graph[i][2 +6*k] = true;
                    else if (str == "L") graph[i][3 +6*k] = true;
                    else if (str == "XL") graph[i][4 +6*k] = true;
                    else if (str == "XXL") graph[i][5 +6*k] = true;
                }
            }
        }

        if (M == maxBPM(graph, M, N)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
