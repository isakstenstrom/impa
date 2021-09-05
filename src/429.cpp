#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

const string ALPHABET  = "abcdefghijklmnopqrstuvwxyz1234567890";

void findNeighbours(const string& word, vector<string>& neighbours, unordered_set<string>& dictionary) {
    for (int i = 0; i < word.size(); i++) {
        string workingWord = word;
        for (int j = 0; j < ALPHABET.size(); j++) {
            workingWord[i] = ALPHABET[j];

            if (dictionary.count(workingWord)){
                neighbours.push_back(workingWord);
            }
        }
    }
}

int wordChain(const string& w1, const string& w2, unordered_set<string>& dictionary) {
    unordered_set<string> usedWords = {w1};
    queue<pair<string, int>> q;
    q.emplace(w1, 0);

    while (!q.empty()) {
        string word = q.front().first;
        int hops = q.front().second;
        q.pop();
        if (word == w2) {
            return hops;
        } else {
            vector<string> neighbours;
            findNeighbours(word, neighbours, dictionary);
            for (auto neighbour : neighbours) {
                if (!usedWords.count(neighbour)) {
                    usedWords.insert(neighbour);
                    q.emplace(neighbour, hops +1);
                }
            }
        }
    }
    return 0;
}

int main() {
    string tmp;
    getline(cin, tmp);
    int N = stoi(tmp);
    getline(cin, tmp);
    for (int n = 0; n < N; n++) {
        unordered_set<string> dictionary;
        while (true) {
            string word;
            getline(cin, word);
            if (word == "*") break;
            dictionary.insert(word);
        }

        while (true) {
            tmp = "";
            getline(cin, tmp);
            if (tmp == "") break;
            string word1, word2;
            int delim = tmp.find(' ');
            word1 = tmp.substr(0, delim);
            word2 = tmp.substr(delim +1, tmp.length() - delim -1);
            int steps = wordChain(word1, word2, dictionary);
            cout << word1 << " " << word2 << " " << steps << endl;
        }
        if (n < N -1) cout << endl;
    }
    return 0;
}

