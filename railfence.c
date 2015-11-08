#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<string.h>

int main()
{
	char enc[50], msg[50], k;
	int i, j, m, n, ch, len = 0, key;

	printf("\n\t 1] Sender \n\t 2] Reciever \n\t");
	scanf("%d", &ch);


	if (ch == 1)
	{
		printf("\n\nenter the key:-");
		scanf("%d", &key);


		printf("\n\nenter the plain text:-");
		scanf("%s", msg);

		len = strlen(msg);
		if (len%key != 0)
		{
			m = len%key;
			for (i = 1; i < m; i++)
			{
				strcat(msg, "x");
			}
		}
		len = strlen(msg);
		for (i = 0; i < len; i++)
		{
			printf("%c ", msg[i]);
		}

		n = len / key;
		k = 0;

		for (j = 0; j < key; j++)
		{
			for (i = 0; i < len; i++)
			{
				if (i%key == j)
				{
					enc[k] = msg[i];
					k++;
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
		scanf("%d", &key);


		printf("\n\nenter the encrypted text:-");
		scanf("%s", enc);

		len = strlen(enc);
		n = len / key;

		k = 0;

		for (j = 0; j < n; j++)
		{
			for (i = 0; i < len; i++)
			{
				if (i%n == j)
				{
					msg[k] = enc[i];
					k++;
				}
			}
		}
		printf("\n\n");
		for (i = 0; i < len; i++)
		{
			printf("%c ", msg[i]);
		}
		len = strlen(msg);
		for (i = 0; i < n - 1; i++)
		{
			msg[len - i] = NULL;
		}
		printf("\n\n");
		for (i = 0; i < len; i++)
		{
			printf("%c ", msg[i]);
		}
	}


	getchar();
	return 0;
}
