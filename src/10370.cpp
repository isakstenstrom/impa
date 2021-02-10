#include <iostream>
#include <vector>

using namespace std;

int main() {
    int C;
    cin >> C;

    for (int i = 0; i < C; i++) {
        int N;
        cin >> N;

        int grade;
        vector<int> grades;

        double averageGrade = 0;
        for (int j = 0; j < N; j++) {
            cin >> grade;
            grades.push_back(grade);
            averageGrade += grade;
        }
        averageGrade = averageGrade / N;

        int numberOverAverage = 0;
        for (int j = 0; j < N; j++) {
            if (grades.at(j) > averageGrade) numberOverAverage++;
        }

        printf("%2.3f%%\n", 100*numberOverAverage/(double)N);
    }
}