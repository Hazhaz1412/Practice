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
        int n; cin >> n;
        vt<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if(n == 1) {
            cout << 1 << endl;
            continue;
        }
        int cnt = 1, last = a[0]; 
        for(int i = 1; i < n; i++) {
            if(a[i] >= last + 2) {
                cnt++;
                last = a[i];
            }
        }
        
        cout << cnt << endl;
    }
}

void sol2() {
    ll n,k; cin >> n >> k;
    ll odd = (n+1)/2;
    if(k <= odd) {
        cout << 2*k-1;
    }
    else {
        cout << 2*(k-odd);
    }
}

void sol3() {
    int n; cin >> n;
    vt<int> a(n+1);
    for(int i = 1 ; i <= n; i++) cin >> a[i];
    int x = 0, y = 0, z = 0;
    for(int i = 1 ; i <= n; i++) {
        if(a[i] == 1) x++;
        if(a[i] == 2) y++;
        if(a[i] == 3) z++;
    }
    int res = min(min(x,y), z);
    cout << res << '\n';
    vt<int> idx1, idx2, idx3;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) idx1.pb(i + 1); 
        else if (a[i] == 2) idx2.pb(i + 1);
        else if (a[i] == 3) idx3.pb(i + 1);
    }
    for (int i = 0; i < res; i++) {
        cout << idx1[i]-1 << " " << idx2[i]-1 << " " << idx3[i]-1 << "\n";
    }
}

void sol4() {
    int t; cin >> t; while(t--) {
        int n; cin >> n;
        if(n%4) cout << "ALICE\n";
        else cout << "BOB\n";
    }
}
void sol5() {
    int t; cin >> t; while(t--) {
        int n,j,k; cin >> n >> j >> k;
        int b = 0;
        vt<int> a(n+1); for(int i = 1; i <= n; i++) {
            cin >> a[i];
            b = max(b, a[i]);
        }
        if(k > 1) {
            cout << "YES\n";
        }
        else {
            if(a[j] != b) {
                cout << "NO\n";
            }
            else {
                cout << "YES\n";
            }
        }

    }
}

void sol6() {
    int t; cin >> t; while(t--) {
       int n; cin >> n;
        vt<int> a(n);
        for (int &x : a) cin >> x;
        vt<int> pre(n), suff(n);
        pre[0] = a[0];
        for (int i = 1; i < n; ++i)
            pre[i] = min(pre[i - 1], a[i]);

        suff[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; --i)
            suff[i] = max(suff[i + 1], a[i]);

        for (int i = 0; i < n; ++i) {
            if (a[i] == pre[i] || a[i] == suff[i]) cout << '1';
            else cout << '0';
        }
        cout << '\n';
    }
}

int main() {
    fast_io;
    sol6();
    return 0;
}