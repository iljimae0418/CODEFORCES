#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;  
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
int a[100005],b[100005]; 
int main(){
	int n; 
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> a[i];
		b[i] = a[i];  
	}
	sort(b,b+n);  
	int f = -1, l = -1;  
	for (int i = 0; i < n-1; i++){
		if (a[i] > a[i+1] && f == -1){
			f = i;  
		}
		if (a[i] < a[i+1] && f != -1 && l == -1){
			l = i;  
			break; 
		}
	}	
	if (f != -1 && l == -1){
		l = n-1;  
	}
	if (f == -1 && l == -1){
		cout << "yes" << endl; 
		cout << "1 1" << endl; 
		return 0; 
	}
	int m = l;  
	for (int i = f; i <= (f+l)/2; i++){
		swap(a[i],a[m]);
		m--;     
	}
	/*for (int i = 0; i < n; i++){
		cout << a[i] << " "; 
	}
	cout << endl; */  
	for (int i = 0; i < n; i++){
		if (b[i] != a[i]){
			cout << "no" << endl; 
			return 0;  `
		}
	}
	cout << "yes" << endl; 
	cout << f+1 << " " << l+1 << endl; 
	return 0; 
}
