#include <bits/stdc++.h>
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,O2")
using namespace std;
#define vt vector
#define pb push_back
#define pii pair<int,int>
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
 
int moveX[4] = {1, -1, 0, 0};
int moveY[4] = {0, 0, 1, -1};
char dir[4] = {'D', 'U', 'R', 'L'};


bool valid(vt<vt<char>> &grid, vt<vt<bool>> &visited, int i, int j, int n, int m) {
    return (i >= 0 && i < n && j >= 0 && j < m && !visited[i][j] && grid[i][j] != '#');
}

void sol() {
    int n, m; cin >> n >> m;
    pii start, end;
    vt<vt<char>> grid(n, vt<char> (m));
    vt<vt<bool>> visited(n, vt<bool> (m));
    vt<vt<char>> move(n, vt<char>(m, 0));
    for(int i =0; i < n;i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if(grid[i][j]=='A') start = {i,j};
            if(grid[i][j] =='B') end= {i,j};
        }
    }
    queue<pii> q;
    q.push(start);
    visited[start.first][start.second] = true;
    bool found = false;
    while(!q.empty()) {
        auto [x,y] = q.front();
        q.pop();
        if(make_pair(x,y) == end) {
            found = true;
            break;
        }
        for(int i = 0; i < 4; i++) {
            int go1 = x + moveX[i];
            int go2 = y + moveY[i];
            if(valid(grid, visited, go1, go2, n, m)) {
                visited[go1][go2] = true;
                move[go1][go2] = dir[i];
                q.push({go1, go2});
            }
        }
        
    }
    if(found){
        cout << "YES\n";
        string path;
        pii cur = end;
        while(cur != start) {
            char c = move[cur.first][cur.second];
            path += c;
            if(c == 'D') cur.first--;
            else if(c == 'U') cur.first++;
            else if(c == 'R') cur.second--;
            else if(c == 'L') cur.second++;
        }
        reverse(path.begin(), path.end());
        cout << path.size() << '\n' << path << '\n';
        
    }
    else {
        cout << "NO\n";
    }


    cerr << "Time elapsed: " << TIME << " s.\n";
}

int main() {
    fast_io;
    sol();
    return 0;
}