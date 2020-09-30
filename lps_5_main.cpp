#include <iostream>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define NMAX 101
using namespace std;
// interfata programului
void AfisareFisiser(char fnume[]);
int NrCuvinte(char fraza[]);
int Palindrom(char cuvint[]);
int CuvintePalindroame(char fraza[]);
int CuvinteLungimeMic5(char fraza[]);
int NrCuvinte();
int CuvintePalindroame();
int CuvinteLungimeMic5();
char *Cautare(char fraza[]);
int ScrieFisierPalindrom();
void Sters_Cuvintele(char fraza[]);
int StergeFisierPalindrom();
int main()
{
    int key;

	FILE *f;
    char fraza[NMAX] = "vremea cu ANNNA trece,vremea vine cu cazac, doar amintirea, ea cu noi ramine";
    do					/*vremea cu ANNNA trece,vremea vine cu cazac si CAZAC, doar amintirea lui cazac, ea cu noi ramine.*/
    {					/*cu trece vremea vine cu cazac doar amintirea ea cu noi ramine*/
        system("cls");
        int b= 5;
        b--;
        cout << "b=" << b;
        cout << "\tProiect nr. 5 elaborat de Bazaochi Dumitru!" << endl;
        cout << "\tTema: Siruri de caractere. Fisiere text \n";
        cout << "\n 1. Nr. de cuvinte dintr-o fraza";
        cout << "\n 2. Nr. de cuvinte palindroame dintr-o fraza";
        cout << "\n 3. Nr. de cuvinte lung < 5 dintr-o fraza";
        cout << "\n 4. Nr. de cuvinte dintr-un fisier";
        cout << "\n 5. Nr. de cuvinte palindroame dintr-un fisier";
        cout << "\n 6. Nr. de cuvinte lung < 5 dintr-un fisier";
        cout << "\n 7. Nr. de cuvinte palindroame dintr-un fisier in alt fisier";
        cout << "\n 8. De sters cuvintele palindroame dintr-un fisier ";
        cout << "\n 0. Stop";
        cout << "\n\n\t Alege (de la 0 la 9) => ";
        cin >> key;
        switch(key)
        {
            case 1:
            	cout << "Dati fraza: " << endl;
                fflush(stdin);
				gets(fraza);
                cout << "\n\tFraza este: " << endl;
                puts(fraza);
                cout << "\n  Fraza contine " << NrCuvinte(fraza) << " cuvinte";
                getch();
                break;
            case 2:
                //gets(fraza);
                cout << "\n\tFraza este: " << endl;
                puts(fraza);
                cout << "\n  Fraza contine " << CuvintePalindroame(fraza) << " cuvinte palindroame";
                getch();
                break;
            case 3:
                //gets(fraza);
                cout << "\n\tFraza este: " << endl;
                puts(fraza);
                cout << "\n  Fraza contine " << CuvinteLungimeMic5(fraza) << " cuvinte de lungime < 5";
                getch();
                break;
            case 4:
                //gets(fraza);
                cout << "\n\tContinutul din fisier este: " << endl;
                AfisareFisiser("dimainput.txt");
                cout << "\n\n  Fisierul contine " << NrCuvinte() << " cuvinte";
                getch();
                break;
            case 5:
                //gets(fraza);
                cout << "\n\tContinutul din fisier este: " << endl;
                AfisareFisiser("dimainput.txt");
                cout << "\n  Fisierul contine " << CuvintePalindroame() << " cuvinte palindroame";
                _getch();
                break;
            case 6:
            	cout << "\n\tContinutul din fisier este: " << endl;
                AfisareFisiser("dimainput.txt");
                cout << "\n Fisierul contine " << CuvinteLungimeMic5() << " cuvinte de lungime < 5";
                getch();
                break;
            case 7:
            	cout << "\n\tContinutul din fisier este: " << endl;
                AfisareFisiser("dimainput.txt");
            	cout << "\n Cuvintele palindroame din fisierul dimainput.txt sunt: " << endl;
                ScrieFisierPalindrom();
                cout << "\n Cuvintele palindroame copiate in alt fisier dimaoutput.txt sunt: " << endl;
                AfisareFisiser("dimaoutput.txt");
                getch();
                break;
            case 8:
            	cout << "De sters cuvintele dintr-un fisier text, care satisfac conditia de palindrom." << endl;
        		cout << "\n\tContinut fisier: " << endl;
                AfisareFisiser("dimainput.txt");
            	StergeFisierPalindrom();
            	cout << "\n\tRezultatul\n";
            	AfisareFisiser("dima.out");
                getch();
                break;
        }
    }
    while(key);
    return 0;
}
void AfisareFisiser(char fnume[])
{
    FILE *f = fopen(fnume, "r");
    char fraza[NMAX];
    while(fgets(fraza, NMAX-1, f) != NULL)
        printf("%s", fraza);
    fclose(f);
}

int NrCuvinte(char fraza[])
{
    char copia[NMAX];
    char *cuvint;
    int n = 0;
    strcpy(copia, fraza);
    if((cuvint = strtok(copia, " ,.:;\n")) ==  NULL) return 0;
    n = 1;
    while((cuvint = strtok(NULL, " ,.:;\n")) !=  NULL)
        n++;
    return n;
}
int Palindrom(char cuvint[])
{
    char revers[21];
    strcpy(revers, cuvint);
    strrev(revers);
    return (strcmp(cuvint, revers) == 0);
}

int CuvintePalindroame(char fraza[])
{
    char copia[NMAX];
    char *cuvint;
    int n = 0;
    strcpy(copia, fraza);
    if((cuvint = strtok(copia, " ,.:;\n")) ==  NULL) return 0;
    if(Palindrom(cuvint))
    {
        n = 1; puts(cuvint);
    }
    while((cuvint = strtok(NULL, " ,.:;\n")) !=  NULL)
    {
        if(Palindrom(cuvint))
        {
            puts(cuvint); n++;
        }

    }
    return n;
}

int CuvinteLungimeMic5(char fraza[])
{
    char copia[NMAX];
    char *cuvint;
    int n = 0;
    strcpy(copia, fraza);
    if((cuvint = strtok(copia, " ,.:;\n")) ==  NULL) return 0;
    if(strlen(cuvint) <= 5)
    {
            puts(cuvint);
            n = 1;
    }
    while((cuvint = strtok(NULL, " ,.:;\n")) !=  NULL)
        if(strlen(cuvint) <= 5)
        {
            puts(cuvint);
            n++;
        }
    return n;
}

int NrCuvinte()
{
    FILE *f;
    char fraza[NMAX];
    int n = 0;
    f = fopen("dimainput.txt", "r");
    while(fgets(fraza, NMAX-1, f) != NULL)
        n += NrCuvinte(fraza);
    return n;
}

int CuvintePalindroame()
{
	FILE *f;
    char fraza[NMAX];
    int n = 0;
    f = fopen("dimainput.txt", "r");
    while(fgets(fraza, NMAX-1, f) != NULL)
        n += CuvintePalindroame(fraza);
    return n;
}
int CuvinteLungimeMic5()
{
	FILE *f;
    char fraza[NMAX];
    int n = 0;
    f = fopen("dimainput.txt", "r");
    while(fgets(fraza, NMAX-1, f) != NULL)
        n += CuvinteLungimeMic5(fraza);
    return n;
}
char *Cautare(char fraza[])
{
    char copia[NMAX];
    char *cuvint;
    int n = 0;
    strcpy(copia, fraza);
    if((cuvint = strtok(copia, " ,.:;\n")) ==  NULL) return 0;
    if(Palindrom(cuvint))
        return cuvint;
    while((cuvint = strtok(NULL, " ,.:;\n")) !=  NULL)
        if(Palindrom(cuvint))
            return cuvint;
    return NULL;
}
int ScrieFisierPalindrom()
{
    int l, poz;
    char fraza[NMAX];
    char *p, *cuvint, cuv[20];
    FILE *f, *fout;
    f = fopen("dimainput.txt", "r");
    fout = fopen("dimaoutput.txt", "w");
    while(fgets(fraza, NMAX-1, f) != NULL)
        while(cuvint = Cautare(fraza))
    {
        strcpy(cuv, cuvint);
        puts(cuv);
        fputs(cuv, fout);
        fputs("\n", fout);
        p = strstr(fraza, cuv);
        poz = p - fraza;
        l = strlen(cuv);
        strcpy(&fraza[poz], &fraza[poz+l]);

    }
    fclose(f);
    fclose(fout);
    return 0;
}

int StergeFisierPalindrom()
{
    char fraza[NMAX];
   int l, poz;
    char *p, *cuvint;
    FILE *fin, *fout;
    fin = fopen("dimainput.txt", "r");
    fout = fopen("dima.out", "w");
    while(fgets(fraza, NMAX-1, fin) != NULL)
    {
        while(cuvint = Cautare(fraza))
        {
            p = strstr(fraza, cuvint);
            poz = p - fraza;
            l = strlen(cuvint);
            strcpy(&fraza[poz], &fraza[poz+l]);
        }
        fputs(fraza, fout);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
