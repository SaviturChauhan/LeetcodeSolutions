class Solution {
public:
    int find(int i, vector<int>& parent) {
        if (i == parent[i])
            return i;
        return find(parent[i], parent);
    }
    void Union(int x, int y, vector<int>& parent, vector<int>& rank) {
        int xpar = find(x, parent);
        int ypar = find(y, parent);

        if (xpar == ypar)
            return;
        if (rank[xpar] > rank[ypar]) {
            parent[ypar] = xpar;
        } else if (rank[xpar] < rank[ypar]) {
            parent[xpar] = ypar;
        } else {
            parent[xpar] = ypar;
            rank[ypar]++;
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> rank;
        vector<int> parent;
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (auto& e : edges) {
            Union(e[0], e[1], parent, rank);
        }

        unordered_map<int, int> nodes;
        unordered_map<int, int> edgecnt;

        for (int i = 0; i < n; i++) {
            nodes[find(i,parent)]++;
        }

        for (auto& e : edges) {
            edgecnt[find(e[0],parent)]++;
        }

        int ans = 0;

        for (auto& [root, cnt] : nodes) {
            int required = cnt * (cnt - 1) / 2;
            if (edgecnt[root] == required)
                ans++;
        }

        return ans;
    }
};