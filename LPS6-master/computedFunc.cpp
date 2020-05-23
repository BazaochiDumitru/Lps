//computedFunc.cpp
#include "global.h"

float Calitate(vector<Students> &array) {
    float calitate = 0, media;
    for (int i = 0; i < array.size(); ++i) {
        media = 0;
        for (auto &note : array[i].note) {
            media += note;
        }
        media = media / 6;
        if (media == 10 || media == 9) {
            calitate++;
        }
    }
    return round((calitate / (array.size()) * 100) * 100) / 100;
}
