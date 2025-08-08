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

int value(char c) {
    if(c == 'I') return 1;
    if(c == 'V') return 5;
    if(c == 'X') return 10;
    if(c == 'L') return 50;
    if(c == 'C') return 100;
    if(c == 'D') return 500;
    if(c == 'M') return 1000;
    return 0;
}
void sol() {
    string s; cin >> s;
    int n = sz(s);
    int res = value(s[n-1]);
    for(int i = n-2; i >= 0; i--) {
        if(value(s[i]) < value(s[i+1])) {
            res -= value(s[i]);
        }
        else {
            res += value(s[i]);
        }
    }
    cout << res << '\n';
}

void sol2() {
    int n; cin >> n;
    vt<int> a(n);
    ll sum = 0;
    for(int &x: a) {
        cin >> x;
        sum += x;
    }
    ll res = INF;
    for(int m = 0; m < (1 << n); m++) {
        ll s = 0;
        for(int i = 0; i < n; i++) {
            if(m & (1 << i)) s += a[i];
        }
        res = min(res, abs(sum - 2* s));
    }
    cout << res;

    cerr << "Time elapsed: " << TIME << " s.\n";
}

char board[8][8];
bool col[8], diag1[15], diag2[15]; // col[j], diag1[i+j], diag2[i-j+7]
int ans = 0;

// Lưu vị trí hậu theo từng hàng
int queen_pos[8];

void printFullBoard(int placedRow) {
    cout << ">>> Đã đặt " << placedRow + 1 << " quân hậu:\n";
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (i <= placedRow && queen_pos[i] == j)
                cout << 'Q';
            else if (board[i][j] == '*')
                cout << '*';
            else
                cout << '.';
        }
        cout << '\n';
    }
    cout << "----------------------\n";
}

void backtrack(int row) {
    if (row == 8) {
        ans++;
        return;
    }

    for (int j = 0; j < 8; ++j) {
        if (board[row][j] == '*') continue;
        if (col[j] || diag1[row + j] || diag2[row - j + 7]) continue;

        col[j] = diag1[row + j] = diag2[row - j + 7] = true;
        queen_pos[row] = j; // Ghi lại vị trí hậu ở hàng row

        printFullBoard(row); // DEBUG: In trạng thái hiện tại

        backtrack(row + 1);

        col[j] = diag1[row + j] = diag2[row - j + 7] = false;
        // queen_pos[row] không cần reset vì sẽ bị ghi đè ở lượt sau
    }
}

void sol3() {
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            cin >> board[i][j];

    backtrack(0);
    cout << "Tổng số cách đặt hậu hợp lệ: " << ans << endl;
}


int main() {
    fast_io;
    sol3();
    return 0;
}