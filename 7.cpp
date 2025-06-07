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
 
const int maxn = 301;
const int maxm = maxn * maxn;
 
int n, a[305];

int getDepth(int x, unordered_map<int,int>& memo) {
    if(x == 1) return 0;
    if(memo.count(x)) return memo[x];
    int d = 1;
    for (int i = 2; i * i <= x; i++) {
        if(x % i == 0) {
            d = getDepth(x / i, memo) + 1;
            break;
        }
    }
    memo[x] = d;
    return d;
}
vt<vt<int>> graph;
vt<int> matchR;
vt<bool> used;
bool dfs(int u) {
    if(used[u]) return false;
    used[u] = true;
    for(auto v : graph[u])
        if(matchR[v] == -1 || dfs(matchR[v])) {
            matchR[v] = u;
            return true;
        }
    return false;
}
void sol() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
 
    unordered_set<int> cs;
    unordered_map<int,int> memo;
    for (int i = 0; i < n; i++){
        vector<int> divs;
        for (int j = 1; j * j <= a[i]; j++){
            if(a[i] % j == 0){
                divs.push_back(j);
                if(j * j != a[i])
                    divs.push_back(a[i]/j);
            }
        }
        for(auto d : divs)
            cs.insert(d);
    }
 
    vt<pair<int,int>> cand; 
    for(auto x : cs)
        cand.pb({getDepth(x, memo), x});
    sor(cand);
    int m = cand.size();
    graph.assign(m, vt<int>()); 
    for (int i = 0; i < m; i++){
        int val = cand[i].second;
        for (int j = 0; j < n; j++){
            if(a[j] % val == 0)
                graph[i].pb(j);
        }
    }
    int res = 0;
    for(int i = 0; i < n; i++){
        res += getDepth(a[i], memo);
    }
    matchR.assign(n, -1);
    for(int i = 0; i < m; i++){
        used.assign(m, false);
        if(dfs(i))
            res -= cand[i].first;
    }
    cout << res;
}
int main() {
    fast_io;
    sol();
    return 0;
}
