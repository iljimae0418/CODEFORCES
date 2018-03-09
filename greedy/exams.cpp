#include <iostream>
#include <algorithm> 
using namespace std; 
struct info{
	int a,b; 
}; 
info e[5005]; 
bool cmp(info &i1,info &i2){
	return i1.a < i2.a || (i1.a == i2.a && i1.b < i2.b);  
}
int main(){
	int n; 
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> e[i].a >> e[i].b; 
	}	
	sort(e,e+n,cmp);  	
	int best = -1; 
	for (int i = 0; i < n; i++){
		if (best <= e[i].b){
			best = e[i].b;  
		}else{
			best = e[i].a; 
		}
	}
	cout << best << endl; 
	return 0; 
}
