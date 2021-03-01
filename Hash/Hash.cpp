// Abdykkah Ali GUN 191307005
//

#include <iostream>
using namespace std;

int hashArray[250];
int dizidekiElemanSayisi;
int hashle(int x) {
    return (3*x + 5) % 250;
}
int ekle(int anahtar, int deger) {
	if (hashArray[hashle(anahtar)] == 0) {
		hashArray[hashle(anahtar)] = deger;
		dizidekiElemanSayisi++;
	}
	else if(dizidekiElemanSayisi == 250){
		cout << "Hash Dolu..." << endl;

	}
	else {
		int indis = hashle(anahtar);
		while (hashArray[indis] != 0)
		{
			indis++;
			if (indis == 250) indis = 0;
		}
		hashArray[indis] = deger;
		dizidekiElemanSayisi++;
	}
	return 0;
}
int anahtarlaAra(int anahtar) {
	if (dizidekiElemanSayisi == 0) {
		cout << "Hash Boş" << endl;
		return -99999999;
	}
	if (hashArray[hashle(anahtar)] == 0) {
		cout << "Aranan Hash Indexi Boş" << endl;
		return -99999999;
	}
	if (anahtar < 0 || anahtar > 250) {
		cout << "Anahtar dizin dışında" << endl;
		return -99999999;
	}
	return hashArray[hashle(anahtar)];
}
int degerleAra(int deger) {
	for (int i = 0; i < 250; i++)
	{
		if (hashArray[hashle(i)] == deger) return i;
	}
	return -99999999;
}
int anahtarlaSil(int anahtar) {
	if (dizidekiElemanSayisi == 0) { 
		cout << "Hash Boş" << endl;
		return -99999999;
	}
	if (hashArray[hashle(anahtar)] == 0) { 
		cout << "Aranan Hash Zaten Indexi Boş" << endl;
		return -99999999;
	}
	if (anahtar < 0 || anahtar > 250) {
		cout << "Anahtar dizin dışında" << endl;
		return -99999999;
	}
	cout << "Silme islemi basarili" << endl;
	dizidekiElemanSayisi--;
	return hashArray[hashle(anahtar)] = NULL;
}
int degerleSil(int deger) {
	for (int i = 0; i < 250; i++)
	{
		if (hashArray[hashle(i)] == deger) { 
			hashArray[hashle(i)] = NULL; 
			cout << "Silme islemi basarili" << endl;
			dizidekiElemanSayisi--;
			return 0;
		}
	}
	cout << "Aranan deger yok;" << endl;
	return -99;
}
int main()
{
	cout << "hash (3*x + 5) % 250" << endl;
	int islem, deger, anahtar;

	cout << endl;
	do
	{
		cout << endl;
		cout << "1-Ekle\n2-Ara\n3-Sil\n4-Bitir\nIslem Seciniz : ";
		cin >> islem;
		switch (islem)
		{
		case 1: 
			cout << "Degeri Giriniz : ";
			cin >> deger;
			cout << "Anahtarı Giriniz (random anahtar için -1 girin) : ";
			cin >> anahtar;
			if (anahtar == -1) anahtar = rand() % 250;
			ekle(anahtar, deger);
			cout << endl;
			break;
		case 2:
			cout << "1- Deger ile ara\n2- Anahtar ile ara\nIslem Seciniz : ";
			cin >> islem;
			cout << endl;
			switch (islem)
			{
			case 1 : 
				cout << "Deger giriniz : ";
				cin >> deger;
				anahtar = degerleAra(deger);
				if(anahtar != -99999999) cout << "Aranan " << deger << "'i " << hashle(anahtar) << "' hash koduna" << anahtar << "' indexine sahiptir" << endl;
				break;
			case 2 : 
				cout << "Anahtar Giriniz (0-250) : ";
				cin >> anahtar;
				deger  = anahtarlaAra(anahtar);
				if (deger != -99999999)
				cout << "Aranan " << anahtar << "'indexi " << hashle(anahtar) << "' hash koduna" << deger << "' degerine sahiptir" << endl;
				break;
			default:
				cout << "Yanlis bir islem girdiniz" << endl;
				islem = -99999999;
				break;
			}
			break;
		case 3:
			cout << "1- Deger sil\n2- Anahtar sil\nIslem Seciniz : ";
			cin >> islem;
			cout << endl;
			switch (islem)
			{
			case 1:
				cout << "Deger giriniz : ";
				cin >> deger;
				degerleSil(deger);
				break;
			case 2:
				cout << "Anahtar Giriniz (0-250) : ";
				cin >> anahtar;
				anahtarlaSil(anahtar);
				break;
			default:
				cout << "Yanlis bir islem girdiniz" << endl;
				islem = -99999999;
				break;
			}
			break;
		default:
			cout << "Yanlis bir islem girdiniz" << endl;
			cout << endl;
			islem = -99999999;
			break;
		}

	} while (islem != 4);
	return 0;
}

