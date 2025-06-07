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

void sol() {
    int t; cin >> t; while(t--) {
        int x,y,z; cin >> x >> y >> z;
        vt<int> a = {x,y,z};
        sort(a.begin(), a.end());
        int res = abs(x-a[1]) + abs(y-a[1]) + abs(z-a[1]);
        cout << res << '\n';
    }
    //cerr << "Time elapsed: " << TIME << " s.\n";
}

int N,M;
 
int moveX[4] = {0, 0, -1, 1};
int moveY[4] = {1, -1, 0 , 0};

bool valid(int i, int j) {
    if(i >= 0 && i < N && 0 <= j && j < M) {
        return true;
    }
    else {
        return false;
    }
}
void sol2() {
    int t; cin >> t; while(t--) {
        cin >> N >> M;
        vt<vt<int>> a(N, vt<int> (M));
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M;j++) {
                cin >> a[i][j];
            }
        }
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M;j++) {
                 int tmp = 0;
                 for(int k = 0; k < 4; k++) {
                    int xi = i + moveX[k], yj = j + moveY[k];
                    if(valid(xi,yj)) {
                        tmp = max(tmp, a[xi][yj]);
                    }
                 }
                 a[i][j] = min(a[i][j], tmp);
            }
        }
        for(int i = 0; i < N; i++) {
            cout << '\n';
            for(int j = 0; j < M;j++) {
                cout << a[i][j] << ' ';
            }
        }
    }
}

void sol3() {
    int T;
	cin >> T;
	while (T--) {
		int a, b, c;
		cin >> a >> b >> c;
		int tong = a + b + c;
		if ( tong % 3 != 0 ) {
			cout << "NO" << endl;
			continue;
		}
		int tb = tong / 3;
		if (a <= tb && b <= tb && c >= tb &&
			(tb - a) + (tb - b) == (c - tb)) {
			cout << "YES" << endl; 
		}
		else {
			cout << "NO" << endl;
		}
	}
}

void sol4() {
    int t; cin >> t; while(t--) {
        int n; cin >> n;
        vt<int> a(n);
        for(int i = 0 ; i < n ;i++) {
            cin >> a[i];
        }
        int big = *max_element(all(a));
        int sm = *min_element(all(a));
        if(big == sm) {
            cout << "NO\n";
            continue;
        }
        cout << "Yes\n";
        for(int i = 0 ; i < n;i++) {
            if(a[i] == big) {
                cout << 1 << ' ';
            }
            else {
                cout << 2 << ' ';
            }
        }
        cout << '\n';
    }
}
void sol5() {
    int n, q;cin >> n >> q;
    vt<int> a(n + 1), b(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        a[i] = i;
    }
    function<int(int)> it = [&](int x) -> int {
        if(a[x] != x) {
            a[x] = it(a[x]); 
        }
        return a[x];
    };
    
    for(int i = 0; i < q; i++) {
        string op;
        int x, y;
        cin >> op >> x >> y;
        
        if(op == "union") {
            int rootX = it(x);
            int rootY = it(y);
            
            if(rootX != rootY) {
                if(b[rootX] < b[rootY]) {
                    a[rootX] = rootY;
                } else {
                    a[rootY] = rootX;
                    if(b[rootX] == b[rootY]) {
                        b[rootX]++;
                    }
                }
            }
        } else { 
            if(it(x) == it(y)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}

int main() {
    fast_io;
    sol5();
    return 0;
}