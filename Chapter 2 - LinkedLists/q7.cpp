#include <iostream>


struct Node {
  int data;
  Node * next;
  Node( int d ) : data{ d }, next{ nullptr } { }
};

/**
 * [printList Helper routine to print list]
 * @param head [head of the list]
 */
void printList( Node * head )
{
  while( head ) {
    std::cout << head->data << "-->";
    head = head->next;
  }
  std::cout << "NULL" << std::endl;
}
int len( Node * head ){
  int count = 0;
  while(head){
    head = head->next;
    count++;
  }
  return count;
}

// Time - O(n^2)
//Space - O(1)
Node* inter(Node* list1, Node* list2){
    int list1len = len(list1);
    int list2len = len(list2);

    Node* l1 =  list1len >= list2len ? list1: list2;
    Node* l2 =  list1len >= list2len ? list2: list1;
    while(l1){
        l2 =  list1len >= list2len ? list2: list1;
        while(l2){
            if(l1 == l2){
                return l1;
            }
            l2 = l2->next;
        }
        l1 = l1->next;
    }
    return nullptr;
}






int main()
{
  Node * list1 = new Node(3);
  list1->next = new Node(6);
  list1->next->next = new Node(9);
  list1->next->next->next = new Node(12);
  list1->next->next->next->next = new Node(15);
  list1->next->next->next->next->next = new Node(18);

  Node * list2 = new Node(7);
  list2->next = new Node(10);
  list2->next->next = list1->next->next->next;

  printList(list1);
  printList(list2);

  Node * intersectingNode = inter( list1 , list2 );
  if (intersectingNode) {
    std::cout << "Intersecting Node of lists is :" << intersectingNode->data << std::endl;
  } else {
    std::cout << "Lists do not interset" << std::endl;
  }
  return 0;
}