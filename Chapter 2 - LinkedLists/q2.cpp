#include <iostream>
#include <unordered_set>

struct Node{
    int data = 0;
    Node *next = nullptr;
};

void push(Node** head, int new_data){
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}

void printList(Node* head){
    while(head){
        std::cout<<head->data<<"-->";
        head = head->next;
    }
    std::cout<<"nullptr"<<std::endl;
}

// Random from stackoverflow
int random(int min, int max) //range : [min, max)
{
   static bool first = true;
   if (first) 
   {  
      srand( time(NULL) ); //seeding for the first time only!
      first = false;
   }
   return min + rand() % (( max + 1 ) - min);
}

// Time - O(n)
// Space = o(1)
Node* kthElem(Node* head, int k){
    Node* p1 = head;
    Node* p2 = head;
    for(int i = 0; i < k; i++){
        if(p1)
            p1 = p1->next;
        else
            return nullptr;
    }
    while(p1){
        p1 = p1->next;
        p2 = p2->next;
    }
    return p2;
}


int main() {
	std::cout << "Method 1 : \n";
	Node * head = nullptr;
	for ( int i = 0; i < 10; ++i ) {
		push(&head, random(1,7));
	}
	printList(head);
	
	printList(kthElem(head, 3));

	std::cout << "Method 2 : \n";
	Node * head1 = nullptr;
	for ( int i = 0; i < 10; ++i ) {
		push(&head1, random(1,7));
	}
	printList(head1);

	printList(kthElem(head1, 4));

	return 0;
}