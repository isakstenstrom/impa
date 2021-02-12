#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int m;
    scanf("%d", &m);
    
    for (; m > 0; m--) {
        int n;
        scanf("%d", &n);

        vector<int> vec;
        vec.reserve(50);
        int k = 2;
        while (n >= 0) {
            vec.push_back(k);
            n -= k;
            k++;
        }

        if (n == -1) {
            vec.erase(vec.begin());
            vec.pop_back();
            vec.push_back(k);
        }

        for (int i = 0; i < vec.size(); i++) {
            if (vec.at(i) == abs(n)) {
                vec.erase(vec.begin() +i);
            }
        }
        
        for (int i = 0; i < vec.size(); i++) {
            cout << vec.at(i);
            if (i < vec.size() -1) cout << " ";
        }
        
        cout << endl;
        if (m != 1) cout << endl;   
    }
    return 0;
}