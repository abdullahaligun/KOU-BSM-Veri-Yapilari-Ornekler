//Abdullah Ali GÜN 191307005
#include <iostream>
using namespace std;
struct BLISTE
{
    int veri;
    BLISTE* arka, * on;
};
class stack {
    BLISTE* ilk, * son;
public:
    stack();
    void ekle(int veri);
    int cek();
    void listele();
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
    if (son == NULL) {
        cout << "Stack Bos" << endl;
        return -1;
    }
    int doncekVeri = son->veri;
    BLISTE* f = son;
    son = son->on;
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
int main()
{
    cout << "Baglantili liste ile yıgın yapisi" << endl;
    int islem, eklenecek;
    stack s;
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

