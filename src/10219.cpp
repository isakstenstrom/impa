#include <iostream>
#include <math.h>

using namespace std;


int main() {
    unsigned long long n, k;
    while(scanf("%llu %llu", &n, &k) != EOF) {
        long double sum = 0;
        for (unsigned long long i = n-k+1; i <= n; i++) {
            sum += log10(i);
        }
        for (unsigned long long i = 1; i <= k; i++) {
            sum -= log10(i);
        }
        cout << int(sum) + 1<< endl;
    }
    return 0;
}
