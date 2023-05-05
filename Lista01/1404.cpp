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

const int MAX = 20;

int tab[MAX][MAX];
bool vis[MAX][MAX];

vector<ii> mov = {{2, 2}, {2, -2}, {-2, 2}, {-2, -2}};
vector<ii> ate = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int n, m;

bool val(int xmov, int ymov, int xate, int yate){
	return xmov >= 0 and ymov >= 0 and xmov < n and ymov < m
		and !vis[xate][yate] and tab[xate][yate] == 2 and tab[xmov][ymov] == 0;
}

int maxcap(int x, int y){
	int ret = 0;

	for(int i = 0; i < 4; i++){
		if(val(x + mov[i].f, y + mov[i].s, x + ate[i].f, y + ate[i].s)){

			vis[x + ate[i].f][y + ate[i].s] = true;

			ret = max(ret, maxcap(x + mov[i].f, y + mov[i].s) + 1);
			
			vis[x + ate[i].f][y + ate[i].s] = false;
		}
	}
	return ret;
}

int main(){ _

	while(1){

		cin >> n >> m;

		if(!n && !m) return 0;

		for(int i = 0; i < n; i++){
			for(int j = i % 2; j < m; j += 2){
				cin >> tab[i][j];
			}
		}

		int count = 0;

		for(int i = 0; i < n; i++){
			for(int j = i % 2; j < m; j += 2){
				if(tab[i][j] == 1){
					tab[i][j] = 0;
	
					count = max(count, maxcap(i, j));

					tab[i][j] = 1;
				}
			}
		}
		cout << count << endl;
	}
}
