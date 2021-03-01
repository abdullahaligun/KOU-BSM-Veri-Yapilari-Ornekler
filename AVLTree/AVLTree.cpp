//abdullah ali güb 191307005

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
    int height;
};

int Height(Node* root)
{
    if (!root) return 0;
    return root->height;
}

int Max(int a, int b)
{
    return (a > b) ? a : b;
}
Node* NewNode(int data) {
    Node* AVLNode = new Node();
    AVLNode->data = data;
    AVLNode->left = NULL;
    AVLNode->right = NULL;
    AVLNode->height = 1;
    return AVLNode;
}
int HeightControl(Node* root)
{
    if (root == NULL)
        return 0;
    return Height(root->left) - Height(root->right);
}



Node* rightRotate(Node* root)
{
    Node* temp = root->left;
    Node* temp2 = temp->right;

    
    temp->right = root;
    root->left = temp2;

    root->height = Max(Height(root->left),Height(root->right)) + 1;
    temp->height = Max(Height(temp->left),Height(temp->right)) + 1;

    return temp;
}


Node* leftRotate(Node* root)
{
    Node* temp = root->right;
    Node* temp2 = temp->left;

    temp->left = root;
    root->right = temp2;

    root->height = Max(Height(root->left),Height(root->right)) + 1;
    temp->height = Max(Height(temp->left),Height(temp->right)) + 1;

    return temp;
}

Node* Insert(Node* root, int data) {

    if (!root) return NewNode(data);

    if (data < root->data) root->left = Insert(root->left, data);
    else if (data > root->data) root->right = Insert(root->right, data);
    else return root;

    root->height = 1 + Max(Height(root->left), Height(root->right));

    int heightControl = HeightControl(root);
    // sag
    if (heightControl > 1 && data < root->left->data)
        return rightRotate(root);

    // sol
    if (heightControl < -1 && data > root->right->data)
        return leftRotate(root);

    // sol sag
    if (heightControl > 1 && data > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    //sag sol
    if (heightControl < -1 && data < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    
    return root;
}
Node* DeleteNode(Node* root, int data) {
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
        root->height = Max(Height(root->left), Height(root->right)) + 1;
        int heightControl = HeightControl(root);
        // sag
        if (heightControl > 1 && data < root->left->data)
            return rightRotate(root);

        // sol
        if (heightControl < -1 && data > root->right->data)
            return leftRotate(root);

        // sol sag
        if (heightControl > 1 && data > root->left->data)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        //sag sol
        if (heightControl < -1 && data < root->right->data)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        return root;
    }
    else return NULL;
}
Node* Search(Node* root, int data) {
    if (root) {
        if (root->data == data) return root;
        if (root->data < data) root = Search(root->right, data);
        else root = Search(root->left, data);
    }
    return root;
}
void Preorder(Node* root)
{
    if (root)
    {
        cout << root->data << " - ";
        Preorder(root->left);
        Preorder(root->right);
    }
}
int main()
{
    Node* alininRootu = NULL;

    int islem;
    int data;
    
    do
    {
        cout << "1- ekle\n2- Cikar\n3- Ara\n4- Preorder Yazdir\n5- Cik\nIslem Seciniz : ";
        cin >> islem;
        switch (islem)
        {
        case 1 : 
            cout << "Eklenmesi Icin Tam sayi Giriniz : ";
            cin >> data;
            alininRootu = Insert(alininRootu, data);
            break;
        case 2 :
            cout << "Silinmesi Icin Tam sayi giriniz : ";
            cin >> data;
            alininRootu = DeleteNode(alininRootu, data);
            break;
        case 3 : 
            cout << "Aranmasi Icin Tam sayi giriniz : ";
            cin >> data;
            cout << Search(alininRootu, data) << endl;
            break;
        case 4 :
            cout << "preorder ciktisi : ";
            Preorder(alininRootu);
            cout << endl;
        default:
            break;
        }
    } while (islem != 5);

    return 1903;
}
