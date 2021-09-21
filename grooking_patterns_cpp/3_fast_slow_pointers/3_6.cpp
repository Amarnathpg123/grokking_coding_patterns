#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next = NULL;
        Node(){this->data=0;}
};

void push_front(Node** head_ref, int const &new_data){
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void push_back(Node** head_ref, Node** tail_ref, int const &new_data){
    if(not *head_ref){
        push_front(head_ref, new_data);
        *tail_ref = *head_ref;
    }
    else {
        Node* new_node = new Node();
        new_node->data = new_data;
        (*tail_ref)->next = new_node;
        *tail_ref = new_node;
    }
}

void print_list(Node* head){
    printf("Linked list: ");
    while(head) {printf("%d ",head->data); head = head->next;}
    printf("\n");
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

void rearrange(Node* head){
    if(not(head and head->next and head->next->next)) return;

    Node *slow = head, *fast = head;
    while(fast and fast->next) slow = slow->next, fast = fast->next->next;

    slow = reverse(slow);
    Node* temp = NULL;
    while(head and slow){
        if(head == slow) break;
        temp = head->next;
        head->next = slow;
        head = temp;

        temp = slow->next;
        slow->next = head;
        slow = temp;
    }

    if(head) head->next = NULL;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    Node *head = NULL, *tail = NULL;
    int temp; size_t n;
    cout << "Enter number of nodes: " << endl; cin >> n;
    cout << "Enter the elements: " << endl;
    while(n--) cin >> temp, push_back(&head, &tail, temp);

    print_list(head);
    printf("Rearranging...\n");
    rearrange(head);
    print_list(head);
    return 0;
}