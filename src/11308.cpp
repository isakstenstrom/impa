#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>


using namespace std;

struct recepieCompare {
    bool operator() (const pair<string, int>& lhs, const pair<string, int>& rhs) const {
        if (lhs.second == rhs.second) {
            return lexicographical_compare(lhs.first.begin(), lhs.first.end(), rhs.first.begin(), rhs.first.end());
        }
        return lhs.second<rhs.second;
    }
};

int main() {
    string tmp;
    getline(cin, tmp);
    int T = stoi(tmp);
    for (int t = 0; t < T; t++) {
        string binderName;
        getline(cin, binderName);
        transform(binderName.begin(), binderName.end(), binderName.begin(), ::toupper);
        cout << binderName << endl;
        int M, N, b;
        cin >> M >> N >> b;

        map<string, int> ingredients;

        for (int m = 0; m < M; m++) {
            string ingredient;
            cin >> ingredient;
            int price;
            cin >> price;
            ingredients[ingredient] = price;
            getline(cin, tmp);
        }

        set<pair<string, int>, recepieCompare> recepies;
        for (int n = 0; n < N; n++) {
            string recepieName;
            getline(cin, recepieName);
            getline(cin, tmp);
            int K = stoi(tmp);
            
            int recepiePrice = 0;
            for (int k = 0; k < K; k++) {
                string ingredient;
                cin >> ingredient;
                int amount;
                cin >> amount;
                recepiePrice += ingredients[ingredient] * amount;
                getline(cin, tmp);
            }
            if (recepiePrice <= b) {
                recepies.emplace(recepieName, recepiePrice);
            }
        }
        
        if (recepies.empty()) {
            cout << "Too expensive!" << endl;
        } 
        else {
            for (auto recepie : recepies) {
                cout << recepie.first << endl;
            }
        }

        cout << endl;
    }
    return 0;
}