// Abdullah Ali GUN 191307005
//
#define yedi 7
#include <iostream>
using namespace std;


//A EV
//B YUNUSELI PARKI
//C AGAC PARKI
//D YONCA CICEKCILIK
//E CIHAN PIDE
//F 23 NISAN
//Z IMKB
int graf[yedi][yedi] = {
    //{A,B,C,D,E,F,Z}
      {0,8,0,0,0,5,3},//A
      {8,0,3,4,3,0,0},//B
      {0,3,0,5,0,0,0},//C
      {0,0,0,0,0,9,0},//D
      {0,0,0,3,0,0,0},//E
      {0,0,0,0,5,0,1},//F
      {0,0,0,0,0,1,0},//Z
};
string int2str(int i) {
    string c;
    switch (i)
    {
    case 0:
        c = "EV              ";
        break;
    case 1:
        c = "YUNUSELI PARKI  ";
        break;
    case 2:
        c = "AGAC PARKI      ";
        break;
    case 3:
        c = "YONCA CICEKCILIK";
        break;
    case 4:
        c = "CIHAN PIDE      ";
        break;
    case 5:
        c = "23 NISAN        ";
        break;
    case 6:
        c = "IMKB            ";
        break;
    default:
        c = "NULL            ";
        break;
    }
    return c;
}
int sayac = 0;
void CozumuYazdir(int uzaklik[], string yol[])
{
    sayac++;
    cout << endl;
    cout << sayac << ".Asama EV'den diger hedeflere en kisa uzaklik\n";
    for (int i = 0; i < yedi; i++)
        cout << int2str(i) << "\t" << uzaklik[i] << "\t" << yol[i]<< endl;
}

int EnKisaUzaklik(int uzaklik[], bool enKisaMi[])
{
    int enKucuk = INT_MAX, enKucukInndex;

    for (int v = 0; v < yedi; v++) {
        if (enKisaMi[v] == false && uzaklik[v] <= enKucuk) {
            enKucuk = uzaklik[v];
            enKucukInndex = v;
        }
    }
    return enKucukInndex;
}
void dijkstra(int baslangic)
{
    int uzaklik[yedi];
    string yol[yedi];
    bool enKisaMi[yedi];
    for (int i = 0; i < yedi; i++) {
        uzaklik[i] = INT_MAX;
        enKisaMi[i] = false;
        yol[i] = "";
    }
    uzaklik[baslangic] = 0;
    int x;

    for (int i = 0; i < yedi - 1; i++) {
        CozumuYazdir(uzaklik, yol);
        x = EnKisaUzaklik(uzaklik, enKisaMi);
        enKisaMi[x] = true;
        for (int y = 0; y < yedi; y++) {
            if (!enKisaMi[y] && graf[x][y] && uzaklik[x] != INT_MAX && uzaklik[x] + graf[x][y] < uzaklik[y]) {
                uzaklik[y] = uzaklik[x] + graf[x][y];
                yol[y] = yol[x] + int2str(x);
            }
        }

    }
    CozumuYazdir(uzaklik, yol);


}

int main()
{
    setlocale(LC_ALL, "Turkish");
    dijkstra(0);
}

