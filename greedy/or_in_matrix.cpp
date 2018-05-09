#include <iostream>
#include <cstdlib>
#include <cstring> 
#include <algorithm>
#include <vector> 
using namespace std;  
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);  
typedef pair<int,int> P;  
int b[101][101],a[101][101],test[101][101];  
int m,n; 
int main(){
	IOFAST();  
	cin >> m >> n; 
	vector<P> v; // list of coordinates containing 0 
	vector<P> test_one; 
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			cin >> b[i][j]; 
			if (b[i][j] == 0) v.push_back(P(i,j));  
			else test_one.push_back(P(i,j)); 
		}
	}
	// construct test 
	memset(test,-1,sizeof(test)); 
	for (int i = 0; i < v.size(); i++){
		int x = v[i].first; 
		for (int j = 0; j < n; j++){
			test[x][j] = 0; 
		}
		int y = v[i].second; 
		for (int j = 0; j < m; j++){
			test[j][y] = 0; 
		}
	}
	vector<P> unfilled;  
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if (test[i][j] == -1){
				unfilled.push_back(P(i,j)); 
			}
		}
	}
	for (int i = 0; i < unfilled.size(); i++){
		int x = unfilled[i].first, y = unfilled[i].second; 
		for (int j = 0; j < n; j++){
			test[x][j] = 1; 
		}
		for (int j = 0; j < m; j++){
			test[j][y] = 1; 
		}
		test[x][y] = 1;  
	}
	// compare test and b. If equal, the answer is yes 
	bool mistake = false; 
	for (int i = 0; i < m; i++){
		if (mistake) break; 
		for (int j = 0; j < n; j++){
			if (b[i][j] != test[i][j]){
				mistake = true; 
				break; 
			}
		}
	}
	if (mistake){ // made a mistake 
		cout << "NO" << endl; 
	}else{
		// we know there is an answer, so reconstruct 
		// we fill A 
		// first fill all zero positions 
		memset(a,-1,sizeof(a)); 
		for (int i = 0; i < v.size(); i++){
			int x = v[i].first;  
			for (int j = 0; j < n; j++){
				a[x][j] = 0; 
			}
			int y = v[i].second; 
			for (int j = 0; j < m; j++){
				a[j][y] = 0; 
			}
		}
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				if (a[i][j] == -1) a[i][j] = 1; 
			}
		}
		// final step: printing out 
		cout << "YES" << endl; 
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				cout << a[i][j] << " ";  
			}
			cout << endl; 
		}
	}	
	return 0; 
}
