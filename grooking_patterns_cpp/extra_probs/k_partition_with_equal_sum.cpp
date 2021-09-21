#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &arr,int x){
    for(int i=0;i<(int)arr.size();i++){
        if(arr[i]!=x) return false;
    }
    return true;
}

//simple solution with backtracking
bool fun(int i,int x,int k,vector<int> &nums,vector<int>&arr){
    if(i==(int)nums.size()){
        if(check(arr,x)) return true;
        return false;
    }
    for(int j=0;j<=min(i,k-1);j++){
        if(arr[j]+nums[i]>x) continue;      
        arr[j]+=nums[i];
        if(fun(i+1,x,k,nums,arr)){
            return true;
        }
        arr[j]-=nums[i];
    }
    return false;
}

bool canPartitionKSubsets(vector<int> nums, int k) {
    sort(nums.begin(),nums.end(),greater<int>());
    if(k==1) return true;
    int sum = accumulate(nums.begin(),nums.end(),0);
    if(sum%k!=0) return false;
    int x = sum/k;
    vector<int> arr(k,0);
    return fun(0,x,k,nums,arr);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    canPartitionKSubsets({4,3,2,3,5,2,1}, 4)? printf("Yes\n") : printf("No\n");
    canPartitionKSubsets({1,2,3,4}, 3)? printf("Yes\n") : printf("No\n");
    return 0;
}
