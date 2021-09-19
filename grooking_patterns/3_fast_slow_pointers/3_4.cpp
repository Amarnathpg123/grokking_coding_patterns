#include <bits/stdc++.h>
using namespace std;

unsigned square_of_digits(unsigned num){
    unsigned square_num = 0;
    while(num > 0){
        square_num += pow(num%10,2);
        num = num/10;
    }
    return square_num;
}

bool is_happy_number(unsigned const &number){
    unsigned fast = number, slow = number;
    while(1){
        fast = square_of_digits(square_of_digits(fast));
        slow = square_of_digits(slow);
        if(fast == slow) break;
    }
    return slow == 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    unsigned num;
    cout << "Enter a positive number to check whether its a happy number or not" << endl; cin >> num;
    if(is_happy_number(num)) cout << "Yes, Happy Number" << endl;
    else cout << "Not Happy Number" << endl;
    return 0;
}