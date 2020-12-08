// Abdullah-Ali-GUN-191307005

#include <iostream>
#include <math.h>//matematik işlemleri için
using namespace std;

float OrtalamaHesaplayici(int, int);
int CevreHesaplayici(int, int);
int AlanHesaplayici(int, int);

int main() {
    //1-Kullanıcının seçimine göre toplama veya çıkarma işlemi yapan programı yazınız
    int a, b;
    char islemTipi;
    cout << "Birinci sayiyi girin : ";
    cin >> a;
    cout << endl;
    cout << "toplama icin : + \n" <<
        "cikarma icin: - \n" <<
        "islem seciniz :";
    cin >> islemTipi;
    cout << "Ikinci sayiyi girin : ";
    cin >> b;
    cout << endl;

    if (islemTipi == '+') cout << "Toplama Sonucu : " << a + b << endl;
    else if (islemTipi == '-') cout << "Cikarma Sonucu : " << a - b << endl;
    else cout << "Hatali Giris Yaptiniz" << endl;

    //2-Klavyeden girilen sayıya ve seçime göre matemtiksel işlemleri yapan programı yazınız.
    //1:Karekok, 2:Kare, 3:Mutlak Deger
    int girilenSayi, islemIcinSayi;
    cout << "1:Karekok \n2:Kare \n3:Mutlak Deger \nİslemi Seciniz : ";
    cin >> islemIcinSayi;
    cout << endl;

    cout << "İslem Yapilacak Sayiyi Girin : ";
    cin >> girilenSayi;
    cout << endl;

    if (islemIcinSayi == 1) cout << "Karekok : " << sqrt(girilenSayi) << endl;
    else if (islemIcinSayi == 2) cout << "Kare : " << (girilenSayi * girilenSayi) << endl;
    else if (islemIcinSayi == 3)cout << "Karekok : " << abs(girilenSayi) << endl;
    else cout << "Hatali Giris Yaptiniz" << endl;

    //3- Klavyeden -1 girilene kadar, girilen sayıların ortalamalarını gösteren programı yazınız
    int klavyedenGirilenSayi, sayac = 0, toplam = 0;
    cout << "-1 girilene kadarki tum sayilar toplanip ortalaması alinacaktir" << endl;
    do {
        sayac++;
        cout << "lutfen bir sayi giriniz : ";
        cin >> klavyedenGirilenSayi;
        cout << endl;
        toplam += klavyedenGirilenSayi;
        if (klavyedenGirilenSayi == -1) {
            toplam -= klavyedenGirilenSayi;
            sayac--;

        }
    } while (klavyedenGirilenSayi != -1);

    if (sayac == 0) cout << "Ortalamaya katilabilecek bir sayi girilmedi (ilk girdi -1)" << endl;
    else cout << "Girilen sayilarin ortalamasi : " << (toplam / sayac) << endl;

    //4-Klavyeden girilen rakamlari farkli 4 basamakli sayinin basamaklarini bulan programı C++ ile yazınız.
    //Sayi 4 basamakli olmazsa hata verecek! Sayının rakamlari farkli olmazsa hata verecek!
    int klavyedenGirilenRakamlariFarkliSayi;
    int basamaklar[4];

    cout << "Rakamlari farkli 4 basamakli sayi giriniz : ";
    cin >> klavyedenGirilenRakamlariFarkliSayi;
    cout << endl;

    for (int i = 0; i < 4; i++) {
        basamaklar[i] = klavyedenGirilenRakamlariFarkliSayi % 10;
        klavyedenGirilenRakamlariFarkliSayi /= 10;
    }
    if (klavyedenGirilenRakamlariFarkliSayi != 0 || basamaklar[3] == 0) cout << "Girilen sayi 4 basamakli degil" << endl;

    for (int i = 0; i < 4; ++i) {
        for (int j = i + 1; j < 4; ++j) {
            if (basamaklar[i] == basamaklar[j]) cout << "Girilen sayida bazi basamaklar bir birine esit" << endl;
        }
    }
    for (int i = 0; i < 4; ++i) {
        cout << (i + 1) << ".basamak " << basamaklar[i] << endl;
    }



    //5-C++ ile Fonksiyon kullanarak Vize ve Final notu girilen öğrencinin ortalamasını hesaplayınız.
    int vize, final;
    cout << "Vize notunu giriniz (%40) : ";
    cin >> vize;
    cout << endl;

    cout << "Final notunu giriniz (%60) : ";
    cin >> final;
    cout << endl;

    cout << "Ortalama : " << OrtalamaHesaplayici(vize, final) << endl;

    //6-C++ ile Fonksiyon kullanarak dikdörtgen alan ve çevre hesaplayan örneği oluşturunuz
    int kisaKenar, uzunKenar;
    cout << "Dikdortgen icin \n";
    cout << "kisa kenari giriniz : ";
    cin >> kisaKenar;
    cout << endl;

    cout << "uzun kenari giriniz : ";
    cin >> uzunKenar;
    cout << endl;

    cout << "Dikdortgenin cevresi : " << CevreHesaplayici(kisaKenar, uzunKenar) << endl << "Dikdortgenin Alani : " << AlanHesaplayici(kisaKenar, uzunKenar);

    return  0;
}
float OrtalamaHesaplayici(int v, int f) {
    return (v * 0.4f) + (f * 0.6f);
}
int CevreHesaplayici(int k, int u) {
    return  (k + k + u + u);
}

int AlanHesaplayici(int k, int u) {
    return k * u;
}