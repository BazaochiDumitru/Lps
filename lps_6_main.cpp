#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
#include <stdio.h>
#include <string.h>
using namespace std;

void Creare();
void Afisare(char nume[]);
void Adaugare();

void AdaugareZodieNumarPiatra();
void AranjareAlfabetica();
void AranjareZodieNume();
void AranjareGrupaNume();
int GenerareNote(int x[]);
void ListaNume(char sir[]);
void ListaGrupa(char sir[]);
void ListaZodie(int semestru);
void ListaLuna(int l);
void Linia(char sting, char line, char mijloc, char drept);

struct Data
{
    int zi; int luna; int an;
};
struct Student
{
    int id;
    char nume[21];
    Data dn;
    int semes;
    char grupa[12];
    int note[6];
    double media;
};
struct Nod
{
    Student info;
    struct Nod *next;
};

int main()
{
    int optiune;
    char sir[12];
    int semestru;
    int l;
    system("color F0");
    do
    {
        system ("cls");
        cout << "Proiect nr. 6 elaborat de Bazaochi Dumitru" << endl;
        cout << "Aplicarea fisierelor binare: " << endl;
        cout << "1.  De inscris datele dintr-un fisier binar intr-un fisier text." << endl;
        cout << "2.  De afisat continutul fisierului." << endl;
        cout << "3.  De adaugat datele intr-un fisier." << endl;
        cout << "4.  De adaugat denumirea grupei." << endl;
        cout << "5.  Aranjare alfabetica." << endl;
        cout << "6.  Aranjarea dupa semestru." << endl;
        cout << "7.  Cautarea persoanelor dupa nume." << endl;
        cout << "8.  Lista persoanelor dintr-o grupa." << endl;
        cout << "9.  Lista persoanelor nascuti intr-o luna anumita." << endl;
        cout << "0.  Stop " << endl;
        cout << " \n \t Alege (de la 0 la 9) ---> ";
        cin >> optiune;
        switch (optiune)
        {
            case 1: Creare(); break;
            case 2: Afisare("f13_zodiac.in"); break;
            case 3: Adaugare(); break;
            case 4: AdaugareZodieNumarPiatra(); break;
            case 5: AranjareAlfabetica(); Afisare("f13_zodiac1.out"); break;
            case 6: AranjareZodieNume(); Afisare("f13_zodiac2.out"); break;
            case 7:
                printf("Indicati numele: "); fflush(stdin); gets(sir);
                ListaNume(sir);
            break;
            /*case 8:
                printf("Indicati semestrul: "); scanf("%d", semestru); //fflush(stdin); 
                ListaZodie(semestru);
            break;*/
            case 8:
                //AranjareGrupaNume();
                //Afisare("f13_zodiac3.out");
                printf("Indicati numele Grupei: "); fflush(stdin); gets(sir);
                ListaGrupa(sir);
            break;
            case 9:
                printf("Indicati luna: "); scanf("%d", &l);
                ListaLuna(l);
            break;
        }
    } while(optiune);
    return 0;
}

int GenerareNote(int x[]){
    int i = 0;
    while(i < 6){
        x[i] = rand() % 5 + 5;
        i++;
    }
}

void Creare()
{
    ifstream ft;
    ofstream f;
    Student z;
    char prenume[21];
    ft.open("f13_zodiac.txt");
    f.open("f13_zodiac.in", ios::binary);
    while (ft >> z.id >> z.nume >> prenume >> z.dn.zi >> z.dn.luna >> z.dn.an)
    {
        strcat(z.nume, " "); strcat(z.nume, prenume);
        strcpy(z.grupa, " ");
        z.semes = rand() % 2 + 1;
        GenerareNote(z.note);
        z.media =double(z.note[0]+z.note[1]+z.note[2]+z.note[3]+z.note[4]+z.note[5])/(double)6;
        f.write(reinterpret_cast<char*>(&z), sizeof(Student));
    }
    printf("\n Datele sunt citite.");
    getch();
    ft.close();    f.close();
}
void ListaNume(char sir[]) //afiseaza tabelul dupa numele cautat
{
    ifstream f;
    int n = 0;
    Student z;
    f.open("f13_zodiac.in", ios::binary);
    printf("Lista Persoanelor cu numele care incep cu literele %s \n", sir);
    Linia(201, 205, 209, 187);
    printf("%cNr%c ID%c Numele/prenume %cData nast.%cSemestru%c  Grupa %4c  Notele %5cMedia%c\n",
           186, 179, 179, 179, 179, 179, 179, 179, 186);
    Linia(199, 196, 197, 182);
    while (f.read(reinterpret_cast<char*>(&z), sizeof(Student)))
    {
        if (strnicmp(z.nume, sir, strlen(sir)) == 0)
        {
            n++;
            printf("%c%2d%c%3d%c%-16.16s%c%02d.%02d.%4d%c    %d   %c %-10.10s%c %d %d %d %d %d %d %c %.2f%c\n",
                186, n, 179, z.id, 179, z.nume, 179, z.dn.zi, z.dn.luna, z.dn.an,
                179, z.semes, 179, z.grupa, 179, z.note[0], z.note[1],z.note[2],z.note[3],z.note[4],z.note[5], 179, z.media, 186);
        }
    }
    Linia(200, 205, 207, 188);
    fflush(stdin); getch();
    f.close();
}

void ListaGrupa(char sir[]) //afiseaza tabelul dupa numele de grupa cautat
{
    ifstream f;
    int n = 0;
    Student z;
    f.open("f13_zodiac.in", ios::binary);
    printf("Lista Persoanelor cu numele care incep cu literele %s \n", sir);
    Linia(201, 205, 209, 187);
    printf("%cNr%c ID%c Numele/prenume %cData nast.%cSemestru%c  Grupa %4c  Notele %5cMedia%c\n",
           186, 179, 179, 179, 179, 179, 179, 179, 186);
    Linia(199, 196, 197, 182);
    while (f.read(reinterpret_cast<char*>(&z), sizeof(Student)))
    {
        if (strnicmp(z.grupa, sir, strlen(sir)) == 0)
        {
            n++;
            printf("%c%2d%c%3d%c%-16.16s%c%02d.%02d.%4d%c    %d   %c %-10.10s%c %d %d %d %d %d %d %c %.2f%c\n",
                186, n, 179, z.id, 179, z.nume, 179, z.dn.zi, z.dn.luna, z.dn.an,
                179, z.semes, 179, z.grupa, 179, z.note[0], z.note[1],z.note[2],z.note[3],z.note[4],z.note[5], 179, z.media, 186);
        }
    }
    Linia(200, 205, 207, 188);
    fflush(stdin); getch();
    f.close();
}

void ListaLuna(int l) // afiseaza lista dupa luna cautata
{
    ifstream f;
    int n = 0;
    Student z;
    f.open("f13_zodiac.in", ios::binary);
    printf("Lista Persoanelor nascute in luna %d \n", l);
    Linia(201, 205, 209, 187);
    printf("%cNr%c ID%c Numele/prenume %cData nast.%cSemestru%c  Grupa %4c  Notele %5cMedia%c\n",
           186, 179, 179, 179, 179, 179, 179, 179, 186);
    Linia(199, 196, 197, 182);
    while (f.read(reinterpret_cast<char*>(&z), sizeof(Student)))
    {
        if (z.dn.luna == l)
        {
            n++;
            printf("%c%2d%c%3d%c%-16.16s%c%02d.%02d.%4d%c    %d   %c %-10.10s%c %d %d %d %d %d %d %c %.2f%c\n",
                186, n, 179, z.id, 179, z.nume, 179, z.dn.zi, z.dn.luna, z.dn.an,
                179, z.semes, 179, z.grupa, 179, z.note[0], z.note[1],z.note[2],z.note[3],z.note[4],z.note[5], 179, z.media, 186);
        }
    }
    Linia(200, 205, 207, 188);
    fflush(stdin); getch();
    f.close();
}
//Actualizare
void Linia(char sting, char line, char mijloc, char drept) // liniile tabelului
{
    int i;
    printf("%c", sting);
    for (i=1; i<=2; i++) printf("%c",line); printf("%c",mijloc); //nr
    for (i=1; i<=3; i++) printf("%c",line); printf("%c",mijloc); //id
    for (i=1; i<=16; i++) printf("%c",line); printf("%c",mijloc); //nume
    for (i=1; i<=10; i++) printf("%c",line); printf("%c",mijloc); //zi luna an
    for (i=1; i<=8; i++) printf("%c",line); printf("%c",mijloc); //disciplina
    for (i=1; i<=11; i++) printf("%c",line); printf("%c",mijloc); //disciplina
    for (i=1; i<=13; i++) printf("%c",line); printf("%c",mijloc); //inaltime
    for (i=1; i<=5; i++) printf("%c",line); printf("%c",drept); //categorie
    printf("\n");
}
void Afisare(char nume[])
{
    ifstream f;
    int n = 0;
    Student z;
    f.open(nume, ios::binary);
    printf("Lista Persoanelor \n");
    Linia(201, 205, 209, 187);
    printf("%cNr%c ID%c Numele/prenume %cData nast.%cSemestru%c  Grupa %4c  Notele %5cMedia%c\n",
           186, 179, 179, 179, 179, 179, 179, 179, 186);
    Linia(199, 196, 197, 182);
    while (f.read(reinterpret_cast<char*>(&z), sizeof(Student)))
    {
        n++;
        printf("%c%2d%c%3d%c%-16.16s%c%02d.%02d.%4d%c    %d   %c %-10.10s%c %d %d %d %d %d %d %c %.2f%c\n",
        186, n, 179, z.id, 179, z.nume, 179, z.dn.zi, z.dn.luna, z.dn.an,
        179, z.semes, 179, z.grupa, 179, z.note[0], z.note[1],z.note[2],z.note[3],z.note[4],z.note[5], 179, z.media, 186);
    }
    Linia(200, 205, 207, 188);
    fflush(stdin); getch();
    f.close();
}
int GenerareCodZodiac(int z, int l)
{
    int k;
    switch(l)
    {
        case 1: if(z<20) k = 10; else k = 11; break;
        case 2: if(z<19) k = 11; else k = 12; break;
        case 3: if(z<21) k = 12; else k = 1; break;
        case 4: if(z<20) k = 1; else k = 2; break;
        case 5: if(z<21) k = 2; else k = 3; break;
        case 6: if(z<21) k = 3; else k = 4; break;
        case 7: if(z<23) k = 4; else k = 5; break;
        case 8: if(z<23) k = 5; else k = 6; break;
        case 9: if(z<23) k = 6; else k = 7; break;
        case 10: if(z<23) k = 7; else k = 8; break;
        case 11: if(z<22) k = 8; else k = 9; break;
        case 12: if(z<22) k = 9; else k = 10; break;
    }
    return k;
}
void Adaugare() // adauga un student nou
{
    fstream f;
    Student z;
    f.open("f13_zodiac.in", ios::binary | ios::app);
    printf("Dati numele urmatoarei persoane: ");
    fflush(stdin); gets(z.nume);
    while (strlen(z.nume) > 0)
    {
        printf("ID Persoanei: "); scanf("%d", &z.id);
        printf("Data nasterii: "); scanf("%d %d %d", &z.dn.zi, &z.dn.luna, &z.dn.an);
        strcpy(z.grupa, " ");
        z.semes = rand() % 2 + 1;
        GenerareNote(z.note);
        z.media =double(z.note[0]+z.note[1]+z.note[2]+z.note[3]+z.note[4])/(double)5;
        f.write(reinterpret_cast<char*>(&z), sizeof(Student));
        printf("Dati numele urmatoarei persoane: ");
        fflush(stdin); gets(z.nume);
    }
    f.close();
}

void AdaugareZodieNumarPiatra() // adauga grupa studentilor
{
    fstream f;
    int i, k, n = 0;
    Student z;
    f.open("f13_zodiac.in", ios::binary | ios::out | ios::in);
    long ofset = f.tellg();
    while (f.read(reinterpret_cast<char*>(&z), sizeof(Student)))
    {
        k = GenerareCodZodiac(z.dn.zi, z.dn.luna);
        switch(k)
        {
            case 1: strcpy(z.grupa, "IS11Z");break;
            case 2:  strcpy(z.grupa, "MI11Z"); break;
            case 3: strcpy(z.grupa, "TP11Z"); break;
            case 4:  strcpy(z.grupa, "CP11Z"); break;
            case 5: strcpy(z.grupa, "DU11Z"); break;
            case 6: strcpy(z.grupa, "RT11Z"); break;
            case 7: strcpy(z.grupa, "UV11Z"); break;
            case 8:  strcpy(z.grupa, "IM11Z"); break;
            case 9: strcpy(z.grupa, "TU11Z"); break;
            case 10:  strcpy(z.grupa, "RU11Z"); break;
            case 11: strcpy(z.grupa, "VI11Z"); break;
            case 12: strcpy(z.grupa, "FG11Z"); break;
        }
        f.seekg(ofset);
        f.write(reinterpret_cast<char*>(&z), sizeof(Student));
        ofset = f.tellg();
        f.seekg(ofset);
    }
    printf("\n S-au generat datele!"); getch();
    f.close();
}
void AranjareAlfabetica() // aranjeaza studentii in ordine arfabetica dupa nume
{
    ifstream f;
    ofstream g;
    int n = 0;
    Student z;
    f.open("f13_zodiac.in", ios::binary);
    g.open("f13_zodiac1.out", ios::binary);
    Nod *prim, *ultim, *curent, *nou, *prec;
    f.read(reinterpret_cast<char*>(&z), sizeof(Student));
    prim = new Nod;
    prim->info = z;    prim->next = 0;
    ultim = prim;
    while (f.read(reinterpret_cast<char*>(&z), sizeof(Student)))
    {
        nou = new Nod;
        nou->info = z;
        if(stricmp(z.nume, prim->info.nume) < 0)
            {
                nou->next = prim;
                prim = nou;
            }
        else
        {
            prec = prim;
            for(curent = prim->next; curent && (stricmp(z.nume, curent->info.nume) > 0);
                curent = curent->next)
                    prec = curent;
            if(curent)
            {
                nou->next = curent;
                prec->next = nou;
            }

            else // adaug la sfirsit
            {
                nou->next = 0;
                ultim->next = nou;
                ultim = nou;
            }
        }
    }
    for(curent = prim; curent; curent = curent->next)
    {
        z = curent->info;
        g.write(reinterpret_cast<char*>(&z), sizeof(Student));
    }
    printf("Lista este aranjata. Apasa orice tasta pentru a continua.");
    getch();
    f.close();    g.close();
}
void AranjareZodieNume() //aranjeaza dupa semestru
{
    ifstream f;
    ofstream g;
    int n = 0, aux;
    Student z;
    f.open("f13_zodiac.in", ios::binary);
    g.open("f13_zodiac2.out", ios::binary);
    char sp1[40], sp2[40], spp[40];
    Nod *prim, *ultim, *curent, *nou, *prec;
    f.read(reinterpret_cast<char*>(&z), sizeof(Student));
    prim = new Nod;
    prim->info = z;    prim->next = 0;
    ultim = prim;
    while (f.read(reinterpret_cast<char*>(&z), sizeof(Student)))
    {
        nou = new Nod;
        nou->info = z;
        
        if(nou->info.semes < prim->info.semes)
            {
                nou->next = prim; prim = nou;
            }
        else
        {
            prec = prim; curent = prim->next;

            while(curent && (nou->info.semes > curent->info.semes))
            {
                 prec = curent;
                 curent = curent->next;
                 
            }
            if(curent)
            {
                nou->next = curent; prec->next = nou;
            }
            else // adaug la sfirsit
            {
                nou->next = 0;
                ultim->next = nou;
                ultim = nou;
            }
        }
    }
    for(curent = prim; curent; curent = curent->next)
    {
        z = curent->info;
        g.write(reinterpret_cast<char*>(&z), sizeof(Student));
    }
    printf("Lista este aranjata. Apasa orice tasta pentru a continua.");
    getch();
    f.close(); g.close();
}

void AranjareGrupaNume() // aranjeaza grupele studentilor in ordine alfabetica
{
    ifstream f;
    ofstream g;
    int n = 0, aux;
    Student z;
    f.open("f13_zodiac.in", ios::binary);
    g.open("f13_zodiac3.out", ios::binary);
    char sp1[40], sp2[40], spp[40];
    Nod *prim, *ultim, *curent, *nou, *prec;
    f.read(reinterpret_cast<char*>(&z), sizeof(Student));
    prim = new Nod;
    prim->info = z;    prim->next = 0;
    ultim = prim;
    while (f.read(reinterpret_cast<char*>(&z), sizeof(Student)))
    {
        nou = new Nod;
        nou->info = z;
        sprintf(sp1, "%s %s", z.grupa, z.nume);
        sprintf(spp, "%s %s", prim->info.grupa, prim->info.nume);
        if(stricmp(sp1, spp) < 0)
            {
                nou->next = prim; prim = nou;
            }
        else
        {
            prec = prim; curent = prim->next;
            if(curent)
                sprintf(sp2, "%s %s", curent->info.grupa, curent->info.nume);
            while(curent && (stricmp(sp1, sp2) > 0))
            {
                 prec = curent;
                 curent = curent->next;
                 if(curent)
                    sprintf(sp2, "%s %s", curent->info.grupa, curent->info.nume);
            }
            if(curent)
            {
                nou->next = curent; prec->next = nou;
            }
            else // adaug la sfirsit
            {
                nou->next = 0;
                ultim->next = nou;
                ultim = nou;
            }
        }
    }
    for(curent = prim; curent; curent = curent->next)
    {
        z = curent->info;
        g.write(reinterpret_cast<char*>(&z), sizeof(Student));
    }
    printf("Lista este aranjata. Apasa orice tasta pentru a continua.");
    getch();
    f.close(); g.close();
}

/*void ListaZodie(int semestru) // afiseaza tabelul dupa semestrul indicat
{
    /*ifstream f;
    int n = 0;
    Student z;
    f.open("f13_zodiac.in", ios::binary);
    printf("Lista Persoanelor cu semestrul in care au primit bursa %d \n", semestru);
    Linia(201, 205, 209, 187);
    printf("%cNr%c ID%c Numele/prenume %cData nast.%cSemestru %c  Grupa %4c  Notele %3cMedia%c\n",
           186, 179, 179, 179, 179, 179, 179, 179, 186);
    Linia(199, 196, 197, 182);
    cout << 1;
    while (f.read(reinterpret_cast<char*>(&z), sizeof(Student)))
    {
        if (z.semes == semestru)
        {
            n++;
            printf("%c%2d%c%3d%c%-16.16s%c%02d.%02d.%4d%c %d%c %-10.10s%c %d%c %.2f %c\n",
                186, n, 179, z.id, 179, z.nume, 179, z.dn.zi, z.dn.luna, z.dn.an,
                179, z.semes, 179, z.grupa, 179, z.note, 179, z.media, 186);
        }
    }
    Linia(200, 205, 207, 188);
    fflush(stdin); getch();
    f.close();
    
    ifstream f;
    int n = 0;
    Student z;
    f.open("f13_zodiac.in", ios::binary);
    printf("Lista Persoanelor cu semestrul in care au primit bursa %d \n", semestru);
    Linia(201, 205, 209, 187);
    printf("%cNr%c ID%c Numele/prenume %cData nast.%cSemestru%c  Grupa %4c  Notele %5cMedia%c\n",
           186, 179, 179, 179, 179, 179, 179, 179, 186);
    Linia(199, 196, 197, 182);
    while (f.read(reinterpret_cast<char*>(&z), sizeof(Student)))
    {
    	if (z.semes == semestru)
    	{
		
        n++;
        printf("%c%2d%c%3d%c%-16.16s%c%02d.%02d.%4d%c    %d   %c %-10.10s%c %d %d %d %d %d %d %c %.2f%c\n",
        186, n, 179, z.id, 179, z.nume, 179, z.dn.zi, z.dn.luna, z.dn.an,
        179, z.semes, 179, z.grupa, 179, z.note[0], z.note[1],z.note[2],z.note[3],z.note[4],z.note[5], 179, z.media, 186);
    }
    }
    Linia(200, 205, 207, 188);
    fflush(stdin); getch();
    f.close();
}*/
