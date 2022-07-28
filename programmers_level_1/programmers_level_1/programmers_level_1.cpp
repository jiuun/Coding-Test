#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int solution12931(int n);
int solution64061(vector<vector<int>> board, vector<int> moves);

int main()
{
    {
        vector<vector<int>> board = { {0, 0, 0, 0, 0},{0, 0, 1, 0, 3},{0, 2, 5, 0, 1},{4, 2, 4, 4, 2},{3, 5, 1, 3, 1} };
        vector<int> moves = { 1,5,3,5,1,2,1,4 };

        int result = solution64061(board, moves);
    }
}

// https://school.programmers.co.kr/learn/courses/30/lessons/12931
// 자릿수 더하기
int solution12931(int n)
{
    int temp = n;
    int sum = 0;

    while (temp > 0)
    {
        sum += temp % 10;

        temp /= 10;
    }

    return sum;
}

// https://school.programmers.co.kr/learn/courses/30/lessons/64061
// 크레인 인형뽑기 게임
int solution64061(vector<vector<int>> board, vector<int> moves)
{
	int answer = 0;
	vector<int> stack;
	stack.reserve(moves.size());
	vector<int> rowIndex(board.size());

	for (int i = 0; i < moves.size(); ++i)
	{
		int col = moves[i] - 1;

		for (int row = rowIndex[col]; row < board.size(); rowIndex[col] = ++row)
		{
			if ((board[row][col] != 0))
			{
				if (stack.empty() || board[row][col] != stack.back())
				{
					stack.push_back(board[row][col]);
				}
				else
				{
					stack.pop_back();
					answer += 2;
				}

				board[row][col] = 0;
				break;
			}
		}
	}

	return answer;
}
