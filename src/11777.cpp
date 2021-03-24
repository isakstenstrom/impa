#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int Term1, Term2, Final, Attendance, ClassTest1, ClassTest2, ClassTest3;
        scanf("%d %d %d %d %d %d %d", &Term1, &Term2, &Final, &Attendance, &ClassTest1, &ClassTest2, &ClassTest3);
        int score = Term1 + Term2 + Final + Attendance + (ClassTest1 + ClassTest2 + ClassTest3 - min(min(ClassTest1, ClassTest2), ClassTest3)) / 2;
        char grade;
        if (score >= 90) grade = 'A';
        else if (score >= 80) grade = 'B';
        else if (score >= 70) grade = 'C';
        else if (score >= 60) grade = 'D';
        else grade = 'F';
        
        cout << "Case " << t << ": " << grade << endl;
    }
}