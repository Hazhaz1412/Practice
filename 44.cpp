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
    int t; cin >> t; while(t--) {
        int n,a,b; cin >> n >> a >> b;
        if ((n % 2) != (b % 2)) {
            cout << "NO\n";
        } else if (a <= b) {
            cout << "YES\n";
        } else if ((n % 2) == (a % 2)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    cerr << "Time elapsed: " << TIME << " s.\n";
}

void sol2() {
    int t; cin >> t; while(t--) {
        int n; ll k;
        cin >> n >> k;
        ll m = k + 1;
        for (int i = 0; i < n; ++i) {
            ll a; cin >> a;
            ll s = a % m;          
            ll res = a + s * k;    
            cout << res << (i + 1 == n ? '\n' : ' ');
        }
    }
}

void sol3() {
    int t; cin >> t; while(t--) {
        int n; cin >> n;
        vt<ll> a(n+1);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        ll s = 0, M = 0, res = 0;    
        for (int m = 1; m <= n/2; ++m) {
            int i = 2*m - 1;  
            int j = 2*m;     
            if (a[i] > a[j]) {
                res += (a[i] - a[j]);
                a[i] = a[j];
            }
            s += (a[j] - a[i]);
            if (j + 1 <= n) {
                ll cap = s - M;
                if (cap < 0) cap = 0;
                if (a[j+1] > cap) {
                    res += (a[j+1] - cap);
                    a[j+1] = cap;
                }
            }
            if (s > M) M = s;
        }

        cout << res << '\n';
    }
}

int main() {
    fast_io;
    sol3();
    return 0;
}
