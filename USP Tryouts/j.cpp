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

const int MAX = 5*1e5 + 10;

vector<vector<ii>> g(MAX);

bool intended[MAX];
bool current[MAX];
bool vis[MAX];

int aux[MAX];

set<int> ans;

int dfs1(int v){
    vis[v] = true;
    aux[v] = intended[v];

    for(auto u: g[v]) if(!vis[u.f])
        aux[v] += dfs1(u.f);

    return aux[v];
}

bool dfs2(int v){
    vis[v] = true;
    
    for(auto u: g[v]) if(!vis[u.f]){
        if(aux[u.f] % 2){
            current[v] = !current[v];
            current[u.f] = !current[u.f];
            ans.insert(u.s);
        }
        dfs2(u.f);
    }

    return current[v] == intended[v];
}

int main(){ _
    memset(current, 0, sizeof(current));
    memset(vis, 0, sizeof(vis));

    int n, m; cin >> n >> m;

    for(int i = 1; i <= n; i++){
        int u, v; cin >> u >> v;

        g[u].pb(mp(v, i));
        g[v].pb(mp(u, i));
    }
    for(int i = 1; i <= m; i++)
        cin >> intended[i];

    for(int i = 1; i <= m; i++) if(!vis[i]){
        dfs1(i);
    }
    memset(vis, 0, sizeof(vis));

    for(int i = 1; i <= m; i++) if(!vis[i]){
        if(!dfs2(i)){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans.size() << endl;

    for(auto i: ans)
        cout << i << ' ';
    
    cout << endl;
}
