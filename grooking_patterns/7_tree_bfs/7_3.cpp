#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    long key;
    Node* left;
    Node* right;

    Node(long key_): key(key_), left(NULL), right(NULL) {}
};


void zz_level_order_traversal(Node *root=nullptr){
    printf("Level Order Tree Traversal: \n");
    if(not root) return;

    queue<Node*> Q;
    Q.push(root);
    size_t sz = Q.size();
    bool L2R = true;
    while(sz){
        deque<long> temp_dQ;
        while(sz){
            Node *current = Q.front();
            Q.pop();
            if(L2R) temp_dQ.push_back(current->key);
            else temp_dQ.push_front(current->key);

            if(current->left) Q.push(current->left);
            if(current->right) Q.push(current->right);
            sz--;
        }
        for(auto &i: temp_dQ) printf("%ld ", i);
        printf("\n");
        L2R = !L2R;
        sz = Q.size();
    }
 
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    Node *root = new Node(12);
    root->left = new Node(7);
    root->right = new Node(1);
    root->left->left = new Node(9);
    root->left->right = new Node(99);
    root->right->left = new Node(10);
    root->right->right = new Node(5);
    root->left->left->left = new Node(10);
    root->left->left->right = new Node(98);
    root->left->right->right = new Node(8);
    
    zz_level_order_traversal(root);
    return 0;
}