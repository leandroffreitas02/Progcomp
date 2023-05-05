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

const int MAX = 26;

vector<vector<int>> g(MAX);
vector<bool> vis(MAX);
vector<char> aux;

void dfs(int v){
	vis[v] = true;
	aux.pb(v + 'a');

	for(auto w: g[v]) if(!vis[w]){
		dfs(w);
	}
}

int main(){ _

	int t; cin >> t;

	for(int i = 0; i < t; i++){
		cout << "Case #" << i + 1 << ':' << endl;

		int v, e; cin >> v >> e;

		for(int j = 0; j < e; j++){
			char a, b; cin >> a >> b;

			g[a-'a'].pb(b-'a');
			g[b-'a'].pb(a-'a');
		}
		int count = 0;

		for(int j = 0; j < v; j++) if(!vis[j]){
			dfs(j);
			sort(aux.begin(), aux.end());

			for(char k: aux) cout << k << ',';

			count++;
			cout << endl;
			aux.clear();
		}
		cout << count << " connected components" << endl << endl;

		for(int j = 0; j < v; j++){
			vis[j] = false;
			g[j].clear();
		}

	}

	return 0;
}
