//Abdullah ALi GÜN 191307005
#include <iostream>
using namespace std;

float OrtalamaDizi(int*);
void ArtanDizi(int* []);

const int diziUzunluk = 7;
int main()
{
    int dizi[diziUzunluk] = { 41, 16, 34, 06, 65, 11, 2000 };
    int* ptr = dizi;
    int* ptrdizi[diziUzunluk];

    for (int i = 0; i < diziUzunluk; ++i)
    {
        ptrdizi[i] = &dizi[i];
    }
    /*fonksiyona pointer dizisi mi yollayacaz yoksa bir pointer yollayıp dizi elemanlarına onun üzerinden mi
    ulaşacaz kararsız kaldığım için bir fonksiyonu ptr dizisi diğerini de ptr den diziye ulaşarak yaptım.*/
    cout << "Dizi ortalamasi : " << OrtalamaDizi(ptr) << endl;

    cout << endl << "Artan Dizi Siralamasi" << endl;
    ArtanDizi(ptrdizi);

    for (int i = 0; i < diziUzunluk; ++i)
    {
        cout << dizi[i] << endl;
    }
    return 0;
}

float  OrtalamaDizi(int* ptr)
{
    int toplam = 0;
    for (int i = 0; i < diziUzunluk; ++i)
    {
        toplam += *(ptr + i);
    }
    return (toplam / diziUzunluk);
}

void ArtanDizi(int* ptr[])
{
    for (int i = 0; i < diziUzunluk; ++i)
    {
        for (int j = i; j < diziUzunluk; ++j)
        {
            if (*(ptr[i]) < *(ptr[j]))
            {
                int temp = *(ptr[j]);
                *(ptr[j]) = *(ptr[i]);
                *(ptr[i]) = temp;
            }
        }
    }
}
