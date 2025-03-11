#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;
};

void print(node* head) {
  node* curr = head ;

  while(curr!=nullptr) {
    cout << curr->data << " " ;
    curr = curr->next ;
  }
  cout << endl ;
}

int main() {
    //Allocating the head node
    node* head = nullptr;

    node* new_node = new node;
    new_node->data = 5 ;
    new_node->next = nullptr;

    head = new_node ;

    print(head);

    //Allocting a new node
    node* first = new node;
    first->data = 2 ;
    first->next = nullptr;

    head->next = first ;

    print(head) ;
}

