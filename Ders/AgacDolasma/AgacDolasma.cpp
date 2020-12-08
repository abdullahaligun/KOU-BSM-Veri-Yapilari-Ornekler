//abdullah ali g�n 191307005
#include <iostream>
using namespace std;

struct node{
	int data;
	node* left, * right;
};

typedef struct node BTREE;

// yeni k�k olu?turma
BTREE* new_node(int data) {
	BTREE* p = new BTREE;
	p->data = data;
	p->left = NULL;
	p->right = NULL;
	return p;
}
BTREE* insert(BTREE* root, int data) {
	if (root) {
		if (data < root->data)
			root->left = insert(root->left, data);
		else
			root->right = insert(root->right, data);
	}
	else
		root = new_node(data);
	return root;
}

void preorder(BTREE* root) {
        if (root) {
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }
    void inorder(BTREE* root) {
        if (root) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }
    void postorder(BTREE* root) {
        if (root) {
            inorder(root->left);
            inorder(root->right);
            cout << root->data << " ";
        }
}

int main() {
	BTREE* benimRootum = NULL; //alinin rootu =D

	benimRootum = insert(benimRootum, 27);
	benimRootum = insert(benimRootum, 18);
	benimRootum = insert(benimRootum, 39);
	benimRootum = insert(benimRootum, 14);
	benimRootum = insert(benimRootum, 22);
	benimRootum = insert(benimRootum, 29);
	benimRootum = insert(benimRootum, 42);
	benimRootum = insert(benimRootum, 2);
	benimRootum = insert(benimRootum, 17);
	benimRootum = insert(benimRootum, 12);
	benimRootum = insert(benimRootum, 24);
	benimRootum = insert(benimRootum, 34);
	benimRootum = insert(benimRootum, 15);
	benimRootum = insert(benimRootum, 23);

	cout << "preorder" << endl;
	preorder(benimRootum);
	cout << endl;
	cout << "inorder" << endl;
	inorder(benimRootum);
	cout << endl;
	cout << "postorder" << endl;
	postorder(benimRootum);
	return 1903;
}
