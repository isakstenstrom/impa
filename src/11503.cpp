#include <iostream>
#include <math.h>
#include <vector>
#include <set>
#include <algorithm>
#include <string.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int F;
        cin >> F;

        vector<set<string>> networks;

        for (int f = 0; f < F; f++) {
            string a, b;
            cin >> a;
            cin >> b;

            bool foundNetwork = false;
            int firstNetwork = 0;
            for (int n = 0; n < networks.size(); n++) {
                if (foundNetwork) {
                    if (networks.at(n).count(a) == 1 || networks.at(n).count(b) == 1) {
                        for (auto str : networks.at(n)) {
                            networks.at(firstNetwork).insert(str);
                        }
                        networks.at(n).clear();
                    }
                }
                else {
                    if (networks.at(n).count(a) == 1 || networks.at(n).count(b) == 1) {
                        foundNetwork = true;
                        firstNetwork = n;
                        networks.at(n).insert(a);
                        networks.at(n).insert(b);
                    }
                }             
            }
            if (!foundNetwork) {
                firstNetwork = networks.size();
                networks.emplace_back(set<string>{a, b});
            }
            
            cout << networks.at(firstNetwork).size() << endl;

        }
    }
    return 0;
}   