//
// BACKTRACKING (4),
// NUMBER

// 중복을 포함한 모든 조합을 출력하므로 단순 재귀 함수를 사용하여 풀이함.

#include <iostream>
#include <cmath>
using namespace std;

#define endl "\n"

int n, output = 0;
int queenRow[15];

bool isPossible(int c)
{
    for (int i = 1; i < c; i++)
    {
        // 같은 행, 열
        if (queenRow[i] == queenRow[c])
        {
            return false;
        }
        // 대각선
        if (abs(queenRow[i] - queenRow[c]) == abs(i - c))
        {
            return false;
        }
    }
    return true;
}

void dfs(int row)
{
    if (row == n)
    {
        output++;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            queenRow[row + 1] = i;
            if (isPossible(row + 1))
            {
                dfs(row + 1);
            }
            else
            {
                queenRow[row + 1] = 0;
            }
        }
    }
    queenRow[row] = 0;
}

void loop()
{
    for (int i = 1; i <= n; i++)
    {
        for (int o = 0; o < 15; o++)
            queenRow[o] = 0;
        queenRow[1] = i;
        // 정점은 행을 기준. (i = 1) => 1행(1열), (i = 2) => 2행(1열), (i = 3) => 3행(1열)
        dfs(1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    loop();
    cout << output << endl;
    return 0;
}