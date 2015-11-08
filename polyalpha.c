#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<string.h>

int main()
{
	char pa[26][26], key[4], enc[50], msg[50], k, ikey[50];
	int i, j, m, n, ch, len;

	printf("\n\t 1] Sender \n\t 2] Reciever \n\t");
	scanf("%d", &ch);


	for (i = 0; i < 26; i++)
	{
		printf("\t");
		for (j = 0; j < 26; j++)
		{
			k = ((i + j) % 26) + 97;
			pa[i][j] = k;
			printf("%c ", k);
		}
		printf("\n");
	}

	if (ch == 1)
	{

		printf("\n\nenter the key:-");
		scanf("%s", key);



		printf("\n\nenter the plain text:-");
		scanf("%s", msg);

		len = strlen(msg);
		printf("\n\n the message with key is:-\n\n");
		printf("\t");
		for (i = 0; i < len; i++)
		{
			printf("%c ", msg[i]);
		}
		printf("\n\t");
		for (i = 0; i < len; i++)
		{
			ikey[i] = key[i % 4];
			printf("%c ", key[i % 4]);
		}

		printf("\n\n\t");
		for (j = 0; j < len; j++)
		{
			for (i = 0; i < 26; i++)
			{
				if (msg[j] == pa[0][i])
				{
					for (m = 0; m < 26; m++)
					{
						if (ikey[j] == pa[m][0])
						{
							enc[j] = pa[m][i];
							printf("%c ", enc[j]);
						}
					}
				}
			}
		}
		printf("\n\n");
		for (i = 0; i < len; i++)
		{
			printf("%c ", enc[i]);
		}


	}

	else
	{
		printf("\n\nenter the key:-");
		scanf("%s", key);


		printf("\n\nenter the encrypted text:-");
		scanf("%s", enc);

		len = strlen(enc);
		printf("\n\n the message with key is:-\n\n");
		printf("\t");
		for (i = 0; i < len; i++)
		{
			printf("%c ", enc[i]);
		}
		printf("\n\t");
		for (i = 0; i < len; i++)
		{
			ikey[i] = key[i % 4];
			printf("%c ", key[i % 4]);
		}

		printf("\n\n\t");

		for (j = 0; j < len; j++)
		{
			for (i = 0; i < 26; i++)
			{
				if (ikey[j] == pa[i][0])
				{
					for (m = 0; m < 26; m++)
					{
						if (enc[j] == pa[i][m])
						{
							msg[j] = pa[0][m];
							printf("%c ", msg[j]);
						}
					}
				}
			}
		}
		printf("\n\n");

		for (i = 0; i < len; i++)
		{
			printf("%c ", msg[i]);
		}

	}

	getchar();
	getchar();
	return 0;
}
