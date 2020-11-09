#include <iostream>
#include <vector>
using namespace std;

double shortestPath(vector<int>& path, vector<bool>& visited, double currentLength);

vector<vector <double> > dist;
int n = 0;
double INF = 100000;

int main(){
	cin >> n;
	
	vector<bool> visited(n, false);
	visited[0] = true;
	vector<int> path;
	path.push_back(0);
	
	for(int j = 0; j < n; j ++){
		vector< double > v;
		for(int k = 0; k < n; k++){
			int input;
			cin >> input;
			v.push_back(input);
		}
		dist.push_back(v);
	}
	
	cout << shortestPath(path, visited, 0) << endl;
	
//	for(int i = 0; i < n; ++i){
//		for(int j = 0; j < n; j++){
//			cout << dist[i][j] << " ";
//		}
//		cout << endl;
//	}
}

double shortestPath(vector<int>& path, vector<bool>& visited, double currentLength){
	if(path.size() == n){
//		for(int i = 0; i < path.size(); ++i){
//			cout << path[i] << " ";
//		}
//		cout << currentLength + dist[path.back()][path[0]] << endl;
		
		return currentLength + dist[path.back()][path[0]];
	}
	
	double ret = INF;
	for(int next = 0; next < n; ++next){
		if(visited[next]) continue;
		int here = path.back();
		path.push_back(next);
		visited[next] = true;
		double cand = shortestPath(path, visited, currentLength + dist[here][next]);
		ret = min(ret, cand);
		visited[next] = false;
		path.pop_back();
	}
	return ret;
}

