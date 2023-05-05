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

	ll n; cin >> n;
	set<ll> s;


	for(ll i = 2; i*i <= n; i++){
		if(n % i == 0){
			s.insert(i);
			n = n/i;
			i--;
		}
	}
	s.insert(n);

	int x = s.size();
	ll ans = pow(2, x) - x - 1;



	cout << ans << endl;

	return 0;
}
