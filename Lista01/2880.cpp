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

	string s1, s2; cin >> s1 >> s2;
	int l1 = s1.size(), l2 = s2.size();
	int count = 0;

	for(int i = 0; i <= l1 - l2; i++){
		bool flag = true;
		for(int j = 0; j < l2; j++){
			if(s1[i+j] == s2[j]) flag = false;
		}
		if(flag) count++;
	}

	cout << count << endl;

	return 0;
}
