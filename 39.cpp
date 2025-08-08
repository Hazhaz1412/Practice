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
const int IINF = 1e9;
void sol() {
    int t; cin >> t; while(t--) {
        int n; cin >> n;
        vt<int> a(n);
        int big = 0;
        int sm = IINF;
        for(int &x: a) cin >> x;
        for(int i = 0; i < n;i++) {
            big = max(big, a[i]);
            sm = min(sm, a[i]);
        }
        cout << big - sm << endl;
    }
    cerr << "Time elapsed: " << TIME << " s.\n";
}

void sol2() {
    int T;
	cin >> T; 
	while (T--) {
		int N;
		cin >> N;
		ll a[1000000];
		ll chan = 0;
		ll le = 0;
		for (int i = 0; i < N; i++) {
			cin >> a[i];
			if (a[i] % 2 == 0) {
				chan++;
			}
			else {
				le++;
			}
		}
		ll tong = (chan * (chan - 1)) / 2 + (le * (le - 1)) / 2;
		cout << tong << endl;
	}
}

int main() {
    fast_io;
    sol2();
    return 0;
}