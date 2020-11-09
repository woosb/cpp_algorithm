# cpp_algorithm

프로그래밍 대회에서 배우는 알고리즘 문제해결전략
c++알고리즘 연습

1. 무식하게 풀기(재귀 호출과 완전탐색)
- boggle : 
  재귀함수를 이용하여 5x5 알파벳 격자에 존재하는 단어를 완전탐색을 하여 존재여부와 위치를 알려주는 프로그램 입니다.
- Picnic : 
  친구끼리 짝을 지어주는 프로그램 입니다.
  
package test;

import java.util.ArrayList;
import java.util.Scanner;
import java.util.Vector;

class Main{
	static int n;
	static int[][] dist;
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		n = scanner.nextInt();
		
		dist = new int[n][n];
		
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				int input = scanner.nextInt();
				dist[i][j] = input;
			}
		}
		
		ArrayList<Boolean> visited = new ArrayList<Boolean>();
		ArrayList<Integer> path = new ArrayList<Integer>();
		visited.add(true); // 0은 방문했다고 표시해 준다.
		for(int i = 1; i < n; ++i) {
			visited.add(false);
		}
		path.add(0); //처음 시작 도시는 0 이다.
		
		System.out.println(shortestPath(visited, path, 0));
		
//		for(int i = 0; i < n; i ++) {
//			for(int j : dist[i]) {
//				System.out.print(j + " ");
//			}	
//			System.out.println();
//		}
		
	}
	public static double shortestPath(ArrayList<Boolean> visited, ArrayList<Integer> path, int currentLength) {
		if(path.size()==n) {
//			for(int i : path) {
//				System.out.print(i + " ");
//			}
//			System.out.println(currentLength+dist[path.get(path.size()-1)][path.get(0)]);
			
			// 재귀함수로 마지막까지 가는 루트를 구한 다음 마지막에서 처음으로 돌아가는 비용을 더해준다.
			return currentLength+dist[path.get(path.size()-1)][path.get(0)]; 
		}
		
		double ret = 1.797679e+308;
		for(int next = 0; next < n; ++next) {
			if(visited.get(next)) continue;
			int here = path.get(path.size()-1); // path = {0,};
			path.add(next);
			visited.add(next, true);
			System.out.println(path.get(here));
			
//			double cand = shortestPath(visited, path, currentLength+dist[path.get(here)][path.size()-1]);
			double cand = shortestPath(visited, path, 0);
			ret = Math.min(ret, cand);
			visited.set(next, false);
			path.remove(path.size()-1);
		}
		return ret;
	}
}
