#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<int> trains;
        trains.resize(n);
        for (int i = 0; i < n; i++) scanf("%d", &trains[i]);

        vector<int> lis(trains.size(), 1);
        vector<int> lds(trains.size(), 1);
        for (int i = lis.size()-1; i >= 0; i--) {
            for (int j = lis.size()-1; j > i; j--) {
                if (trains[i] < trains[j]) {
                    lis[i] = max(lis[i], lis[j]+1);
                }
                else if (trains[i] > trains[j]) {
                    lds[i] = max(lds[i], lds[j]+1);
                }
            }
        }
        int maxLength = 0;
        for (int i = 0; i < trains.size(); i++) {
            maxLength = max(maxLength, lis.at(i) + lds.at(i) - 1);
        }
        cout << maxLength << endl;
    }
    return 0;
}