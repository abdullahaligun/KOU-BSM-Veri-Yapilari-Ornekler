//Abdullah Ali GÜN 191307005

#include <iostream>
using namespace std;


struct BLISTE
{
    int bilgi;
    BLISTE *arka;
};

void basa_ekle(int);
void araya_ekle(int);
void sona_ekle(int);
void ara();
void yaz();
void bastan_sil();
void sondan_sil();
void aradan_sil();


static BLISTE* ilk, * son;
int main()
{
    basa_ekle(9);
    basa_ekle(19);
    basa_ekle(29);
    basa_ekle(39);
    basa_ekle(49);
    yaz();
    sona_ekle(1);
    sona_ekle(21);
    sona_ekle(31);
    sona_ekle(41);
    sona_ekle(51);
    yaz();
    araya_ekle(5);
    araya_ekle(15);
    araya_ekle(25);
    araya_ekle(35);
    araya_ekle(45);
    yaz();
    ara();
    yaz();
    bastan_sil();
    yaz();
    sondan_sil();
    yaz();
    aradan_sil();
    yaz();
    return 1903;
}

void basa_ekle(int ekle) {
    BLISTE* p = new BLISTE;

    p->bilgi = ekle;
    if (ilk == NULL)
    {
        ilk = p;
        ilk->arka = NULL;
        son = ilk;
    }
    else {
        p->arka = ilk;
        ilk = p;
    }
    while (p)
    {
        if (p->arka == NULL) son = p; 
        p = p->arka;
    }
}
void araya_ekle(int ekle) {
    BLISTE* p = new BLISTE, * q = ilk, *bionceki;
    p->bilgi = ekle;
    for (int i = 0; i < 5; i++)
    {
        bionceki = q;
        q = q->arka;
    }
    bionceki->arka = p;
    p->arka = q;

    while (p)
    {
        if (p->arka == NULL) son = p;
        p = p->arka;
    }
}
void sona_ekle(int ekle) {
    BLISTE* p = new BLISTE;
    p->bilgi = ekle;

    son->arka = p;
    son = p;
    son->arka = NULL;
}

void ara() {
    cout << endl;
    BLISTE* p;
    p = ilk;
    while (p)
    {
        if (p->bilgi % 3 == 0) cout << p->bilgi << " - ";
        p = p->arka;
    }
    cout << endl;
}

void yaz() {
    cout << endl;
    BLISTE* p;
    p = ilk;
    while (p)
    {
        if(p !=  NULL) cout << p->bilgi << " - ";
        p = p->arka;
    }
    cout << endl;
}

void bastan_sil() {

    BLISTE* p;
    for (int i = 0; i < 3; i++)
    {
        p = ilk;
        ilk = ilk->arka;
        free(p);
    }
}
void sondan_sil() {
    BLISTE * q = ilk, * bionceki = new BLISTE;
    for (int i = 0; i < 3; i++)
    {
        q = ilk;
        while (q)
        {
            bionceki = q;
            q = q->arka;
            if (q == son) break;
        }
        son = bionceki;
        son->arka = NULL;
        free(q);
    }
    
}

void aradan_sil() {

    BLISTE * q = ilk, * bionceki;
    for (int ai = 0; ai < 3; ai++)
    {
        q = ilk;
        for (int i = 0; i < 3; i++)
        {
            bionceki = q;
            q = q->arka;
        }

        bionceki->arka = q->arka;
        free(q);
    }
    
}

