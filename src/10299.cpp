#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cstring>

using namespace std;

void getPrimeFactors(set<int> &factors, int n) {
    while (n % 2 == 0) {
        factors.insert(2);
        n = n/2;
    }

    for (int i = 3; i*i <= n; i = i+2) {
        while (n % i == 0) {
            n = n/i;
            factors.insert(i);
        }
    }

    if (n != 1) factors.insert(n);
}

int main() {
    while (true) {
        int n;
        scanf("%d", &n);
        if (n == 0) break;
        else if (n == 1) {
            cout << "0" << endl;
            continue;
        }

        set<int> factors;
        getPrimeFactors(factors, n);

        for (int factor : factors) {
            n -= n / factor;
        }
        cout << n << endl;
    }
    return 0;
}