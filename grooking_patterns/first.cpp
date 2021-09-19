#include <bits/stdc++.h>
using namespace std;

#define int long long

void count_sort(vector<int>& arr)
{
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    int range = max - min + 1;
 
    vector<int> count(range), output(arr.size());
    for (size_t i = 0; i < arr.size(); i++)
        count[arr[i] - min]++;
 
    for (size_t i = 1; i < count.size(); i++)
        count[i] += count[i - 1];
 
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }
 
    for (size_t i = 0; i < arr.size(); i++)
        arr[i] = output[i];
}

void find_max_no_houses(vector<int> &A, int &B, size_t &max_no){
    count_sort(A);
    size_t i = 0;
    while(B >= A[i]){
        B -= A[i++]; max_no++;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    size_t T; cin >> T;
    
    for(size_t i = 1; i <= T; ++i){
        size_t N, max_no = 0;
        int B, temp; cin >> N >> B;
        vector<int> A;
        while(N){
            cin >> temp; A.push_back(temp);
            N--;
        }
        find_max_no_houses(A, B, max_no);
        printf("Case #%lu: %lu\n",i,max_no);
    }
}