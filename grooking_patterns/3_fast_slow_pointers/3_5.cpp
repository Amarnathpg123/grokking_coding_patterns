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

Node* reverse(Node* node){
    Node *prev = NULL, *next = NULL;
    while(node){
        next = node->next;
        node->next = prev;
        prev = node;
        node = next;
    }
    return prev;
}

bool is_palindrome(Node* head){
    if(not(head && head->next)) return true;
    
    Node *fast = head, *slow = head;
    while(fast && fast->next) slow = slow->next, fast = fast->next->next;  //to find the middle element
    slow = reverse(slow); // reversing the second half
    fast = slow; // copy pointer of second half

    while(head && slow){
        if(head->data != slow->data) break; //check each element for equality
        head = head->next;
        slow = slow->next;
    }

    fast = reverse(fast); //reverting back the second half

    if(not head or not slow) return true; //if any half ends then its a palindrome
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    Node *head = NULL;
    push_node(&head, 2);
    push_node(&head, 4);
    push_node(&head, 6);
    push_node(&head, 4);
    push_node(&head, 2);

    if(is_palindrome(head)) printf("Yes, Palindrome\n");
    else printf("Not a Palindrome\n");
    return 0;
}