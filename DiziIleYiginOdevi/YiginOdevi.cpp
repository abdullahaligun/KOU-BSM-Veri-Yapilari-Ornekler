/*Abdullah Ali GÜN 191307005
* 
* yığınlarda son giren eleman ilk olarak diziden çekildiği için ekledikten sonra yazdırırken
aynalanarak tersten çıktı veriyor.
*/

#include <iostream>
#include <string>
using namespace std;
#define diziUzunlugu 10
struct yiginstring
{
    string dizi[diziUzunlugu];
    int tos = 0;
};
struct yiginint
{
    int dizi[diziUzunlugu];
    int tos = 0;
};

void ekleint(int);
void eklestring(string);
int cekint();
string cekstring();

static yiginint yigin1;
static yiginstring adsoyad;
int main()
{
    setlocale(LC_ALL, "Turkish");
    for (int i = 0; i < 12; i++)
    {
        ekleint(i);
    }
    for (int i = 0; i < 12; i++)
    {
        cout << "yigindan çekilen deger : " << cekint() << endl;;
    }

    eklestring("Abdullah");
    eklestring("Ali");
    eklestring("GUN");

    for (int i = 0; i < 3; i++)
    {
        cout << cekstring() << endl;
    }
}
void ekleint(int eklenecek) {
    if (yigin1.tos >= diziUzunlugu) {
        cout << "yigin dizisi dolu.\"" << eklenecek << "\" eklenemedi" << endl;
    }
    else {
        cout << "yigin dizisinde yeterli yer var.\"" << eklenecek << "\" eklendi" << endl;
        yigin1.dizi[yigin1.tos] = eklenecek;
        yigin1.tos++;
    }
}
int cekint() {
    if (yigin1.tos <= 0) {
        cout << "yigin dizisi bos eleman çekilemedi" << endl;
        return NULL;
    }
    else {
        yigin1.tos--;
        int donecekdeger = yigin1.dizi[yigin1.tos];
        return donecekdeger;
    }
}
void eklestring(string eklenecek) {

    if (adsoyad.tos >= diziUzunlugu) {
        cout << "yigin dizisi dolu.\"" << eklenecek << "\" eklenemedi" << endl;
    }
    else {
        cout << "yigin dizisinde yeterli yer var.\"" << eklenecek << "\" eklendi" << endl;
        adsoyad.dizi[adsoyad.tos] = eklenecek;
        adsoyad.tos++;
    }
}
string cekstring() {
    if (adsoyad.tos <= 0) {
        cout << "yigin dizisi bos eleman çekilemedi" << endl;
        return "";
    }
    else {
        adsoyad.tos = adsoyad.tos-1;
        string donecekdeger = adsoyad.dizi[adsoyad.tos];
        return donecekdeger;

    }
}

/*Abdullah Ali GÜN 191307005
*
* yığınlarda son giren eleman ilk olarak diziden çekildiği için ekledikten sonra yazdırırken
aynalanarak tersten çıktı veriyor.
*/