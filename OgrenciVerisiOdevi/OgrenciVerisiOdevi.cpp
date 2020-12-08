#include <iostream>
#include <string>
using namespace std;

struct  BLISTE
{
	int tc_no;
	string ad_soyad;
	string cinsiyet;
	BLISTE* arka, * on;
};

class OgrenciListesi
{
public:
	OgrenciListesi();
	void OgrenciEkle(int,string, string );
	void OgrenciSil(int);
	void OgrencileriListele();
private:
	BLISTE* ilk = NULL, * son = NULL;
};

OgrenciListesi::OgrenciListesi()
{
	ilk = NULL;
	son = NULL;
}

void OgrenciListesi::OgrenciEkle(int tc, string adsoyad, string cinsiyetgelen) {
	BLISTE* yeniOgrenci = new BLISTE;
	yeniOgrenci->tc_no = tc;
	yeniOgrenci->ad_soyad = adsoyad;
	yeniOgrenci->cinsiyet = cinsiyetgelen;
	yeniOgrenci->arka = NULL;
	yeniOgrenci->on = NULL;
	if (ilk == NULL) {
		ilk = yeniOgrenci;
		son = ilk;
	}
	else {
		BLISTE* SiraBul = ilk;
		while (SiraBul)
		{
			if (SiraBul->arka == NULL) {
				SiraBul->arka = yeniOgrenci;
				yeniOgrenci->on = SiraBul;
				break;
			}
			else if (SiraBul->tc_no < yeniOgrenci->tc_no && SiraBul-> arka -> tc_no > yeniOgrenci-> tc_no) {
				yeniOgrenci->arka = SiraBul->arka;
				SiraBul->arka->on = yeniOgrenci;
				yeniOgrenci->on = SiraBul;
				SiraBul->arka = yeniOgrenci;
				break;
			}
		}
	}
	BLISTE* p  = ilk;
	while (p)
	{
		if (p->arka == NULL) son = p;
		p = p->arka;
	}
	cout << "Eklenen T.C. Kimlik Numarasi : " << yeniOgrenci->tc_no << " - Ad Soyad : " << yeniOgrenci->ad_soyad << " - Cinsiyet : " << yeniOgrenci->cinsiyet << endl;
}

void OgrenciListesi::OgrenciSil(int silinecekTC) {
	BLISTE* arayici = ilk;
	while (arayici)
	{
		if (arayici->tc_no == silinecekTC)
			break;
		arayici = arayici->arka;
	}
	if (arayici == NULL) {
		cout << "Aranan  T.C. numarası listede bulunmadı " << silinecekTC << endl;
	}
	else if (arayici == ilk) {
		cout << "Aranan T.C numarasine ait ogrenci listeden cikartildi " << silinecekTC << endl;
		ilk = ilk -> arka;
		ilk -> on = NULL;
	}
	else if (arayici == son) {
		cout << "Aranan T.C numarasine ait ogrenci listeden cikartildi " << silinecekTC << endl;
		son = son->on;
		son->arka = NULL;
	}
	else {
		cout << "Aranan T.C numarasine ait ogrenci listeden cikartildi " << silinecekTC << endl;
		arayici->arka->on = arayici->on;
		arayici->on->arka = arayici->arka;
	}
	free(arayici);
	
}
void OgrenciListesi::OgrencileriListele() {
	BLISTE* listele = ilk;
	cout << "Listeleniyor" << endl;
	while (listele)
	{
		cout << "T.C. Kimlik Numarasi : " << listele -> tc_no << " - Ad Soyad : " << listele->ad_soyad << " - Cinsiyet : " << listele->cinsiyet << endl;
		listele = listele->arka;
	}
}

int main() {
	int islem, tc_no;
	char ad_soyad[256];
	string cinsiyet;
	OgrenciListesi liste;

	cout << "Otomatik Kisim" << endl;
	liste.OgrenciEkle(191307005,"Abdullah Ali GUN", "Erkek");
	liste.OgrencileriListele();
	liste.OgrenciEkle(200000000, "ananim ogrenci", "bilinmiyor");
	liste.OgrencileriListele();
	liste.OgrenciEkle(191307010,"Emre CetinDemir", "Erkek");
	liste.OgrencileriListele();
	liste.OgrenciSil(200000000);
	liste.OgrencileriListele();
	liste.OgrenciSil(200000000);
	liste.OgrencileriListele();
	cout << "Manuel Kisim" << endl;
	do
	{
		cout << "1- Ogrenci Ekle\n2- Ogrenci Sil\n3- Ogrencileri Listele\n4-Cıkıs" << endl;
		cin >> islem;
		if (islem == 1)
		{
			cout << "Ogrencinin Adini Soyadini Girin (en fazla 256 karakter) :";
			cin.ignore();
			cin.getline(ad_soyad, 256);
			cout << "Ogrenciye Ait T.C. Kimlik Numarasini Girin : ";
			cin >> tc_no;
			cout << "Ogrencinin Cinsiyetini Girin :";
			cin >> cinsiyet;
			liste.OgrenciEkle(tc_no,ad_soyad,cinsiyet);
		}
		else if (islem == 2) {
			cout << "Silinecek Ogrenciye Ait T.C. Kimlik Numarasini Girin : ";
			cin >> tc_no;
			liste.OgrenciSil(tc_no);
		}
		else if (islem == 3) {
			liste.OgrencileriListele();
		}
		else {
			cout << "Yanlis Giris Yaptiniz" << endl;
		}
		
	} while (islem != 4);
}
