#include <bits/stdc++.h>
using namespace std;

bool all9s(string &s) {
    for(char &c: s) if(c != '9') return 0;
    return 1;
}

string utility(string s, int &n) {
    int mid = n / 2;
 
    // A bool variable to check if copy of left
    // side to right is sufficient or not
    bool leftsmaller = false;
 
    // End of left side is always 'mid -1'
    int i = mid - 1;
 
    // Beginning of right side depends
    // if n is odd or even
    int j = (n % 2) ? mid + 1 : mid;
 
   // Initially, ignore the middle same digits
    while (i >= 0 && s[i] == s[j])
        i--, j++;
 
    // Find if the middle digit(s) need to be
    // incremented or not (or copying left
    // side is not sufficient)
    if (i < 0 || s[i] < s[j])
        leftsmaller = true;
 
    // Copy the mirror of left to tight
    while (i >= 0)
    {
        s[j] = s[i];
        j++;
        i--;
    }
 
    // Handle the case where middle digit(s) must
    // be incremented. This part of code is for
    // CASE 1 and CASE 2.2
    if (leftsmaller == true)
    {
        int carry = 1;
        i = mid - 1;
 
        // If there are odd digits, then increment
        // the middle digit and store the carry
        if (n % 2 == 1)
        {
            s[mid] += carry;
            carry = (s[mid]-'0')/10;
            s[mid] = char((s[mid]-'0')%10+'0');
            j = mid + 1;
        }
        else
            j = mid;
 
        // Add 1 to the rightmost digit of the
        // left side, propagate the carry towards
        // MSB digit and simultaneously copying
        // mirror of the left side to the right side.
        while (i >= 0)
        {
            s[i] += carry;
            carry = (s[i]-'0')/10;
            s[i] = char((s[i]-'0')%10+'0');
             
            // Copy mirror to right
            s[j++] = s[i--];
        }
    }
    return s;
}

string findNextGreaterPalindrome(string &s) {
    int n = s.length();
    if(n < 2) return s;
    string res;

    if(all9s(s)) {
        res = "1"+res;
        for(int i = 1; i < n; ++i) res = "0"+res;
        res = "1"+res;
        return res;
    }

    else return utility(s, n);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    string s; cin >> s;
    cout << findNextGreaterPalindrome(s) << endl;
    return 0;
}