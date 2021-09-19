#include <bits/stdc++.h>
using namespace std;

#define vN vector<Node *>

class Node{
public:
    long val = 0;
    Node *left = nullptr, *right = nullptr;
    Node(int val_): val(val_){}
};

void level_order_traversal(Node *root=nullptr){
    // printf("Level Order Tree Traversal: \n");
    if(not root) return;

    queue<Node*> Q;
    Q.push(root);
    Q.push(nullptr);

    while(Q.size() > 1){
        Node *current = Q.front();
        Q.pop();

        if(not current){
            printf("\n");
            Q.push(nullptr);
            continue;
        }
        printf("%ld ", current->val);

        if(current->left) Q.push(current->left);
        if(current->right) Q.push(current->right);
    }

    printf("\n\n");
}

vN find_unique_BSTs(long start, long end){
    vN res = {};

    if(start > end){
        res.push_back(nullptr);
        return res;
    }

    for(long i = start; i <= end; ++i){
        vN left = find_unique_BSTs(start, i-1);
        vN right = find_unique_BSTs(i+1, end);
        for(Node *l: left){
            for(Node *r: right){
                Node *root = new Node(i);
                root->left = l;
                root->right = r;
                res.push_back(root);
            }
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long n; cin >> n;
    vN res;
    res = find_unique_BSTs(1,n);
    for(long i = 0; i < res.size(); ++i){
        cout << "Tree: " << i+1 << endl;
        level_order_traversal(res[i]); 
    }
    return 0;
}