#include<bits/stdc++.h>
using namespace std;

struct Node;

struct Edge{
    Node* node;
    Edge* next;
};

struct Node{
    int data;
    Node* next;
    Edge* edge;
};

void print(Node* root) {
    Node* curr = root;
    while(curr != nullptr) {
        cout << "Value: " << curr->data << " Edges: " ;
        Edge* curr_edge = curr->edge ;
        while(curr_edge!=nullptr) {
            Node* neighbour = curr_edge->node ;
            cout << neighbour->data << ", " ;
            curr_edge = curr_edge->next ;
        }
        cout << endl ;
        curr = curr->next ;
    }
}

int main() {
    Node* root = nullptr;

    cout << "Add a root node with value 5" << endl ;
    Node* new_node = new Node;
    new_node->data = 5;
    new_node->edge = nullptr;
    new_node->next = nullptr;
    root = new_node ;

    print(root);

    cout << "Now Let add another node with value 8" << endl ;
    Node* node1 = new Node;
    node1->data = 8;
    node1->edge = nullptr;
    node1->next = nullptr;
    root->next = node1 ;

    print(root);

    cout << "Let add an edge from root node to new node" << endl ;
    Edge* new_edge = new Edge;
    new_edge->node = node1 ;
    new_edge->next = nullptr ;
    root->edge = new_edge ;

    print(root);
}
