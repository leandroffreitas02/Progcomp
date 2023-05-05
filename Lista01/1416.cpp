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

bool func (vector<int> a, vector<int> b){
	if(a[0] == b[0]) return (a[1] < b[1]);
	else return a[0] > b[0];
}

int main(){ _

	while(1){
		int T, P; scanf("%d %d", &T, &P);
		int pen = 20;
		if(!T && !P) return 0;

		vector<vector<int>> r(T, vector<int>(3, 0));

		for(int i = 0; i < T; i++){
			for(int j = 0; j < P; j++){
				int a; char str[4];

				scanf("%d/%s", &a, str);
				string s = str;

				if(s != "-"){
					int aux;
					stringstream ss;
					ss << s;
					ss >> aux;

					r[i][0]++;
					r[i][1] += aux + (a - 1)*pen;
					r[i][2] += a - 1;
				}
			}
		}
		sort(r.begin(), r.end(), func);

		int vmin = 1, vmax = INF;

		for(int i = 0; i < T-1; i++){
			if(r[i][0] == r[i+1][0]){

				if(r[i][1] == r[i+1][1] && r[i][2] != r[i+1][2]){
					vmin = 20; vmax = 20;
					break;
				}
				else if(r[i][2] > r[i+1][2]){
					float aux = ceil((float)(r[i+1][1] - r[i][1] + r[i][2]*pen - r[i+1][2]*pen)/(r[i][2] - r[i+1][2]));
					int np = aux;
					vmax = min(vmax, np - 1);
				}
				else if(r[i][2] < r[i+1][2]){

					int np = (r[i+1][1] - r[i][1] + r[i][2]*pen - r[i+1][2]*pen)/(r[i][2] - r[i+1][2]);

					vmin = max(vmin, np + 1);
				}
			}
		}
		cout << vmin << ' ';

		if(vmax == INF) cout << '*' << endl;
		else cout << vmax << endl;
	}
}
