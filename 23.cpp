#include <bits/stdc++.h>
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
#define fast_io ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
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
    int n; cin >> n; 
    ll res = 0;
    for(int i = 1; i <= n; i++) {
        res += i;
    }
    if (res % 2 != 0) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    vt<int> a,b;
    ll x = res /2;
    for(int i = n; i >= 1; i--) {
        if(i <= x) {
            a.pb(i);
            x-=i;
        }
        else {
            b.pb(i);
        }
    }
    cout << sz(a) << endl;
    for(int &x: a) cout << x << ' ';
    cout << endl;
    cout << sz(b) << endl;
    for(int &x: b) cout << x << ' ';
}

void sol2() {
    int n; cin >> n;
    ll res = 2;
    for(int i = 0; i < n-1;i++) {
        res *= 2;
    }
    cout << res;
}
//2 4 8

void sol3() {
    int n; cin >> n;
    ll res = 0;
    for(ll i = 5; n / i >= 1; i *= 5) {
        res += n/i;
    }
    cout << res << endl;

}

void sol5() {
    int t; cin >> t; while(t--) {
        int a,b; cin >> a >> b;

        if(max(a,b) > 2*min(a,b)) {
            cout << "NO\n";
            continue;
        }
        if((a+b) % 3 == 0) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}

void sol6() {
    string s; cin >> s;
    int n = sz(s);
    vt<int> a(26, 0);
    for (int i = 0; i < n; i++) {
        a[s[i] - 'A']++;
    }
    int odd = 0;
    for(int i = 0; i < 26; i++) {
        if(a[i] % 2 != 0) {
            odd++;
        }
    }
    if(odd > 1) {
        cout << "NO SOLUTION";
        return;
    }

    string l = "", r = "", c = "";
    for(int i = 0 ; i < 26; i++) {
        if(a[i] % 2 == 1) {
            c = string(a[i], 'A' +i);
        }
        else {
            l += string(a[i]/2, 'A' + i);
        }
    }
    r = l;
    reverse(all(r));
    cout << l << c << r;
}



void sol8() {
    int n; cin >> n;
    for(int i = 0; i < (1 << n); i++) {
        int x = i ^ (i >> 1);
        cout << bitset<16>(x).to_string().substr(16 - n) << '\n';
    }
}

void move(int n, string a, string b, string c) {
    if(n==0) {
        return;
    }
    move(n-1, a, c, b);
    cout << a << ' ' << b << endl;
    move(n-1, c, b, a);
}

void sol9() {
    int n; cin >> n;
    cout << (1<<n)-1 << '\n';
    move(n, "1", "3", "2");
}

//1 2 6 

//abc acb bca bac cab cba 

void sol10() {
    string s; cin >> s;
    sort(all(s)); 
    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }
    ll total_perms = 1;
    for (int i = 1; i <= s.length(); i++) {
        total_perms *= i;
    }
    for (auto& [c, count] : freq) {
        long long fact = 1;
        for (int i = 1; i <= count; i++) {
            fact *= i;
        }
        total_perms /= fact;
    }
    cout << total_perms << "\n";
    do {
        cout << s << "\n";
    } while (next_permutation(all(s)));
}

void sol11() {
    int n,m,k; cin >> n >> m >> k;

}


void sol7() {
    freopen("CSBN.INP", "r", stdin);
    freopen("CSBN.OUT", "w", stdout);
    int n; cin >> n;
    vt<int> a(n);
    for(int &x: a) cin >> x;
    unordered_map<int,int> mp;
    ll res = 0;
    for(int x: a) mp[x]++;
    for (auto &[val, freq] : mp) {
        if (freq >= 2) {
            for(int i = freq -1; i > 0; i--) {
                res += i;
            }
        }
    }
    cout << res << endl;
}

void sol12() {
    freopen("SDB.INP", "r", stdin);
    freopen("SDB.OUT", "w", stdout);
    int n; cin >> n;
    vt<ll> a(n);
    unordered_map<ll, ll> mp;
    mp.reserve(1e6+1);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        mp[a[i]]++;
    }
    vt<ll> res;
    for(int i = 0; i < n; ++i) {
        if(mp[a[i]] == 1) res.pb(a[i]);
    }
    int szc = sz(res);
    cout << szc << '\n';
    for(int i = 0 ; i < szc; i++) {
        cout << res[i] << '\n';
    }
}

int uoc(int x) {
    int sum = 0;
    for (int i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            sum += i;
            if (i != x / i) sum += x / i;
        }
    }
    return sum;
}

void sol13() {
    freopen("GHH.INP", "r", stdin);
    freopen("GHH.OUT", "w", stdout);

    int n; cin >> n;
    vt<int> res;

    while (n--) {
        int x; cin >> x;
        int sum = uoc(x);
        if (sum > 2 * x - 1) {
            res.pb(x);
        }
    }

    cout << res.size() << '\n';
    for (int x : res) cout << x << '\n';
}

void sol14() {
    freopen("TROCHOI.INP", "r", stdin);
    freopen("TROCHOI.OUT", "w", stdout);
    int t; cin >> t;
    vector<tuple<string, int, int>> a; 
    for (int i = 0; i < t; i++) {
        string s; cin >> s;
        int num = 0;
        for (char c : s) {
            if (isdigit(c)) num++;
        }
        a.pb({s, num, i});
    }
    sort(all(a), [](const auto& x, const auto& y) {
        if (get<1>(x) != get<1>(y)) return get<1>(x) < get<1>(y); 
        return get<2>(x) < get<2>(y); 
    });

    for (auto& [s, num, idx] : a) {
        cout << s << '\n';
    }
}
void sol15() {
    freopen("THUGON.INP", "r", stdin);
    freopen("THUGON.OUT", "w", stdout);
    string s;
    while (getline(cin, s)) {
        int n = sz(s);
        string res = "";
        int l = 0, num = 1;
        for (int i = 1; i < n; i++) {
            if (s[l] != s[i]) {
                if (num > 1) {
                    res += to_string(num);
                }
                res += s[l];
                num = 1;
                l = i;
            } else {
                num++;
            }
        }
        if (num > 1) {
            res += to_string(num);
        }
        res += s[l];
        cout << res << endl;
    }
}
int main() {
    fast_io;
    sol15();
    return 0;
}
