#include <bits/stdc++.h>
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,O2")
using namespace std;
#define vt vector
#define pb push_back
#define eb emplace_back
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
 
int ceil_div(int a, int b) {
    return (a + b - 1) / b;
}
void sol() {
    int t; cin>>t; while(t--){
	    int n,k; cin>>n>>k;
	    string s; cin>>s;
	    int x = count(all(s), '1');
	    if(k>=x) cout<<"ALICE\n";
	    else if(k>n/2) cout<<"ALICE\n";
	    else cout<<"BOB\n";
	}

    cerr << "Time elapsed: " << TIME << " s.\n";
}

void sol2() {
    int n; cin >> n;
    vt<int> a(n);
    for (int &x : a) cin >> x;
    int even = 0, odd = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == 0) ++even;
        else ++odd;
    }
    int x = (even == 1) ? 0 : 1;  
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == x) {
            cout << i + 1 << endl;
            return;
        }
    }
}


void sol3() {
    int t; cin >> t; while(t--) {
        vector<int> nums(4);
        for (int i = 0; i < 4; ++i) cin >> nums[i];

        int maxResult = -1;

        sort(nums.begin(), nums.end()); 

        do {
            int a = nums[0];
            int b = nums[1];
            int c = nums[2];
            int d = nums[3];

            int result = a * b + c * d;
            if (result > maxResult) {
                maxResult = result;
            }
        } while (next_permutation(nums.begin(), nums.end()));

        cout << maxResult << endl;
    }
     
}
void sol4() {
   int t; cin >> t; while(t--) {
    int n; cin >> n;
    vt<ll> a(n);
    for(int i = 0 ; i < n ;i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n-1; i++) {
        a[i] = a[i] & a[i+1];
    }
    cout << a[0] << endl;
   }
}

void sol5() {
    int t; cin >> t; while(t--) {
        ll n; cin >> n;
        ll res = n;
        while(n > 0) {
        res += (n >> 1);
        n = (n>>1);
    }
    cout << res << '\n';
    }
}

void sol6() {
    int n; cin >> n;
    vt<int> a(n);
    for(int &x:a) cin >> x;
    vt<vt<bool>> dp(n+1, vt<bool>(360, false));
    dp[0][0] = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 360; j++) {
            if(dp[i][j]) {
                dp[i+1][(j+a[i])%360] = true;
                dp[i+1][(j-a[i] +360) % 360] = true;
            }
        }
    }
    cout << (dp[n][0] ? "YES" : "NO");
}

void sol7() {
    int t; cin >> t; while(t--) {
        int a,b; cin >> a >> b;
        int x = min(a,b);

        cout << (a^x) + (b^x) << '\n';
    }
}

void sol8() {
    int n, w; cin >> n >> w;
    vt<pair<ll,ll>> a(n);
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        a[i] = {x, y};
    }
    vt<ll> dp(w + 1, 0);
    for(int i = 0; i < n; i++) {
        for(int j = w; j >= a[i].first; j--) {
            dp[j] = max(dp[j], dp[j - a[i].first] + a[i].second);
        }
    }
    cout << dp[w];
}

void sol9() {
    int n;
    cin >> n;
    cin.ignore();
    vector<pair<string, string>> names;
    while (n--) {
        string s;
        getline(cin, s);
        for (int i = 0; i < s.size(); i++) {
            if (isupper(s[i])) { 
                string key = s.substr(i);
                names.emplace_back(key, s);
                break;
            }
        }
    }

    sort(names.begin(), names.end());

    for (auto& [key, v] : names) {
        cout << v << '\n';
    }
}


const int N = 1e5 + 1;
int n, m, cat[N];
vt<int> arr[N];
bool visited[N];
int res = 0;

void dfs(int u, int cnt) {
    visited[u] = true;
    if (cat[u]) cnt++;
    else cnt = 0;

    if (cnt > m) return;

    bool ok = true;

    for (int v : arr[u]) {
        if (!visited[v]) {
            ok = false;
            dfs(v, cnt);
        }
    }
    if (ok) res++;
}

void sol10() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> cat[i];

    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        arr[u].pb(v);
        arr[v].pb(u);
    }

    dfs(1, 0);
    cout << res << '\n';
}

void sol11() {
    string s; cin >> s;
    vt<int> a;
    for (char x : s) {
        a.pb(x - 'a');
    }
    vt<int> lis;
    for (int x : a) {
        auto it = lb(all(lis), x);
        if (it == lis.end()) lis.pb(x);
        else *it = x;
    }

    cout << 26 - sz(lis) << '\n';
}
vt<int> ad[N], dp(N);

int dfs(int r) {
    if(dp[r]) return dp[r];
    int bg = 1;
    for(auto x : ad[r]) {
        bg = max(bg, dfs(x) + 1);
    }
    return dp[r] = bg;
}

void sol12() {
    int n; cin >> n;
    vt<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        a[i] = x;
        if(x != -1) {
            ad[x].pb(i);
        }
    }

    int res = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] == -1) {   
            res = max(res, dfs(i));
        }
    }

    cout << res;
}


int main() {
    fast_io;
    sol12();
    return 0;
}