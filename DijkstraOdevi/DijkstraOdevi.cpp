// Abdullah Ali GÜN 191307005
//
#define alti 6
#include <iostream>
using namespace std;



int graf[alti][alti] = {
  //{A ,B ,C ,D ,E ,Z }
    {0 ,4 ,2 ,0 ,0 ,0 },//A
    {4 ,0 ,1 ,5 ,0 ,0 },//B
    {2 ,1 ,0 ,8 ,10,0 },//C
    {0 ,5 ,8 ,0 ,2 ,6 },//D
    {0 ,0 ,10,2 ,0 ,3 },//E
    {0 ,0 ,0 ,6 ,3 ,0 },//Z
};
string int2str(int i) {
    string c;
    switch (i)
    {
    case 0:
        c = "A";
        break;
    case 1:
        c = "B";
        break;
    case 2:
        c = "C";
        break;
    case 3:
        c = "D";
        break;
    case 4:
        c = "E";
        break;
    case 5:
        c = "Z";
        break;
    default:
        c = "NULL";
        break;
    }
    return c;
}
void CozumuYazdir(int uzaklik[],string yol[])
{
    cout << endl;
    cout <<"A'dan di?er hedeflere en kisa uzaklik\n";
    for (int i = 0; i < alti; i++)
        cout << int2str(i) << "\t" << uzaklik[i] << "\t" << yol[i] << endl;
}

int EnKisaUzaklik(int uzaklik[], bool enKisaMi[])
{
    int enKucuk = INT_MAX, enKucukInndex;

    for (int v = 0; v < alti; v++) {
        if (enKisaMi[v] == false && uzaklik[v] <= enKucuk) {
            enKucuk = uzaklik[v];
            enKucukInndex = v;
        }
    }
    return enKucukInndex;
}
void dijkstra(int baslangic)
{
    int uzaklik[alti];
    string yol[alti];
    bool enKisaMi[alti]; 
    for (int i = 0; i < alti; i++) {
        uzaklik[i] = INT_MAX;
        enKisaMi[i] = false;
        yol[i] = "";
    }
    uzaklik[baslangic] = 0;
    int x;
    
    for (int i = 0; i < alti - 1; i++) {
         CozumuYazdir(uzaklik, yol);
         x = EnKisaUzaklik(uzaklik, enKisaMi);
         enKisaMi[x] = true;
         for (int y = 0; y < alti; y++) {
             if (!enKisaMi[y] && graf[x][y] && uzaklik[x] != INT_MAX && uzaklik[x] + graf[x][y] < uzaklik[y]) {
                 uzaklik[y] = uzaklik[x] + graf[x][y];
                 yol[y] = yol[x] + int2str(x) + "-";
             }
         }
         
    }
    CozumuYazdir(uzaklik, yol);
    
    
}

int main()
{
    dijkstra(0);
}

