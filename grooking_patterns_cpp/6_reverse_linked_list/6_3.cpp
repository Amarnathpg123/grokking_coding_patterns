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

Node* partial_k_reverse(Node* head, size_t const &n, size_t const &k){
    if(k < 2) return head;
    
    size_t j = k, q = n/k-1;
    Node *prev = head, *next = head, *temp = NULL;

    while(j-- > 1) next = next->next;
    temp = next->next;
    next->next = NULL;
    next = temp;
    head = reverse(prev);
    prev->next = next;

    while(q){
        j = k;
        while(j-- > 1) next = next->next;
        temp = next->next;
        next->next = NULL;
        next = temp;

        temp = prev->next;
        prev->next = reverse(prev->next);
        temp->next = next;

        j = k;
        while(j) prev = prev->next, j--;
        q--;
    }

    prev->next = reverse(prev->next);
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

    head = partial_k_reverse(head, n, k);
    printf("After ");
    print_list(head);

    return 0;
}