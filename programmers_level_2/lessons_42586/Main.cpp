#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds);

int main()
{
	vector<int> result;
	
	vector<int> progresses1 = { 93, 30, 55 };
	vector<int> speeds1 = { 1, 30, 5 };

	result = solution(progresses1, speeds1);

	vector<int> progresses2 = { 95, 90, 99, 99, 80, 99 };
	vector<int> speeds2 = { 1, 1, 1, 1, 1, 1 };

	result = solution(progresses2, speeds2);


	return 0;
}

// 스택/큐 기능개발
// https://school.programmers.co.kr/learn/courses/30/lessons/42586

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
	vector<int> answer;
	vector<int> requiredDays;
	requiredDays.reserve(progresses.size());

	const int COMPLETION_PROGRESS = 100;

	for (int i = 0; i < requiredDays.capacity(); ++i)
	{
		int curr_progress = progresses[i];
		int tempRequiredDay = 0;

		while (curr_progress < COMPLETION_PROGRESS)
		{
			curr_progress += speeds[i];
			++tempRequiredDay;
		}

		requiredDays.push_back(tempRequiredDay);
	}


	int completionCount = 1;
	int tempMaxRequiredDay = requiredDays[0];

	for (int i = 1; i < requiredDays.size(); ++i)
	{
		if (tempMaxRequiredDay < requiredDays[i])
		{
			tempMaxRequiredDay = requiredDays[i];
			answer.push_back(completionCount);
			completionCount = 0;
		}

		++completionCount;
	}

	answer.push_back(completionCount);

	return answer;
}
