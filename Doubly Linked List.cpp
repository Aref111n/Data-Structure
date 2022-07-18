#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct node {
  int data ;
  node* next ;
  node* prev ;
};

node* push_back(node* &head, int x) {
  node* new_node = new node ;
  new_node->data = x ;
  new_node->next = nullptr ;
  new_node->prev = nullptr ;

  if(head==nullptr)
    head = new_node ;
  else {
    node* curr = head ;
    while(curr->next!=nullptr) {
      curr = curr->next ;
    }

    curr->next = new_node ;
    new_node->prev = curr ;
  }

  return head;
}

node* push_front(node* head, int x) {
  node* new_node = new node ;
  new_node->data = x ;
  new_node->next = head ;
  new_node->prev = nullptr ;
  head->prev = new_node ;
  return new_node;
}

node* insert_after_pos(node* head, int x, int pos) {
  node* new_node = new node ;
  new_node->data = x ;
  new_node->next = nullptr ;
  new_node->prev = nullptr ;

  int c=0 ;
  node* curr = head ;
  while(curr!=nullptr) {
    c++ ;
    if(c==pos) {
      break;
    }
    curr = curr->next ;
  }

  new_node->next = curr->next ;
  (curr->next)->prev = new_node ;
  curr->next = new_node ;
  new_node->prev = curr ;

  return head ;
}

node* insert_after_val(node* head, int x, int val) {
  node* new_node = new node ;
  new_node->data = x ;
  new_node->next = nullptr ;
  new_node->prev = nullptr ;

  int c=0 ;
  node* curr = head ;
  while(curr!=nullptr) {
    c++ ;
    if(curr->data==val) {
      break;
    }
    curr = curr->next ;
  }

  new_node->next = curr->next ;
  (curr->next)->prev = new_node ;
  curr->next = new_node ;
  new_node->prev = curr ;

  return head ;
}

void print(node* head) {
  node* curr = head ;

  while(curr!=nullptr) {
    cout << curr->data << " " ;
    curr = curr->next ;
  }
  cout << endl ;
}

node* Delete(node* head, int x) {
  node* curr = head ;

  while(curr!=nullptr) {
    if(curr->data == x) {
      break;
    }
    curr = curr->next ;
  }

  (curr->prev)->next = curr->next ;
  (curr->next)->prev = curr->prev ;

  return head ;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
  freopen("outpp.txt", "w", stdout);
#endif
  node* head = nullptr ;
  node* prev_node = nullptr ;

  head = push_back(head, 5) ;
  head = push_back(head, 6) ;
  head = push_back(head, 11) ;
  print(head) ; //output: 5 6 11

  head = push_front(head, 2) ;
  head = push_front(head, 1) ;
  print(head) ; //output: 1 2 5 6 11

  head = insert_after_pos(head, 7, 3) ;
  print(head) ; //output: 1 2 5 7 6 11

  head = insert_after_val(head, 3, 7) ;
  print(head) ; //output: 1 2 5 7 3 6 11 

  head = Delete(head, 7) ;
  print(head) ; //output: 1 2 5 3 6 11
  return 0;
}
