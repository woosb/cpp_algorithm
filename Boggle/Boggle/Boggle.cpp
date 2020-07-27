#include <iostream>
#include <vector>
#include <string>

const int dx[]{ -1, 0, 1, 1, 1, 0, -1, -1, -1 };
const int dy[]{ -1, -1, -1, 0, 1, 1, 1, 0, -1 };

char board[][5]{
	{'U', 'R', 'L', 'P', 'M'},
	{'X', 'P', 'R', 'E', 'T'},
	{'G', 'I', 'A', 'E', 'T'},
	{'X', 'T', 'N', 'Z', 'Y'},
	{'X', 'O', 'Q', 'R', 'S'},
};

char result[][5]{
	{'.', '.', '.', '.', '.'},
	{'.', '.', '.', '.', '.'},
	{'.', '.', '.', '.', '.'},
	{'.', '.', '.', '.', '.'},
	{'.', '.', '.', '.', '.'},
};

bool inRange(int x, int y);
bool hasWord(int x, int y, const std::string& word);
int findFirst(char board[][5], std::string word);


bool hasWord(int y, int x, const std::string& word) {

	//std::cout << word << " "<<x << " " << y << " " << std::endl;
	if (!inRange(x, y)) {
		//std::cout << "inRange : " <<(bool)(!inRange(x, y))<<std::endl;
		return false;
	}
	if (board[y][x] != word[0]) {
		/*std::cout << "board[y][x] != word[0]" << std::endl;
		std::cout <<  "x = " << x << ", y = " << y << std::endl;
		std::cout << " borad : "<<board[y][x]<< ", word[0] :" <<word[0] <<std::endl;*/
		return false;
	}
	if (word.size() == 1) {
		//std::cout << "check size of word" << std::endl;
		return true;
	}

	for (int i = 0; i < 8; i++) {
		//std::cout << "move x, y location" << std::endl;
		result[y][x] = '@';
		int nexty = y + dy[i];
		int nextx = x + dx[i];
		if (hasWord(nexty, nextx, word.substr(1))) {
			std::cout << "x : " << x << ", y : " << y << std::endl;
			result[nexty][nextx] = '@';
			return true;
		}
	}

	return false;
}

bool inRange(int x, int y) {
	if (x > 4 || y > 4) {
		return false;
	}

	return true;
}
int findFirst(char board[][5], std::string word) {

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (word[0] == board[j][i]) {
				std::cout << "x = " << i << ", y = " << j << " 위치에서 시작 " << std::endl;
				hasWord(j, i, word);
			}
		}
	}

	return 1;
}

int main() {
	const std::string word = "PRETTY";


	findFirst(board, word);

	//hasWord(3, 1, word);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			std::cout << result[i][j];
		}
		std::cout << std::endl;
	}
}