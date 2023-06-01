#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<string>board;
bool is_valid(int i,int j,vector<string>&board){
	if(board[i][j]=='*'){
		return false;
	}
	for(int l=0;l<i;l++){
		if(board[l][j]=='Q'){
			return false;
		}
	}
	for(int p=i,q=j;p>=0&&q>=0;p--,q--){
		if(board[p][q]=='Q'){
			return false;
		}
	}
	for(int p=i,q=j;p>=0&&q<8;p--,q++){
		if(board[p][q]=='Q'){
			return false;
		}
	}
	return true;
}
int solve(int i){
	if(i==8){
		return 1;
	}
	int total=0;
	for(int j=0;j<8;j++){
		if(is_valid(i,j,board)){
			board[i][j]='Q';
			total+=solve(i+1);
			board[i][j]='.';

		}
	}
	return total;
}
int32_t main(){
	for(int i=0;i<8;i++){
		string temp;
		for(int j=0;j<8;j++){
			char c;
			cin>>c;
			temp.push_back(c);
		}
		board.push_back(temp);
	}
	cout<<solve(0)<<endl;
	return 0;
	
}
struct VectorHasher {
  std::size_t operator()(const std::vector<int>& v) const {
    std::hash<int> hasher;
    std::size_t seed = 0;
    for (int i : v) {
      seed ^= hasher(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    return seed;
  }
};
unordered_set<vector<int>, VectorHasher> ans;
