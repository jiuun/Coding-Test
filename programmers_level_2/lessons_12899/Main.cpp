#include <assert.h>
#include <string>
#include <vector>

using namespace std;

string solution(int n);

int main()
{
	int decimalNum[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	for (int i = 0; i < 10; ++i)
	{
		printf("%s\n", solution(decimalNum[i]).c_str());
	}

	return 0;
}

string solution(int n)
{
	string answer = "";
	vector<char> ternarys;

	int ternary = n;

	while (ternary > 0)
	{
		if (ternary % 3 != 0)
		{
			ternarys.push_back(ternary % 3);
			ternary /= 3;
		}
		else
		{
			ternarys.push_back(4);
			ternary = (ternary - 3) / 3;
		}
	}

	answer.reserve(ternarys.size());

	for (int i = (int)ternarys.size() - 1; i >= 0; --i)
	{
		answer.push_back('0' + ternarys[i]);
	}

	return answer;
}