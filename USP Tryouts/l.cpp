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

const int MAX = 2510;

vector<vector<int>> g(MAX);

vector<vector<int>> g2(MAX);

bool removed[MAX];
int state[MAX];

int main(){ _
    memset(removed, 0, sizeof(removed));
    memset(state, 0, sizeof(state));

    int n, m, q; cin >> n >> m >> q;

    stack<int> events;
    stack<int> e1;

    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;

        g[u].pb(v);
        g[v].pb(u);
    }

    for(int i = 0; i < q; i++){
        int c; cin >> c;

        events.push(c);

        if(c == 1){
            int v; cin >> v;
            e1.push(v);

            removed[v] = true;
        }
    }

    for(int i = 1; i <= n; i++) if(!removed[i]){
        events.push(1);
        e1.push(i);
        removed[i] = true;
    }

    stack<vector<int>> ans;

    while(!events.empty()){
        int e = events.top(); events.pop();

        if(e == 1){
            int v = e1.top(); e1.pop();
            removed[v] = false;
            int aux = 0;

            for(auto u: g[v]) if(!removed[u]){
                aux += state[u];
            }
            if(aux >= 0) state[v] = -1;
            else state[v] = 1;
        }
        else{
            vector<int> v;
            for(int i = 1; i <= n; i++) if(state[i] == 1){
                v.pb(i);
            }
            ans.push(v);
        }
    }
    while(!ans.empty()){

        cout << ans.top().size() << ' ';

        for(auto i: ans.top())
            cout << i << ' ';
        cout << endl;

        ans.pop();
    }
}