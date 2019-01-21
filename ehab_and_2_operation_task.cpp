#include <iostream>
#include <cstdlib>
#include <cstring> 
#include <cstdio> 
#include <algorithm> 
#include <vector> 
using namespace std; 
int a[2005]; 
bool strictly_increasing(int *k,int n){
	for (int i = 1; i <= n-1; i++){
		if (k[i] >= k[i+1]) return false; 
	}
	return true; 
}
struct operation{
	int type; 
	int idx; 
	int x;  
	operation(int t,int i,int _x): type(t), idx(i), x(_x){}
};
int main(int argc,char **argv){
	int n; 	
	scanf("%d",&n); 
	for (int i = 1; i <= n; i++){
		scanf("%d",a+i); 
	}
	printf("%d\n1 %d 500000\n",n+1,n);
	for (int i = 1; i <= n; i++){
		printf("2 %d %d\n",i,a[i]+500000-i); 
	}
	return 0; 
}
