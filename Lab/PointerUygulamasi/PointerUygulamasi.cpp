//Abdullah Ali GÜN 191307005

#include <iostream>
using namespace std;

int main()
{
    int i = 41;
    int* ptr1 = &i;
    int** ptr2 = &ptr1;
    int*** ptr3 = &ptr2;
    int**** ptr4 = &ptr3;

    cout << i << endl;
    cout << *ptr1 << endl;
    cout << **ptr2 << endl;
    cout << ***ptr3 << endl;
    cout << ****ptr4 << endl;

    cout << endl;
    cout << endl;
    cout << endl;

    cout << i << endl;
    cout << *ptr1 << "\t" << ptr1 << endl;
    cout << **ptr2 << "\t" << *ptr2 << "\t" << ptr2 << endl;
    cout << ***ptr3 << "\t" << **ptr3 << "\t" << *ptr3 << "\t" << ptr3 << endl;
    cout << ****ptr4 << "\t" << ***ptr4 << "\t" << **ptr4 << "\t" << *ptr4 << "\t" << ptr4 << endl;

    return 0;
}
/* İşlem Yorumu
41
41
41
41
41



41
41      0045F8C8
41      0045F8C8        0045F8BC
41      0045F8C8        0045F8BC        0045F8B0
41      0045F8C8        0045F8BC        0045F8B0        0045F8A4

Pointerin pointerini tanımlamak için kaçıncı pointeri ise o kadar '*' koyuyoruz.
yazdırırken de her  '*' ile bir geriye giziyoruz
örnek :
burada
cout << ****ptr4 << "\t" << ***ptr4 << "\t" << **ptr4 << "\t" << *ptr4 << "\t" << ptr4 << endl;

ptr4 > ptr3 ün adresini verirken
*ptr4 > ptr2 nin
**ptr4 > ptr1 in
***ptr4 > i nin adresini
****ptr4 > i sayısını veriyor.
*
///
ek olarak dikatimi çeken diğer bir konu ise her bir pointerin pointeri bellekte ondan önceki bir adreste tutuluyor.
*/

