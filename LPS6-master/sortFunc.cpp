//sortFunc.cpp
#include "global.h"

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