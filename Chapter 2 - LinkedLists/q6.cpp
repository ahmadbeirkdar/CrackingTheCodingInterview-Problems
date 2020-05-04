#include <iostream>
#include <deque>


struct Node {
  char data;
  Node * next;
  Node ( char c ) : data{ c }, next{ nullptr } { }
};

/**
 * [insert helper routine to insert new node at head]
 * @param head [current head of the list]
 * @param c    [new node's data]
 */
void insert( Node * & head, char c ) {
  Node * newNode = new Node(c);
  newNode->next = head;
  head = newNode;
}

/**
 * [printList = helper routine to print the list]
 * @param head [head of the list]
 */
void printList( Node * head ) {
  while( head ) {
    std::cout << head->data << "-->";
    head = head->next;
  }
  std::cout << "nullptr" << std::endl;
}

//Time - O(n)
//Space - O(1)
bool isPalindromeIter(Node* list){
    std::deque<char> reverse;
    std::deque<char> normal;
    while(list){
        reverse.push_front(list->data);
        normal.push_back(list->data);
        list = list->next;
    }
    return reverse == normal;

}

int main()
{
  Node * head1 = nullptr;
  insert( head1, 'a' );
  insert( head1, 'b' );
  insert( head1, 'c' );
  insert( head1, 'c' );
  insert( head1, 'b' );
  insert( head1, 'a' );
  std::cout << "List 1: ";
  printList(head1);
  if ( isPalindromeIter(head1) ) {
    std::cout << "List 1 is pallindrome list\n";
  } else {
    std::cout << "List 1 is not a pallindrome list\n";
  }
  std::cout << "List 1: ";
  printList(head1);

    Node * head2 = nullptr;
  insert( head2, 'r');
  insert( head2, 'a');
  insert( head2, 'd');
  insert( head2, 'a');
  insert( head2, 'c');
  std::cout << "List 2: ";
  printList(head2);

  if ( isPalindromeIter( head2 ) ) {
    std::cout << "List 2 is pallindrome list\n";
  } else {
    std::cout << "List 2 is not a pallindrome list\n";
  }

  return 0;
}