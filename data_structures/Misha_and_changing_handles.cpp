#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <set>
#include <vector>
#include <map> 
using namespace std; 
vector<int> G[3000]; 
int indegree[3000]; 
set<string> used; 
map<string,int> id; 
map<int,string> reverse_id;   
void print_end(int x){
	if (G[x].size() == 0){
		cout << reverse_id[x] << endl; 
		return; 
	}
	print_end(G[x][0]); // there should only be one edge in this graph 
}
int main(){
	int q; 
	cin >> q; 
	int no = 1;  
	int chk = 0;  
	for (int i = 0; i < q; i++){
		string old_string,new_string; 
		cin >> old_string >> new_string; 
		if (!used.count(new_string)){
			if (!id.count(old_string)){
				id[old_string] = no;  
				reverse_id[no] = old_string; 
				id[new_string] = no+1;  
				reverse_id[no+1] = new_string; 
				no += 2;  
				G[id[old_string]].push_back(id[new_string]);  
			}else{
				id[new_string] = no; 
				reverse_id[no] = new_string; 
				no++; 
				G[id[old_string]].push_back(id[new_string]);  
			}
			used.insert(old_string); 
			used.insert(new_string);  
		}
	}
	// calculate indegree
	for (int i = 1; i <= used.size(); i++){
		for (int j = 1; j <= used.size(); j++){
			for (int k = 0; k < G[j].size(); k++){
				if (G[j][k] == i) indegree[i]++;  
			}
		}
	}
	vector<int> ans;  
	for (int i = 1; i <= used.size(); i++){
		if (indegree[i] == 0){
			ans.push_back(i); 
		}
	}
	cout << ans.size() << endl; 
	for (int i = 0; i < ans.size(); i++){
		cout << reverse_id[ans[i]] << " "; 
		print_end(ans[i]); 
	}
	return 0; 
}
