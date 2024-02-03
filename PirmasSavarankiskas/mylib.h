#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int minimum(int a, int b);

void bufer_nusk(std::string read_vardas, std::string write_vardas);

class Student {
    std::string Name, Surname;
    std::vector<int> HW;
    int Exam;
    float Rez;

public:
    Student();
    Student(string N, string S, vector<int> H, int E);
    Student& operator=(const Student& A);
    Student(const Student& A);
    ~Student();

    float Med() const;
    float Vid() const;

    float GetRez() const { return Rez; }
    float GetExam() const { return Exam; }
    const vector<int>& GetHW() const { return HW; }

    void Rezult(char pas);

    inline void SetName(string N) { Name = N; };
    inline void SetSurname(string S) { Surname = S; };
    inline void SetHW(vector<int> Vec) { HW = Vec; };
    inline void SetExam(int n) { Exam = n; };

    void printas();

    friend std::ostream& operator<<(std::ostream& out, const Student& A);
    friend std::istream& operator>>(std::istream& in, Student& a);

    inline string GetName() const { return Name; }
    inline string GetSurname() const { return Surname; }
};