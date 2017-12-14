#include <stdio.h>


typedef struct	s_counters
{
	int i;
	int count_x;
	int count_y;
	int count_hash;
	int tet_count;
}		t_counters;

t_counters	g_iters = { 0, 0, 0, 0, 0 };

extern t_counters	g_iters;

int main()
{
//	struct counters iters;


	int i;
	i = 7;
	while (i > 0)
	{
		g_iters.count_x++;
		i--;
	}

	printf("%dcount_x\n", g_iters.count_x);

	return (0);
}
