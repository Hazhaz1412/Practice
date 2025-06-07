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
#define sq(x) void sol##x()
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
        vt<int> s(3);
        int a,b,c;
        cin >> a >> b >> c;
        s[0] = a; s[1]= b; s[2] = c;
        for(int i = 0; i < 5;i++){
            sor(s);
            s[0]++;
        }
        cout << s[0]*s[1]*s[2] << endl;
    }
}

void sol2() {
    int t; cin >> t; while(t--) {
        int n,k; cin >> n >> k;
        vt<int> a(k);
        for(int &x: a) {
            cin >> x;
        }
        sor(a);
        int res = 0;
        for(int i = k-2; i >= 0; i--) {
            if(a[i] == 1) {
                res++;
            }
            else {
                res += ((a[i]-1) + a[i]);
            }
        }
        cout << res << endl;
    }
}
// f >= k
// g <= m
void sol3() {
    int t; cin >> t; while(t--) {
        int n,m,k; cin >> n >> m >> k;
        vt<int> a;
        for (int i = n; i >= m + 1; i--) {
            a.push_back(i);
        }
        for (int i = 1; i <= m; i++) {
            a.push_back(i);
        }
        for(int &x: a) cout << x << " ";
        cout << endl;
    }
}

sq(4) {
    int t; cin >> t; while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        string s;
        cin >> s;
        int l = m - 1, w = 0;
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if(s[i] == 'L') l = m;
            else {
                if(l <= 0) {
                    if(s[i] == 'W') {
                        w++;
                    }
                    else {
                        ok = false;
                    }
                }
            }
            l--;
        }
        if (w > k) ok = false;
        cout << (ok? "YES\n" : "NO\n");
    }

}

sq(5) {
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        int res = 0;
        for (int i = 0; i < n - 1; i++) {
            if ((s[i] == 'A' && s[i + 1] == 'B')) {
                swap(s[i], s[i + 1]);
                res++;
            }
        }
        for (int i = n - 2; i > 0; i--) {
            if(s[i] == 'B' && s[i-1] == 'A') {
                swap(s[i], s[i-1]);
                res++;
            }
        }
        cout << res << endl;
    }
}

sq(6) {
    int t; cin >> t; while(t--) {
        ll n, k; cin >> n >> k;
        ll l = 1, r = k*k, res = r;
        while(l <= r) {
            ll mid = l + (r - l) /2 ;
            ll tmp = mid - mid / n;
            if(tmp >= k) {
                res = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        cout << res << endl;
    }
}

sq(7) {
    int t; cin >> t; while(t--) {
        ll n, k; cin >> n >> k;
        ll l = 1, r = k*2, res = r;
        while(l <= r) {
            ll mid = l + (r - l) / 2;
            ll tmp = mid - mid / n;
            if(tmp >= k) {
                res = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        cout << res << endl;
    }
}

sq(8) {
    int t; cin >> t; while(t--) {
        int n; cin >> n;
        vt<int> a(n);
        for(int &x:a) {
            cin >> x;
        }
    }
}

int main() {
    fast_io;
    sol7();
    return 0;
}
