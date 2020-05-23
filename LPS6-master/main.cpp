//main.cpp

#include "global.h"

#pragma pack (push, 1)
#pragma pack (pop)

int main() {
    vector<Students> grupa;
    grupa.reserve(100);
    int deletedItem, updatedItem;

    ReadTextFile(grupa);
    cout << "\n" << "\t1. Tabelul citit din students.txt este:" << "\n";
    PrintList(grupa);
    cout << "\n" << "\t2. Tabelul sortat dupa nume este:" << "\n";
    SortByName(grupa);
    WriteBinFile(grupa);
    ReadBinFile();
    cout << "\n" << "\t3. Tabelul sortat dupa data nasterii este:" << "\n";
    SortByDn(grupa);
    WriteBinFile(grupa);
    ReadBinFile();
    cout << "\n" << "\tIntoduceti nr elementului pentru stergere: " << "\n";
    cin >> deletedItem;
    cout << "\n" << "\t4. Tabelul obtinut dupa stergerea elementului sub nr " << deletedItem << " este: " << "\n";
    DeleteElement(grupa, deletedItem - 1);
    WriteBinFile(grupa);
    ReadBinFile();
    /*cout << "\n" << "Procentul calitatii este " << Calitate(grupa) << "\n";*/
    cout << "\n" << "\tIntoduceti nr elementului pentru innoirea datelor unui student: " << "\n";
    cin >> updatedItem;
    UpdateElement(grupa, updatedItem - 1);
    WriteBinFile(grupa);
    cout << "\n" << "\t5. Tabelul obtinut dupa innoirea elementului sub nr " << updatedItem << " este: " << "\n";
    ReadBinFile();
    cout << "\n" << "\tAdaugati un nou element!" << "\n";
    AddElement(grupa);
    cout << "\n" << "\t6. Tabelul final citit din bin.dat este:" << "\n";
    WriteBinFile(grupa);
    ReadBinFile();

    return 1;
}

int toNumber(string word) {
    return atoi(word.c_str());
}

Students ParseLine(vector<Students> &array, string line) {
    int currentWord = 0;
    Students Student;
    string word;
    istringstream stream(line);

    while (stream) {
        stream >> word;

        if (currentWord == 6) Student.id = toNumber(word);
        if (currentWord == 7) Student.nume = word;
        if (currentWord == 8) Student.grupa = word;
        if (currentWord == 9) Student.dataNasterii.zi = toNumber(word);
        if (currentWord == 10) Student.dataNasterii.luna = toNumber(word);
        if (currentWord == 11) Student.dataNasterii.an = toNumber(word);
        if (currentWord == 12) Student.semestrul = toNumber(word);
        if (currentWord < 6)
            for (int i = 0; i < 6; i++)
                Student.note[currentWord] = toNumber(word);

        currentWord++;
    }
    return Student;
}

void SortByName(vector<Students> &array) {
    vector<Students>::iterator i1, i2;
    i1 = array.begin();
    i2 = array.begin();

    for (int i = array.size() - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (array[j].nume > array[j + 1].nume) {
                iter_swap(i1 + j, i2 + j + 1);
            }
        }
    }
}

void SortByDn(vector<Students> &array) {
    vector<Students>::iterator i1, i2;
    i1 = array.begin();
    i2 = array.begin();

    for (int i = array.size() - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (array[j].dataNasterii.an > array[j + 1].dataNasterii.an) {
                iter_swap(i1 + j, i2 + j + 1);
            } else if (array[j].dataNasterii.an == array[j + 1].dataNasterii.an) {
                if (array[j].dataNasterii.luna > array[j + 1].dataNasterii.luna) {
                    iter_swap(i1 + j, i2 + j + 1);
                } else if (array[j].dataNasterii.luna == array[j + 1].dataNasterii.luna) {
                    if (array[j].dataNasterii.zi > array[j + 1].dataNasterii.zi) {
                        iter_swap(i1 + j, i2 + j + 1);
                    }
                }
            }
        }
    }
}

void ReadTextFile(vector<Students> &array) {
    string line;
    array.clear();
    ifstream inputF("students.txt");
    cout << 1;
    while (getline(inputF, line)) {
    	cout << line << endl;
       array.push_back(ParseLine(array, line));
       //cout << array[]
    }
    inputF.close();
}

void WriteBinFile(vector<Students> &array) {
    Students student;
    ofstream fout("bin.dat", ios::binary);
    for (int i = 0; i < array.size(); ++i) {
        fout.write(reinterpret_cast<char *>(&array[i]), sizeof(Students));
    }
    fout.close();
}

void ReadBinFile() {
    Students student;
    vector<Students> vec;

    ifstream ifs("bin.dat", ios::binary);
        while (ifs.read(reinterpret_cast<char *>(&student), sizeof(Students))) {
            vec.push_back(student);
        }
    ifs.close();

    PrintList(vec);
}

void PrintList(vector<Students> &array) {
    for (int i = 0; i < array.size(); ++i) {
        cout << "id: " << array[i].id;
        cout << ", nume: " << array[i].nume;
        cout << ", grupa: " << array[i].grupa;
        cout << ", Data nasterii: ";
        cout << array[i].dataNasterii.zi << ".";
        cout << array[i].dataNasterii.luna << ".";
        cout << array[i].dataNasterii.an;
        cout << ", Semestrul: " << array[i].semestrul;
        cout << ", Note: ";
        cout << array[i].note[0] << ",";
        cout << array[i].note[1] << ",";
        cout << array[i].note[2] << ",";
        cout << array[i].note[3] << ",";
        cout << array[i].note[4] << ",";
        cout << array[i].note[5] << "\n";
    }
}


void DeleteElement(vector<Students> &array, int index) {
    vector<Students>::iterator first;
    first = array.begin();
    array.erase(first + index);

}

void AddElement(vector<Students> &array) {
    int k;
    do {
        Students Student;
        cout << "id: " << "\n";
        cin >> Student.id;
        cout << "Numele: " << "\n";
        cin >> Student.nume;
        cout << "Grupa: " << "\n";
        cin >> Student.grupa;
        cout << "Zi: " << "\n";
        cin >> Student.dataNasterii.zi;
        cout << "Luna: " << "\n";
        cin >> Student.dataNasterii.luna;
        cout << "An: " << "\n";
        cin >> Student.dataNasterii.an;
        cout << "Semestrul: " << "\n";
        cin >> Student.semestrul;
        for (int i = 0; i < 6; i++) {
            cout << "nota nr " << i << "\n";
            cin >> Student.note[i];
        }
        array.push_back(Student);
        cout << "Doriti sa introduceti ceva? " << endl;
        cin >> k;
    } while (k != 0);
}

void UpdateElement(vector<Students> &array, int index) {
    cout << "Numele: " << "\n";
    cin >> array[index].nume;
    cout << "Grupa: " << "\n";
    cin >> array[index].grupa;
    cout << "Zi: " << "\n";
    cin >> array[index].dataNasterii.zi;
    cout << "Luna: " << "\n";
    cin >> array[index].dataNasterii.luna;
    cout << "An: " << "\n";
    cin >> array[index].dataNasterii.an;
    cout << "Semestrul: " << "\n";
    cin >> array[index].semestrul;

    for (int i = 0; i < 6; i++) {
        cout << "nota nr " << i << "\n";
        cin >> array[index].note[i];
    }
}

#ifndef LPS6_PRINT_H
#define LPS6_PRINT_H

#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

struct data {
    int zi;
    int luna;
    int an;
};

struct Students {
    int id;
    string nume;
    string grupa;
    data dataNasterii;
    int semestrul;
    int note[6];
};

int toNumber(string word);

void PrintList(vector<Students> &array);

Students ParseLine(vector<Students> &array, string line);

void UpdateElement(vector<Students> &array, int index);

void SortByName(vector<Students> &array);

void SortByDn(vector<Students> &array);

void ReadTextFile(vector<Students> &array);

void WriteBinFile(vector<Students> &array);

void ReadBinFile();

void AddElement(vector<Students> &array);

void DeleteElement(vector<Students> &array, int index);

float Calitate(vector<Students> &array);

#endif
