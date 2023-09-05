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

const int MAX = 1e5 * 2 + 10;

int v[MAX];

int main(){ _

	int t; cin >> t;

	while(t--) {
		int n, k; cin >> n >> k;

		int m = n/2 + n%2;

		ll ans = 0;

		for(int i = 0; i < n*k; i++)
			cin >> v[i];

		int p = n*k - m - 1 + n%2;

		for(int i = 0; i < k; i++){
			ans += v[p];
			p -= m + 1 - n%2;

		}

		cout << ans << endl;
	}

	return 0;
}
