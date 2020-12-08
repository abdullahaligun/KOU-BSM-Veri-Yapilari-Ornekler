//Abdullah Ali GÜN 191307005
#include <iostream>
#include <string>
#include <string.h>
using namespace std;


#define arraySize 100
class Stack {
	char array[arraySize];


public:
	Stack();
	void push(char ch);
	char pop();
	void traverse();
	int tos;
	int length = arraySize;
};

Stack::Stack() {
	tos = 0;
}
void Stack::push(char ch) {
	if (tos >= length) { //yığın dolu mukontrol ediliyor
		cout << "yigin dolu" << endl;
	}
	else {
		array[tos] = ch;
		tos++;
	}
}
char Stack::pop() {
	if (tos <= 0) // yığın boş mu kontrol ediliyor
	{
		cout << "yigin bos" << endl;
		return -1;
	}
	tos--;
	return array[tos];
}

void Stack::traverse() {
	for (int i = 0; i < tos; i++)
	{
		cout << "index : " << i << " deger : " << array[i] << endl;
	}
}

bool ParantezKontrol(string);
int main()
{
	setlocale(LC_ALL, "Turkish");
	cout << "bu program girilen ifadedeki parantezleri kontrol ederek \n"
		<< "parantezlerin dogru girilip girilmedigini kontrol ediyor.\n";
	bool iscontinue = true;
	string girilenIfade;
	do
	{
		cout << "lutfen bir ifade giriniz : \n"
			<< "(orn : 2*i+5*(7-j/(4*k)) \n ";
		cin >> girilenIfade;
		iscontinue = ParantezKontrol(girilenIfade);

	} while (iscontinue);

	return 1903;
}

bool ParantezKontrol(string ifade) {

	Stack stack;
	cout << endl;
	char pop;

	// girilen ifadenin her elemanını dönerek açılış parantezlerini stack e ekleyip kapanışlarda stackten çekerek kontrol ediyor.
	for (int i = 0; i < ifade.size(); i++)
	{
		if (ifade[i] == '(' || ifade[i] == '[' || ifade[i] == '{') {
			stack.push(ifade[i]);
		}
		else if (ifade[i] == ')' || ifade[i] == ']' || ifade[i] == '}') {
			pop = stack.pop();
			if ((ifade[i] == ')' && pop != '(') || (ifade[i] == ']' && pop != '[') || (ifade[i] == '}' && pop != '{')) {

				cout << pop << " açılış ifadesinin kapanış ifadesi gelmedi. Gelen kapanış ifadesi : " << ifade[i] << endl;
			}
		}
	}
	// döngü bittiğinde stackte hala eleman kaldı ise onları dönerek hata mesajlarını ekrana yazıyor.
	// hala eleman kalıp kalmadığını kontrol etmek için tos u public tanımladım.
	if (stack.tos > 0)
	{
		for (int i = 0; i < stack.tos; i++)
		{
			cout << "parantezlerde hata var " << stack.pop() << " açılış parantezinin kapanış parantezi yok" << endl;
		}
	}

	cout << endl;
	cout << endl;
	cout << "başka bir ifade girmek istiyorsanı E yada e yazın \nistemiyosanız rastgele bir değer girin: ";
	string devam;
	cin >> devam;
	return (devam == "E" || devam == "e");
}
