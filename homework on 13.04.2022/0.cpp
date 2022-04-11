//0 задание (сортировка)
#include <iostream>
#include <tuple>
#include <string>
#include <fstream>
#include<iomanip>

using namespace std;

class Student
{
public:
    //Student();
    int operator[](int a);
    bool readFromFile(ifstream& fin);
    bool writeToFile(ofstream& fout);
private:
    string name, surname, secondName;
    int birthYear;
    int marks[5];
    double midMark;
    friend void selectionSort(Student* a, int n);
    friend bool comp(Student s1, Student s2);
};

int Student::operator[](int a)
{
    return marks[a];
}

bool Student::readFromFile(ifstream& fin)
{
    fin >> surname >> name >> secondName >> birthYear;
    midMark = 0;
    for (int i = 0; i < 5; i++) {
        fin >> marks[i];
        midMark += marks[i];
    }
    midMark /= 5;
    return true;
}

bool Student::writeToFile(ofstream& fout)
{
    fout << surname << ' ' << name << ' ' << secondName << ' ' << birthYear << ' ';
    for (int i = 0; i < 5; i++)
        fout << marks[i] << ' ';
    fout <<fixed<< midMark<<'\n';
    return true;
}



void selectionSort(Student* a, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (comp(a[j],a[i]))
                swap(a[i], a[j]);
}

bool comp(Student s1, Student s2) {
    return make_tuple(-s1.midMark, s1.birthYear, s1.surname, s1.name, s1.secondName) 
           < make_tuple(-s2.midMark, s2.birthYear, s2.surname, s2.name, s2.secondName);
}

int main()
{
    int group, n;
    ifstream fin("input.txt");
    fin >> n;
    Student* arr = new Student[n];
    Student temp;
    for (int i = 0; i < n; i++) {
        temp.readFromFile(fin);
        arr[i] = temp;
    }
    fin.close();
    selectionSort(arr, n);
    ofstream fout("output.txt");
    for (int i = 0; i < n; i++) {
        arr[i].writeToFile(fout);
    }
    fout.close();
    cout << "Success!";
}
