#include <iostream>
#include <vector>
using namespace std;

bool set(vector< vector<int> > & board, int y, int x, int type, int delta);
int cover(vector< vector<int> > & board);

const int coverType[4][3][2] = {
	{{ 0, 0},{1, 0}, {0, 1}}, 
	{{ 0, 0},{0, 1}, {1, 1}},
	{{ 0, 0},{1, 0}, {1, 1}},
	{{ 0, 0},{1, 0}, {1, -1}},
};

int main(){
	int test;
	int y, x;
	
	cin >> test;
	cin >>y >> x;
	
	for(int i = 0; i < test; i ++){
		vector<vector <int> > board;
		for(int j = 0; j < y; j ++){
			vector< int > v;
			for(int k = 0; k < x; k++){
				char input;
				cin >> input;
				if(input == '#'){
					v.push_back(1);
				}else{
					v.push_back(0);
				}
			}
			board.push_back(v);
		}
		cout << cover(board) << endl;
	}
}

bool set( vector<vector<int> > & board, int y, int x, int type, int delta){
	bool ok = true;
	
	for(int i = 0; i < 3; i ++){
		int ny = y + coverType[type][i][0];
		int nx = x + coverType[type][i][1];
		if(nx < 0 || nx > board[i].size() || ny < 0 || ny > board.size())
			ok = false;
		else if((board[ny][nx] += delta) > 1)
			ok = false;
	}
	return ok;
}

int cover( vector<vector<int> > &board){
	int x = -1;
	int y = -1;
	
	for(int i = 0; i < board.size(); i++){
		for(int j = 0; j < board[i].size(); j++){
			if(board[i][j] == 0){
				y = i;
				x = j;
				break;
			}
		}
		if(y != -1) break;
	}
	
	if(y == -1) return 1;
	
	int ret = 0;
	
	for(int type = 0; type < 4; type++){
		if(set(board, y, x, type, 1))
			ret += cover(board);
		set(board, y, x, type, -1);
	}
	return ret;
}
 

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
