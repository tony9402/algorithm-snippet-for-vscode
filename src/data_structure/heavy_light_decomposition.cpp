//title: Heavy-Light Decomposition
//prefix: hld, heavy
//description: Heavy-Ligth Decomposition Query O(log^2N)
struct HLD {
    Graph<int> G;
    vector<int> par, top, dep, siz, in, out;
    $1
    int id;
    HLD(Graph<int> G):G(G) {
        int N = (int)G.size();
        siz = par = top = dep = in = out = vector<int>(N);
        id = 0;
    }
    void dfs(int cur=1, int prev=0) {
        siz[cur] = 1;
        par[cur] = prev;
        dep[cur] = dep[prev] + 1;
        for(int &nxt : G[cur]) {
            if(nxt == prev) continue;
            dfs(nxt, cur);
            siz[cur] += siz[nxt];
            if(siz[nxt] > siz[G[cur][0]]) swap(nxt, G[cur][0]);
        }
    }
    void dfs2(int cur=1, int prev=0) {
        in[cur] = ++id;
        if(cur == 1) top[cur] = 1;
        for(int nxt: G[cur]) {
            if(nxt == prev)continue;
            top[nxt] = (nxt == G[cur][0] ? top[cur] : nxt);
            dfs2(nxt, cur);
        }
        out[cur] = id;
    }
    $2
};
