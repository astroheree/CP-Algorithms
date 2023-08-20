#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define rep(i,a,n) for(int i=a;i<n;i++)
#define rep1(i,a,n) for(int i=a;i<=n;i++)
#define br cout << "\n";
#define pb push_back
#define fast_io() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) 
#define all(x) x.begin(),x.end()
typedef vector<int> vi;
#define pb push_back
#define ss second
#define ff first
int mod  = 1e9+7;

void init_code(){
    fast_io();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

string l,r;
int dp[11][2][2];

int solve(int ind, string &s, int tight, int allZero)
{

	if(isZero == 1 && ind == s.size()) return 0;
	// tight
	int ub = 0;
	if(tight == 1)
	{
		ub = s[i] - '0';
	}
	else
	{
		ub = 9;
	}
	int ans = 0;
	for(int i = 0 ; i <= ub ; i++)
	{
		if(isZero == 1 && i == 0) 
		{
			ans += solve(i+1,s,0,1);
		}
		else
		{
			int newTight = 0;
			if(i == ub && tight == 1)
			{
				newTight = 1;
			}
			else
			{
				newTight = 0;
			}
			ans += solve(i+1,s,newTight,0);
		}
		 
	}
}

void solveAnswer(){

	cin>>l>>r;
	memset(dp,-1,sizeof(dp));
	int right = solve(0,r,1,1);
	memset(dp,-1,sizeof(dp));
	int left = solve(0,l,1,1);
	cout<<right-left<<endl;

}

int32_t main(){
    init_code();
    int t = 1;
    // cin>>t; 
    while(t--){
        solveAnswer();
    }
 	
    return 0;
}
