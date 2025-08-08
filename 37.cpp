#include <bits/stdc++.h>
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,O2")
using namespace std;
#define vt vector
#define pb push_back
#define ft first
#define sc second
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
    string s; cin >> s;
    int n = sz(s);
    int t; cin >> t; while(t--) {
        string p; cin >> p;
        if(sz(p) % n != 0) {
            cout << "NO\n";
            continue;
        }
        int ok = 0;
        for(int i = 0; i < sz(p); i += n) {
            if(p.substr(i, n) == s) {
                ok++;
            }
        }
        if(ok == sz(p) / n) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }

    }
    cerr << "Time elapsed: " << TIME << " s.\n";
}

void sol2() {
    int n,m; cin >> n >> m;
    vt<int> a(n+1);
    for(int i = 1; i <=n; i++) {
        cin >> a[i];
        if(a[i] >= m) {
            cout << i; 
            goto end;
        }
    }
    cout << -1;
    end:;

}
void sol3() {
    int k; cin >> k;
    vt<ll> a(k); 
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }

    int n; cin >> n;
    vt<ll> c(k); 
    vt<vt<ll>> orders(n, vt<ll>(k)); 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> orders[i][j];
            c[j] += orders[i][j];
        }
    }

    ll day = INF;
    for (int i = 0; i < k; i++) {
        if (c[i] == 0) continue;
        day = min(day, a[i] / c[i]);
    }

    for (int i = 0; i < k; i++) {
        a[i] -= c[i] * day;
    }
    for (int i = 0; i < n; i++) {
        bool can = true;
        for (int j = 0; j < k; j++) {
            if (a[j] < orders[i][j]) {
                can = false;
                break;
            }
        }
        if (!can) {
            cout << (day + 1) << ' ' << (i + 1) << '\n';
            return;
        }
        for (int j = 0; j < k; j++) {
            a[j] -= orders[i][j];
        }
    }
    cout << (day + 2) << " 1\n";
}

int p[26];
int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }

void sol4() {
    int t; cin >> t; while (t--) {
        string s1, s2, s3; cin >> s1 >> s2 >> s3;
        if (sz(s1) != sz(s2)) { 
            cout << "NO\n"; 
            continue; 
        }
        if (sz(s1) != sz(s3)) { 
            cout << "YES\n"; 
            continue; 
        }
        iota(p, p + 26, 0);
        for (int i = 0; i < sz(s1); ++i) {
            if (s1[i] != s2[i]){
                p[find(s1[i] - 'a')] = find(s2[i] - 'a');
            }  
        }
        for (int i = 0; i < sz(s1); ++i) {
            if (s1[i] != s3[i] && find(s1[i] - 'a') != find(s3[i] - 'a')) {
                cout << "YES\n";
                goto end;
            }
        }
        cout << "NO\n";
        end:;
    }
}

int main() {
    fast_io;
    sol4();
    return 0;
}