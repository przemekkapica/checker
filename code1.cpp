#include <cstdio>
#include <algorithm>

using namespace std;

int k[1000011];

int main()
{
    int n, a, cur;
    cur = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        k[i] = 0;
    scanf("%d", &a);
    if (a == 0)
    {
        printf("nie");
        return 0;
    }
    k[1+a] = 1;
    for (int i = 2; i <= n; ++i)
    {
        scanf("%d", &a);
        if (!cur)
        {
            printf("nie");
            return 0;
        }
        k[min(n, i+a)]++;
        cur = cur + 1 - k[i];
    }
    printf("tak");
}
