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
            a[i] = (a[i-1] + a[i-2]) % MOD;  
        }
        for(ll i = 0; i <= n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}

void sol5() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        if (m % 2 != 0) {
            cout << -1 << endl;
            continue;
        }
        int y = (4 * n - m) / 2;     
        int z = n - y;     
        if (y >= 0 && z >= 0) {
            cout << z << " " << y << " " << 0 << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
}

void sol4() {
    
	int t; cin >> t; while (t--) {
		int n, a, b; cin >> n >> a >> b;
        ll l = 0, r = min(n, b);
        ll res = 0;
        while (l <= r) {
            ll mid = (l + r) / 2;
            ll profit_mid = mid * b - (mid * (mid - 1)) / 2 + (n - mid) * a;
            res = max(res, profit_mid);
            if ((mid + 1) * b - ((mid + 1) * mid) / 2 + (n - (mid + 1)) * a > profit_mid) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
		cout << res << endl;
	}
}

void sol6() {
        int n; cin >> n; 
        set<int> s;
        while(n--) {
            int x; cin >> x;
            s.insert(x);
        }
        cout << s.size() << endl;
    }

unordered_set<ll> s;

void sieve(int n) {
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i)
                prime[j] = false;
        }
    }
    for (int i = 2; i <= n; ++i) {
        if (prime[i]) {
            s.insert(1LL * i * i);  
        }
    }
}
void sol7() {
    int n; 
    cin >> n;
    sieve(1e6);  
    while (n--) {
        ll x; 
        cin >> x;
        cout << (s.count(x) ? "YES" : "NO") << '\n';
    }
}

void sol8() {
    string s; cin >> s;
    int n = s.size();
    sort(s.begin(), s.end());
    string res = "";
    for(int i = 0; i < n; i++) {
        if(s[i] != '+') {
            res += s[i];
            res += '+';
        }
    }
    res[n] = ' ';
    cout << res;
}

void sol9() {
    int n; cin >> n;
    vt<int> a(n);
    int sum = 0;
    for(int &x:a) {
        cin >> x;
        sum +=x;
    }
    int total = sum;
    sum = 0;
    sort(a.rbegin(), a.rend());
    int id = 0;
    while(total >= sum) {
        sum += a[id];
        total -=a[id];
        id++;
    }
    cout << id << endl;
}

int main() {
    fast_io;
    sol9();
    return 0;
}