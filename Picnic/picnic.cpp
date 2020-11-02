#include <iostream>
using namespace std;

int dfs(int taken[11]);
int dfs2(int taken[11]);

int taken[11] = {0,};
int checkFriend[11][11] = {0,};
int C,N,M = 0;
int main(){
	cin >> C;
	for(int i = 0; i < C; i ++){//test case 3번
		cin >> N >> M;
		for(int j = 0; j < M; j ++){
			int friend1, friend2;
			cin >> friend1 >> friend2;
		// (1, 2) 와 (2, 1)은 같은 의미이다.(둘이 친구라는 뜻이기 때문에) 
			checkFriend[friend1][friend2] = 1;
			checkFriend[friend2][friend1] = 1;
		}
	}
	int ret = dfs2(taken);
	cout << "ret : "<< ret;
}


int dfs(int taken[11]){
	bool finished = true;
	for(int i = 0; i < N; i ++){
	if(!taken[i]) finished = false;
	}    
	if(finished) return 1;
	
	int ret = 0;
	for(int i = 0; i < N; i ++){
		for(int j = 0; j < N; j ++){
			if(!taken[i] && !taken[j] && checkFriend[i][j]){
				taken[i] = taken[j] = true;
				ret += dfs(taken);
				taken[i] = taken[j] = false;
			}  
		}
	}
	return ret;
}

int dfs2(int taken[11]){
	int fristFree = -1;

	for(int i = 0; i < N; i ++){
		if(!taken[i]) fristFree = i;
		break;
	}    
	if(fristFree == -1) return 1;

	int ret = 0;
	for(int pairWith = fristFree + 1; pairWith < N; pairWith ++){
		if(!taken[pairWith] && checkFriend[fristFree][pairWith]){
			taken[fristFree] = taken[pairWith] = true;
			ret += dfs2(taken);
			taken[fristFree] = taken[pairWith] = false;
		}
	}
	return ret;
}
