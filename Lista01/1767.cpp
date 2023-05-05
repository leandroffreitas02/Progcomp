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

const int MAX = 110;

int v[MAX];
int w[MAX];

int m[MAX][60];

int ks(int n, int W){
	for(int i = 1; i <= n; i++) m[i][0] = 0;
	for(int j = 0; j <= W; j++) m[0][j] = 0;

	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= W; j++){
			if(w[i] > j) m[i][j] = m[i-1][j];

			else m[i][j] = max(m[i-1][j], m[i-1][j-w[i]] + v[i]);
		}
	}
	return m[n][W];
}

set<int> k(int i, int j){
	set<int> ret;

	if(i == 0) return {};

	if(m[i][j] > m[i-1][j]){
		ret = k(i-1, j-w[i]);
		ret.insert(i);
		return ret;
	}
	else return k(i-1, j);
}

int main(){ _

	int t; cin >> t;

	while(t--){
		int n; cin >> n;

		for(int i = 1; i <= n; i++) cin >> v[i] >> w[i];

		cout << ks(n, 50) << " brinquedos" << endl;

		set<int> s = k(n, 50);

		int peso = 0, pac = s.size();

		for(auto i: s){
			peso += w[i];
		}
		cout << "Peso: " << peso << " kg" << endl;
		cout << "sobra(m) " << n - pac << " pacote(s)" << endl << endl;
	}

	return 0;
}
