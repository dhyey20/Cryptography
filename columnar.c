#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<string.h>

int main()
{
	char pt[100], ct[100];
	char temp[10][10], inter[10][10];
	int key[10], ch, i, j, l, lp, row, k, z;

	printf("\n1]Sender\n2] Receiver\nEnter the choice:");
	scanf("%d", &ch);

	if (ch == 1)
	{
		printf("\nEnter Plain Text:");
		scanf("%s", pt);
		lp = strlen(pt);
		printf("\nEnter length of key:");
		scanf("%d", &l);
		printf("\nEnter key:");
		for (i = 0; i < l; i++)
		{
			scanf("%d", &key[i]);
		}
		if (lp%l != 0)
		{
			while (lp%l != 0)
			{
				lp++;
				pt[lp - 1] = 'x';
			}
		}
		row = lp / l;
		k = 0;
		for (i = 0; i < row; i++)
		{
			for (j = 0; j < l; j++)
			{
				temp[i][j] = pt[k];
				printf(" %c ", pt[k]);
				k++;
			}
			printf("\n");
		}

		for (i = 0; i < lp; i++)
		{
			for (j = 1; j <= l; j++)
			{
				k = 0;
				while (key[k] != j)
				{
					k++;
				}
				for (z = 0; z < row; z++)
				{
					ct[i] = temp[z][k];
					i++;
				}
			}
		}
		printf("\nCipher:");
		for (i = 0; i < lp; i++)
		{
			printf("%c ", ct[i]);
		}
	}

	else if (ch == 2)
	{
		printf("\nEnter cipher text:");
		scanf("%s", ct);
		lp = strlen(ct);

		printf("\nEnter length of key:");
		scanf("%d", &l);

		printf("\nEnter the key:");
		for (i = 0; i < l; i++)
		{
			scanf("%d", &key[i]);
		}

		row = lp / l;
		k = 0;
		for (i = 0; i < lp; i++)
		{
			for (j = 0; j < l; j++)
			{
				for (z = 0; z < row; z++)
				{

					temp[z][j] = ct[i];
					i++;
				}
			}
		}

		for (i = 0; i < row; i++)
		{
			for (j = 0; j < l; j++)
			{
				printf("%c", temp[i][j]);
			}
			printf("\n");
		}



		for (k = 0; k < row; k++)
		{
			for (i = 1; i <= l; i++)
			{

				for (j = 0; j < l; j++)
				{

					if (key[j] == i)
					{
						inter[k][j] = temp[k][i - 1];
					}
				}

			}
		}
		z = 0;
		for (i = 0; i < row; i++)
		{
			for (j = 0; j < l; j++)
			{
				pt[z] = inter[i][j];
				z++;
			}
		}
		printf("\nPlain text:");
		for (i = 0; i < lp; i++)
		{
			printf("%c", pt[i]);
		}



	}


	else
	{
		printf("\nInvalid choice......");
	}

	getchar();
	return 0;

}
