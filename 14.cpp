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
        int n; cin >> n;
        int res = 0;
        if(n <= 15) {
            for(int i = 0; i <=n ;i++) {
                if((i % 3) == (i%5)) {
                    res++;
                }
            }
            cout << res << endl;
            continue;
        }
        res = (n / 15) * 3 + min(3, n % 15 + 1);
        cout << res << endl;
    }
}
bool pf(ll x) {
    ll r = floor(sqrt(x));
    return r * r == x;
}

void sol2() {
    int t; cin >> t; while(t--) {
        ll n; cin >> n;
        ll sum = n * (n + 1) / 2;
        if(pf(sum)) {
            cout << -1 << endl;
            continue;
        }
        vt<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = i + 1;
        }
        ll pref = 0;
        for (int i = 0; i < n; i++) {
            if(i + 1 < n && pf(pref + res[i])) {
                swap(res[i], res[i+1]);
            }
            pref += res[i];
        }
        for (int x : res) {
            cout << x << " ";
        }
        cout << endl;
    }
}
// 0 1 2 15 16 17 30 31 32 

void sol3() {
    unordered_map<string, int> a;
    int t; cin >> t; while(t--) {
        string s; cin >> s;
        if(a[s] == 0) {
            cout << "OK\n";
        }
        else {
            cout << s << a[s] << endl;
        }
        a[s]++;
    }
}

void sol4() {
    int t; cin >> t; while(t--) {
        int n; cin >> n;
        unordered_map<int, ll> a;
        ll p = 0;
        for(int i = 0; i<n; i++) {
            int v; cin >> v;
            int s = v-i;
            p += a[s];
            a[s]++;
            
        } 
        cout << p << endl;
        
    }
}
bool check(ll p, const string& s, const vt<ll>& a, int k) {
    int n = s.size();
    int total_cnt = 0; 
    int i = 0;
    while (i < n) {
        if (a[i] > p && s[i] == 'R') {
            i++;
        } else {
            int l = i;
            bool ch = false;
            while (i < n && !(a[i] > p && s[i] == 'R')) {
                if (a[i] > p && s[i] == 'B') {
                    ch = true; 
                }
                i++;
            }
            if (ch) {
                total_cnt++; 
            }
        }
    }
    return total_cnt <= k;
}

int main() {
    fast_io
    int t; cin >> t; while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int cnt = 0; 
        for (int i = 0; i < n; i++) {
            if (s[i] == 'B' && (i == 0 || s[i-1] != 'B')) {
                cnt++;
            }
        }
        if (cnt <= k) {
            cout << 0 << endl;
            continue;
        }
        set<ll> st(all(a));
        vt<ll> p(all(st));
        int l = 0, r = p.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (check(p[mid], s, a, k)) {
                r = mid; 
            } else {
                l = mid + 1; 
            }
        }
        cout << p[l] << endl;
    }
    return 0;
}