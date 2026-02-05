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
    string mode;
    if (!(cin >> mode)) return;

    if (mode == "first") {
        int n; 
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i]; 
        }
        string s;
        s.reserve(n + 1 + n);
        s.append(n, 'a');
        s.pb('b');
        for (int x : a) { 
            s.pb(char('a' + (x - 1)));
        }
        cout << s << '\n';
        return;
    } else { 
        string s; cin >> s;
        int n = 0;
        while (n < (int)sz(s) && s[n] == 'a') ++n;
        vt<int> a;
        a.reserve(n);
        int pos = n + 1;
        for (int i = 0; i < n; ++i) {
            a.pb((s[pos + i] - 'a') + 1);
        }
        cout << n << '\n';
        for (int i = 0; i < n; ++i) {
            if (i) cout << ' ';
            cout << a[i];
        }
        cout << '\n';
    }
}

void sol2() {
    string mode;
    if (!(cin >> mode)) return; 
    ll p26[7];
    p26[0] = 1;
    for (int i = 1; i < 7; ++i) {
        p26[i] = p26[i-1] * 26LL;
    }
    if (mode == "first") {
        int n; 
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        string s;
        s.reserve(n + 1 + 7LL * n);
        s.append(n, 'a');
        s.pb('b');
        for (ll v : a) {
            ll x = v - 1;
            for (int k = 6; k >= 0; --k) {
                ll div = p26[k];
                int tmp = int((x / div) % 26);
                s.pb(char('a' + tmp));
            }
        }

        cout << s << '\n';
        return;
    } else { 
        string s; cin >> s; 
        int n = 0;
        while (n < (int)s.size() && s[n] == 'a') ++n;
        int pos = n + 1;
        cout << n << '\n';
        for (int i = 0; i < n; ++i) {
            ll x = 0;
            for (int j = 0; j < 7; ++j) {
                x = x * 26 + (s[pos++] - 'a');
            }
            ll ai = x + 1;
            if (i) cout << ' ';
            cout << ai;
        }
        cout << '\n';
    }
}

int main() {
    fast_io;
    sol2();
    return 0;
}
