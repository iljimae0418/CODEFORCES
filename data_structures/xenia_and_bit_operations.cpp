#include <iostream>
#include <algorithm>
using namespace std; 
const int MAXN = 1<<18; 
int num[MAXN]; 
int ans[MAXN<<2]; 
void build(int l,int r,int rt,int turn){
	if (l == r){
		ans[rt] = num[l]; 
		return; 
	}
	int mid = (l+r)>>1;  
	build(l,mid,rt<<1,!turn); 
	build(mid+1,r,rt<<1|1,!turn);   
	if (turn) ans[rt] = ans[rt<<1]|ans[rt<<1|1];  
	else ans[rt] = ans[rt<<1]^ans[rt<<1|1];  
}
void update(int l,int r,int rt,int index,int value,int turn){
	if (l == r && l == index){
		ans[rt] = value;   
		return; 
	}
	int mid = (l+r)>>1; 
	if (mid < index){
		update(mid+1,r,rt<<1|1,index,value,!turn); 
	}else{
		update(l,mid,rt<<1,index,value,!turn); 
	}
	if (turn) ans[rt] = ans[rt<<1]|ans[rt<<1|1];  
	else ans[rt] = ans[rt<<1]^ans[rt<<1|1]; 
}
int main(){
	int n,m; 
	cin >> n >> m; 
	int sum = 1<<n; 
	for (int i = 1; i <= sum; i++){
		cin >> num[i];  
	}
	build(1,sum,1,n%2); 
	for (int i = 0; i < m; i++){
		int a,b; 
		cin >> a >> b;  
		update(1,sum,1,a,b,n%2);  
		cout << ans[1] << endl; 
	}
	return 0; 
}
