#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
int tin[MAXN], low[MAXN];
bool ch[MAXN];
vector<pair<int, int>> bridges;
int timer = 0;

void dfs(int u, int parent) {
    tin[u] = low[u] = ++timer;
    int children = 0;

    for (int v : adj[u]) {
        if (v == parent) continue; 
        if (tin[v]) { 
            low[u] = min(low[u], tin[v]); 
        } else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);

            if (low[v] >= tin[u] && parent != -1) 
                ch[u] = true;
            
            if (low[v] > tin[u]) 
                bridges.push_back({u, v});

            children++;
        }
    }
    if (parent == -1 && children > 1) 
        ch[u] = true;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(tin, 0, sizeof(tin));
    memset(low, 0, sizeof(low));
    memset(ch, 0, sizeof(ch));

    for (int i = 1; i <= n; i++) {
        if (!tin[i]) {
            timer = 0;
            dfs(i, -1);
        }
    }

    int a = count(ch + 1, ch + n + 1, true);
    int b = bridges.size();

    cout << a << " " << b << endl;
    return 0;
}
