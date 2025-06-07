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
    int n; cin >> n;
    string s; cin >> s;
    string cc = "#";
    for (int i = 0; i < n; i++) {
        cc += s[i];
        cc += "#";
    }
    int m = cc.size();
    vector<int> a(m, 0);
    int c = 0, r = 0, res = 0;
    for (int i = 0; i < m; i++) {
        int mirr = 2 * c - i;
        if (i < r)
            a[i] = min(r - i, a[mirr]);

        while (i + a[i] + 1 < m && i - a[i] - 1 >= 0 && cc[i + a[i] + 1] == cc[i - a[i] - 1])
            a[i]++;

        if (i + a[i] > r) {
            c = i;
            r = i + a[i];
        }

        res = max(res, a[i]);
    }

    cout << res;
}
 


void sol2() {
    int n; cin >> n;
    string s; cin >> s;
    string cc = "#";
    for(int i = 0; i < n; i++) {
        cc += s[i];
        cc += '#';
    }
    
    int m = cc.size();
    vt<int> a(m,0);
    int c =0, r=0, res=0;
    for(int i = 0; i < m; i++) {
        int mid = 2*c-i;
        if(i < r) {
            a[i] = min(a[mid], r-i);
        }
        while(i + a[i] +1 < m && i-a[i] -1>= 0 && cc[i + a[i] +1] == cc[i-a[i]-1]) {
            a[i]++;
        }
        if(i+a[i] > r) {
            c = i;
            r = i + a[i];
        }
        res = max(res, a[i]);
    }
    cout << res;
}


void sol3() {
    int t; cin >> t; while(t--) {
        string s; cin >> s;
        int n = sz(s);
        int x =0, y= 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'U') x++;
            else {
                y++;
            }
            if(x >= y*2 && y > 0 || y >= x*2 && x > 0) {
                cout << "YES" << ' ' << 1 << ' ' << i+1 << '\n';
                goto end;
            }
        }
        cout << "NO\n";
        end:;
    }
}


void sol4() {
    int t; cin >> t; while (t--) {
        int n, m; cin >> n >> m;
        if (n == m) { cout << 0 << '\n'; continue; }
        if (m % n) { cout << -1 << '\n'; continue; }
        vt<int> a;
        while (n < m) {
            int x = gcd(n, m / n);
            n *= x;
            a.pb(x);
            if (x == 1) {
                cout << -1 << '\n';
                goto end;
            }
        }
        cout << sz(a) << ' ';
        for (int& x : a) cout << x << ' ';
        cout << endl;
    end:;
    }
}


int main() {
    fast_io;
    sol4();
    return 0;
}