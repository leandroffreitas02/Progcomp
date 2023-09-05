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

int main(){ _

	int n; cin >> n;

	vector<int> v(n);

	for(int i = 0; i < n; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	int count = 1;
	bool ans = true;

	for(int i = 1; i < n; i++){
		if(v[i] == v[i-1])
			count++;
		else 
			count = 1;

		if(count > n/2 + n%2){
			ans = false;
			break;
		}
	}

	cout << (ans ? "YES" : "NO") << endl;
	
	return 0;
}
