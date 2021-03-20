#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;


struct Agency{
    string name;
    int cost;
};


bool sortAgency(const Agency &a, const Agency &b) {
    if (a.cost == b.cost) {
        return a.name < b.name;
    }
    return a.cost < b.cost;
}


int main() {
    int T;
    scanf("%d\n", &T);
    for (int t = 1; t <= T; t++) {
        int N, M, L;
        scanf("%d %d %d\n", &N, &M, &L);
        vector<Agency> agencies;
        for (int i = 0; i < L; i++) {
            string str;
            getline(cin, str);
            agencies.push_back(Agency());
            agencies.back().name = str.substr(0, str.find(':'));
            int A = stoi(str.substr(str.find(':') +1, str.find(',') - str.find(':') -1));
            int B = stoi(str.substr(str.find(',') +1, str.find('\n') - str.find(',') -1));

            int n = N;
            int cost = 0;
            while (n > M) {
                int newN = n/2;
                if (newN >= M && (n-newN)*A > B) {
                    n = newN;
                    cost += B;
                }
                else {
                    n--;
                    cost += A;
                }
            }
            agencies.back().cost = cost;
        }
        sort(agencies.begin(), agencies.end(), sortAgency);
        
        cout << "Case " << t << endl;
        for (Agency a : agencies) {
            cout << a.name << " " << a.cost << endl;
        }

    }
    return 0;
}