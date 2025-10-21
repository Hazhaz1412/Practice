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

const ll MOD = 1e9+7;
const ll INF = 1e18;

vt<ll> f(1001, -1);

ll fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (f[n] != -1) return f[n];
    return f[n] = (fib(n-1) + fib(n-2)) % MOD;
}

void sol() {
    int t; cin >> t; while(t--) {
        int n; cin >> n;
        cout << fib(n) << '\n';
    }
    cerr << "Time elapsed: " << TIME << " s.\n";
}


void sol2() {
    int t;
    if (!(cin >> t)) return;
    while (t--) {
        long long n;
        cin >> n;                   
        
        if (n < 0) {
            cout << "0\n";          
            continue;
        }
        ll res = n * n;
        
        cout << res << '\n';
    }
}

bool isSquare(long long x) {
    long long r = sqrtl(x);
    return r * r == x;
}

bool isFibo(long long n) {
    return isSquare(5*n*n + 4) || isSquare(5*n*n - 4);
}

void sol3() {
    int T; cin >> T;
    while (T--) {
        long long n; cin >> n;
        cout << (isFibo(n) ? "YES" : "NO") << "\n";
    }

}


unordered_set<ll> fibo;

void precompute() {
    ll a = 0, b = 1;
    fibo.insert(a);
    fibo.insert(b);
    while (true) {
        ll c = a + b;
        if (c > (ll)1e18) break;
        fibo.insert(c);
        a = b;
        b = c;
    }
}

void sol4() {
    precompute();

    int T; cin >> T;
    while (T--) {
        ll n; cin >> n;
        cout << (fibo.count(n) ? "YES" : "NO") << "\n";
    }
}

void sol5() {
    int n; cin >> n;

}


int main() {
    fast_io;
    //sol5();
    
    return 0;
}
