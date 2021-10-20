#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin>>n;
    vector<int> ivy;
    for(int i= 0;i<n;i++){
    int a;
    cin >>a;
    ivy.push_back(a);
    }

    // 1st line
    cout<<"+";
    for(int i =0; i< 2*n+1;i++){
    cout<<"-";
    }
    cout<<endl;
    // 2nd to max(a)+2
    int maxa = *max_element(ivy.begin(), ivy.end());

    for(int k = 2 ; k<= maxa+2;k++) {
    cout<<"|";
    for(int j = 2; j<=2*n+2;j++){
        if(j %2 ==0){
            cout<<".";
        } else{
            int i = (j - 1) /2;
            if(k <= ivy[i-1]){
            cout<<"X";
            } else if(k == ivy[i-1]+1){
            cout<<"V";
            } else{
            cout<<".";
            }
        }
    }
    cout<<endl;
    }
    cout<<"+";
    for(int i =0; i< 2*n+1;i++){
    cout<<"-";
    }
    cout<<endl;

    return 0;
}