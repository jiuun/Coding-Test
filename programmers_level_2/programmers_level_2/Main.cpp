#include <assert.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> Split(string input, char delimiter);
vector<string> solution(vector<string> record);

int main()
{
	vector<string> record = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" };

	vector<string> answer = solution(record);

	for (auto& message : answer)
	{
		cout << message << endl;
	}

	return 0;
}

// https://school.programmers.co.kr/learn/courses/30/lessons/42888
// 오픈채팅방
vector<string> solution(vector<string> record)
{
	vector<string> answer;
	answer.reserve(record.size());

	unordered_map<string, string> uidNicknameMap;
	uidNicknameMap.reserve(record.size());

	vector<pair<string, char>> uidActions;
	uidActions.reserve(record.size());

	for (auto& message : record)
	{
		vector<string> words = Split(message, ' ');

		switch (words[0][0])
		{
		case 'E':
			assert(words.size() == 3);

			if (uidNicknameMap.find(words[1]) == uidNicknameMap.end())
			{
				uidNicknameMap.insert(make_pair<string&, string&>(words[1], words[2]));
			}
			else
			{
				uidNicknameMap[words[1]] = words[2];
			}

			uidActions.push_back({ words[1], 'E' });
			break;
		case 'L':
			assert(words.size() == 2);

			uidActions.push_back({ words[1], 'L' });
			break;
		case 'C':
			assert(words.size() == 3);

			if (uidNicknameMap.find(words[1]) != uidNicknameMap.end())
			{
				uidNicknameMap[words[1]] = words[2];
			}
			break;
		default:
			assert(false);
			break;
		}
	}

	for (auto& uidAction : uidActions)
	{
		string message = uidNicknameMap[uidAction.first];

		switch (uidAction.second)
		{
		case 'E':
			message += "님이 들어왔습니다.";
			break;
		case 'L':
			message += "님이 나갔습니다.";
			break;
		default:
			assert(false);
			break;
		}

		answer.push_back(message);
	}

	return answer;
}

vector<string> Split(string input, char delimiter)
{
	vector<string> split;
	stringstream ss(input);
	string temp;

	while (getline(ss, temp, delimiter))
	{
		split.push_back(temp);
	}

	return split;
}