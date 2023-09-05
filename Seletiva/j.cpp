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

const int MAX = 35;
int n, m;

int a[MAX];

int main(){ _

	cin >> n >> m;
	int ans = 0;

	set<int> left, right;

	for(int i = 0; i < n; i++)
		cin >> a[i];

	for(int i = 0; i < (1 << n/2 + n%2); i++){
		ll sum = 0;
		for(int j = 0; j < n/2 + n%2; j++)
			if(int(i & (1<<j))){
				sum += a[j];
				sum %= m;
			}
		left.insert(-sum);
	}

	for(int i = 0; i < (1 << n/2); i++){
		ll sum = 0;
		for(int j = 0; j < n/2; j++)
			if(int(i & (1<<j))){
				sum += a[j + n/2 + n%2];
				sum %= m;
			}
		right.insert(sum);
	}

	for(auto i: right){
		int lb = (m - i - 1) % m;

		auto it = left.lower_bound(-lb);

		if(it != left.end()){
			ans = max(i -(*it), ans);
		}
		else
			ans = max(ans, i);
	}
	ans = max(ans, -(*left.begin()));

	cout << ans << endl;

	return 0;
}
