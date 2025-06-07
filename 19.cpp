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
    cout << "puzzling" << endl;
}

void sol2() {
    cout << "12345678910111213141516"<<endl;
}

void sol3() {
    cout << 143 << endl;
}

void sol4() {
    cout << 36.104288 << " " << -115.1734968 << endl;
}
//36.10428850190244, -115.17349680839267
void sol6() {
    string words[] = {
        "",
        "CODEFORCES", // Dòng 1
        "EYE",        // Dòng 2
        "TESTING",    // Dòng 3
        "SYSTEM",     // Dòng 4
        "APRIL",      // Dòng 5
        "FOOLS",      // Dòng 6
        "FUN",     // Dòng 7
        "QUICK",      // Dòng 8
        "BROWN",      // Dòng 9
        "AC",      // Dòng 10
        "OVER"        // Dòng 11
    };
    int n; cin >> n;
    cout << words[n] << endl;
}

int main() {
    fast_io;
    sol3();
    return 0;
}
