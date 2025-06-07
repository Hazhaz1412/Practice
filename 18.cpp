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
    int t; cin >> t; while (t--) {
        int n; cin >> n; vt<int> a(n);
        int zero = 0;
        int two = 0;
        int one = 0;
        int five = 0;
        int three = 0;
        for (int& x : a) {
            cin >> x;
        }
        bool ok = false;
        int res = 0;
        for (int& x : a) {
            res++;
            if (x == 0) {
                zero++;
            }
            else if (x == 2) {
                two++;
            }
            else if (x == 1) {
                one++;
            }
            else if (x == 5) {
                five++;
            }
            else if (x == 3) {
                three++;
            }
            if (zero >= 3 && two >= 2 && one >= 1 && five >= 1 && three >= 1)
            {
                ok = true;
                break;
            }
            
        }
        if (ok) {

            cout << res << endl;
        }
        else {
            cout << 0 << endl;
        }
    }
}


void sol2() {
    int t; cin >> t; while (t--) {
        int n, x; cin >> n >> x;
        vt<int> a(n);
        for (int& x : a) {
            cin >> x;
        }
        int ss = 1;
        vt<int> b;
        rsor(a);
        int res = 0;
        int sm = a[0];
        for (int i = 0; i < n; i++) {
            if(a[i] >= x) {
                res++;
            }
            else {
                b.pb(a[i]);
            }
        }
        rsor(b);
        int smb = b[0];
        int bs = b.size();
        for (int i = 0; i < bs; i++) {
            if (smb > b[i]) {
                smb = b[i];
            }
            if (ss * smb >= x) {
                res++;
                ss = 0;
                smb = INT_MAX;
            }
            ss++;
        }
        cout << res << endl;
    }
}


void sol2b() {
    int t; cin >> t;while(t--) {
        int n, x;
        cin >> n >> x;
        vt<int> a(n);
        for (int &x : a) cin >> x;
        rsor(a); 
        int res = 0, team = 0, sm = INT_MAX;
        for (int i = 0; i < n; i++) {
            team++;  
            sm = a[i]; 
            if (team * sm >= x) {
                res++; 
                team = 0; 
            }
        }
        cout << res << endl;
    }
     
}

void sol3() {
    int t; cin >> t; while(t--) {
        int n; cin >> n; 
        if(n % 2 == 0) {
            cout << -1 << endl;
        }
        else {
            vt<int> a(n);
            for(int i = 0; i < n; i++) {
                a[i] = i+1;
            }
            for(int&x:a) {
                cout << x << " ";
            }
            cout << endl;
        }

    }
} 
int main() {
    fast_io;
    sol3();
} 