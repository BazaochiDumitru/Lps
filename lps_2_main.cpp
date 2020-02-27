#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#define MAX 2147483647

using namespace std;

int Politicoase(int n);
int intervalPoliticoase(int from, int to);
int maxPoliticoase(int n);

int main()
{
    int from, to;
    int key;
    int number = 0;
    int n;
    int counter = 0;
    do
    {
        system("cls");
        cout << endl << "\tProiect numarul 2 elaborat de Bazaochi Dumitru"<< endl << endl;
        cout << "1 - De verificat daca numarul este Politicos" << endl;
        cout << "2 - De afisat toate numerele politicoase dintr-un interval " << endl;
        cout << "3 - De afisat primele n numere Politicoase " << endl;
        cout << "4 - De afisat cel mai mare numar " << endl;
        cout << "0 - Stop" << endl;
        cout << endl << "Alegeti o varianta ";
        cin >> key;

        switch (key)
        {
            case 1:
                cout << "\nIntroduceti un numar: ";
                cin >> number;
                if (!Politicoase(number))
                    cout << "Nu ";
                cout << "- este un numar Politicos" << endl;
                _getch();
                break;
            case 2:
                do {
                    cout << endl << "Dati inceputul intervalului (from) ";
                    cin >> from;
                    cout << "Dati sfarsitul intervalului (to) ";
                    cin >> to;
                } while (from > to);
                cout << "Toate numerele politicoase din interval sunt: " << endl;
                counter = intervalPoliticoase(from, to);
                cout << endl << "Sunt " << counter << " de numere Politicoase" << endl;
                _getch();
                break;
            case 3:
                number = 0;
                counter = 0;
                cout << endl <<  "Introduceti cate numere doriti sa afisati ";
                cin >> n;
                do
                {
                    if (Politicoase(number))
                    {
                        cout << number << " ";
                        counter++;
                    }
                    number++;
                } while (counter < n);
                _getch();
                break;
            case 4:
                cout << endl << "Numarul Politicos maxim este: ";
                maxPoliticoase(MAX);
                cout << endl;
                _getch();
                break;
            default:
                cout << "Eroare in sistem. Mai incercati o data" << endl;
                _getch();
                break;
        }
    } while (key != 0);
}

int Politicoase(int n)
{
    int s, i, k;
    for (k = 0; k <= n / 2; k++)
    {
        for (s = k, i = k + 1; s < n; i++)
            s += i;
        if (s == n)
            return 1;
    }
    return 0;
}

int intervalPoliticoase(int from, int to)
{
    int n = 0;
    for (from; from < to; from++)
    {
        if (Politicoase(from))
            cout << from << " ";
        n++;
    }
    return n;
}

int maxPoliticoase(int n) {
    for (int from = n; from >= 1; from--) {
        if (Politicoase(from))
        {
            cout << from << " ";
            return 0;
        }
    }
}
