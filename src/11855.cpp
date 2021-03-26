#include <iostream>
#include <math.h>
#include <set>
#include <algorithm>
#include <string>
#include <map>
#include <sstream>

using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        string str = "";
        string tmpStr;
        istringstream iss(line);
        while (iss >> tmpStr) {
            str += tmpStr;
        }
        for (int wordLength = 1; wordLength <= str.length(); wordLength++) {
            int maxLength = 0;
            map<string, int> occurrences;
            for (int i = 0; i <= str.length() - wordLength; i++) {
                string word = str.substr(i, wordLength);
                maxLength = max(maxLength, ++occurrences[word]);
            }
            if (maxLength > 1) {
                cout << maxLength << endl;
            }
            else {
                cout << endl;
                break;
            }
        }
    }
    return 0;
}