#include <iostream>

using namespace std;

int main() {
    unsigned long long x;
    while (scanf("%llu", &x) != EOF) {
        unsigned long long sum = (x * (x + 1) / 2);
        cout << sum*sum << endl;
    }
    return 0;
}