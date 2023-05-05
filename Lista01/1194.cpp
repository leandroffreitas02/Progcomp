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

string pre, in;
int aux;

int search(int l, int r, char c){

	for(int i = l; i < r; i++) if(in[i] == c) return i;

	return -1;
}

void post(int l, int r){

	int x = aux;

	int root = search(l, r, pre[aux++]);

	if(l != root)
		post(l, root);

	if(r - 1 != root)
		post(root + 1, r);

	cout << pre[x];
}


int main(){ _

	int t; cin >> t;

	while(t--){
		int n;
		cin >> n >> pre >> in;

		aux = 0;

		post(0, n);
		cout << endl;
	}

	return 0;
}
