#include <stdio.h>
#include <string.h>
    //char s[5] = {'A', 'B', 'C', 'D', 'E'};
int max(int a, int b)
{
    return a > b ? a : b;
}

int LCS(char *s1, char *s2, int i, int j)
{
    int c;
    if(i == 0 || j == 0) return 0;
    if(s1[i] == s2[j]) {
        c = LCS(s1, s2, i-1, j-1) + 1;
    } else {
        int c1 = LCS(s1, s2, i-1, j);
        int c2 = LCS(s1, s2, i, j-1);
        c = max(c1, c2); 
    }
    return c;
}

int extend_LCS_aux(char *s1, char *s2, int m, int n, int **c)
{
    if(c[m][n] == -1) {
        if(m == 0 || n == 0) c[m][n] = 0;
        else if(s1[m] == s2[n]) {
            c[m][n] = extend_LCS_aux(s1, s2, m-1, n-1, c) + 1;
        } else {
            int c1 = extend_LCS_aux(s1, s2, m-1, n, c);
            int c2 = extend_LCS_aux(s1, s2, m, n-1, c);
            c[m][n] = max(c1, c2);
        }
    }
    return c[m][n];
}
int extend_LCS(char *s1, char *s2, int m, int n)
{
    int i, j;
    int **c = (int **) malloc(m * sizeof(int *));
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            c[i][j] = -1;
        }
    }
    return extend_LCS_aux(s1, s2, m, n, c);
}
void main()
{
    char *s1 = "AFBBCFWS";
    char *s2 = "ABCFDDDDRWSSSS";

    int l1 = strlen(s1);
    int l2 = strlen(s2);
    //int lcs = LCS(s1, s2, l1-1, l2-1);
    int lcs = extend_LCS(s1, s2, l1-1, l2-1);
    printf("%s\n%s\n lenght = %d\n", s1, s2, lcs);
    /*
    int i, j;
    i = 0;
    j = 0;
    while(i < strlen(s1) && j < strlen(s2)) {
        if(s1[i] == s2[j]) j++;
        i++;
    }
    if(j == strlen(s2))printf("YES!\n");
    else printf("NO!\n");
    */
}
