#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {
    string line;
    getline(cin, line);
    int C = stoi(line);
    getline(cin, line);

    for (int c = 0; c < C; c++) {
        getline(cin, line);
        stringstream ss;
        ss.str(line);
        int P, T;
        ss >> P;
        ss >> T;

        vector<string> v;
        if (P != 0 && T != 0) {
            vector<vector<bool>> pepole(P, vector<bool>(T));
            while (true) {
                getline(cin, line);
                if (line.length() < 2) break;
                
                stringstream ss2(line);
                int p = 0, t = 0;
                ss2 >> p;
                ss2 >> t;
                pepole[p-1][t-1] = true;
            }

            for (int i = 0; i < P; i++) {
                string s;
                for (int j = 0; j < T; j++) {
                    if (pepole[i][j]) {
                        s.append("1");
                    } else {
                        s.append("0");
                    }
                }

                if (find(v.begin(), v.end(), s) == v.end()) {
                    v.push_back(s);
                }
            }
        } else {
            if (P != 0) v.push_back("");
            getline(cin, line);
        }

        cout << v.size() << endl;
        if (c != C-1) cout << endl;
    }
}