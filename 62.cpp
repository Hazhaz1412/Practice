#include <bits/stdc++.h>
using namespace std;
class Graph{
    private:
    int n;
    vector<vector<int>> matrix;
    vector<char> label;
    vector<bool> visited;
    public:
        Graph(int n, int m) {
            this->n = n;
            matrix.assign(n+1, vector<int>(n+1,0));
            label.assign(n+1, ' ');
            visited.assign(n+1, false);
        }
    public:
        void add_edge(int i, int j) {
            matrix[i][j] = 1;
            matrix[j][i] = 1;
        }
    public:
        void print() {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n ;j++) {
                    cout << matrix[i][j] << ' '; 
                }
                
                cout << endl;
            }
            cout << endl << "=====\n";
            for(int i = 0 ; i <= n;i++) {
                cout << label[i] << " = " << i <<'\n';
            }
        }
    public:
        void vertex(int vertex, char s) {
            label[vertex] = s;
        } 
        int index(char s) {
            for(int i = 0; i < label.size();i++) {
                    if(label[i] == s) {
                        return i;
                    }
            } 
            return -1;

        }
        void start(char s) {
            dfs(index(s));
        }
        void dfs(int u) {
            visited[u] = true;
            cout << label[u] << "->";
            for(int i = 1; i <= n;i++) {
                if(matrix[u][i] == 1 && !visited[i]) {
                    dfs(i);
                }
            }
        }
        
};

int main() {
    int n, m;
    cin >> n >> m;
    Graph g(n,m);

    for(int i = 0 ;i < m; i++) {
        int a,b; cin >> a >> b;
        g.add_edge(a,b);
    }
    for(int i = 1 ;i <= n;i++) {
        char s; cin >> s;
        g.vertex(i, s);
    }
    g.print();
    g.start('D');
}