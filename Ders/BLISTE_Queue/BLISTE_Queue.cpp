//Abdullah Ali GÜN 191307005
#include <iostream>
using namespace std;
struct BLISTE
{
    int veri;
    BLISTE* arka, * on;
};
class queue {
    BLISTE* ilk, * son;
public:
    queue();
    void ekle(int veri);
    int cek();
    void listele();
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
    if (ilk == NULL) {
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
int main()
{
    int islem, eklenecek;
    queue s;
    do
    {
        cout << "1- Ekle\n2- Cek\n3- Listele\n4- Bitir\nIslem giriniz : ";
        cin >> islem;
        switch (islem)
        {
        case 1:
            cout << "Eklenecek sayiyi girin" << endl;
            cin >> eklenecek;
            s.ekle(eklenecek);
            break;
        case 2:
            cout << "Cekilen Sayi : " << s.cek() << endl;
            break;
        case 3:
            s.listele();
            break;
        case 4:
            cout << "Program sonlandi";
            break;
        default:
            cout << "Yanlis giris yaptiniz";
            break;
        }
    } while (islem != 4);

    return 1903;
}


