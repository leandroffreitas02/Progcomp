#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e4+10;

int s, t, m;

vector<vector<ii>> g(MAX);
int peso[MAX][MAX];

int dist[MAX];

void dijkstra(int v){
        priority_queue<ii> pq;
        pq.push(mp(0, v));

        dist[v] = 0;

        while(!pq.empty()){
                int u = pq.top().s, w = -pq.top().f;
                pq.pop();

                if(w > dist[u]) continue;

                for(auto x: g[u]){
                        if(dist[x.f] > dist[u] + x.s){
                                dist[x.f] = dist[u] + x.s;
                                pq.push(mp(-dist[x.f], x.f));
                        }
                }
        }
}

int vis[MAX];
int tam[MAX];
int vmin[MAX];
int pai[MAX];


int num = 0;
int n[MAX];

void dfs(int v, int p){

        if(vis[v] == 2){
                return;
        }

//      Encontrou um ciclo
        if(vis[v] == 1){
                int aux = p;
                vmin[num] = v;
                tam[num] = n[p] - n[v] + peso[p][v];

                num++;
                return;
        }

        vis[v] = 1;
        pai[v] = p;

        n[v] = n[p] + peso[v][p];

        for(auto w: g[v])if(w.f != pai[v]){
                dfs(w.f, v);
        }

        vis[v] = 2;
}

int main(){ _

        while(cin >> s >> t){

                for(int i = 0; i < s; i++){
                        g[i].clear();
                }

                while(t--){
                        int a, b, c; cin >> a >> b >> c; a--, b--;

                        g[a].pb(mp(b, c));
                        g[b].pb(mp(a, c));
                        peso[a][b] = c;
                        peso[b][a] = c;
                }

                int q; cin >> q;

                while(q--){
                        int x0; cin >> x0 >> m; x0--;

                        memset(dist, INF, sizeof dist);
                        memset(n, 0, sizeof n);
                        memset(vis, 0, sizeof vis);
                        memset(tam, 0, sizeof tam);
                        num = 0;

                        dijkstra(x0);

                        peso[x0][x0] = 0;

                        dfs(x0, x0);

                        int d = INF;

                        for(int i = 0; i < num; i++) if(tam[i] >= m){
                                d = min(d, 2*dist[vmin[i]] + tam[i]);
                        }
                        if(d == INF) cout << -1 << endl;
                        else cout << d << endl;

                }
        }
        return 0;
}
