#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next = NULL;
        Node(){this->data=0;}
};

void push_node(Node** head_ref, int new_data){
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

Node* middle_node(Node* head){
    Node *slow = head, *fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    Node* head = NULL;
    push_node(&head, 1);
    push_node(&head, 2);
    push_node(&head, 3);
    push_node(&head, 4);
    push_node(&head, 5);
    push_node(&head, 6);
    push_node(&head, 7);
    push_node(&head, 8);
    //push_node(&head, 9);

    cout << "Middle node data of the list is: " << middle_node(head)->data << endl;
    return 0;
}