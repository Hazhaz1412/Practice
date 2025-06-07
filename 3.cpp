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

//t = 1
//s = 0

void sol() {
    int t; cin >> t; while(t--) {
        int n; cin >> n;
        string s; cin >> s; 
        int res = 0;
        if(s[0] == '1') res++;
        for (int i = 0; i < n - 1; i++) {
            if(s[i] != s[i + 1])
                res++;
        }
        cout << res << endl;
    }
}

void sol2() {
    int t; cin >> t; while(t--){
        int n; cin >> n;
        vt<int> a(n);
        for(int &x: a) cin >> x;
        unordered_map<int,int> cnt;
        for (int i = 0; i < n; i++){
            cnt[a[i]]++;
        } 
        int res = 0, l = -1, r = -1, it = -1;
        for (int i = 0; i < n; i++){
            if(cnt[a[i]] == 1){
                if(it == -1) it = i; 
            } else{
                if(it != -1){
                    int len = i - it;
                    if(len > res){
                        res = len;
                        l = it;
                        r = i - 1;
                    }
                    it = -1;
                }
            }
        } 
        if(it != -1){
            int len = n - it;
            if(len > res){
                res = len;
                l = it;
                r = n - 1;
            }
        } 
        if(res > 0){ 
            cout << (l + 1) << " " << (r + 1) << endl;
        } else{
            cout << 0 << endl;
        }
    }
}

void sol3() {
    int t; cin >> t; while(t--){
        int n; cin >> n;
        vt<int> a(n);
        for (int &x : a) cin >> x;
        ll negsum = 0;
        for (int x : a)
            if(x < 0) negsum += -x;
        ll l = 0, acc = 0, res = negsum; 
        for (int i = 0; i < n; i++){
            if(a[i] > 0)
                l += a[i];
            else
                acc += -a[i];
            res = max(res, l + (negsum - acc));
        }
        cout << res << endl;
    }
}

void sol4() {
    static const int U=1<<30;
    auto mergeInt=[&](vt<pair<int,int>> v){
        if(v.empty()) return v;
        sor(v); vt<pair<int,int>> r; auto cur=v[0];
        for(int i=1;i<sz(v);i++){
            if(v[i].f<=cur.s) cur.s=max(cur.s,v[i].s);
            else r.pb(cur),cur=v[i];
        }
        r.pb(cur); return r;
    };
    auto inInt=[&](const vt<pair<int,int>> &v,int x){
        int lo=0,hi=sz(v)-1;
        while(lo<=hi){
            int m=(lo+hi)/2;
            if(v[m].f<=x && x<v[m].s) return true;
            (x<v[m].f?hi=m-1:lo=m+1);
        }
        return false;
    };

    int t; cin >> t; 
    while(t--) {
        int n,q; cin>>n>>q; 
        vt<int>A(n),S(n),T(n+1);
        for(auto &x:A) cin>>x;
        S.resize(n);
        reverse_copy(all(A),S.begin());
        for(int i=1;i<=n;i++) T[i]=T[i-1] ^ S[i-1];
        vt<vt<pair<int,int>>> I(n),J(n+1);
        J[0].pb({0,U}); 
        int mv=0;

        for(int k=0;k<n;k++){
            int c=T[k], L=S[k];
            vt<pair<int,int>> blks;
            {
                int st=0; 
                while(st<L){
                    int step=(st==0?1:(st&-st));
                    while((ll)(step<<1)<=L-st) step<<=1;
                    while(st+step>L) step>>=1;
                    blks.pb({st,st+step});
                    st+=step;
                }
            }
            vt<pair<int,int>> y;
            for(auto &p:blks){
                int s=p.s-p.f, k2=31-__builtin_clz(s), C=c>>k2;
                int bs=((p.f/s)^C)*s;
                y.pb({bs,bs+s});
            }
            auto i1=mergeInt(y);
            vt<pair<int,int>> compRes; 
            {
                int p=0;
                for(auto &iv:i1){
                    if(p<iv.f) compRes.pb({p,iv.f});
                    p=max(p,iv.s);
                }
                if(p<U) compRes.pb({p,U});
            }
            auto i2=mergeInt(compRes);
            I[k]=i2;

            vt<pair<int,int>> it;
            {
                int iA=0,iB=0;
                while(iA<sz(J[k]) && iB<sz(I[k])){
                    int L2=max(J[k][iA].f,I[k][iB].f), R2=min(J[k][iA].s,I[k][iB].s);
                    if(L2<R2) it.pb({L2,R2});
                    (J[k][iA].s<I[k][iB].s?iA++:iB++);
                }
            }
            auto merged=mergeInt(it);
            if(merged.empty()){
                mv=k; for(int m=k+1;m<=n;m++) J[m].clear();
                break;
            }
            J[k+1]=merged; mv=k+1;
        }

        while(q--){
            int z; cin>>z;
            int lo=0,hi=mv;
            while(lo<hi){
                int m=(lo+hi+1)/2;
                if(!J[m].empty()&&inInt(J[m],z)) lo=m; else hi=m-1;
            }
            cout<<lo<<(q?" ":"\n");
        }
    }
    
}

int main() {
    fast_io;
    sol4();
    return 0;
}
