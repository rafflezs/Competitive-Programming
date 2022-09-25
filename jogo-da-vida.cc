#include <bits/stdc++.h>

int count_live_neighbour_cell(int a[][], int r, int c)
{
    int i, j, count = 0;
    for (i = r - 1; i <= r + 1; i++)
    {
        for (j = c - 1; j <= c + 1; j++)
        {
            if ((i == r && j == c) || (i < 0 || j < 0) || (i >= m || j >= n))
            {
                continue;
            }
            if (a[i][j] == 1)
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{

    int q = 1;
    while (true)
    {
        std::cin >> q;
        if (q != 0)
        {
            break;
        }
        int n, m;
        std::cin >> m >> n;
        
        int a[m][n];

        int i, j;
        int neighbour_live_cell;
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                a[i][j] = rand() % 2;
            }
        }

        for (int k = 0; k < q; k++)
        {
            for (i = 0; i < m; i++)
            {
                for (j = 0; j < n; j++)
                {
                    neighbour_live_cell = count_live_neighbour_cell(a, i, j);
                    if (a[i][j] == 1 && (neighbour_live_cell == 2 || neighbour_live_cell == 3))
                    {
                        b[i][j] = 1;
                    }

                    else if (a[i][j] == 0 && neighbour_live_cell == 3)
                    {
                        b[i][j] = 1;
                    }

                    else
                    {
                        b[i][j] = 0;
                    }
                }
            }
        }
    }
    return 0;
}