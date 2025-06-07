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
    int t; cin >> t; while(t--) {
        int n, k, p; cin >> n >> k >> p;
        if(k == 0) {
            cout << 0 << endl;
            continue;
        }
        int m = (abs(k) + p - 1) / p; 
        if(m > n)
            cout << -1 << endl;
        else
            cout << m << endl;
    }
     
}

void sol2() {
    ll t; cin >> t;while(t--) {
        ll n; cin >> n;
        string s; cin >> s;
        ll one = 0, two = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '-') {
                one++;
            }
            else {
                two++;
            }
        }
        if(n < 3 || one < 2) {
            cout << 0 << endl;
            continue;
        }
        ll l = one / 2;
        ll r = one - l;
        ll res =  l * r * two;
        cout << res << endl; //Hello world

    }
} 

void sol3() {
    ll n;
    cin >> n;
    ll ans = 1;
    ll tmp = n;
    for (ll p = 2; p * p <= tmp; p++) {
        if (tmp % p == 0) {
            ans *= p; 
            while(tmp % p == 0) {
                tmp /= p;
            }
        }
    }
    if (tmp > 1) {
        ans *= tmp;
    }
    cout << ans << endl;
}

void sol4() {
    ll n; cin >> n;
    ll res = 1;
    
}

void sol5() {
    ll m,n,s0; cin >> m >> n >> s0;
    vt<ll> a(n),b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    queue<ll> q;
    vt<ll> dist(m, -1);
    vt<bool> visited(m, false);
    q.push(s0);
    visited[s0] = true;
    dist[s0] = 0;
    while(!q.empty()) {
        ll cur = q.front();
        q.pop();
        for(int i = 0; i < n; i++) {
            ll nxt = (cur * a[i] + b[i]) % m;
            if(!visited[nxt]) {
                visited[nxt] = true;
                q.push(nxt);
                dist[nxt] = dist[cur] + 1;
                if(nxt == 0) {
                    cout << dist[nxt] << endl;
                    return;
                }
            }
        }
    }
    cout << -1 << endl;
}

void sol6() {
    
}

int main() {
    fast_io;
    sol5();
}

