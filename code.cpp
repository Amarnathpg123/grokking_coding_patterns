#include <bits/stdc++.h>
using namespace std;

/*
	Given array a of length n
	find  max((xor of all except i )^ (a[i]&(a[i]^a[j])))
	This can be also given as :
		//if total = xor of all elements in a
		//then find max ((total^a[i])^(a[i]&(a[i]^a[j])))
	n<=1e5
	a[i]<=1e9

*/

int brute_force(const vector<int>& a){
	const int n = a.size();
	int total = 0;
	for(const int& i:a) total^=i;
	int ans = 0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){

			ans = max(ans,total^a[i]^(a[i]&(a[i]^a[j])));
		}
	return ans;
} 

const int lg = 30;
const int N = 1e5+10; 
bitset<N> ele[lg];
bitset<N> temp,local,sample;
/*
	Start from the highest bit 
	and try what shout be the j's heighest bit
	so that it will be set in answer.

*/
int sol(const vector<int>& a ){
	const int n = a.size();
	int total = 0;
	for(const int& i:a) total^=i;
	for(int i=0;i<lg;i++) ele[i].reset();
	for(int i=0;i<n;i++){
		for(int bit=0;bit<lg;bit++){
			if(a[i]&(1<<bit)) ele[bit].set(i);
		}
	}
	sample.reset();
	for(int i=0;i<n;i++) sample.set(i);
	int ans = 0;
	for(int i=0;i<n;i++){
		int now = 0;
		const int rest = total^a[i];
		temp = sample;
		for(int bit=lg-1;bit>=0;bit--){
			if(a[i] & (1<<bit)){
				if(rest & (1<<bit) ){
					local = temp & (ele[bit]);
					if(local.count()){
						temp = local;
						now |= (1<<bit);
					}
					else {
						temp = temp & (~ele[bit]);
					}
				}
				else {
					local = temp & (~ele[bit]);
					if(local.count()){
						temp = local;
						now |= (1<<bit);
					}
					else {
						temp = temp & (ele[bit]);
					}
				}

			}
			else{
				// if the bit is not set in a[i]
				// then we can't change the value in 
				// our ans
				// so this bit will remain same as in rest
				if(rest & (1<<bit)){
					now|=(1<<bit);
				}
			}

		}
		ans = max(ans,now);
	}
	return ans;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin.exceptions(cin.failbit);
	// int n;
	// cin >> n;
	// vector<int> a(n);
	// for(int& i:a) cin >> i;

	vector<int> a = {7,3,4,5,2,9,8};

	int b = brute_force(a);
	int x = sol(a);
	cout << "from brute_force : " << b <<endl;
	cout <<"from sol : " << x <<endl;
	if(b==x) {
		cout <<" you are right";
	}
	else cout << "you are wrong";



	return 0;
}