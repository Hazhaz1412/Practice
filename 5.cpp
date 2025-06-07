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
    int n; cin >> n;
    vt<ll> dp(n+1);
    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 6 &&j <= i; j++) {
            dp[i] = (dp[i] + dp[i-j]) % MOD;
        }
    }
    cout << dp[n];
}

void sol2() {
    int n,x; cin >> n >> x;
    vt<int> a(n);
    for(int &x: a) {
        cin >> x;
    } 
    vt<ll> dp(x+1, INF);
    dp[0] = 0;
    for(int i = 1; i <= x; i++) {
        for(int j = 0; j < n; j++) {
           if(a[j] > i || dp[i-a[j]] == INF) {
            continue;
           } 
           dp[i] = min(dp[i], dp[i-a[j]]+1); 
        }
    }
    if(dp[x] != INF) {
        cout << dp[x];
    }
    else {
        cout << -1 << endl;
    }
}

void sol3() {
    int t; cin >> t; while(t--) {
        int l,r; cin >> l >> r;
        int res = 0;
        for(int i = 1; l <= r; i++) {
            l += i;
            cout << l << " ";
        }
    }
}

void sol4() {
    int t; cin >> t; while(t--) {
        int l, r; cin >> l >> r;
        r -= l;
        int le = 1, ri = 1e9;
        while(le < ri) {
            ll mid = (le+ri) / 2;
            if(mid*(mid-1)/2 <= r) {
                le = mid+1;
            }
            else {
                ri = mid;
            }
        }
        cout << le -1 << endl;
    }
}
// max time = 240;
void sol5() {
    int n,k; cin >> n >> k;
    int t = 240 - k;
    int res = 0;
    for(int i = 1; i <= n;i++) {
        if(t >= 5*i) {
            res++;
            t-=5*i;
        }
    }
    cout << res << endl;
}

void sol6() {
    int t; cin >> t; while(t--) {
        int n; cin >> n; 
        vt<int> a(n);
        ll sum = 0;
        for(int &x: a) {cin >> x; sum += x;}
        ll x = sqrt(sum);
        if(x*x == sum) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}
 
void sol7() {
    int t; cin >> t; while(t--) {
        int n; cin >> n; 
        vt<int> a(n);
        ll sum = 0;
        for(int &x: a) {cin >> x; sum += x;}
        int l = 1, r = 1e9;
        bool found = false;
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            long long msqrt = mid * mid;
            if (msqrt == sum) {
                found = true;
                break;
            } else if (msqrt < sum) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (found) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

void sol8() {
    int t; cin >> t; while(t--) {
        int n,k; cin >> n >> k;
        if(k == 1) {
            cout << 1 << endl;
            continue;
        }
        ll x = (n + k - 1) / k;
        ll sum = x * k;
        cout << (sum +n-1)/ n << endl;
    }
}

void sol9() {
    int n,k; cin >> n >> k;
    vt<int> a(n); for(int &x: a) cin >> x;
    sor(a); 
    int mid = n / 2;
    vt<ll> pref(n + 1, 0);
    for (int i = mid; i < n; i++) {
        pref[i + 1] = pref[i] + a[i];
    }
    ll l = a[mid], r = a[mid] + k;
    while (l < r) {
        ll m = (l + r + 1) >> 1 ;
        int j = int(upper_bound(a.begin() + mid, a.end(), m - 1) - a.begin());
        ll x = (ll)(j - mid) * m - (pref[j] - pref[mid]);
        if (x <= k) l = m; 
        else r = m - 1;
    }
    cout << l << endl;
}

void sol10() {
    int t; cin >> t; while(t--) {
        int n; cin >> n;
        vt<int> b(n-2);
        for (int &x : b) cin >> x;
        bool ok = 1;
        for (int i = 3; i <= n-2; i++) {
            int x = i - 2; 
            if(b[x - 1] == 1 && b[x + 1] == 1 && b[x] == 0){
                ok = 0;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}
int main() {
    fast_io;
    sol10();
    return 0;
}
