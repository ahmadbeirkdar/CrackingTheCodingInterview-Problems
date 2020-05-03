#include <iostream>
#include <random>

struct Node {
  int data;
  Node * next;
  Node( int d ) : data{ d }, next{ nullptr } { }
};

void insert( Node * & head, int data ) {
  Node * newNode = new Node(data);
  if ( head == nullptr ) {
    head = newNode;
  } else {
    Node * curr = head;
    while( curr->next ) {
      curr = curr->next;
    }
    curr->next = newNode;
  }
}

void printList( Node * head ) {
  while ( head ) {
    std::cout << head->data << "-->";
    head = head->next;
  }
  std::cout << "nullptr" << std::endl;
}


// Time - O(n)
// Space - O(1)
Node* partition(Node* head, int x){
    Node* big = nullptr;
    Node* bighead = nullptr;
    Node* small = nullptr;
    Node* smallhead = nullptr;
    Node* curr = head;
    while(curr){
        if(curr->data < x){
            if(small == nullptr){
                small = curr;
                smallhead = small;
            }
            else{
                small->next = curr;
                small = small->next;
            }
            
        }
        else{
            if(big == nullptr){
                big = curr;
                bighead = big;
            }
            else{
                big->next = curr;
                big = big->next;
            }
        }
        curr = curr->next;
    }
    small->next = bighead;
    big->next = nullptr;
    return smallhead;

}

int main() {
    Node * head = nullptr;
    for ( int i = 0; i < 10; ++i ) {
            insert(head, rand() % 9);
        }
    std::cout << "List before partition around 5:\n";
    printList(head);
    std::cout << "List after partition around 5:\n";
    printList(partition(head, 5));
    return 0;
}
