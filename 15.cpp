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

struct Node {
    ll value;
    Node* next;
};

void push(Node*& top, ll val) {
    Node* newNode = new Node{val, top};
    top = newNode;
}

ll pop(Node*& top) {
    if (!top) {
        cerr << "Tràn\n";
        exit(EXIT_FAILURE);
    }
    ll val = top->value;
    Node* tmp = top;
    top = top->next;
    delete tmp;
    return val;
}

void sol() {
    string n;
    getline(cin, n);
    istringstream id(n);
    string c;
    Node* top = nullptr;
    while (id >> c) {
        if (c == "+" || c == "-" || c == "*" || c == "/") {
            ll b = pop(top);
            ll a = pop(top);
            ll tmp;
            if (c == "+") tmp = a + b;
            else if (c == "-") tmp = a - b;
            else if (c == "*") tmp = a * b;
            else if (c == "/") tmp = a / b;
            push(top, tmp);
        }
        else {
            ll num = stod(c);
            push(top, num);
        }
    }
    ll res = pop(top);
    cout << res << endl;
}

int main() {
    fast_io;
    sol();
    return 0;
}
