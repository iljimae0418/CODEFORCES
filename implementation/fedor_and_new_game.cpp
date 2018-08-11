#include <iostream>
#include <cstdlib>
#include <algorithm> 
using namespace std; 
int a[2222]; 
bool possibleFriend(int k1,int k2,int threshold){
	string bk1,bk2; 
	while (k1){
		bk1 += (k1%2) + '0';  
		k1 /= 2; 
	}
	reverse(bk1.begin(),bk1.end()); 
	while (k2){
		bk2 += (k2%2) + '0'; 
		k2 /= 2; 
	}
	reverse(bk2.begin(),bk2.end()); 
	while (bk1.size() < bk2.size()){
		bk1 = "0" + bk1; 
	}
	while (bk2.size() < bk1.size()){
		bk2 = "0" + bk2; 
	}
	int cnt = 0; 
	for (int i = 0; i < bk1.size(); i++){
		if (bk1[i] != bk2[i]) cnt++; 
	}
	return cnt <= threshold; 
}	
int main(){
	int n,m,k; 
	cin >> n >> m >> k;  
	for (int i = 0; i < m+1; i++){
		cin >> a[i]; 
	}
	int fedor = a[m],cnt = 0; 
	for (int i = 0; i < m; i++){
		if (possibleFriend(fedor,a[i],k)){
			cnt++; 
		} 
	}
	cout << cnt << endl; 
	return 0;  
}
