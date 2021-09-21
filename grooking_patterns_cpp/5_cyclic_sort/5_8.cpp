#include <bits/stdc++.h>
using namespace std;

void cyclic_sort(vector<int> &array){
    size_t i = 0, j = 0;
    while(i < array.size()){
        j = array[i]-1;
        if(array[i]>0 and array[i]<=array.size() and array[i] != array[j]) 
            swap(array[i], array[j]);
        else i++;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    vector<int> array, extras;
    int n,k;  int temp;
    cout << "Enter the k: " << endl; cin >> k;
    cout << "Enter the number of elements: " << endl; cin >> n;
    cout << "Enter the elements: "<< endl;
    while(n--){
        cin >> temp; array.push_back(temp);
    }

    cyclic_sort(array);
    printf("First %d missing numbers are: ",k);
    for(n = 0; n < array.size(); ++n){
        if(array[n] != n+1){
            if(not k--) break;
            printf("%d ", n+1);
            extras.push_back(array[n]);
        }
    }
    while(k-- > 0) {
        if(extras.size() and find(extras.begin(), extras.end(), (n++)+1) == extras.end())
            printf("%d ", n);
        else k++;
    }
    printf("\n");
    return 0;
}