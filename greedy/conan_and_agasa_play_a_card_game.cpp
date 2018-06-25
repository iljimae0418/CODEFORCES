#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <map> 
using namespace std; 
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
int main(){
	IOFAST(); 
	int n,x; 
	cin >> n;
	map<int,int> mp;   
	for (int i = 0; i < n; i++){
		cin >> x; 
		mp[x]++; 
	}	
	int k = mp.rbegin()->second; 
	if (k == 1){
		cout << "Conan" << endl; 
	}else{
		for (map<int,int>::iterator it = mp.begin(); it != mp.end(); it++){
			if (it->second%2 == 1){
				cout << "Conan" << endl; 
				return 0; 
			}
		}
		cout << "Agasa" << endl; 
	}
	return 0;  
}
