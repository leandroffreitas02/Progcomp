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

const int MAX = 1e3+10;

int n, m;

vector<vector<ii>> g(MAX);
vector<int> dist(MAX, INF);

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

int main(){ _

        cin >> n >> m;

        for(int i = 0; i < m; i++){
                int u, v, p; cin >> u >> v >> p; u--, v--;

                g[u].pb(mp(v, p));
                g[v].pb(mp(u, p));
        }
        int s; cin >> s; s--;

        dijkstra(s);

        int vmax = -1, vmin = INF;

        for(int i = 0; i < n; i++){
                if(i != s){
                        vmax = max(vmax, dist[i]);
                        vmin = min(vmin, dist[i]);
                }
        }

        cout << vmax - vmin << endl;

        return 0;
}
