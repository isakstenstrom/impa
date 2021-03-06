#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        unsigned long start = 0;
        unsigned long max_len = 0;
        map<unsigned long, unsigned long> m;
        unsigned long x;
        for (unsigned long i = 1; i <= n; i++) {
            cin >> x;
            if (m.count(x) == 1) {
                start = max(start, m.at(x));
                m.at(x) = i;
            }
            else {
                m.insert(pair<unsigned long, unsigned long>(x, i));
            }
            max_len = max(max_len, i - start);
        }
        cout << max_len << endl;
    }
    return 0;
}