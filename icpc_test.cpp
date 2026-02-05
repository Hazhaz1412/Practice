#include <bits/stdc++.h>
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,O2")
using namespace std;
#define vt vector
#define pb push_back
#define pii pair<int,int>
#define tii tuple<int,int,int>
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
    int t; cin >> t; while(t--) {
        int n; cin >> n;
        string res = "";
        while(n > 1) {
            if(n % 2 == 0) {
                res += 'L';
                n /= 2;
            }
            else {
                res += 'R';
                n /= 2;
            }
        }
        reverse(all(res));
        cout << res << '\n';
    }
    cerr << "Time elapsed: " << TIME << " s.\n";
}
bool can_make_2026(array<int,10> cnt) {
    const int target[4] = {2,0,2,6};

    function<bool(int)> dfs = [&](int i)->bool {
        if (i == 4) return true;
        int d = target[i];

        // 1) Dùng trực tiếp chữ số d
        if (cnt[d] > 0) {
            --cnt[d];
            if (dfs(i+1)) return true;
            ++cnt[d];
        }

        // 2) Dùng hai chữ số a,b với a+b==d hoặc |a-b|==d
        for (int a = 0; a <= 9; ++a) if (cnt[a] > 0) {
            --cnt[a];
            for (int b = 0; b <= 9; ++b) if (cnt[b] > 0) {
                --cnt[b];
                if (a + b == d || abs(a - b) == d) {
                    if (dfs(i+1)) return true;
                }
                ++cnt[b];
            }
            ++cnt[a];
        }
        return false;
    };

    return dfs(0);
}
void sol2() {
    int T; 
    if (!(cin >> T)) return;
    while (T--) {
        array<int,10> cnt{};
        for (int d = 0; d < 10; ++d) cin >> cnt[d];
        cout << (can_make_2026(cnt) ? "YES" : "NO") << '\n';
    }
}

int main() {
    fast_io;
    sol2();
    return 0;
}
