#include <bits/stdc++.h>
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,O2")
using namespace std;
#define vt vector
#define pb push_back
#define pii pair<int,int>
#define tii tuple<int,int,int>
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
    vt<int> a(n);
    for(int&x: a) {
        cin >> x;
    }
    vt<int> pf(n);
    pf[0] = a[0];
    for(int i = 1; i < n; i++) {
        pf[i] = pf[i-1] + a[i];
    }
    int m; cin >> m;
    for(int i = 0; i < m; i++) {
        int q; cin >> q;
        int res = lb(all(pf), q) - pf.begin() + 1;
        cout << res << '\n';
    }
}
void sol2() {
    int t; cin >> t;
    while(t--) {
        ll n, k; cin >> n >> k;
        ll ans = n;  
        for(ll i = 1; i * i <= n; i++) {
            if(n % i == 0) {
                if(i <= k) {
                    ans = min(ans, n / i);
                }
                ll tmp = n / i;
                if(tmp <= k) {
                    ans = min(ans, n / tmp);
                }
            }
        }
        
        cout << ans << '\n';
    }
}


int main() {
    fast_io;
    sol();
    return 0;
}
