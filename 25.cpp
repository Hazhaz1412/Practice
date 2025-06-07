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
    freopen("DAYDEP.INP", "r", stdin);
    freopen("DAYDEP.OUT", "w", stdout);
    int n; cin >> n;
    vt<ll> a(n);
    unordered_map<ll, ll> mp;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        mp[a[i]]++;
    }
    ll res = 0;
    for (auto &[v, x] : mp) {
        if(x < v) {
            res += x;
            continue;
        }
        res += min(x, abs(v - x));
    }
    cout << res << '\n';
}

void sol2() {
    freopen("WORK.INP", "r", stdin);
    freopen("WORK.OUT", "w", stdout);
    int n; cin >> n;
    vt<int> a(n), b(n-1);
    for(int &x: a) {
        cin >> x;
    }
    for(int &x: b) cin >> x;
    vt<int> dp(n+1);
    dp[0] = a[0];
    dp[1] = min(a[0] + a[1], b[0]);
    for (int i = 2; i < n; ++i) {
        dp[i] = min(dp[i-1] + a[i], dp[i-2] + b[i-1]);
    }
    cout << dp[n-1];
}


void sol3() {
    freopen("QUA.INP", "r", stdin);
    freopen("QUA.OUT", "w", stdout);

    vt<int> num = {6, 28, 496, 8128, 33550336};
    unordered_set<int> st(all(num));
    int n;
    cin >> n;
    vt<int> a(n);
    for (int &x : a) cin >> x;

    vt<int> res;
    for (int x : a) {
        if (st.count(x)) {
            res.pb(x);
        }
    }

    cout << res.size() << '\n';
    for (int x : res) cout << x << ' ';


}

void sol4() {
    int a,b,c,n; cin >> a >> b >> c >> n;
    if(a < 1 || b < 1 || c < 1) {
        cout << "NO";
        return;
    }
    if(n < 3) {
        cout << "NO";
        return;
    }
    n -= a;
    n -= b;
    n -= c;
    if(n > 0) {
        cout << "NO";
        return;
    }
    cout << "YES";

}

void sol5() {
    int t; cin >> t; while(t--) {
        int n; cin >> n;
        vt<int> a(n);
        int res = 1e9;
        for(int &x: a) cin >> x;
        sor(a);
        res = min(res, a[n-1] - a[1]);
        res = min(res, a[n-2] - a[0]);
        cout << res << '\n';
    }
}

//bruteforce

void sol6() {
    int n; cin >> n;
    vt<int> a(n);
    for (int& x : a) cin >> x;
    set<int> st,sum;     
    for (int i = 0; i < n; ++i) {
        set<int> tmp;
        tmp.insert(a[i]);
        for (int x : sum)
        tmp.insert(x | a[i]);

        sum = tmp;
        for (int x : sum)
            st.insert(x);
    }

    cout << st.size();
}

vt<ll> sont;

void sieve(int n) {
    vt<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i)
                prime[j] = false;
        }
    }
    for (int i = 2; i <= n; ++i) {
        if (prime[i]) {
            sont.pb(1LL * i * i); 
        }
    }
    sor(sont);
}

void sol7() {
    freopen("SDB.INP", "r", stdin);   
    freopen("SDB.OUT", "w", stdout);
    sieve(1e6);  
    int q; cin >> q;
    while (q--) {
        int x;
        cin >> x;
        auto it = lower_bound(sont.begin(), sont.end(), x);
        cout << *it << '\n';
    }
}

void sol8() {
    int t; cin >> t; while(t--) {
        int x1 =0, x2= 0;
        int n; cin >> n;
        string a,b; cin >> a >> b;
        for(int i = 0; i < n ;i++) {
            if(i % 2 == 0) {
                if(a[i] == '0') x1++;
                if(b[i] == '0') x2++;
            }
            else {
                if(b[i] == '0') x1++;
                if(a[i] == '0') x2++;
            }
        }
        if(x1 >= (n+1)/2 && x2 >= (n/2) ) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}

int main() {
    fast_io;
    sol8();
    return 0;
}
