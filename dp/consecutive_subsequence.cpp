#include <iostream> 
#include <cstdlib>
#include <algorithm> 
#include <cstring> 
#include <vector> 
#include <map> 
using namespace std;  
const int INF = (int)2e9; 
int a[200005]; 
typedef pair<int,int> P; 
map<int,P> dp;  
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
int main(){
	IOFAST();  
	int n; 
	cin >> n; 
	vector<int> a(n);  
	for (int i = 0; i < n; i++){
		cin >> a[i]; 
	}
	map<int,int> dp; 
	int ans = 0, lst = 0; 
	for (int i = 0; i < n; i++){
		int x = a[i];  
		dp[x] = dp[x-1]+1;  
		if (ans < dp[x]){
			ans = dp[x]; 
			lst = x;  
		}
	}
	vector<int> res; 
	for (int i = n-1; i >= 0;  i--){
		if (a[i] == lst){
			res.push_back(i); 
			--lst;  
		}
	}
	reverse(res.begin(),res.end()); 
	printf("%d\n",ans); 
	for (int i = 0; i < res.size(); i++){
		printf("%d ",res[i]+1); 
	}
	puts(""); 
	return 0; 	
}
