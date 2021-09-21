#include <bits/stdc++.h>
using namespace std;

void get_next_index(string const &str, int &index){
    size_t backs = 0;
    while(index >= 0){
        if(str[index--] == '#') backs++;
        else if(backs>0) backs--;
        else break;
    }
}

bool compare_backspace_strings(string const &str1, string const &str2){
    int i1 = str1.length()-1, i2 = str2.length()-1;

    while(i1 >= 0 and i2 >= 0){
        get_next_index(str1,i1); get_next_index(str2,i2);
        if(i1<0 and i2<0) return true;
        else if (i1<0 or i2<0) return false;
        else if(str1[i1--] != str2[i2--]) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    string str1, str2;
    cout << "Enter the 2 strings with backspace as '#': " << endl; cin >> str1 >> str2;
    if(compare_backspace_strings(str1, str2)) printf("Equal strings\n");
    else printf("Not equal strings\n");
    return 0;
}