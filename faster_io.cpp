#include <bits/stdc++.h>

#define rep(i,n) for (int i = 0; i < n; ++i)    //works as rep(#1, #2) for(int #1=0, #1<#2; ++#1) (inplace subst)
#define REP(i,k,n) for (int i = k; i <= n; ++i)
#define REPR(i,k,n) for (int i = k; i >= n; --i)

template<typename T> 
void scan(T &x){
	x = 0; bool neg = 0;
	register T c = getchar();
	if(c == '-') neg = 1, c = getchar();
	while((c < 48) || (c > 57)) c = getchar();
	for(; c < 48||c > 57; c = getchar());
	for(; c > 47 && c < 58; c = getchar()) x = (x << 3) + ( x << 1 ) + (c&15);   // c&15 = c-48
	if(neg) x *= -1;
}

template<typename T> 
void print(T n) {
    bool neg = 0;
    if (n < 0) n *= -1, neg = 1;
    char snum[65]; int i = 0;
    do { snum[i++] = n % 10 + '0'; n /= 10; } while(n); --i;
    if(neg) putchar('-');
    while(i >= 0) putchar(snum[i--]);
    putchar('\n');
}

// Driver Program
int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);
	long long value;

	rep(j,3) {
		// printf("%d:\n",j);
		scan(value); std::cout << value << std::endl;
		print(value);
	}
	
	return 0;
}

