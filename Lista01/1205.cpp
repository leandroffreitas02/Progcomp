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

vector<vector<int>> g(MAX);
vector<int> soldados(MAX, 0);
vector<int> dist(MAX, INF);

int n, m, k;


void dijkstra(int v){
        dist[v] = soldados[v];

        priority_queue<ii> pq;
        pq.push(mp(-dist[v], v));

        while(!pq.empty()){
                int u = pq.top().s, w = -pq.top().f;
                pq.pop();

                if(w > dist[u]) continue;

                for(auto x: g[u]){
                        if(dist[x] > dist[u] + soldados[x]){
                                dist[x] = dist[u] + soldados[x];
                                pq.push(mp(-dist[x], x));
                        }
                }
        }
}

int main(){ _

        double p, ans;

        while(cin >> n >> m >> k >> p){

                for(int i = 0; i < n; i++){
                        g[i].clear();
                        soldados[i] = 0;
                        dist[i] = MAX;
                }

                while(m--){
                        int a, b; cin >> a >> b; a--, b--;

                        g[a].pb(b);
                        g[b].pb(a);
                }

                int a; cin >> a;
                while(a--){
                        int x; cin >> x; x--;
                        soldados[x]++;
                }
                int saida, chegada; cin >> saida >> chegada; saida--, chegada--;

                dijkstra(saida);

                ans = pow(p, dist[chegada]);

                cout << fixed << setprecision(3);

                if(dist[chegada] <= k) cout << ans << endl;
                else cout << "0.000" << endl;
        }

        return 0;
}
