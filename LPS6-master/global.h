//global.h
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
