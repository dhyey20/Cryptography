#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<string.h>

int main()
{
	int key[3][3], i, j, k, l, n[3][1], m, len, t[3][1], ch;
	char msg[50], enc[50], temp[3];

	printf("enter the choise:-\n\t 1] Sender\n\t 2] Reciever\n");
	scanf("%d", &ch);

	if (ch == 1)
	{
		printf("SENDER SIDE:-\n\n");
		printf("enter the key matrix:-\n");
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				scanf("%d", &key[i][j]);
			}
		}


		printf("enter the plain text:- ");
		scanf("%s", msg);

		len = strlen(msg);
		if (len % 3 != 0)
		{
			l = len % 3;
			for (i = 1; i < l; i++)
			{
				strcat(msg, "x");
			}
		}

		printf("the message is :- %s\n\n", msg);
		len = strlen(msg);
		for (i = 0; i < len; i = i + 3)
		{
			for (j = 0; j < 3; j++)
			{
				temp[j] = msg[i + j];
				temp[j] = temp[j] - 97;
				t[j][0] = (int)temp[j];
				printf("%c %d\n", temp[j] + 97, t[j][0]);
			}

			for (j = 0; j < 3; j++)
			{
				printf("\t");
				for (k = 0; k < 1; k++)
				{
					n[j][k] = 0;
					for (m = 0; m < 3; m++)
					{
						n[j][k] += (key[j][m] * t[m][k]);
					}
					printf("%d mod 26 =  %d ", n[j][k], n[j][k] % 26);
					enc[j + i] = (char)(n[j][k] % 26) + 97;
				}
				printf("\n");
			}
			printf("\n");
		}

		printf("the encrypted text is:-\n");
		printf("%s", enc);

	}





	else
	{
		printf("RECIEVER SIDE:-\n\n");
		printf("enter the INVERSE key matrix:-\n");
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				scanf("%d", &key[i][j]);
			}
		}


		printf("enter the encrypted text:- ");
		scanf("%s", enc);

		len = strlen(enc);


		printf("the message is :- %s\n\n", enc);
		len = strlen(enc);
		for (i = 0; i < len; i = i + 3)
		{
			for (j = 0; j < 3; j++)
			{
				temp[j] = enc[i + j];
				temp[j] = temp[j] - 97;
				t[j][0] = (int)temp[j];
				printf("%c %d\n", temp[j] + 97, t[j][0]);
			}

			for (j = 0; j < 3; j++)
			{
				printf("\t");
				for (k = 0; k < 1; k++)
				{
					n[j][k] = 0;
					for (m = 0; m < 3; m++)
					{
						n[j][k] += (key[j][m] * t[m][k]);
					}
					printf("%d mod 26 =  %d ", n[j][k], n[j][k] % 26);
					msg[j + i] = (char)(n[j][k] % 26) + 97;
				}
				printf("\n");
			}
			printf("\n");
		}

		printf("the encrypted text is:-\n");
		for (i = 0; i < len; i++)
		{
			printf("%c", msg[i]);
		}
		j = 0;
		for (i = 0; i < 2; i++)
		{
			if (msg[len - i - 1] == 'x')
			{
				msg[len - i - 1] == NULL;
				j++;
			}

		}
		len = strlen(msg);
		printf("the final encrypted text is:-\n");
		for (i = 0; i < len - j - 1; i++)
		{
			printf("%c", msg[i]);
		}
	}


	getchar();
	getchar();

	return 0;
}
