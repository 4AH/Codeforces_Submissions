#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
typedef vector<ll> VI;
typedef vector<VI> VVI;
const ll MOD = 1000000007;
const ll INF = 1e18;
#define REP(i, n) for(int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

int main() {
	int n, m; cin >> n >> m;
	vector<string> s(n);
	REP(i,n) cin >> s[i];
	if(n>=4&&m>=4){
		cout << -1 << endl;
	}
	else{
		if(n==1||m==1){
			cout << 0 << endl;
		}
		else{
			vector<vector<bool>> f(n-1,vector<bool>(m-1,0));
			REP(i,n-1)REP(j,m-1){
				int sum=0;
				sum+=s[i][j]-'0';
				sum+=s[i+1][j]-'0';
				sum+=s[i][j+1]-'0';
				sum+=s[i+1][j+1]-'0';
				f[i][j]=sum%2;
			}
			if(n==3){
				VVI dp(m-1,VI(4,INF));
				REP(i,4) dp[0][i]=1;
				dp[0][f[0][0]+2*f[1][0]]=0;
				REP(j,m-2){
					int p=f[0][j+1]+2*f[1][j+1];
					REP(k,4){
						dp[j+1][p^k]=min(dp[j+1][p^k],dp[j][3^k]+(bool)k);
					}
				}
				ll ans=INF;
				REP(i,3)
					ans=min(ans,dp[m-2][i]+1);
				ans=min(ans,dp[m-2][3]);	
				cout << ans << endl;
			}
			else{
				VVI dp(m-1,VI(2,INF));
				REP(i,2) dp[0][i]=1;
				dp[0][f[0][0]]=0;
				REP(j,m-2){
					int p=f[0][j+1];
					REP(k,2){
						dp[j+1][p^k]=min(dp[j+1][p^k],dp[j][1^k]+(bool)k);
					}
				}
				ll ans=INF;
				ans=min(dp[m-2][1],dp[m-2][0]+1);
					cout << ans << endl;
			}
		}
	}
	return 0;
}
