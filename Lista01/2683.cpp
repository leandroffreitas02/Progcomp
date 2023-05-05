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

vector<vector<ii>> adj(MAX);
bool vis[MAX];

int revprim(int v){
	int ans = 0;

	priority_queue<ii> pq;
	pq.push(mp(0, v));

	while(!pq.empty()){
		ii x = pq.top(); pq.pop();

		if(vis[x.s]) continue;

		vis[x.s] = true;

		for(auto w: adj[x.s]){
			pq.push(mp(w.s, w.f));
		}
		ans += x.f;
	}
	return ans;
}

int prim(int v){
	int ans = 0;

	priority_queue<ii> pq;
	pq.push(mp(0, v));

	while(!pq.empty()){
		ii x = pq.top(); pq.pop();

		if(vis[x.s]) continue;

		vis[x.s] = true;

		for(auto w: adj[x.s]){
			pq.push(mp(-w.s, w.f));
		}
		ans -= x.f;
	}
	return ans;
}

int main(){ _

	int n; cin >> n;

	for(int i = 0; i < n; i++){
		int u, v, w; cin >> u >> v >> w; u--, v--;

		adj[u].pb(mp(v, w));
		adj[v].pb(mp(u, w));
	}
	memset(vis, false, sizeof vis);

	cout << revprim(0) << endl;

	memset(vis, false, sizeof vis);

	cout << prim(0) << endl;

	return 0;
}
