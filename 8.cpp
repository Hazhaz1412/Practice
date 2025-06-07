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
    int k; cin >> k; string s; cin >> s;
    vt<int> a(26, 0);
    for(char x :s ) {
        a[x-'a']++;
    }
    for(int i = 0; i < 26; i++) {
        if(a[i] % k != 0) {
            cout << -1; return;
        }
    }
    string tmp = "";
    for(int i = 0; i < 26; i++) {
        tmp.append(a[i]/k, 'a'+i);
    }
    string res = "";
    for(int i = 0; i < k; i++) {
        res += tmp;
    }
    cout << res;
}

void sol2() {
    int t; cin >> t; while(t--){
        int n; cin >> n;
        vt<int> a(n);
        for(int &x: a) cin >> x;
        int ans = 0;
        ll sum = 0;
        set<ll> s;
        s.insert(0);
        for (int i = 0; i < n; i++){
            sum += a[i];
            if(s.count(sum)){
                ans++;
                s.clear();
                s.insert(0);
                sum = 0;
            }
            else {
                s.insert(sum);
            }
        }
        
        cout << ans << endl;
    }
}

int main() {
    fast_io;
    sol2();
    return 0;
}
