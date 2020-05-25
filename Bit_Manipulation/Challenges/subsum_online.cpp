#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,st,end) for(int i=st;i<end;i++)
#define db(x) cout << (#x) << " = " << x << endl;
#define mp make_pair
#define pb push_back
typedef long long int ll;
int main(){

	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif
	

	ll n,a,b;
	ll arr[40];
	ll subSetSize;
	vector<ll>sum1;
	vector<ll>sum2;
	scanf("%lld%lld%lld",&n,&a,&b);
	REP(i,n){
		scanf("%lld",&arr[i]);
	}
	ll powerSetSize=1<<n/2;
	subSetSize=n/2;
	//finding subset sum for first half
	for(ll i=0;i<powerSetSize;i++){
		ll sum=0;
		REP(j,subSetSize){
			if(i&(1<<j)){
				sum+=arr[j];
			}
		}
		sum1.pb(sum);
	}
	//this is to classify even and odd n cases
    if((n&1)==1){
		
		subSetSize=n/2+1;
		powerSetSize=1<<subSetSize;
	}
	else{
		
		subSetSize=n/2;
		powerSetSize=1<<subSetSize;
	}
	//finding subset sum for 2nd half
	for(ll i=0;i<powerSetSize;i++){
		ll sum=0;
		REP(j,subSetSize){
			if(i&(1<<j)){
				sum+=arr[n/2+j];
			}
		}
		sum2.pb(sum);
	}
	sort(sum1.begin(),sum1.end());
	vector<ll>::iterator low,high;
	ll ans=0;
	//use STL functions to find lower bounds and upper bounds(which internally uses binary search)
	REP(i,sum2.size()){
		low=lower_bound(sum1.begin(),sum1.end(),a-sum2[i]);
		high=upper_bound(sum1.begin(),sum1.end(),b-sum2[i]);
		ans+=(high-low);
	}
	printf("%lld\n",ans);
	
}