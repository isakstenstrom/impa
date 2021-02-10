#include <iostream>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

int main() {
    int treeCounter = 0;
    while (true) {
        int depth;
        cin >> depth;
        if (depth == 0) return 0;

        treeCounter++;
        cout << "S-Tree #" << treeCounter << ":" << endl;

        string nodes;
        int *nodeWeight = new int[depth];
        for (int i = 0; i < depth; i++) {
            cin >> nodes;
            nodeWeight[nodes.at(1) - '0' -1] = pow(2, (depth-i-1));
        }

        string terminalNodesValues;
        cin >> terminalNodesValues;

        int VVAs;
        cin >> VVAs;

        for (int i = 0; i < VVAs; i++) {
            string input;
            cin >> input;

            int sum = 0;
            for (int j = 0; j < depth; j++) {
                sum += nodeWeight[j] * (input.at(j) - '0');
            }
            cout << terminalNodesValues.at(sum);
        }
        cout << endl << endl;
        delete nodeWeight;
    }
}