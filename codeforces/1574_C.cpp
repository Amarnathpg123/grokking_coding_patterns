#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

struct InputOutputStream {
    enum { SIZE = 1000001 };
    char ibuf[SIZE], *s, *t, obuf[SIZE], *oh;
    bool eof;
 
    InputOutputStream() : s(), t(), oh(obuf), eof(false) {}
    ~InputOutputStream() { fwrite(obuf, 1, oh - obuf, stdout); }
 
    explicit operator bool() const {
        return static_cast<bool>(eof == false);
    }
 
    inline char read() {
        if (s == t) t = (s = ibuf) + fread(ibuf, 1, SIZE, stdin);
        return s == t ? -1 : *s++;
    }
 
    inline InputOutputStream &operator>>(char* x) {
        static char c;
        for (c = read(); isspace(c); c = read())
            if (c == -1) {eof = true; return *this;}
        for (; !isspace(c); c = read()) *x = c, ++x;
        *x = 0;
        return *this;
    }
 
    template <typename T>
    inline InputOutputStream &operator>>(T &x) {
        static char c;
        static bool iosig;
        for (c = read(), iosig = false; !isdigit(c); c = read()) {
            if (c == -1) {eof = true; return *this;}
            iosig |= c == '-';
        }
        for (x = 0; isdigit(c); c = read()) x = x * 10 + (c ^ '0');
        if (iosig) x = -x;
        return *this;
    }
 
    inline void print(char c) {
        if (oh == obuf + SIZE) {
            fwrite(obuf, 1, SIZE, stdout);
            oh = obuf;
        }
        *oh++ = c;
    }
 
    template <typename T>
    inline void print(T x) {
        static int buf[23], cnt;
        if (x != 0) {
            if (x < 0) print('-'), x = -x;
            for (cnt = 0; x; x /= 10) buf[++cnt] = x % 10 | 48;
            while (cnt) print((char)buf[cnt--]);
        } else print('0');
    }
 
    template <typename T>
    inline InputOutputStream &operator<<(const T &x) {
        print(x);
        return *this;
    }
 
    inline void print(const char* x) {
        for(; *x; x++)
            print(*x);
    }
 
    inline void print(char* x) {
        for(; *x; x++)
            print(*x);
    }    
} io;
 
using ll = long long;
using ull = unsigned long long;
 
const int maxn = 2e5 + 50;
 
int n, q;
ll a[maxn];
ll sum[maxn];
 
signed main() {	
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    io >> n;
    for(int i = 1;i <= n;++i) {
        io >> a[i];
    }
    sort(a+1, a+1+n);
    for(int i = 1;i <= n;++i) {
        sum[i] = sum[i - 1] + a[i];
    }
    io >> q;
    while(q--) {
        ll x, y;
        io >> x >> y;
        int p = lower_bound(a+1, a+1+n, x) - a;
        if(p == n + 1) {
            ll ans = x - a[n];
            ans += max(0LL, y - sum[n - 1]);
            cout << ans << '\n';
        } else {
            ll sum0 = sum[p - 1] + sum[n] - sum[p];
            ll ans1 = max(0LL, y - sum0);
            ll ans2 = 0x3f3f3f3f3f3f3f3f;
            if(p >= 2) {
                --p;
                ans2 = x - a[p];
                ll sum1 = sum[n] - sum[p] + sum[p - 1];
                ans2 += max(0LL, y - sum1);
            }
            ll ans = min(ans1, ans2);
            cout << ans << '\n';
        }
    }
    return 0;
}