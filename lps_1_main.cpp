#include <iostream>
#include <iomanip>
#define NMAX 2147483647
using namespace std;

int main()
{
    int n = 10;
    int varsta;
    int maxim = 0, minim = 150, decalaj;
    float media = 0;
    int mici = 0, medii = 0, mari = 0;
    int copii = 0, adolescenti = 0, maturi = 0;
    int compareNumber;
    cout << "Project number 1 created by Bazaochi Dumitru. \n" << endl;
    cout << " \t Tema: Varstele persoanelor dintr-o familie." << endl;
    minim = NMAX;
    maxim = 0;

    cout << "Dati o valoare de comparare : ";
    cin >> compareNumber;

    for ( int i = 1; i <= n; i++)
    {
        do {
        cout << "Varsta cu nr " << i << " : ";
        cin >> varsta;
        }
        while (varsta <=0);

        media += varsta;

        if (varsta > maxim)
            maxim = varsta;
        if (varsta < minim)
            minim = varsta;
        if (varsta > compareNumber)
        {
            mari++;
        }
        else if (varsta < compareNumber)
        {
            mici++;
        }
        else
        {
            medii++;
        }

        if (varsta > 20)
        {
            maturi++;
        }
        else if (varsta > 19 && varsta <= 20)
        {
            adolescenti++;
        }
        else
        {
            copii++;
        }
    }

    media /= n;
    decalaj = maxim - minim;
    cout << "Media varstelor membrilor familiei este : " << setprecision(4) << media << "\n";
    cout << "Varsta maxima este : " << maxim << "\n";
    cout << "Varsta minima este : " << minim << "\n";
    cout << "Decalajul dintre maxim si minim este : " << decalaj << "\n";
    cout << "Membri cu varsta pana la 20 sunt : " << mici << "\n";
    cout << "Membri cu varsta egala cu 20 sunt : " << medii << "\n";
    cout << "Membri cu varsta dupa 20 sunt : " << mari << "\n";
    cout << "Maturi sunt: " << maturi << "\n";
    cout << "Adolescenti sunt: " << adolescenti << "\n";
    cout << "Copii sunt: " << copii << "\n";
    return 0;

}
