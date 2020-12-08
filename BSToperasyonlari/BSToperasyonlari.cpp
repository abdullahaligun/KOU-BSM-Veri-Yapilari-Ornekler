

#include <iostream>
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


}
