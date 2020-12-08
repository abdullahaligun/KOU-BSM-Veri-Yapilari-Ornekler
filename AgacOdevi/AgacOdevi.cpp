//abdullah ali gün 191307005
#include <iostream>
using namespace std;

struct Dugum {
	int data;
	Dugum* sol, * sag;
};


// yeni kök olu?turma
Dugum* new_Dugum(int data) {
	Dugum* p = new Dugum;
	p->data = data;
	p->sol = NULL;
	p->sag = NULL;
	return p;
}
Dugum* AgacaEkle(Dugum* kok, int data) {
	if (kok) {
		if (data < kok->data)
			kok->sol = AgacaEkle(kok->sol, data);
		else
			kok->sag = AgacaEkle(kok->sag, data);
	}
	else
		kok = new_Dugum(data);
	return kok;
}

void preorder(Dugum* kok) {
	if (kok) {
		cout << kok->data << " ";
		preorder(kok->sol);
		preorder(kok->sag);
	}
}
void inorder(Dugum* kok) {
	if (kok) {
		inorder(kok->sol);
		cout << kok->data << " ";
		inorder(kok->sag);
	}
}
void postorder(Dugum* kok) {
	if (kok) {
		inorder(kok->sol);
		inorder(kok->sag);
		cout << kok->data << " ";
	}
}

int dugumSayisi(Dugum* kok) {
	if (kok) return dugumSayisi(kok->sol) + 1 + dugumSayisi(kok->sag);
	else return 0;
}
int yukseklik(Dugum* kok) {
	if (kok) {
		int sol_yukseklik, sag_yukseklik;
		sol_yukseklik = yukseklik(kok->sol);
		sag_yukseklik = yukseklik(kok->sag);
		if (sol_yukseklik > sag_yukseklik)
			return sol_yukseklik + 1;

		else return sag_yukseklik + 1;
	}
	else return -1;
}

int main() {
	Dugum* benimkokum = NULL; //alinin koku =D

	benimkokum = AgacaEkle(benimkokum, 27);
	benimkokum = AgacaEkle(benimkokum, 18);
	benimkokum = AgacaEkle(benimkokum, 39);
	benimkokum = AgacaEkle(benimkokum, 14);
	benimkokum = AgacaEkle(benimkokum, 22);
	benimkokum = AgacaEkle(benimkokum, 29);
	benimkokum = AgacaEkle(benimkokum, 42);
	benimkokum = AgacaEkle(benimkokum, 2);
	benimkokum = AgacaEkle(benimkokum, 17);
	benimkokum = AgacaEkle(benimkokum, 12);
	benimkokum = AgacaEkle(benimkokum, 24);
	benimkokum = AgacaEkle(benimkokum, 34);
	benimkokum = AgacaEkle(benimkokum, 15);
	benimkokum = AgacaEkle(benimkokum, 23);

	cout << "preorder" << endl;
	preorder(benimkokum);
	cout << endl;
	cout << "inorder" << endl;
	inorder(benimkokum);
	cout << endl;
	cout << "postorder" << endl;
	postorder(benimkokum);
	cout << endl;
	cout << endl;
	cout << "Dugum sayisi : " << dugumSayisi(benimkokum) << endl;
	cout << endl;
	cout << "Yukseklik : " << yukseklik(benimkokum) << endl;
	cout << endl;
	return 1903;
}
