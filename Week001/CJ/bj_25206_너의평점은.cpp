#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main()
{
    // fastcpp;
    map<string,double> gradeToMark;
    string subjectName = "";
    double inputGrade = 0.0;
    string mark = "";
    double grade = 0.0;
    double average = 0.0;

    gradeToMark["A+"] = 4.5;
    gradeToMark["A0"] = 4.0;
    gradeToMark["B+"] = 3.5;
    gradeToMark["B0"] = 3.0;
    gradeToMark["C+"] = 2.5;
    gradeToMark["C0"] = 2.0;
    gradeToMark["D+"] = 1.5;
    gradeToMark["D0"] = 1.0;
    gradeToMark["F"]  = 0.0;

    for(int index = 0; index < 20; index++)
    {
        cin >> subjectName >> inputGrade >> mark;
        if (mark != "P")
        {
            grade += inputGrade;
            average += inputGrade * gradeToMark[mark];
        }
    }
    
    cout << average / grade;
}

