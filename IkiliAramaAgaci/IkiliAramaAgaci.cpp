//Abdullah Ali GUN 191307005



#include <iostream>
#include <string>
using namespace std;
struct Node
{
    int data;
    Node* left, * right;
};
class BST {

private:
    Node* NewNode(int);
    Node* Insert(Node*, int);
    Node* DeleteNode(Node*, int);
    Node* Search(Node*,int);
public:
    Node* mainRoot;
    BST();
    Node* Insert(int);
    Node* DeleteNode(int);
    Node* Search(int);

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
    }
    else
        root = NewNode(data);
    return root;
}
Node* BST::DeleteNode(Node* root, int data) {
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
Node* BST::Search(Node* root, int data) {
    if (root) {
        if (data == root->data) return root;
        else if (data < root->data) return Search(root->left, data);
        else return Search(root->right, data);
    }
    else return NULL;
}
#pragma endregion
#pragma region BTS Public
BST::BST() {
    mainRoot = NULL;
}
Node* BST::Insert(int data) {
    mainRoot = Insert(mainRoot, data);
    return mainRoot;
}
Node* BST::DeleteNode(int data) {
    mainRoot = DeleteNode(mainRoot, data);
    return mainRoot;
}
Node* BST::Search(int data) {
    return Search(mainRoot, data);
}
#pragma endregion
BST ilkAgac;
BST yeni;
bool ilkSayi = true;
Node* silinen;
int yeniAgac(Node* root) {
    if (root) {
        yeni.Insert(root->data);
        yeniAgac(root->left);
        yeniAgac(root->right);
    }
    return 0;
}
int preorder(Node* root) {
    if (root) {
        cout << root->data << " ";
        if (root->data >= 60 && root->data <= 70 && ilkSayi) {
            ilkSayi = false;
            
            silinen = root;            
        }
        preorder(root->left);
        preorder(root->right);
    }
    return 0;
}
int yenipreorder(Node* root) {
    if (root) {
        ilkAgac.DeleteNode(root->data);
        cout << root->data << " ";        
        yenipreorder(root->left);
        yenipreorder(root->right);
    }
    return 0;
}


int main()
{
    
    int eklenecekler[24] = { 50, 28, 46, 80, 47, 96, 14, 10, 68, 20, 34, 71,  61, 41, 82, 64, 13, 18, 27, 95, 74, 81, 11, 36 };
    for (int i = 0; i < 24; i++)
    {
        ilkAgac.Insert(eklenecekler[i]);
    }
    
    int aranacakSayi;
    do
    {
        cout << "Aranacak Sayiyi Girin (Cikmak icin -1 girin)" << endl;
        cin>>aranacakSayi;
        cout << ilkAgac.Search(aranacakSayi) << endl;
    } while (aranacakSayi != -1);
    cout << "Silinmeden once agac : ";
    preorder(ilkAgac.mainRoot);
    cout << endl;
    yeniAgac(silinen);
    ilkAgac.DeleteNode(silinen->data);
    cout << "Silinmeden sonra agac : ";
    preorder(ilkAgac.mainRoot);
    cout << endl;
    cout << "yeni agac : ";
    yenipreorder(yeni.mainRoot);
    cout << endl;
    cout << "Aktarimdan sonra agac : ";
    preorder(ilkAgac.mainRoot);
    cout << endl;
}

/*İkili arama ağacı-2
Aşağıdaki işlemleri tek bir cpp dosyası içinde yapıp ilgili .cpp dosyasını yükleyiniz. 
Her hafta yazılan kodun en üstünde açıklama satırı olarak adınız soyadınız numaranız olmalıdır.



a-) “50, 28, 46, 80, 47, 96, 14, 10, 68, 20, 34, 71,  61, 41, 82, 64, 13, 18, 27, 95, 74, 81, 11, 36” değerlerine sahip düğümlerini oluşturacağınız ikili ağaç yapısına yerleştiren program kodunu yazınız. 

b-) Yazacağınız bir fonksiyonla, a şıkkında verilen ağaç yapısı üzerinde dışarıdan girilen “x” sayısının bulunup bulunmadığını tespit eden, bulunduğu takdirde adresini, aksi takdirde “null” değerini döndüren fonksiyonun program kodunu yazınız. 

c-) Ağaçta preorder dolaşma esnasında değeri 60-70 arasındaki ilk sayının olduğu düğümü silip ağacı yeniden yapılandırın.

d-) c şıkkında silmek için tespit edilen sayı kök kabul edilerek, o ve ondan sonraki bütün düğümleri yeni bir ağaca aktaran programı yazınız. Oluşturulan yeni ağacın düğümlerini preorder dolaşarak ekrana yazınız.*/
