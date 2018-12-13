#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
#include <fstream> 
using namespace std; 
typedef pair<int,int> P;  
P a[1005];
int n,k;   
int main(int argc,char **argv){
	ifstream fin("input.txt"); 
	ofstream fout("output.txt"); 
	fin >> n >> k; 
	for (int i = 1; i <= n; i++){
		fin >> a[i].first; 
		a[i].second = i; 
	}
	sort(a+1,a+n+1); 
	// print minimum value first 
	fout << a[n-k+1].first << endl; 
	vector<int> ans; 
	for (int i = n; i >= n-k+1; i--){
		ans.push_back(a[i].second);  
	}
	sort(ans.begin(),ans.end()); 
	for (int i = 0; i < ans.size(); i++){
		fout << ans[i] << " "; 
	}
	fout << "\n"; 
	return 0; 
}
