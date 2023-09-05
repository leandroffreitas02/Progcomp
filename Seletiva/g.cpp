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

const int MAX = 110;

vector<vector<int>> g(MAX);
vector<bool> vis(MAX, true);

void dfs(int v){
	vis[v] = true;
	
	for(auto w: g[v]) if(!vis[w]) {
		dfs(w);
	}
}

int main(){ _

	int n, m; cin >> n >> m;
	int count = 0;

	for(int i = 0; i < n; i++){
		int x; cin >> x;

		if(x == 0) {
			count++;
			continue;
		}

		int v[x];

		for(int j = 0; j < x; j++){
			cin >> v[j];
			vis[v[j]] = false;
		}

		for(int j = 0; j < x; j++){
			for(int k = j + 1; k < x; k++){
				g[v[j]].pb(v[k]);
				g[v[k]].pb(v[j]);
			}
		}
	}

	int ans = 0;

	for(int i = 1; i <= m; i++) if(!vis[i]){
		dfs(i);
		ans++;
	}

	if(ans) ans--;

	cout << count + ans << endl;


	return 0;
}
