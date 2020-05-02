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

//temp buffer
//Space O(n)
//Time O(n)
void removeDupe1(Node* head){
    std::unordered_set<int> buff;
    Node* prev = nullptr;
    Node* curr = head;
    while(curr){
        if(buff.find(curr->data)==buff.end()){
            buff.insert(curr->data);
            prev = curr;
        }
        else{
            prev->next = curr->next;
            delete(curr);
        }
        curr = curr->next;
    }
}


//No temp buffer
//Space O(1)
//Time O(n^2)
void removeDupe2(Node* head){
    Node* curr = head;
    while(curr){
        Node* runner = curr;
        while(runner->next){
            if(curr->data == runner->next->data){
                runner->next = runner->next->next;
            }
            else{
                runner = runner->next;
            }
        }
        curr = curr->next;
    }
}



int main() {
	std::cout << "Method 1 : \n";
	Node * head = nullptr;
	for ( int i = 0; i < 10; ++i ) {
		push(&head, random(1,7));
	}
	printList(head);
	removeDupe1(head);
	printList(head);

	std::cout << "Method 2 : \n";
	Node * head1 = nullptr;
	for ( int i = 0; i < 10; ++i ) {
		push(&head1, random(1,7));
	}
	printList(head1);
	removeDupe2(head1);
	printList(head1);
	return 0;
}