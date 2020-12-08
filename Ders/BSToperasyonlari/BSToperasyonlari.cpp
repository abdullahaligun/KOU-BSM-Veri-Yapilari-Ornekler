

#include <iostream>
#include <string>
using namespace std;
struct Node
{
    int data;
    Node* left, *right;
};
class BST {
    
private:
    Node* NewNode(int);
    Node* Insert(Node*, int);
    Node* DeleteNode(Node*, int);
public:
    Node* mainRoot;
    int carpim;
    BST();
    Node* Insert(int);
    Node* DeleteNode(int data);

};
#pragma region BTS Private
Node* BST::NewNode(int data) {
    Node* p = new Node;
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}
Node* BST::Insert(Node* root, int data) {
    if (root) {
        if (data < root->data)
            root->left = Insert(root->left, data);
        else
            root->right = Insert(root->right, data);
        carpim *= root->data;
    }
    else
        root = NewNode(data);
    return root;
}
Node* BST::DeleteNode(Node* root,int data) {
    Node* p = NULL, * q = NULL;
    if (root) {
        if (root->data == data) {
            if (root->left == NULL && root->right == NULL) {
                free(root);
                return NULL;
            }
            else {
                if (root->right == NULL) {
                    p = root->left;
                    free(root);
                    return p;
                }
                else if (root->left == NULL) {
                    p = root->right;
                    free(root);
                    return p;
                }
                else {
                    p = q = root->right;
                    while (p->left) p = p->left;
                    p->left = root->left;
                    free(root);
                    return q;
                }
            }
        }
        if (root->data < data) root->right = DeleteNode(root->right, data);
        else root->left = DeleteNode(root->left, data);
        return root;
    }
    else return NULL;
}
#pragma endregion
#pragma region BTS Public
BST::BST() {
    carpim = 1;
    mainRoot = NULL;
}
Node* BST::Insert(int data) {
    carpim = 1;
    mainRoot = Insert(mainRoot, data);
    return mainRoot;
}
Node* BST::DeleteNode(int data) {
    mainRoot = DeleteNode(mainRoot, data);
    return mainRoot;
}
#pragma endregion
static BST BSTilk;
static BST BSTTek;
static BST BSTCift;
int preorder(Node* root) {
    if (root) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
    return 0;
}
int tekciftAyir(Node* root) {
    if (root) {
        if (root->data % 2 == 0)BSTCift.Insert(root->data);
        else BSTTek.Insert(root->data);
        tekciftAyir(root->left);
        tekciftAyir(root->right);
    }
    return 0;
}
int CarpimKontrolInt(BST *b, int data) {
    cout << data << " verisi eklenerek kontrolu yapiliyor" << endl;
    b -> Insert(data);
    cout << "Carpim : " << b-> carpim << " - Data : " << data << endl;
    return data == b-> carpim;
}
bool CarpimKontrolBool(BST *b, int data) {
    cout << data << " verisi eklenerek kontrolu yapiliyor" << endl;
    b->Insert(data);
    cout << "Carpim : " << b->carpim << " - Data : " << data << endl;
    return data == b->carpim;
}
int main()
{
    
    cout << "BST'ler tanimlandi..." << endl;
    cout << "BSTilk dolduruluyor..." << endl;
    for (int  i = 0; i < 20; i++)
    {
        int s = rand() %100;
        BSTilk.Insert(s);
        cout << s << " degeri BSTilk'e eklendi"<< endl;
    }
    cout << "BSTilk dolduruldu. Preorder ciktisi..." << endl;
    preorder(BSTilk.mainRoot);
    cout << endl;
    cout << "Tekler ve Ciftler ayriliyor..." << endl;
    tekciftAyir(BSTilk.mainRoot); 
    cout << "Tekler ve Ciftler ayrildi." << endl;
    cout << "Tekler preorder" << endl;
    preorder(BSTTek.mainRoot);
    cout << endl;
    cout << "Ciftler preorder" << endl;
    preorder(BSTCift.mainRoot);
    cout << endl;
    cout << endl;
    cout << endl;

    BST *carpim = new BST;
    cout << "Carpim kontrolu basladi" << endl;
    cout << "Sonuc : " << boolalpha << CarpimKontrolBool(carpim, 1) << endl;
    cout << "Sonuc : " << to_string(CarpimKontrolInt(carpim, 1)) << endl;
    cout << "Sonuc : " << boolalpha << CarpimKontrolBool(carpim, 2) << endl;
    cout << "Sonuc : " << to_string(CarpimKontrolInt(carpim, 2)) << endl;
    cout << "Sonuc : " << boolalpha << CarpimKontrolBool(carpim, 2) << endl;
    cout << "Sonuc : " << to_string(CarpimKontrolInt(carpim, 8)) << endl;
    preorder(carpim -> mainRoot);
}
/*BST'ler tanimlandi...
BSTilk dolduruluyor...
41 degeri BSTilk'e eklendi
67 degeri BSTilk'e eklendi
34 degeri BSTilk'e eklendi
0 degeri BSTilk'e eklendi
69 degeri BSTilk'e eklendi
24 degeri BSTilk'e eklendi
78 degeri BSTilk'e eklendi
58 degeri BSTilk'e eklendi
62 degeri BSTilk'e eklendi
64 degeri BSTilk'e eklendi
5 degeri BSTilk'e eklendi
45 degeri BSTilk'e eklendi
81 degeri BSTilk'e eklendi
27 degeri BSTilk'e eklendi
61 degeri BSTilk'e eklendi
91 degeri BSTilk'e eklendi
95 degeri BSTilk'e eklendi
42 degeri BSTilk'e eklendi
27 degeri BSTilk'e eklendi
36 degeri BSTilk'e eklendi
BSTilk dolduruldu. Preorder ciktisi...
41 34 0 24 5 27 27 36 67 58 45 42 62 61 64 69 78 81 91 95
Tekler ve Ciftler ayriliyor...
Tekler ve Ciftler ayrildi.
Tekler preorder
41 5 27 27 67 45 61 69 81 91 95
Ciftler preorder
34 0 24 36 58 42 62 64 78


Carpim kontrolu basladi
1 verisi eklenerek kontrolu yapiliyor
Carpim : 1 - Data : 1
Sonuc : true
1 verisi eklenerek kontrolu yapiliyor
Carpim : 1 - Data : 1
Sonuc : 1
2 verisi eklenerek kontrolu yapiliyor
Carpim : 1 - Data : 2
Sonuc : false
2 verisi eklenerek kontrolu yapiliyor
Carpim : 2 - Data : 2
Sonuc : 1
2 verisi eklenerek kontrolu yapiliyor
Carpim : 4 - Data : 2
Sonuc : false
8 verisi eklenerek kontrolu yapiliyor
Carpim : 8 - Data : 8
Sonuc : 1
1 1 2 2 2 8
*/