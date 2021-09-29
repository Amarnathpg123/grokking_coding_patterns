//https://leetcode.com/contest/weekly-contest-258/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string s;
    bool ispal(string str){
        int i=0;
        int j=str.length()-1;
        while(i<j){
            if(str[i]!=str[j])return false;
            i++;
            j--;
        }
        return true;
    }
    int maxProduct() {
        cin >> s;
        int n=s.length();
        vector<int>v;
        for(int i=1;i<(1<<n);i++){
            string str="";
            for(int j=0;j<n;j++){
                if(i&(1<<j))str+=s[j];
            }
            if(ispal(str))v.push_back(i);
        }
        int ans=0;
		
        for(int i=0;i<v.size();i++){
            for(int j=i+1;j<v.size();j++){
                if((v[i]&v[j])==0){
                    int a=__builtin_popcount(v[i]);
                    int b=__builtin_popcount(v[j]);
                    ans =max(ans,a*b);
                }
            }
        }
        return ans;   
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    Solution sol;
    printf("Maximum product of lengths of two distinct palindromes in a string: %d\n", sol.maxProduct());
    return 0;
}