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

Node* rotate_k_right(Node* head, size_t const &n, size_t const &k){
    Node* prev = head, *next = head, *temp = NULL;
    size_t i = n-k;

    while(i-- > 1) prev = prev->next;
    next = prev->next;
    prev->next = NULL;
    temp = next;

    while(next->next) next = next->next;
    next->next = head;
    head = temp;
    
    return head;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    Node* head = NULL;
    int temp; size_t n, k;
    cout << "Enter the k: " << endl; cin >> k;
    cout << "Enter the number of nodes: " << endl; cin >> n;
    assert(k<=n);
    cout << "Enter the nodes: " << endl;

    for(size_t i = 0; i < n; ++i){
        cin >> temp;
        push_front(&head, temp);
    }

    printf("Before ");
    print_list(head);

    head = rotate_k_right(head, n, k);
    printf("After ");
    print_list(head);

    return 0;
}