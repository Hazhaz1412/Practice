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
    int t; cin >> t; 
    while(t--) {
        string a,b,c; cin >> a >> b >> c;
        cout << a[0] << b[0] << c[0] << '\n';
    } 
}

void sol2() {
    int t; cin >> t; while(t--) {
        int n,m,l,r; cin >> n >> m >> l >> r;
        if(n == m) {
            cout << l << ' ' << r << '\n';
            continue;
        }

    }
}

void sol3() {
    int n,k; cin >> n >> k;
    vt<int> a(n);
    for(int &x: a) cin >> x;
    vt<int> d;
    for(int i = 0; i < n; ++i) {
        d.pb(a[i] - i * k);
    }
    sort(all(d));
    int med = d[n / 2];
    if(k < 0) {
        med = max(med, 1 - (n-1) * k);
    } else {
        med = max(med, 1);
    }
    ll res = 0;
    for(int i = 0; i < n; ++i) {
        res += abs(a[i] - (med + i * k));
    }
    
    cout << res << endl;

    
}
void sol4() {
    int n; cin >> n;
    vt<ll> a(n), b(n);
    for (ll &x : a) cin >> x;
    for (ll &x : b) cin >> x;
    sor(a);
    ll res = INF;
    for (ll x : b) {
        auto it = lb(all(a), -x);
        if (it != a.end()) res = min(res, abs(*it + x));
        if (it != a.begin()) res = min(res, abs(*prev(it) + x));
    }
    cout << res << endl;
}

void sol5() {
    int t; cin >> t; while(t--) {
        int n; cin >> n;
        string s = to_string(n);
        if(n < 0) {
            cout << s.size()-2 << '\n';
        }
        else {
            cout << s.size() << '\n';
        }
    }
}

void sol7() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        int dem = 0;
        if (n == 0) {
            cout << 1 << endl;
            continue;
        }
        if (n > 0) {
            while (n > 0) {
                dem++;
                n /= 10;
            }
        }
        else {
            while (n < 0) {
                dem++;
                n /= 10;
            }
            dem = dem - 1;
        }
        cout << dem << endl;
    }
}

void sol6() {
    int t;
	cin >> t;
	while (t--) {
		long long n, x; cin >> n;
        if(n == 0) {
            cout << 0 << endl;
            continue;
        }
		x = (n / 2 + 2) / 2;
		long long dientich = x * x;
		cout << dientich << endl;
	}
}

void sol8() {
    int t; cin >> t; 
    while (t--) {
        ll n; cin >> n;
        if(n == 0) {
            cout << 0 << endl;
            continue;
        }
        ll res = n/4+1;
        cout << res * res << endl;
    }
}


int main() {
    fast_io;
    sol8();
    return 0;
}
