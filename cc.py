#include <bits/stdc++.h>
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
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

using int64 = long long;
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
        int a,b,c;cin >> a >> b >> c;
        c = c - (b-a);
        int tmp = c-a;
        if(c < b) {
            cout << "NO\n";
            continue;
        }
        if((tmp-a)% 2 == 0) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}

void sol2() {
    int n,m,k; cin >> n >> m >> k;
    vt<int> a(m+1);
    for(int &x: a) {
        cin >> x;
    }
    int x = a[m], res = 0;
    for(int i = 0 ; i < m ;i++) {
        int tmp = a[i] ^ x;
        if(__builtin_popcount(tmp) <= k) {
            res++;
        }
        
    }
    cout << res;

}

int ab[100000];

void sol3() {
    int n, t; cin >> n >> t;
    for(int i = 1; i < n; i++) {
        cin >> ab[i];
    }
    int x = 1;
    while(x < t) {
        x += ab[x];
    }
    if (x == t) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

// int dfs4(int m, int n) {
//     if (m <= n) return n - m;   // chỉ cần bấm blue mấy lần
//     if (m % 2 == 0)
//         return 1 + dfs4(m / 2, n);  // ngược lại thao tác nhân đôi
//     else
//         return 1 + dfs4(m + 1, n);   // để làm chẵn rồi chia tiếp
// }

// void sol4() {
//     int n,m; cin >> n >> m;
//     cout << dfs4(m,n);
// }




void sol5() {
    vector< unsigned long long> dp(1001);
    dp[0] = 0;
    unsigned long long sum = 0;
    for (int i = 1; i <= 1000; i++) {
        if (i % 2 == 0) {
            dp[i] = sum + 1;
            sum += dp[i];
        }
        else {
            dp[i] = sum;
            sum += dp[i];
        }
    }

    int x;
    while (cin >> x) {
        cout << dp[x] << endl;
    }
}

void sol6() {
    int t; cin >> t; while (t--) {
        long long n; cin >> n;
        ll res = 0;
        for (long long i = 1; i <= sqrt(n); i++) {
            if (n % i == 0) {
                res += i;
                if (i != n / i)
                    res += n / i;
            }
        }
        cout << res << '\n';
    }
}

vector<bool> dp(1e6+1, false);
void sol7() {
    dp[0] = true;
    for (int i = 1; i <= 1e6; ++i) {
            if (i >= 2025 && dp[i - 2025]) dp[i] = true;
            if (i >= 2026 && dp[i - 2026]) dp[i] = true;
    }
    int t; cin >> t; while(t--) {
        int n; cin >> n;
        cout << (dp[n] ? "YES\n" : "NO\n");
    }
}

 
int dfs4(int m, int n) {
    if (m <= n) return n - m;  
    if (m % 2 == 0)
        return 1 + dfs4(m / 2, n);  
    else
        return 1 + dfs4(m + 1, n);  
}
 
void sol8() {
    int n,m; cin >> n >> m;
    cout << dfs4(m,n);
}

void sol9() {
    int t; cin >> t; while(t--) {
        int64 n, m;
        cin >> n >> m;

        int64 steps = 0;
        // 1) Khi cả hai đều > 0, ta ưu tiên chia đôi bên có "lợi ích" lớn hơn
        while (n > 0 && m > 0) {
            // Lợi ích khi chia đôi n: (n - floor(n/2)) + 1 từ m--  → tot1
            // Lợi ích khi chia đôi m: (m - floor(m/2)) + 1 từ n--  → tot2
            int64 half_n = n >> 1;
            int64 half_m = m >> 1;
            int64 gain_n = (n - half_n) + 1;
            int64 gain_m = (m - half_m) + 1;

            if (gain_n >= gain_m) {
                // Nhóm tối đa k lần chia đôi n liên tiếp
                // k ≤ m (vì mỗi phép giảm m--), và k ≤ floor(log2(n)) (để n vẫn > 0)
                int64 p = 63 - __builtin_clzll(n);       // floor(log2(n))
                int64 k = min(m, p);
                // Nếu n=1 thì p=0, k=0 → chúng ta không nhóm được, thực hiện 1 lần
                if (k == 0) k = 1;
                // cập nhật
                n = n >> k;
                m = max<int64>(0, m - k);
                steps += k;
            } else {
                // Nhóm tối đa k lần chia đôi m liên tiếp
                int64 p = 63 - __builtin_clzll(m);
                int64 k = min(n, p);
                if (k == 0) k = 1;
                m = m >> k;
                n = max<int64>(0, n - k);
                steps += k;
            }
        }

        // Một trong hai đã về 0, chỉ còn dùng phép "giảm 1"
        steps += n + m;

        cout << steps << "\n";
    }
}


int main() {
    fast_io;
    sol9();
    return 0;
}