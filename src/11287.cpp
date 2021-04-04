#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool prime(unsigned long long x) {
    for (int i = 2; i*i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

// Copied from https://math.stackexchange.com/questions/195634/how-do-you-calculate-the-modulo-of-a-high-raised-number
unsigned long long modOfPower(unsigned long long base, unsigned long long exponent, unsigned long long modulus) {
    unsigned long long result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}


int main() {
    while (true) {
        unsigned long long q, a, l;
        scanf("%llu %llu", &q, &a);
        if (q == 0 && a == 0) break;

        if (modOfPower(a, q, q) == a && !prime(q)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}