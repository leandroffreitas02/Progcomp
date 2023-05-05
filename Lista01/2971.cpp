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

int cards[13][4];

int main(){ _

	int n, k; cin >> n >> k; k--;

	for(int i = 0; i < n; i++){
		string s; cin >> s;
		vector<int> count(14, 0);
		
		for(int j = 0; j < 4; j++){
			if(s[j] - '0' > 1 && s[j] - '0' < 10) cards[i][j] = s[j] - '0';
			else if(s[j] == 'A') cards[i][j] = 1;
			else if(s[j] == 'D') cards[i][j] = 10;
			else if(s[j] == 'Q') cards[i][j] = 11;
			else if(s[j] == 'J') cards[i][j] = 12;
			else if(s[j] == 'K') cards[i][j] = 13;

			count[cards[i][j]]++;

			if(count[cards[i][j]] == 4 && i != k){
				cout << i+1 << endl;
				return 0;
			}
		}
	}

	int pas = 0;

	while(1){
		int next;

		if(k + 1 == n) next = 0;
		else next = k + 1;

		vector<int> count(14, 0);
		int vmin = INF, ans, it;

		count[pas]++;

		for(int i = 0; i < 4; i++) count[cards[k][i]]++;

		for(int i = 0; i < 4; i++){
			if(count[cards[k][i]] == 4 && pas){
				cout << k+1 << endl;
				return 0;
			}

			if(count[cards[k][i]] < vmin){
				vmin = count[cards[k][i]];
				ans = cards[k][i];
				it = i;
			}
			else if(count[cards[k][i]] == vmin && cards[k][i] < ans){
				ans = cards[k][i];
				it = i;
			}
		}

		if(count[pas] < vmin && pas != 0){
			k = next;
		}
		else if(count[pas] == vmin && pas < ans && pas != 0){
			k = next;
		}
		else{
			cards[k][it] = pas;
			pas = ans;
			k = next;
		}
	}
}
