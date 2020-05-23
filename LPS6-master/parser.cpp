//parser.cpp

#include "global.h"

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
