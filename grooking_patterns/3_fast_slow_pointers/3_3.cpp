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

void cycle_length(Node* slow, int &length){
    Node* current = slow;
    while(1){
        current = current->next;
        length++;
        if(current == slow) break;
    }
}

Node* start_node(Node* head, int &length){
    Node *fast = head, *slow = head;
    while(length--) fast = fast->next;
    while(slow != fast) slow = slow->next, fast = fast->next;
    return slow;
}

Node* cycle_start(Node* head){
    Node *slow = head, *fast = head;
    int length = 0;
    while(slow and fast and fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            cycle_length(slow, length); 
            break;
        }
    }
    return start_node(head, length);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    Node* head = NULL, *start = NULL;
    push_node(&head, 9);
    push_node(&head, 8);
    push_node(&head, 7);
    push_node(&head, 6);
    push_node(&head, 5);
    push_node(&head, 4);
    push_node(&head, 3);
    push_node(&head, 2);
    push_node(&head, 1);

    head->next->next->next->next->next->next->next->next = head->next->next;
    start = cycle_start(head);
    if(start) cout << "Start of the cycle data is: " << start->data << endl;
    else cout << "No cycle found" << endl;
    return 0;
}