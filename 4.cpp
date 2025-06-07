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

int moveX[4] = {0, 0, -1, 1};
int moveY[4] = {1, -1, 0 , 0};

bool valid(vt<vt<char>> &a, vt<vt<bool>> &visited, int i, int j, int n, int m) {
    if(i < 0 || j < 0 || i >= n || j >= m || visited[i][j]  || a[i][j] != '.') {
        return false;
    }
    return true;
}

void dfs(vt<vt<char>> &a, vt<vt<bool>>& visited, int x, int y, int n, int m) {
    visited[x][y] = 1;
    for(int i = 0; i < 4; i++) {
        int x2 = x + moveX[i];
        int y2 = y + moveY[i];
        if(valid(a, visited, x2, y2, n, m) && !visited[x2][y2]) {
            dfs(a,visited, x2, y2, n, m);
        }
    }
}

void sol() {
    int n,m; cin >> n >> m;
    vt<vt<char>> a(n, vt<char>(m));
    vt<vt<bool>> visited(n, vt<bool> (m,0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int res = 0;
    for(int i = 0 ; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == '.' && !visited[i][j]) {
                dfs(a, visited, i, j, n, m);
                res++;
            }
        }
    }
    cout << res << endl;
}



int main() {
    fast_io;
    sol();
    return 0;
}
