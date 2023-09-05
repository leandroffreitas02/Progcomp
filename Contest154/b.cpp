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

    int t; cin >> t;

    while(t--){
        string s1, s2; cin >> s1 >> s2;

        if(s1[0] != s2[0]){
            cout << "NO" << endl;
            return 0;
        }

        for(int i = 1; i < s1.size(); i++){
            if(s1[i] != s2[i]){
                if(s1[i-1] != s1[i]){
                    for(int j = i+1; j < s1.size(); j++){
                        if(s1[j] != s1[i]){
                            for(int k = i; k < j; k++)
                                if(s1[k] == '0') s1[k] = '1';
                                else s1[k] = '0';

                            break;
                        }
                    }
                }

                if(s2[i-1] != s2[i]){
                    for(int j = i+1; j < s2.size(); j++){
                        if(s2[j] != s2[i]){
                            for(int k = i; k < j; k++){
                                if(s2[k] == '0') s2[k] = '1';
                                else s2[k] = '0';
                            }
                            break;
                        }
                    }
                }
            }
        }
        cout << ((s1 == s2) ? "YES" : "NO") << endl;
    }

}