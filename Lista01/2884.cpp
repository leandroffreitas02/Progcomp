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

int main(){ _

	int count = 0, ans = -1;
	int n, m; cin >> n >> m;

	vector<bool> f(m, false);
	vector<bool> v(m, false);

	int l; cin >> l;

	for(int i = 0; i < l; i++){
		int a; cin >> a;
		v[a-1] = true;
	}

	vector<vector<int>> c(n);

	for(int i = 0; i < n; i++){
		int k; cin >> k;

		for(int j = 0; j < k; j++){
			int a; cin >> a;
			c[i].pb(a-1);
		}
	}

	for(int i = 0; i < n; i++){
		count++;

		for(int j: c[i]) v[j] = !v[j];
		
		if(v == f){
			cout << count << endl;
			return 0;
		}
	}

	for(int i = 0; i < n; i++){
		count++;

		for(int j: c[i]) v[j] = !v[j];
		
		if(v == f){
			cout << count << endl;
			return 0;
		}
	}
	cout << ans << endl;
	return 0;
}
