// https://www.acmicpc.net/problem/15649
// BACKTRACKING (1),
// NUMBER 15649
//
// 모든 조합을 출력해야 하므로 DFS 방식을 이용해서 풀이

#include <iostream>
#include <vector>
using namespace std;

#define MAX 11

bool visited[MAX - 1];
int n, nArr[MAX], oArr[MAX - 1];
int maxValue = -1000000000, minValue = 1000000000;
vector<int> operVec;

int Calculate()
{
    int temp;
    switch (operVec[0])
    {
    case 0:
        temp = nArr[0] + nArr[1];
        break;
    case 1:
        temp = nArr[0] - nArr[1];
        break;
    case 2:
        temp = nArr[0] * nArr[1];
        break;
    case 3:
        temp = nArr[0] / nArr[1];
        break;

    default:
        break;
    }

    for (int i = 2; i < n; i++)
    {
        switch (operVec[i - 1])
        {
        case 0:
            temp += nArr[i];
            break;
        case 1:
            temp -= nArr[i];
            break;
        case 2:
            temp *= nArr[i];
            break;
        case 3:
            temp /= nArr[i];
            break;

        default:
            break;
        }
    }
    return temp;
}

void Dfs(int cnt)
{
    if (cnt == n - 1)
    {
        int result = Calculate();
        if (maxValue < result)
            maxValue = result;
        if (minValue > result)
            minValue = result;
        return;
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (visited[i])
            continue;

        visited[i] = true;
        operVec.push_back(oArr[i]);
        Dfs(cnt + 1);
        visited[i] = false;
        operVec.pop_back();
    }
}

void input()
{
    int temp, cTemp = 0;
    cin >> temp;
    for (int i = 0; i < temp; i++)
    {
        oArr[cTemp] = 0;
        cTemp++;
    }

    cin >> temp;
    for (int i = 0; i < temp; i++)
    {
        oArr[cTemp] = 1;
        cTemp++;
    }

    cin >> temp;
    for (int i = 0; i < temp; i++)
    {
        oArr[cTemp] = 2;
        cTemp++;
    }

    cin >> temp;
    for (int i = 0; i < temp; i++)
    {
        oArr[cTemp] = 3;
        cTemp++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> nArr[i];
    }

    input();
    Dfs(0);

    cout << maxValue << endl
         << minValue << endl;

    return 0;
}
