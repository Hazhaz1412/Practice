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
        int n; cin >> n;
        vt<int> a(n);
        int res = -1;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            res = max(res, a[i]);
        }
        cout << res << '\n';

    }
    cerr << "Time elapsed: " << TIME << " s.\n";
}

void sol2() {
    int t; cin >> t; while (t--)
    {
        int n; cin >> n;
        string s; cin >> s;
        vt<int> a;
        for(int i = 0; i < n; i++) {
            if(s[i] == '0') {
                a.pb(i+1);

            }
        }
        cout << sz(a) << '\n';
        for(int &x: a) cout << x << ' ';
        cout << '\n';
    }
    
}

void sol3() {
    int t; cin >> t; while(t--) {
        int a,b; cin >> a >> b;
        int res = 0;
        while(a != b) {
            
        }
    }
}

int main() {
    fast_io;
    //sol2();
    cout << (405 ^ 5);
    return 0;
}
