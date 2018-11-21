#include <iostream>
#include <cstdlib>
#include <cstdio> 
#include <cstring> 
#include <algorithm>
#include <vector> 
#include <queue> 
#include <map> 
using namespace std; 
int main(){
	int n,m; 
	scanf("%d %d",&n,&m); 
	map<int,int> mp; 
	int chk[4]; 
	for (int i = 1; i <= m; i++){
		memset(chk,0,sizeof(chk)); 
		int x,y,z; 
		scanf("%d %d %d",&x,&y,&z); 
		if (mp.count(x)){
			chk[mp[x]] = 1;  
			for (int j = 1, cnt = 0; j <= 3; j++){
				if (!chk[j] && cnt == 0){
					chk[j] = 1; 
					cnt++; 
					mp[y] = j; 
				}else if (!chk[j] && cnt == 1){
					chk[j] = 1;  
					mp[z] = j; 
				}
			}
		}else if (mp.count(y)){
			chk[mp[y]] = 1;  
			for (int j = 1, cnt = 0; j <= 3; j++){
				if (!chk[j] && cnt == 0){
					chk[j] = 1; 
					cnt++; 
					mp[x] = j; 
				}else if (!chk[j] && cnt == 1){
					chk[j] = 1;  
					mp[z] = j; 
				}
			}
		}else if (mp.count(z)){
			chk[mp[z]] = 1;  
			for (int j = 1, cnt = 0; j <= 3; j++){
				if (!chk[j] && cnt == 0){
					chk[j] = 1; 
					cnt++; 
					mp[x] = j; 
				}else if (!chk[j] && cnt == 1){
					chk[j] = 1;  
					mp[y] = j; 
				}
			}
		}else{
			mp[x] = 1;  
			mp[y] = 2;  
			mp[z] = 3; 
		}
	}
	for (int i = 1; i <= n; i++){
		if (!mp.count(i)) printf("%d%c",1,i == n ? '\n' : ' '); 
		else printf("%d%c",mp[i],i == n ? '\n' : ' '); 
	}
	return 0;  
}
