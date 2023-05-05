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

const int MAX = 1e5+10;

int N, C, T;
int p[MAX];

bool possivel(ll x){
	ll m = x*T;
	int c = 1;
	
	for(int i = 0; i < N; i++){
		if(m >= p[i]) m -= p[i];
		else{
			c++;
			m = x*T;
			i--;
		}
		if(c > C) return false;
	}
	return true;
}

int main(){ _

	cin >> N >> C >> T;

	for(int i = 0; i < N; i++) cin >> p[i];

	int l = 0, r = 1e9;

	while(l < r){
		int m = (l + r)/2;
		
		if(possivel(m)) r = m;
		else l = m + 1;
	}
	cout << r << endl;

	return 0;
}
