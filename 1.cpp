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
    int t; cin >> t; while(t--) {
        int n; cin >> n; vt<int> a(n); for (int& i : a) cin >> i;   
        bool ok = false;
        int big = a[n-1];
        for(int i = 0; i < n-1; i++) {
            int tmp = min(a[i], a[i+1]);
            if(a[i]-tmp > big) {
                cout << "NO\n";
                goto end;
            }
            a[i] -= tmp;
            a[i+1] -= tmp;
            
        }
        for(int i = 0; i < n-1;i++) {
            if(a[i] > a[i+1]) {
                cout << "NO\n";
                goto end;
            }
        }
        cout << "YES\n";
        end:;
    }
}

vector<int> fibonacci(int N) {
    vector<int> fib;
    if (N >= 0) fib.push_back(0);
    if (N >= 1) fib.push_back(1);
    int a = 0, b = 1;
    while (true) {
        int next = a + b;
        if (next > N) break;
        fib.push_back(next);
        a = b;
        b = next;
    }
    return fib;
}
void sol2() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> result = fibonacci(N);
        for (int num : result) {
            cout << num << " ";
        }
        cout << "\n";
    }
}
void sol3() {
    int t; cin >> t; while(t--) {
        ll n; cin >> n;
        vt<ll> a(n+3); 
        a[0] = 0;
        a[1] = 1;
        for(ll i = 2; i <= n+2; i++) {
            a[i] = (a[i-1] + a[i-2]);  
        }
        for(ll i = 0; i <= n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}
int main() {
    fast_io;
    sol3();
    return 0;
}
