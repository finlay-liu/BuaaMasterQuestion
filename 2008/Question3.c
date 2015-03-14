#include <stdio.h>
#include <string.h>
#define MAXN 1000 +10
char a[MAXN][MAXN];
char  s[MAXN];

int cmpch(char a, char b)
{
    if (a >= '0' && a <= '9' && a == b)
        return 1;
    else if (a >= 'a' && a <= 'z' && (a == b || (a + 'A' - 'a') == b) )
        return 1;
    else if (a >= 'A' && a <= 'Z' && (a == b || (a + 'a' - 'A') == b))
        return 1;
    else
        return 0;
}

int main()
{
    int n, i, j, m, k, mark, len;
    while(scanf("%d", &n) == 1)
    {
        for(i = 0; i < n; i++)
            scanf("%s", a[i]);
        scanf("%s", s);
        m = strlen(s);

        for(i = 0; i < n; i++)
        {
            len = strlen(a[i]);
            for(j = 0, k = 0; j < len, k < m; j++, k++)
            {
                if(cmpch(a[i][j], s[k]))
                    continue;
                else
                {
                    if(s[k] != '[')
                        goto out;
                    else
                    {
                        mark = 0;
                        k = k + 1;
                        while(s[k] != ']')
                        {
                            if(cmpch(a[i][j], s[k]))
                                mark = 1;
                            k++;
                        }
                        if(mark == 0)
                            goto out;
                    }
                }
            }
out:
            if((j == len) && (k == m))
                printf("%d %s\n", i + 1, a[i]);
        }
    }
    return 0;
}
