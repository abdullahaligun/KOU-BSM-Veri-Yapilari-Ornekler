// Abdullah Ali GUN 191307005
//

#include <iostream>
#define alti 6
using namespace std;

#pragma region digerleri
int komsulukMatrisi[alti][alti] = {
    //{A ,B ,C ,D ,E ,F }
      {0 ,1 ,0 ,1 ,1 ,0 },//A
      {1 ,0 ,1 ,0 ,0 ,0 },//B
      {0 ,1 ,0 ,0 ,1 ,1 },//C
      {1 ,0 ,0 ,0 ,1 ,0 },//D
      {1 ,0 ,1 ,1 ,0 ,1 },//E
      {0 ,0 ,1 ,0 ,1 ,0 },//F
};
struct BLISTE
{
    int veri;
    BLISTE* arka, * on;
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
        c = "F";
        break;
    default:
        c = "NULL";
        break;
    }
    return c;
}
#pragma endregion
#pragma region queue

class queue {
    BLISTE* ilk, * son;
public:
    queue();
    void ekle(int veri);
    int cek();
    void listele();
    bool bosmu();
    BLISTE ilkEleman();
};
queue::queue() {
    ilk = NULL;
    son = NULL;
}
void queue::ekle(int veri) {
    BLISTE* yeni = new BLISTE;
    yeni->veri = veri;
    yeni->on = NULL;
    yeni->arka = NULL;
    if (ilk == NULL) {
        ilk = yeni;
        son = ilk;
    }
    else {
        son->arka = yeni;
        yeni->on = son;
        son = yeni;
    }
}

int queue::cek() {
    if (bosmu()) {
        cout << "queue Bos" << endl;
        return -1;
    }
    int doncekVeri = ilk->veri;
    BLISTE* f = ilk;
    ilk = ilk->arka;
    free(f);
    return doncekVeri;
}
void queue::listele() {
    BLISTE* p = ilk;
    while (p)
    {
        cout << p->veri << endl;
        p = p->arka;
    }
}
bool queue::bosmu() {
    return !ilk;
}
#pragma endregion
#pragma region stack
class stack {
    BLISTE* ilk, * son;
public:
    stack();
    void ekle(int veri);
    int cek();
    void listele();
    bool bosmu();
};
stack::stack() {
    ilk = NULL;
    son = NULL;
}
void stack::ekle(int veri) {
    BLISTE* yeni = new BLISTE;
    yeni->veri = veri;
    yeni->on = NULL;
    yeni->arka = NULL;
    if (ilk == NULL) {
        ilk = yeni;
        son = ilk;
    }
    else {
        son->arka = yeni;
        yeni->on = son;
        son = yeni;
    }
}

int stack::cek() {
    if (bosmu()) {
        cout << "Stack Bos" << endl;
        return -1;
    }
    int doncekVeri = son->veri;
    BLISTE* f = son;
    if (son == ilk) {
        son = NULL;
        ilk = NULL;
    }
    else  son = son->on;
    free(f);
    return doncekVeri;
}
void stack::listele() {
    BLISTE* p = son;
    while (p)
    {
        cout << p->veri << endl;
        p = p->on;
    }
}
bool stack::bosmu() {
    return !son;
}
#pragma endregion
#pragma region DSF
void DSF(int basla) {
    bool ziyaretEdilenler[alti] = { false,false,false,false,false,false };

    stack s, sZiyaretEdilenler;

    s.ekle(basla);
    int a = -1;
    while (a != basla)
    {
        a = s.cek();
        if (!ziyaretEdilenler[a]) {
            cout << int2str(a) << " - ";
            ziyaretEdilenler[a] = true;
            sZiyaretEdilenler.ekle(a);
        }

        do
        {
            for (int i = 0; i < alti; i++)
            {
                if (!ziyaretEdilenler[i] && komsulukMatrisi[a][i]) {
                    s.ekle(i);
                    a = i;
                    break;
                }
            }
            if (s.bosmu()) a = sZiyaretEdilenler.cek();
            if (sZiyaretEdilenler.bosmu()) break;
        } while (s.bosmu());
        
        
    }


}
#pragma endregion
#pragma region BSF
void BSF(int basla) {
    bool ziyaretEdilenler[alti] = { false,false,false,false,false,false };

    queue s;

    s.ekle(basla);
    int a = -1;
    while (!s.bosmu())
    {
        a = s.cek();
        if (!ziyaretEdilenler[a]) {
            cout << int2str(a) << " - ";
            ziyaretEdilenler[a] = true;
        }

        for (int i = 0; i < alti; i++)
        {
            if (!ziyaretEdilenler[i] && komsulukMatrisi[a][i]) {
                s.ekle(i);
            }
        }

       

    }


}
#pragma endregion

int main()
{
    cout << "DSF : ";
    DSF(1);
    cout << endl;
    cout << "BSF : ";
    BSF(1);
}
