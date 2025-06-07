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
using pii = pair<int, int>;
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
 
const int maxn = 301;
const int maxm = maxn * maxn;
 
int a[maxn];
vector<int> e[maxm];
bitset<maxm> vis;
int mch[maxn];

bool dfs(int u) {
    if (vis[u]) return 0;
    vis[u] = 1;
    for (int v : e[u])
        if (mch[v] == -1 || dfs(mch[v])) {
            mch[v] = u;
            return 1;
        }
    return 0;
}
void sol() {
    int n; cin >> n;
    unordered_set<int> s;
    unordered_map<int, int> d;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        vt<int> divs;
        for (int j = 1; j * j <= a[i]; ++j) {
            if (a[i] % j == 0) {
                divs.pb(j);
                if (j * j != a[i])
                    divs.pb(a[i] / j);
            }
        }
        sor(divs);
        vt<pii> cand;
        for (int x : divs) {
            if (!d.count(x)) {
                if (x > 1) d[x] = 1;
                for (int i = 2; i * i <= x; ++i)
                    if (x % i == 0) {
                        d[x] = d[x / i] + 1;
                        break;
                    }
            }
            cand.emplace_back(d[x], x);
        }
        sor(cand);
        if (cand.size() > (unsigned)n) cand.resize(n);
        for (auto [cnt, val] : cand)
            s.insert(val);
    }
    vt<pii> divs;
    for (int x : s)
        divs.emplace_back(d[x], x);
    sor(divs);
    int m = divs.size();
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (a[j] % divs[i].second == 0)
                e[i].push_back(j);
    int res = 0;
    memset(mch, -1, sizeof(mch));
    for (int i = 0; i < m; ++i) {
        vis.reset();
        if (dfs(i))
            res -= divs[i].first;
    }
    for (int i = 0; i < n; ++i)
        res += d[a[i]];
 
    cout << res;
}

int main() {
    fast_io;
    sol();
    return 0;
}