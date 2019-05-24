#include "functions.h"
#include <cstdio>
#include <vector>

void swap_min(int** a, int n, int m)
{
    pair<int, int> ans = {a[0][0], 0};
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            ans = min(ans, {a[i][j], i});
        }
    }
    swap(a[0], a[ans.second]);
}
