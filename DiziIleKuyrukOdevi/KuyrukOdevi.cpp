//Abdullah Ali GÜN 191307005

//kuyruklarda ilk giren eleman ilk ciktigi icin yazdirirkende ekledigimiz sirayla cikiyor


#include <iostream>
#include <string>
using namespace std;
#define diziUzunlugu 8

class Kuyruk {
	int kuyrukDizi[diziUzunlugu];
	int bas, son;
	int elemanSayisi;

public:
	Kuyruk();
	void ekle(int);
	int cikar();
	void listele();
	bool bosmu();
	bool dolumu();
};
Kuyruk::Kuyruk() {
	bas = 0;
	son = 0;
	elemanSayisi = 0;
}
void Kuyruk::ekle(int eklenecek) {
	if (dolumu()) {
		cout << "Kuyruk Dolu" << endl;
		return;
	}
	kuyrukDizi[son] = eklenecek; // Yeni elemani sona koy
	son++; 
	if (son == diziUzunlugu) son = 0;
	elemanSayisi++;

	cout << "Kuyruga eleman eklendi: " << eklenecek << endl;
}
int Kuyruk::cikar() {
	int id = -1;
	if (bosmu()) {
		cout << "Kuyruk Bos" << endl;
		return -1;
	}
	id = bas; // ilk elemanin oldugu yer
	bas++; 
	if (bas == diziUzunlugu) bas = 0;
	elemanSayisi--;
	cout << "Kuyruktan eleman cikarildi: " << kuyrukDizi[id] << endl;
	return kuyrukDizi[id];	
}
void Kuyruk::listele() {
	if (dolumu()) {
		int index = bas;
		for (int i = 0; i < elemanSayisi; i++)
		{
			if (index == diziUzunlugu) index = 0;
			cout << kuyrukDizi[index] << endl;
			index++;
			
		}
	}
	else cout << "Kuyruk Bos" << endl;
}
bool Kuyruk::bosmu() {
	return elemanSayisi == 0;
}
// Kuyruk doluysa ture döndür
bool Kuyruk::dolumu() {
	return elemanSayisi == diziUzunlugu;
}

int main() {
	setlocale(LC_ALL, "Turkish");
	Kuyruk k;
	int islem;
	int girdi;
	
	do
	{	
			cout << "Lütfen bir islem seciniz : \n1 - Ekleme\n2 - Cikarma\n3 - Listeleme\n4 - cikis" << endl;
			cin >> islem;
			switch (islem)
			{
			case 1:
				girdi = rand() % 100;
				k.ekle(girdi);
				break;
			case 2:
				k.cikar();
				break;
			case 3:
				k.listele();
				break;
			default:
				break;
			}		
	} while (islem != 4);
	return 1903;
}