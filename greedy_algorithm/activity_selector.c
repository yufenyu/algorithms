#include <stdio.h>
#define N 11
int cursor = 0;
int res[N];
void recursive_activity_selector(int *s, int *f, int k, int n);
void greedy_activity_selector(int *s, int *f);
int main()
{
	int S[N+1] = {0, 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
	int F[N+1] = {0, 4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};
	//recursive_activity_selector(S, F, 0, N);
	greedy_activity_selector(S, F);
	int i;
	for(i = 0; i < cursor; i++)
		printf("%d ", S[res[i]]);
	printf("\n");
	for(i = 0; i < cursor; i++)
		printf("%d ", F[res[i]]);
	
	printf("\n");
}
void recursive_activity_selector(int *s, int *f, int k, int n)
{
	int m = k + 1;
	while(s[m] < f[k]) m++;
	if(m <= n) {
		res[cursor++] = m;
		recursive_activity_selector(s, f, m, n);
	}
}
void greedy_activity_selector(int *s, int *f)
{
	int k = 0, m;
	while(k <= N)
	{
		m = k + 1;
		while(s[m] < f[k]) m++;
		if(m <= N) {
			res[cursor++] = m;
		}
		k = m;
	}

}
