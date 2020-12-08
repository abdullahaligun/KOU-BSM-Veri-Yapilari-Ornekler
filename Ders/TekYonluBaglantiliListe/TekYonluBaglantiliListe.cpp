//Abdullah Ali GÜN 191307005
#include <iostream>
using namespace std;

struct BLISTE
{
    int bilgi;
    BLISTE* arka;
};


int ekle(BLISTE*);
BLISTE* ara(int);
BLISTE* sil(int);
void listele();

static BLISTE* ilk, * son;
int main()
{
    setlocale(LC_ALL, "Turkish");
    BLISTE* girdi = new BLISTE;
    cout << "Derste anlatılan tek yönlü bağlantılı liste fonksiyonlarının (ekleme, arama, listeleme, silme) kullanımı için ornek program" << endl;
    int islem;
    do
    {
        cout << "Lütfen bir işlem seçiniz : \n1 - Ekleme\n2 - Arama\n3 - Listeleme\n4 - Silme\n5 - Çıkış" << endl;
        cin >> islem;
        switch (islem)
        {
        case 1:
            cout << "eklemek istediğiniz sayıyı girin: ";
            girdi = new BLISTE;
            int girdibilgi;
            cin >> girdibilgi;
            girdi->bilgi = girdibilgi;
            ekle(girdi);
            break;
        case 2:
            cout << "aramak istediğiniz sayıyı girin: ";
            int aranacak;
            cin >> aranacak;
            if (ara(aranacak)) cout << "aradığınız sayı listede mevcut" << endl;
            else cout << "aradığınız sayı listede mevcut değil" << endl;
            break;
        case 3:
            listele();
            break;
        case 4:
            cout << "silmek istediğiniz sayıyı girin: ";
            int silinecek;
            cin >> silinecek;
            if (sil(silinecek))cout << "sayı silindi" << endl;
            else cout << "aradığınız sayı listede mevcut değil" << endl;
            break;
        default:
            break;
        }
    } while (islem != 5);
    return 1903;
}

int ekle(BLISTE* ki)
{
    if (ilk != NULL) {
        son->arka = ki;
        son = ki;
        son->arka = NULL;
    }
    else {
        ilk = ki;
        son = ilk;
        ilk->arka = NULL;
    }
    return 0;
}
BLISTE* ara(int aranan)
{
    BLISTE* p;
    p = ilk;
    while (p) {
        if (p->bilgi == aranan)
            return p;
        p = p->arka;
    }
    return NULL;
}
BLISTE* sil(int silinecek)
{
    BLISTE* p = new BLISTE, * bironceki = new BLISTE;
    p = ilk;
    bironceki = NULL;
    while (p) {
        if (silinecek == p->bilgi)
            break;
        bironceki = p;
        p = p->arka;
    }
    if (p == ilk) {
        ilk = ilk->arka;
        free(p);
        return p;
    }
    else if (p == son)
    {
        bironceki->arka = NULL;
        son = bironceki;
        free(p);
        return p;
    }
    else if (p != ilk && p != son && p != NULL) {
        bironceki->arka = p->arka;
        free(p);
        return p;
    }
    else return NULL;
}
void listele() {
    BLISTE* p;
    p = ilk;
    while (p) {
        cout << p->bilgi << endl;
        p = p->arka;
    }
}
