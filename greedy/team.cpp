#include <iostream>
using namespace std; 
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
bool chk(int a,int b,int c){
	int cnt = 0; 
	if (a == 1) cnt++; 
	if (b == 1) cnt++; 
	if (c == 1) cnt++; 
	return cnt >= 2;  
}
int main(){
	IOFAST(); 
	int n,cnt=0; 
	cin >> n; 
	for (int i = 0; i < n; i++){
		int a,b,c; 
		cin >> a >> b >> c; 
		if (chk(a,b,c)) cnt++; 
	}
	cout << cnt << endl; 
}
