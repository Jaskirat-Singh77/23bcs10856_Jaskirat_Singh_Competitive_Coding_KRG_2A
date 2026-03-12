class Solution {
public:
    
    void dfs(int node, vector<int> adj[], vector<bool> &vis, vector<int> &component){
        vis[node] = true;
        component.push_back(node);
        
        for(int neigh : adj[node]){
            if(!vis[neigh]){
                dfs(neigh, adj, vis, component);
            }
        }
    }
    
    vector<vector<int>> connectedComponents(int V, vector<vector<int>>& edges) {
        
        vector<int> adj[V];
        
      
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> vis(V,false);
        vector<vector<int>> result;
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                vector<int> component;
                dfs(i, adj, vis, component);
                result.push_back(component);
            }
        }
        
        return result;
    }
};
