#include "substring.h"

int min (int a,int b)
{
    return a<b ? a:b;
}

void substr(const char*s,char* sub, int n, int l)
{
	const char *i = s;
	int sz ;
	while (*i != 0)
		i++;
	sz = i - s;
	if (n < 0)
		n += sz;
	if (l < 0)
	{
		n += (l + 1);
		l = abs(l);
	}
	if (n < 0)
	{
		l += n;
		n = 0;
	}
	int r =min(n + l - 1,sz-1);
	if (n > -1 && n<sz&&r>-1 && r < sz)
	{
		i = (s+n);
		for (; i < s + r + 1; i++,sub++)
		{
			*sub = *i;
		}

	}
	*sub = '\0';
	return;
}
