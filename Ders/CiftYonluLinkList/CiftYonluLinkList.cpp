//Abdullah Ali GÜN 191307005
#include <iostream>
using namespace std;

struct BLISTE
{
    int bilgi;
    BLISTE* arka,* on;
};


int ekle(BLISTE*);
BLISTE* bastanara(int);
BLISTE* sondanara(int);
BLISTE* sil(int);
void bastanlistele();
void sondanlistele();

static BLISTE* ilk, * son;
int main()
{
    setlocale(LC_ALL, "Turkish");
    BLISTE* girdi = new BLISTE;
    cout << "Derste anlatilan çift yönlü baglantili liste fonksiyonlarinin kullanimi icin ornek program" << endl;
    cout << "hocam on bağlantilarini kullanirken pratik olsun diye baştan ve sonran ara ve listele diye ek yaptim sadece" << endl;
    int islem;
    do
    {
        cout << "Lütfen bir islem seciniz : \n1 - Ekleme\n2 - Bastan Ara\n3 - Sondan Ara\n4 - Bastan Listele\n5 -Sondan Listele\n6 - Silme\n7 - cikis" << endl;
        cin >> islem;
        switch (islem)
        {
        case 1:
            cout << "eklemek istediginiz sayiyi girin: ";
            girdi = new BLISTE;
            int girdibilgi;
            cin >> girdibilgi;
            girdi->bilgi = girdibilgi;
            ekle(girdi);
            break;
        case 2:
            cout << "aramak istediginiz sayiyi girin: ";
            int aranacak;
            cin >> aranacak;
            if (bastanara(aranacak)) cout << "aradiginiz sayi listede mevcut" << endl;
            else cout << "aradiginiz sayi listede mevcut degil" << endl;
            break;
        case 3:
            cout << "aramak istediginiz sayiyi girin: ";
            int aranacakq;
            cin >> aranacakq;
            if (sondanara(aranacakq)) cout << "aradiginiz sayi listede mevcut" << endl;
            else cout << "aradiginiz sayi listede mevcut degil" << endl;
            break;
        case 4:
            bastanlistele();
            break;
        case 5:
            sondanlistele();
            break;
        case 6:
            cout << "silmek istediginiz sayiyi girin: ";
            int silinecek;
            cin >> silinecek;
            if (sil(silinecek))cout << "sayi silindi" << endl;
            else cout << "aradiginiz sayi listede mevcut degil" << endl;
            break;
        default:
            break;
        }
        cout << "------------------------" << endl;
    } while (islem != 7);
    return 1903;
}

int ekle(BLISTE* ki)
{
    cout << "------------------------" << endl;
    if (ilk != NULL) {
        son->arka = ki;
        ki->on = son;
        son = ki;
        son->arka = NULL;
    }
    else {
        ilk = ki;
        son = ilk;
        ilk->arka = NULL;
        ilk->on = NULL;
    }
    return 0;
}
BLISTE* bastanara(int aranan)
{
    cout << "------------------------" << endl;
    int i = 0;
    BLISTE* p;
    p = ilk;
    while (p) {
        if (p->bilgi == aranan)
        {
            cout << "bastan " << i << ".indexde" << endl;
            return p;
        }
        i++;
        p = p->arka;
    }
    return NULL;
}
BLISTE* sondanara(int aranan)
{
    cout << "------------------------" << endl;
    int i = 0;
    BLISTE* p;
    p = son;
    while (p) {
        if (p->bilgi == aranan)
        {
            cout << "sondan " << i << ".indexde" << endl;
            return p;
        }
        i++;
        p = p->on;
    }
    return NULL;
}
BLISTE* sil(int silinecek)
{
    cout << "------------------------" << endl;
    BLISTE* p = new BLISTE;
    p = ilk;
    while (p) {
        if (silinecek == p->bilgi)
            break;
        p = p->arka;
    }
    if (p == ilk) {
        cout << "silinmek istenen sayi ilk sayi" << endl;
        ilk = ilk->arka;
        ilk->on = NULL;
        free(p);
        return p;
    }
    else if (p == son)
    {
        cout << "silinmek istenen sayi son sayi" << endl;
        son = son->on;
        son->arka = NULL;
        free(p);
        return p;
    }
    else if (p != ilk && p != son && p != NULL) {
        cout << "silinmek istenen sayi aradaki sayi" << endl;
        p->on->arka = p->arka;
        p->arka->on = p->on;
        free(p);
        return p;
    }
    else return NULL;
}
void bastanlistele() {
    cout << "------------------------" << endl;
    BLISTE* p;
    p = ilk;
    while (p) {
        cout << p->bilgi << endl;
        p = p->arka;
    }
}
void sondanlistele() {
    cout << "------------------------" << endl;
    BLISTE* q;
    q = son;
    while (q) {
        cout << q->bilgi << endl;
        q = q->on;
    }
}
