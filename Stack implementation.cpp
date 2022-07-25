#include<bits/stdc++.h>
using namespace std;

struct node {
    int data ;
    node* prev ;
};

node* push(node* top, int x) {
    node* new_node = new node ;
    new_node->data = x ;
    new_node->prev = nullptr ;

    if(top==nullptr) 
        top = new_node ;
    else {
        new_node->prev = top ;
        top = new_node ;
    }

    return top ;
}

int Top(node* top) {
    return top->data ;
}

node* pop(node* top) {
    if(top==nullptr) {
        cout << "UNDERFLOW" << endl ;
        return nullptr ;
    }
    top = top->prev ;
    return top ;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
  freopen("outpp.txt", "w", stdout);
#endif
    
    node* top = nullptr ;
    top = push(top, 3) ;
    top = push(top, 2) ;
    top = push(top, 5) ;
    top = push(top, 9) ;
    top = push(top, 12) ;

    while(top!=nullptr) {
        cout << Top(top) << " " ;
        top = pop(top) ;
    }
}
