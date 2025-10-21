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
        int n,c; cin >> n >> c;
        vt<int> a(n);
        int ti = 0;

        for(int i =0;i <n;i++) {
            cin >> a[i];
        }
        rsor(a);
        int res = 0;
        for(int i =0 ;i < n; i++) {
            if(a[i] > c) {
                res++;
                continue;
            }
            else {
                ll tmp = (1LL * a[i] << ti);
                if(tmp > c) {
                    res++;
                }
                else {

                    ti++;
                } 

            }
        }
        cout << res << '\n';
    }
    cerr << "Time elapsed: " << TIME << " s.\n";
}

void sol2() {
    int t; cin >> t; while(t--) {
        int n; cin >> n; 
        vt<int> a(n+1);
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int l = 1, r = n; bool up = true;  
        string s; s.reserve(n);
        for (int i = 1; i <= n/2; ++i) {
            if ( (a[l] < a[r]) == up ) { s += "LR"; } else { s += "RL"; }
            ++l; --r; up = !up;
        }
        if (n & 1) s += 'L';  
        cout << s << '\n'; 
    }
}

void sol3() {
    int t; cin >> t; while(t--) {
        int n; cin >> n;
        vt<int> a(n);
        for(int &x:a) {
            cin >> x;
        }
        bool ok = true;
        int sm = 1e9;
        for(int i = 0; i < n; i++) {
            if(a[i] > sm*2-1) {
                ok = false;
            }
            sm = min(sm, a[i]);
        }
        if(ok) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}

int main() {
    fast_io;
    sol3();
    return 0;
}
