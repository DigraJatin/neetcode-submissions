class DSU {
    vector<int> parent, rank;
public:
    DSU(int n){
        parent.resize(n);
        rank.assign(n, 0);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int x, int y){
        int px = find(x);
        int py = find(y);

        if(px == py) return false; // already in same component = cycle

        if(rank[px] < rank[py]) parent[px] = py;
        else if (rank[px] > rank[py]) parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
        return true;
    }
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1) return false;
        DSU obj(n);
        for(auto &e : edges){
            int u = e[0], v = e[1];
            if(!obj.unite(u,v)) return false;
        }
        return true;
    }
};
