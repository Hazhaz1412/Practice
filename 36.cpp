#include <bits/stdc++.h>
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,O2")
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
typedef pair<int, int> pii;

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
        int n, res = 9; cin >> n;
        
        while(n > 0) {
            res = min(res, n % 10);
            n /= 10;
        }
        cout << res << '\n';

    }
    cerr << "Time elapsed: " << TIME << " s.\n";
}

void sol2() {
    int t; cin >> t; while(t--) {
        int n,k; cin >> n >> k;
        vt<int> a(n); 
        for(int &x: a) cin >> x;
        int res = 0;
        int cc = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] == 0) {
                cc++;
            }
            if(cc == k) {
                res++;
                cc = 0;
                i++;
            }
            if(a[i] == 1) {
                cc = 0;
            }
            
            
        }
        cout << res << '\n';
    }
}

void sol3() {
    int t; cin >> t; while(t--) {
        int k, n; cin >> k >> n;
        vt<int> a(k);
        for(int i = 0; i <k; i++) {
            cin >> a[i];
        }
        int pos = a[n-1];
        int w = 1;
        sor(a);
        for(int i = 0; i < k; i++) {
            if(a[i] <= pos) {
                continue;
            }
            else {
                if(a[i] - pos <= (pos - w)+1 ) {
                    w += a[i] - pos;
                    pos = a[i];
                } 
                else {
                    cout << "NO\n";
                    goto end;
                }
            }
        }
        cout << "YES\n";
        end:;


    }
}

void sol4() {
    int t; cin >> t; while(t--) {
        int n, k; cin >> n >> k;
        vt<tuple<int,int,int>> a(n);
        for(int i =0; i < n; i++) {
            int l,r,m; cin >> l >> r >> m;
            a[i] = {l, r, m};
        }
        sor(a);
        for(int i =0; i < n; i++) {
            if(k >= get<0>(a[i]) && k <= get<1>(a[i])) {
                k = max(get<2>(a[i]), k);
            }
            //cout << get<0>(a[i]) << ' ' << get<1>(a[i]) << ' ' << get<2>(a[i]) << '\n';
        }
        cout << k << '\n';
    }
}
void sol5() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vt<int> p(n), s(n);
        for (int &x : p) cin >> x;
        for (int &x : s) cin >> x;
        if (n == 1) {
            cout << (p[0] == s[0] ? "YES\n" : "NO\n");
            continue;
        }
        bool ok = true;
        for (int i = 0; i < n; i++) {
            ll amin = lcm((ll)p[i], (ll)s[i]);
            if ((i == 0 && amin != p[i]) || (i == n - 1 && amin != s[i]))
                ok = false;
            if (i > 0 && gcd(amin, p[i - 1]) != p[i])
                ok = false;
            if (i < n - 1 && gcd(amin, s[i + 1]) != s[i])
                ok = false;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}
 

int main() {
    fast_io;
    sol5();
    return 0;
}