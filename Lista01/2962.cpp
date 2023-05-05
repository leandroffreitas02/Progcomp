#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e3+10;

vector<vector<int>> g(MAX);
vector<bool> vis(MAX);
int cam[MAX][3];

void dfs(int v){
	vis[v] = true;

	for(auto w: g[v]) if(!vis[w]){
		dfs(w);
	}
}

int main(){ _

	int m, n, k; cin >> m >> n >> k;

	for(int i = 0; i < k; i++){
		int x, y, s; cin >> x >> y >> s;

		if(x - s <= 0){
			g[k].pb(i);
			g[i].pb(k);
		}
		if(x + s >= m){
			g[k+2].pb(i);
			g[i].pb(k+2);
		}
		if(y + s >= n){
			g[k+1].pb(i);
			g[i].pb(k+1);
		}
		if(y - s <= 0){
			g[k+3].pb(i);
			g[i].pb(k+3);
		}

		cam[i][0] = x;
		cam[i][1] = y;
		cam[i][2] = s;
	}

	for(int i = 0; i < k; i++){
		for(int j = 0; j < k; j++){
			if(i != j){
				if(pow(cam[i][0] - cam[j][0], 2) + pow(cam[i][1] - cam[j][1], 2) <= pow(cam[i][2] + cam[j][2], 2)){

					g[i].pb(j);
					g[j].pb(i);
				}
			}
		}
	}
	dfs(k);

	if(vis[k+2] || vis[k+3]){
		cout << 'N' << endl;
		return 0;
	}

	for(int i = 0; i < k+4; i++) vis[i] = false;

	dfs(k+1);

	if(vis[k+2] || vis[k+3]){
		cout << 'N' << endl;
		return 0;
	}

	cout << 'S' << endl;
	return 0;

}
