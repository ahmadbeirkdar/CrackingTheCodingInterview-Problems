#include <iostream>

struct Node {
    char data;
    Node * next;
    Node( char c ) : data{ c }, next{ nullptr } { }
};

void printList(Node* head){
    while(head){
        std::cout<<head->data<<"-->";
        head = head->next;
    }
    std::cout<<"nullptr"<<std::endl;
}

// Space and Time O(1)
void deleteNode(Node* node){
    if(node == nullptr || node->next == nullptr){
        std::cout << "null" <<std::endl;
        return;
    }
    Node* new_node = node->next;
    node->data = new_node->data;
    node->next = new_node->next;
    delete new_node;
}

int main() {
    Node * head = new Node('a');
    head->next = new Node('b');
    head->next->next = new Node('c');
    head->next->next->next = new Node('d');
    head->next->next->next->next = new Node('e');
    std::cout << "List before deletion:\n";
    printList(head);
    std::cout << "Deleting node containing data as 'c'\n";
    deleteNode(head->next->next);
    std::cout << "List after deletion:\n";
    printList(head);
    return 0;
}