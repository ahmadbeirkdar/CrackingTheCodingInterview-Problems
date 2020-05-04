#include <iostream>

struct Node {
  int data;
  Node * next;
  Node ( int d ) : data{ d }, next{ nullptr } { }
};

/**
 * [insert - insert a new node at head of the list]
 * @param head [head of the list]
 * @param data [new node's data]
 */
void insert( Node * & head, int data ) {
  Node * newNode = new Node(data);
  newNode->next = head;
  head = newNode;
}

/**
 * [printList - print the list]
 * @param head [head of the list]
 */
void printList( Node * head ) {
  while ( head ) {
    std::cout << head->data << "-->";
    head = head->next;
  }
  std::cout << "nullptr" << std::endl;
}


Node* add_iterative(Node* list1, Node* list2){

    Node* list3 = nullptr;
    Node* list3curr = nullptr;
    int carry = 0;
    int sum = 0;
    while(list1 || list2){
        sum = 0;
        sum = carry + (list1 ? list1->data : 0) + (list2 ? list2->data : 0);
        if(sum>9){
            sum = sum%10;
            carry = 1;
        }
        else{
            carry = 0;
        }
        Node* temp = new Node(sum);
        if(list3 == nullptr){
            list3 = temp;
        }else{
            list3curr->next = temp;
        }
        list3curr = temp;
        if(list1){
            list1 = list1->next;
        }
        if(list2){
            list2 = list2->next;
        }
    }
    return list3;
}

Node* add_recursive(Node* list1, Node* list2, int carry){
    if (list1 == nullptr && list2 == nullptr) {
        return nullptr;
    }
    int sum = carry;
    if(list1){
        sum+=list1->data;
    }
    if(list2){
        sum+=list2->data;
    }
    if(sum>9){
        sum = sum%10;
        carry = 1;
    }
    Node* list3 = new Node(sum);
    list3->next = add_recursive(list1 ? list1->next : nullptr, list2 ? list2->next : nullptr, carry);

    return list3;
}

int main()
{
  //making list 1 for number 617
  Node * list1 = nullptr;
  insert(list1, 6);
  insert(list1, 1);
  insert(list1, 7);
  std::cout << "List1:  ";
  printList(list1);

  //making list2 for number 295
  Node * list2 = nullptr;
  insert(list2, 2);
  insert(list2, 9);
  insert(list2, 5);
  std::cout << "List2:  ";
  printList(list2);

  Node * list3 = add_iterative(list1, list2);
  std::cout << "Iterative Solution: \n";
  std::cout << "List3:  ";
  printList(list3);

  Node * list4= add_recursive(list1, list2, 0);
  std::cout << "Recursive Solution: \n";
  std::cout << "List4:  ";
  printList(list4);

  return 0;
}