#include<bits/stdc++.h>
using namespace std;

struct node {
    int data ;
    node* next ;
};

node* push(node* head, int x) {
    node* new_node = new node ;
    new_node->data = x ;
    new_node->next = nullptr ;

    if(head==nullptr) {
        head = new_node ;
    }
    else {
        node* curr = head ;
        while(curr->next != nullptr) {
            curr = curr->next ;
        }

        curr->next = new_node ;
    }

    return head ;
}

node* pop(node* head) {
    head = head->next ;
    return head ;
}

int front(node* head) {
    return head->data ;
}

int back(node* head) {
    node* curr = head ;
    while(curr->next != nullptr)
        curr = curr->next ;

    return  curr->data ;
}

int length(node* head) {
    node* curr = head ;
    int sz=0 ;
    while(curr->next != nullptr) {
        sz++ ;
        curr = curr->next ;
    }

    return  sz+1 ;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
  freopen("outpp.txt", "w", stdout);
#endif
    
    node* head = nullptr ;
    head = push(head, 5) ;
    head = push(head, 1) ;
    head = push(head, 4) ;
    head = push(head, 2) ;
    head = push(head, 7) ;
    head = push(head, 10) ;

    cout << length(head) << endl ; //6

    cout << front(head) << endl ; //5
    cout << back(head) << endl ;  //10

    head = pop(head) ;
    cout << front(head) << endl ; //1
    cout << back(head) << endl ; //10


}
