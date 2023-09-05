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

int machine(int n, int m) {
	if(n >= m) return n - m;

	if(n > m/2 + m%2) return 1 + machine(n-1, m);
	else if (n < m/2 + m%2) return machine(n, m/2 + m%2) + machine(m/2 + m%2, m);
	else return 1 + machine(2*n, m);
}

int main(){ _

	int n, m; cin >> n >> m;

	cout << machine(n, m) << endl;
	
	return 0;
}
