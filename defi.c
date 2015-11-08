#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<math.h>

int main()
{
	int q, a, xa, xb, k1, k2, i, ya, yb;
	double m, n;
	int x, y;

	printf("enter the value of q and a :- \n");
	scanf("%d", &q);
	scanf("%d", &a);

	for (i = q - 1; i>0; i--)
	{
		if (i*i<q)
		{
			xa = 2;
			break;
		}
	}
	printf("\n xa = %d", xa);

	for (i = q - 1; i>0; i--)
	{
		if ((i + i)<q)
		{
			xb = 3;
			break;
		}
	}
	printf("\n xb = %d", xb);
	m = 1;
	n = 1;
	ya = (int)pow(a, xa) % q;
	yb = (int)pow(a, xb) % q;
	printf("\n ya = %d\n yb = %d", ya, yb);

	m = 1;
	n = 1;
	k1 = (int)pow(yb, xa) % q;
	k2 = (int)pow(ya, xb) % q;
	printf("\n\nthe values are :- \n k1 = %d\n k2 = %d", k1, k2);
	getchar();
	getchar();
	return 0;
}
