//crudFunc.cpp

#include "global.h"
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
