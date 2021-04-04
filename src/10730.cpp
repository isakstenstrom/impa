#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <unordered_set>

using namespace std;


int main() {
    while (true) {
        int N;
        scanf("%d", &N);
        if (N == 0) break;
        scanf(":");
        vector<int> numbers;
        numbers.reserve(N);
        unordered_set<int> badNumbers;
        bool antiAritmetic = true;
        for (int i = 0; i < N; i++)
        {
            int n;
            scanf("%d", &n);
            if (antiAritmetic) {
                if (badNumbers.count(n) == 1) {
                    antiAritmetic = false;
                }
                
                for (int num : numbers) {
                    badNumbers.insert(2*n -num);
                }
                numbers.push_back(n);
            }
        }
        if (antiAritmetic) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}