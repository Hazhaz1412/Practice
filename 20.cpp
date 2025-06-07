#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
using namespace std;
#define vt vector
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define pf push_front
#define ins insert
#define sz(x) int((x).size())
#define sor(x) sort(all(x))
#define rsor(x) sort(rall(x))
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using ll = long long;
using ull = unsigned long long;

template <typename T>
void debug(const T& x) { cerr << x << '\n'; } 
template <typename T>
void debugv(const vt<T>& v) { for (const auto& i : v) cerr << i << ' '; cerr << '\n'; }

template <typename T1, typename T2>
inline bool ckmin(T1& a, const T2& b) { return b < a ? (a = b, true) : false; }

template <typename T1, typename T2>
inline bool ckmax(T1& a, const T2& b) { return b > a ? (a = b, true) : false; }

const int MOD = 1e9+7;
const ll INF = 1e18;




void sol() {
    int n; cin >> n;
    vt<int> a(n),b(n);
    for(int &x:a) cin >> x;
    for(int &x:b) cin >> x;
    vt<int> pos(n+1);
    for(int i = 0; i < n; i++) {
        pos[b[i]] = i;
    }
    vt<int> c(n);
    for(int i = 0; i < n;i++) {
        c[i] = pos[a[i]];
    }
    vt<int> res;
    for(int i = 0 ; i < n;i++) {
        auto it = lb(all(res), c[i]);
        if(it == res.end()) {
            res.pb(c[i]);
        }
        else {
            *it = c[i];
        }
    }
    cout << sz(res);
}

void sol2() {
    int n; cin >> n;
    vt<ll> dp(n+1);
    dp[0] = 1;
    for(int i = 1; i <= n;i++) {
        for(int j = 1; j <= 6 && j <= i; j++) {
            dp[i] = (dp[i] + dp[i-j]) % MOD;
        }
    }
    cout << dp[n];
}

void sol3() {
    int n, x; cin >> n >> x;
    vt<int> a(n);
    for(int &x: a) cin >> x;
    vt<int> dp(x+1, 1e9);
    int l = sz(a);
    dp[0] = 0;
    for(int i = 1; i <= x; i++) {
        for(int j = 0; j < n; j++) {
            if(a[j] <= i) {
                dp[i] = min(dp[i], dp[i-a[j]] +1);
            }
        }
    }
    if(dp[x] == 1e9) cout << -1;
    else cout << dp[x];
}

void sol4(){
    
}

int main() {
    fast_io;
    sol3();
    return 0;
}
