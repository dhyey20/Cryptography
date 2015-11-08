#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>


int main()
{
	int p, q, n, r, e, d, i, j, k, count = 0, a[50], flag = 0, f = 0, ch;

	printf("enter p and q:-\n");
	scanf("%d", &p);
	scanf("%d", &q);
	printf("\n\n\t1] e is given\n\n\t2] e is not given:-");
	scanf("%d", &ch);

	for (i = 2; i<p - 1; i++)
	{
		if (p%i == 0)
		{
			printf("p is not prime....");
			count = 1;
			break;
		}
	}
	if (count == 0)
	{
		for (i = 2; i<q - 1; i++)
		{
			if (q%i == 0)
			{
				printf("q is not prime....");
				count = 2;
				break;
			}
		}
	}

	if (count == 0)
	{
		n = p*q;
		printf("\n\n n = p * q = %d * %d = %d", p, q, n);

		r = (p - 1)*(q - 1);
		printf("\n\n r = (p-1) * (q-1) = (%d-1) * (%d-1) = %d", p, q, r);

		j = -1;
		for (i = 1; i<r; i++)
		{
			if (r%i == 0)
			{
				j++;
				a[j] = i;
			}
		}

		printf("\n\n gcd are:-\n");
		for (i = 0; i <= j; i++)
		{
			printf("%d  ", a[i]);
		}

		if (ch == 2)
		{
			for (i = 2; i<r; i++)
			{
				flag = 0;
				for (k = 0; k<j; k++)
				{
					if (a[k] == i)
					{
						flag = 1;
						break;
					}
				}

				if (flag == 0)
				{
					e = i;
					break;
				}

			}
		}
		else
		{
			printf("\n\n enter the value of e :- ");
			scanf("%d", &e);
		}
		printf("\n\n gcd(e,%d) = 1 \n\n so the e is = %d", r, e);

		for (i = r;; i = i + r)
		{
			if ((i + 1) % e == 0)
			{
				d = (i + 1) / e;
				break;
			}
		}

		printf("\n\n the d is :- %d", d);

		printf("\n\nthe public key is:- (%d,%d)", e, n);
		printf("\n\nthe private key is:- (%d,%d)", d, n);

	}

	getchar();
	getchar();
	return 0;
}
