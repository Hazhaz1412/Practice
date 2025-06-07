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
const ll INF = 1e9;
const ll INF2 = 1e18;
void sol() {
    int t; cin >> t; while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        int one = 0;
        for(int i = 0; i < n ;i++) {
            if(s[i] == '1') {
                one++;
            }
        }
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                res += one-1;
            }
            else {
                res += one+1;
            }
        }
        cout << res << '\n';
    }
}

void sol2() {
    int t; cin >> t; while(t--) {
        int n; cin >> n; vt<int> a(n); for(int &x:a) cin >> x;
        map<int, int> cnt;
        for (int x : a) {
            cnt[x]++;
        }
        ll res = 0, sum = 0;
        for (auto [x, c] : cnt) {
            if (c >= 3) {
                res += 1LL * c * (c - 1) * (c - 2) / 6;
            }
            if (c >= 2) {
                res += sum * 1LL * c * (c - 1) / 2;
            }
            sum += c;
        }
        cout << res << '\n';
    }
}


void sol3() {
    int t; cin >> t; while(t--) {
        int n, x; cin >> n >> x;
        vt<int> a;
        if(n == 1) {
            cout << 0 << '\n';
            continue;
        }
        for(int i = 0; i < x; i++) {
            if(i != x) {
                a.pb(i);
            }
        }
        for(int i = n-1; i >= x; i--) {
            a.pb(i);
            
        }
        for(int &x: a) {
            cout << x << ' '; 
        }
        cout << '\n';
    }
}

void sol4() {
    int n; cin >> n; 
    vt<int> a(n);
    for(int &x:a) {
        cin >> x;
    }
    vt<int> dp(n+1, 0);
    dp[0] = 1;
    for(int i = 1; i < n; i++) {
        if(a[i] >= a[i-1]) {
            dp[i] = dp[i-1] +1;
        }
        else {
            dp[i] = 1;
        }
    }
    cout << *max_element(dp.begin(), dp.end());
}

void sol5() {
    int n, a, b, c; cin >> n >> a >> b >> c;
    int v[3] = { a, b, c};
    vt<int> dp(n+1, -1);
    dp[0] = 0;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            if (i >= v[j] && dp[i - v[j]] != -1) {
                dp[i] = max(dp[i], dp[i - v[j]] + 1);
            }
            
        }
        
    }
    cout << dp[n];
}

void sol6() {
    int n; cin >> n;
    vt<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int q; cin >> q;
    while(q--) {

    }
}


void sol7() {
    int t; 
    cin >> t;
    while (t--) {
        int n; string s;
        cin >> n >> s;
        for (int i = 1; i <= n; i++) {
            vt<int> a(n+1);
            multiset<int> st;
            for (int x = 1; x <= n; x++) 
                if (x != i) st.ins(x);
            
            a[1] = i;
            int scs = i, lcs = i;
            bool ok = true;
            for (int j = 2; j <= n; j++) {
                if (s[j-2] == '<') {
                    auto it = st.lower_bound(scs);
                    if (it == st.begin()) {
                        ok = false;
                        break;
                    }
                    --it;
                    a[j] = *it;
                    scs = a[j];
                    st.erase(it);
                } else {
                    auto it = st.ub(lcs);
                    if (it == st.end()) {
                        ok = false;
                        break;
                    }
                    a[j] = *it;
                    lcs = a[j];
                    st.erase(it);
                }
            }
            if (ok) {
                for (int i = 1; i <= n; i++) {
                    cout << a[i] << (i==n?'\n':' ');
                }
                break;
            }
        }
    }
}

void sol8() {
    int n, k; cin >> n >> k;
    vt<int> a(n);
    for(int i = 0; i < n ;i++) {
        cin >> a[i];
    }
    vt<int> dp(n+1, 1000);
    
    for(int i = 0; i < n; i++) {
        int sum = a[i];
        for(int j = 0; j < k-1; j++) {
            sum += a[i+j];
        }
    }
}

void sol9() {
    int t; cin >> t; while(t--) {
        int n; cin >> n; 
        vt<int> a(n);
        int one = 0, two = 0, sum = 0;
        for(int i = 0 ; i < n; i++) {
            cin >> a[i];
            sum += a[i];
            if(a[i] == 1) {
                one++;
            }
            else {
                two++;
            }
        }
        if(two % 2 == 0 && one % 2 == 0 && one > 0) {
            cout << "YES\n";
            continue;
        } 
        if(two % 2 == 0 && one == 0) {
            cout << "YES\n";
            continue;
        } 
        if(one % 2 == 0 && two % 2 != 0 && one > 0) {
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }
}
//vector<bool> dp(1e6+1, false);
//uncomment this to run sol10
// void sol10() {
//     //dp[0] = true;
//     for (int i = 1; i <= 1e6; ++i) {
//             if (i >= 2020 && dp[i - 2020]) dp[i] = true;
//             if (i >= 2021 && dp[i - 2021]) dp[i] = true;
//     }
//     int t; cin >> t; while(t--) {
//         int n; cin >> n;
//         cout << (dp[n] ? "YES\n" : "NO\n");
//     }
// }

void sol11() {
    int n, m; cin >> n;
    vt<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
    vt<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int l = max(n, m);
    vt<int> dp(l + 1, 0);
    for (int i = 0; i < m; i++) {
        if (abs(a[0] - b[i]) <= 1) {
            dp[0] = 1;
            a[0] = 9999;
            b[i] = -999;
            break;
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (abs(a[i] - b[j]) <= 1) {
                dp[i] = dp[i - 1] + 1;
                b[j] = -999;
                a[i] = 9999;
                break;
            }
            if (j == m-1) {
                dp[i] = dp[i - 1];
            }
        }
    }
    cout << *max_element(dp.begin(), dp.end());
}

void sol12() {
    int n; cin >> n;
    vt<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vt<int> dp(n + 2);
    dp[0] = 0;
    int res = 1;
    int tmp = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i + 1]) {
            tmp++;
            res = max(res, tmp);
        }
        else {
            tmp = 1;
            res = max(res,tmp);
        }
    }
    cout << res;
}


void sol13() {
    int m, s; cin >> m >> s;
    if (s > 9*m || (s == 0 && m > 1)) {
        cout << -1 << ' ' << -1;
        return;
    }
    if(s == 0 && m > 0) {
        cout << 0 << ' ' << 0;
        return;
    }
    string a(m, '0');
    int left = s;
    int num = max(1, left - 9 * (m - 1));
    a[0] = '0' + num;
    left -= num;
    for (int i = m - 1; i > 0 && left > 0; i--) {
        int digit = min(9, left);
        a[i] = '0' + digit;
        left -= digit;
    }
    string b(m, '0');
    left = s;
    for (int i = 0; i < m && left > 0; i++) {
        int digit = min(9, left);
        b[i] = '0' + digit;
        left -= digit;
    }
    
    cout << a << ' ' << b;
}

void sol14() {
    int n; cin >> n;
    vt<int> a(n);
    for(int i = 0 ; i < n ; i++) {
        cin >> a[i];
    }
    vt<int>dp(n+1);
    if(a[0] == 0){
        dp[0] = 0;
    }
    else {
        dp[0] = 1;
    }
    for(int i = 1; i < n;i++) {
        if(a[i] != 0 && a[i] != a[i-1]) {
            dp[i] = dp[i-1] + 1;
        }
        else {
            dp[i] = dp[i-1];
        }
    }
    cout << dp[n];
}

void sol15() {
    int n, x; cin >> n >> x;
    vt<ll> a(n);
    for(int i = 0 ; i < n; i++) {
        cin >> a[i];
    }
    vt<ll> dp(x+1);
    dp[0] = 1;
    for(int i = 1 ; i <= n; i++) {
        for(int j = 0; j <= x; j++) {
            if(j-a[i-1] >= 0) {
                dp[j] += dp[j-a[i-1]];
                dp[j] = dp[j] % MOD;

            }
        }
    }
    cout << dp[x];
}

void sol16() {
    int n; cin >> n;
    vt<int> dp(n+1, INF);
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        int tmp = i;
        while(tmp) {
            int d = tmp % 10;
            dp[i] = min(dp[i], dp[i-d]+1);
            tmp /= 10;
        }
    }
    cout << dp[n];
}

int main() {
    fast_io;
    sol16();
    return 0;
}
