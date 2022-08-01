#include<bits/stdc++.h>
#define ll long long
using namespace std ;

struct bst {
	int data ;
	bst *left, *right ;
};

void insert(bst *root, bst *temp) {
	if(root->data > temp->data) {
		if(root->left == NULL) {
			root->left = temp ;
			return ;
		}
		else
			insert(root->left, temp) ;
	}
	else if(root->data < temp->data) {
		if(root->right == NULL) {
			root->right = temp ;
			return;
		}
		else
			insert(root->right, temp) ;
	}
	else
		return;
}

void inorder(bst *root) {
	if(root == NULL)
		return ;

	inorder(root->left) ;
	cout << root->data << " " ;
	inorder(root->right) ;
}

void preorder(bst *root) {
	if(root == NULL)
		return ;

	cout << root->data << " " ;
	preorder(root->left) ;
	preorder(root->right) ;
}

void postorder(bst *root) {
	if(root == NULL)
		return ;

	postorder(root->left) ;
	postorder(root->right) ;
	cout << root->data << " " ;
}

bool find_node(bst *root, int x) {
	if(root==NULL)
		return false ;
	if(root->data == x)
		return true ;

	if(root->data > x)
		return find_node(root->left, x) ;
	else
		return find_node(root->right, x) ;
}

bst* successor(bst *curr) {
	if(curr==NULL || curr->left==NULL)
		return curr ;
	return successor(curr->left) ;
}

bst* erase(bst *root, int x) {
	if(root == NULL)
		return NULL ;

	if(root->data > x) 
		root->left = erase(root->left, x) ;
	else if(root->data < x)
		root->right = erase(root->right, x) ;
	else {
		if(root->left==NULL) {
			bst *temp = root->right ;
			delete root ;
			return temp ;
		}
		else if(root->right==NULL) {
			bst *temp = root->left ;
			delete root ;
			return temp ;
		}

		bst *temp = successor(root->right) ;
		root->data = temp->data ;
		root->right = erase(root->right, temp->data) ;
	}

	return root ;
}

int main() {
#ifndef ONLINE_JUDGE
 	freopen("inp.txt", "r", stdin);
 	freopen("outp.txt", "w", stdout);
#endif

 	bst *root = NULL ;

 	while(1) {
 		int x ;
 		cin >> x ;
 		if(x==-1)
 			break;
 		bst *temp = new bst;
 		temp->data = x ;
 		temp->left = NULL ;
 		temp->right = NULL ;

 		if(root == NULL)
 			root = temp ;
 		else
 			insert(root, temp) ;
 	}

 	inorder(root) ;
 	cout << endl ;
 	preorder(root) ;
 	cout << endl ;
 	postorder(root) ;
 	cout << endl ;

 	cout << (find_node(root, 22)?"found":"not found") << endl ;
 	cout << (find_node(root, 23)?"found":"not found") << endl ;

 	root = erase(root, 19); 
 	inorder(root);
}
