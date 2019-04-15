#include <cstdio>
#include <vector>

using namespace std;

bool odw[1000011];
vector<int>ls[1000011];

void odwiedz(int w)
{
    odw[w] = true;
    for (int i = 0; i < ls[w].size(); ++i)
        if (!odw[ls[w][i]])
          odwiedz(ls[w][i]);
}

void dfs(int n)
{
    for (int i = 1; i <= n; ++i)
        odw[i] = false;
    odwiedz(1);
}

int main()
{
    int n, a, k;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a);
        k = min(i+a, n);
        for (int j = i+1; j <= k; ++j)
            ls[i].push_back(j);
    }
    dfs(n);
    if (odw[n])
        printf("tak");
    else
        printf("nie");
}
