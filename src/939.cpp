#include <iostream>
#include <vector>
#include <map>

using namespace std;


struct Person{
    vector<string> parents;
    string gene = "";
};

string calculateGene(map<string, Person> &pepole, string name) {
    string gene = pepole.at(name).gene;
    if (gene != "") return gene;

    string p1 = calculateGene(pepole, pepole.at(name).parents[0]);
    string p2 = calculateGene(pepole, pepole.at(name).parents[1]);

    if (p1 == "dominant" || p2 == "dominant" || (p1 != "non-existent" && p2 != "non-existent")){
        if ((p1 != "non-existent" && p2 != "non-existent") && (p1 == "dominant" || p2 == "dominant")) {
            pepole.at(name).gene = "dominant";
            return "dominant";
        }
        else {
            pepole.at(name).gene = "recessive";
            return "recessive";
        }
    }
    else {
        pepole.at(name).gene = "non-existent";
        return "non-existent";
    }
}

int main() {
    int N;
    cin >> N;
    map<string, Person> pepole;
    while (N--) {
        string parent, child;
        cin >> parent;
        cin >> child;
        if (child == "non-existent" || child == "recessive" || child == "dominant") {
            pepole[parent].gene = child;
        }
        else {
            pepole[child].parents.push_back(parent);
        }
    }

    for (auto person : pepole) {
        calculateGene(pepole, person.first);
    }
    for (auto person : pepole) {
        cout << person.first << " " << person.second.gene << endl;
    }

    return 0;
}
