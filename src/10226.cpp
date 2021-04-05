#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int T;
    cin >> T;
    string junk;
    getline(cin, junk);
    getline(cin, junk);
    for (int t = 0; t < T; t++) {
        if (t != 0) cout << endl;
        int numberOfTrees = 0;
        map<string, int> trees;
        while (true) {
            string tree;
            getline(cin, tree);
            if (tree == "") break;
            trees[tree]++;
            numberOfTrees++;
        }
        for(auto entry : trees) {
            printf("%s %.4f\n", entry.first.c_str(), (100 * entry.second) / (float) numberOfTrees);
        }
    }
    return 0;
}