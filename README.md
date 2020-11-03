# cpp_algorithm

프로그래밍 대회에서 배우는 알고리즘 문제해결전략
c++알고리즘 연습

1. 무식하게 풀기(재귀 호출과 완전탐색)
- boggle : 
  재귀함수를 이용하여 5x5 알파벳 격자에 존재하는 단어를 완전탐색을 하여 존재여부와 위치를 알려주는 프로그램 입니다.
- Picnic : 
  친구끼리 짝을 지어주는 프로그램 입니다.


#include <iostream>
#include <vector>
using namespace std;
const int coverType[4][3][2] = {
	{{ 0, 0},{1, 0}, {0, 1}}, 
	{{ 0, 0},{0, 1}, {1, 1}},
	{{ 0, 0},{1, 0}, {1, 1}},
	{{ 0, 0},{1, 0}, {1, -1}},
};

int main(){
	int x, y, t;
	
	cin >> t;
	for(int i = 0; i < t; i ++){
		vector< vector<char> > input;
		cin >> x >> y;
		
		for(int i = 0; i < x; i ++){
			vector<char> str;
			for(int j = 0; j < y; j++){
				char a;
				cin >> a;
				str.push_back(a);
			}
			input.push_back(str);
		}
		
//		for(int i = 0; i < x; i++){
//			vector<char> d = input[i];
//			for(int j = 0; j < y; j++){
//				cout << d[j];
//			}
//			cout<< endl;
//		}
		
		for(int i = 0; i < x; i ++){
			input[i].clear();
		}
		input.clear();	
	}
}
