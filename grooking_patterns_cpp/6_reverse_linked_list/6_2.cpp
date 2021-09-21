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

void partial_reverse(Node* head, size_t p, size_t q){
    if(p == q) return;
    Node *prev = head, *next = head, *temp = NULL;
    while(p-- > 2) prev = prev->next;
    while(q-- > 1) next = next->next;
    temp = next->next;
    next->next = NULL;
    next = temp;

    temp = prev->next;
    prev->next = reverse(prev->next);
    temp->next = next;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    Node* head = NULL;
    int temp; size_t n, p, q;
    cout << "Enter the p and q: " << endl; cin >> p >> q;
    cout << "Enter the number of nodes: " << endl; cin >> n;
    assert(p<=n and q<=n);
    cout << "Enter the nodes: " << endl;
    while(n--) {
        cin >> temp;
        push_front(&head, temp);
    }

    printf("Before ");
    print_list(head);

    partial_reverse(head, p, q);
    printf("After ");
    print_list(head);

    return 0;
}