#include <iostream>
#include <unordered_set>

struct Node {
  int data;
  Node * next;
  Node( int d ) : data{ d }, next{ nullptr } { }
};
void insert( Node * & head, int data )
{
  Node * newNode = new Node( data );
  if ( head == nullptr ) {
    head = newNode;
  } else {
    Node * temp = head;
    while( temp->next != nullptr ) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

void printList( Node * head )
{
  while( head ) {
    std::cout << head->data << "-->";
    head = head->next;
  }
  std::cout << "NULL" << std::endl;
}

void detectAndRemoveCycle(Node* head){
    std::unordered_set<Node*> test;
    Node* curr = head;
    while(1){
        if(test.find(curr->next) != test.end()){
            curr->next = nullptr;
            return;
        }
        test.insert(curr);
        curr = curr->next;
    }
}

int main()
{
    Node * head = nullptr;
    insert( head , 1 );
    insert( head , 2 );
    insert( head , 3 );
    insert( head , 4 );
    insert( head , 5 );
    std::cout << "Current List:\n";
    printList( head );
    std::cout << "Inserting loop, connecting 5 to 2 \n";
    head->next->next->next->next->next = head->next;
    std::cout << "Detecting and deleting loop\n";
    detectAndRemoveCycle(head);
    std::cout << "Back to the same old list\n";
    printList( head );
    return 0;
}