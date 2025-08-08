#include <bits/stdc++.h>
using namespace std;

class EulerCircuit {
private:
    // Using adjacency lists to represent the graph
    // For a multigraph, we store edges as pairs (destination, edge_id)
    vector<vector<pair<int, int>>> adj;
    vector<bool> used_edges;
    vector<int> circuit;
    
    // Find a circuit starting from vertex v
    vector<int> findCircuit(int v) {
        vector<int> current_path;
        int start = v;
        
        while (true) {
            // Find an unused edge from current vertex
            bool found = false;
            for (auto& [next, edge_id] : adj[v]) {
                if (!used_edges[edge_id]) {
                    used_edges[edge_id] = true;
                    v = next;
                    current_path.push_back(edge_id);
                    found = true;
                    break;
                }
            }
            
            // If we return to the start with no unused edges, circuit is complete
            if (!found) {
                if (v == start) break;
                // This shouldn't happen in a graph with all even degrees
                throw runtime_error("Failed to complete circuit");
            }
            
            // If we've returned to the starting vertex, we have a circuit
            if (v == start) break;
        }
        
        return current_path;
    }
    
    // Merges a subcircuit into the main circuit at the appropriate position
    void insertSubcircuit(vector<int>& subcircuit, int vertex_pos) {
        vector<int> new_circuit;
        
        // Add edges up to the insertion point
        for (int i = 0; i < vertex_pos; i++) {
            new_circuit.push_back(circuit[i]);
        }
        
        // Insert the subcircuit
        for (int edge_id : subcircuit) {
            new_circuit.push_back(edge_id);
        }
        
        // Add remaining edges from the original circuit
        for (int i = vertex_pos; i < circuit.size(); i++) {
            new_circuit.push_back(circuit[i]);
        }
        
        circuit = new_circuit;
    }

public:
    EulerCircuit(int n) {
        adj.resize(n);
        circuit.clear();
    }
    
    // Add an edge to the graph
    void addEdge(int u, int v, int edge_id) {
        adj[u].push_back({v, edge_id});
        adj[v].push_back({u, edge_id}); // For undirected graph
    }
    
    // Main function to find Euler circuit
    vector<int> findEulerCircuit(int start) {
        int n = adj.size();
        used_edges.assign(n * n, false); // Assuming at most n*n edges
        
        // Step 1: Find initial circuit
        circuit = findCircuit(start);
        
        // Step 2-4: While there are unused edges
        bool has_unused_edges = true;
        while (has_unused_edges) {
            has_unused_edges = false;
            
            // Find a vertex that has unused edges
            for (int v = 0; v < n; v++) {
                for (auto& [next, edge_id] : adj[v]) {
                    if (!used_edges[edge_id]) {
                        has_unused_edges = true;
                        
                        // Find the position of vertex v in the current circuit
                        int vertex_pos = -1;
                        for (int i = 0; i < circuit.size(); i++) {
                            // Check if this edge in circuit connects to vertex v
                            // This is a simplification - in practice you'd need to track vertices
                            if (circuit[i] == v) {
                                vertex_pos = i;
                                break;
                            }
                        }
                        
                        if (vertex_pos != -1) {
                            // Find subcircuit starting at v
                            vector<int> subcircuit = findCircuit(v);
                            
                            // Insert the subcircuit into the main circuit
                            insertSubcircuit(subcircuit, vertex_pos);
                        }
                        
                        break;
                    }
                }
                if (has_unused_edges) break;
            }
        }
        
        return circuit;
    }
};

int main() {
    // Example usage
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;
    
    EulerCircuit euler(n);
    
    cout << "Enter " << m << " edges (u v): ";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        euler.addEdge(u, v, i);
    }
    
    int start;
    cout << "Enter starting vertex: ";
    cin >> start;
    
    try {
        vector<int> result = euler.findEulerCircuit(start);
        cout << "Euler Circuit: ";
        for (int edge_id : result) {
            cout << edge_id << " ";
        }
        cout << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    return 0;
}