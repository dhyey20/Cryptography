#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<string.h>

int main()
{
	char key[5][5], msg[50], enc[50], ks[26], temp[50];
	int i, j, k, ti, tj, ui, uj, m = 0, len, z, choice;

	printf("1.Sender\n2.Receiver:\n");
	scanf("%d", &choice);

	strcpy(ks, "cryptoghabdefiklmnqsuvwxz");
	for (i = 0; i<5; i++)
	{
		for (j = 0; j<5; j++)
		{
			key[i][j] = ks[m];
			m++;
		}
	}

	printf("the key table is\n");

	for (i = 0; i<5; i++)
	{
		for (j = 0; j<5; j++)
		{
			printf("\t%c", key[i][j]);
		}
		printf("\n\n");
	}
	if (choice == 1)
	{

		printf("\n\n enter the plain text:-");
		scanf("%s", msg);

		len = strlen(msg);
		for (i = 0; i<len; i++)
		{
			if (msg[i] == 'j')
			{
				msg[i] = 'i';
			}
		}
		printf("\n\n\tlength is:-%d\n\n\n", len);

		for (i = 0; i<len; i++)
		{
			if (i % 2 == 0 && msg[i] == msg[i + 1])
			{
				len++;
				for (j = len; j>i; j--)
				{
					msg[j] = msg[j - 1];
				}
				msg[i + 1] = 'x';
			}
		}
		if (len % 2 != 0)
		{
			len++;
			strcat(msg, "x");
		}
		len = strlen(msg);
		printf("After adding fillers:%s\n", msg);
		z = 0;
		ti = 0;
		tj = 0;
		ui = 0;
		uj = 0;
		printf("\nFrom the key table:");
		for (k = 0; k<len; k = k + 2)
		{

			for (i = 0; i<5; i++)//key row
			{

				for (j = 0; j<5; j++)//key column
				{
					if (msg[k] == key[i][j])
					{
						ti = i;
						tj = j;
					}
					if (msg[k + 1] == key[i][j])
					{
						ui = i;
						uj = j;
					}

				}


			}
			if (ti == ui)//same row
			{
				tj++;
				if (tj>5)
				{
					tj = tj % 5;
				}
				uj++;
				if (uj>5)
				{
					uj = uj % 5;
				}
				enc[k] = key[ti][tj];
				enc[k + 1] = key[ui][uj];
			}
			else if (tj == uj)//same col
			{
				ti++;
				ui++;
				if (ti>5)
				{
					ti = ti % 5;
				}
				if (ui>5)
				{
					ui = ui % 5;
				}
				enc[k] = key[ti][tj];
				enc[k + 1] = key[ui][uj];
			}
			else//nothing same
			{
				enc[k] = key[ti][uj];
				enc[k + 1] = key[ui][tj];
			}
			printf(" %c %c\t", enc[k], enc[k + 1]);
		}


		printf("\n\nCipher:%s", enc);
	}//end sender
	else if (choice == 2)//receiver
	{
		printf("\n\n enter the cipher text:-");
		scanf("%s", enc);

		len = strlen(enc);

		ti = 0;
		tj = 0;
		ui = 0;
		uj = 0;
		printf("\nFrom the key table:");
		for (k = 0; k<len; k = k + 2)
		{

			for (i = 0; i<5; i++)//key row
			{

				for (j = 0; j<5; j++)//key column
				{
					if (enc[k] == key[i][j])
					{
						ti = i;
						tj = j;
					}
					if (enc[k + 1] == key[i][j])
					{
						ui = i;
						uj = j;
					}

				}


			}
			if (ti == ui)//same row
			{
				tj--;
				if (tj<0)
				{
					tj = tj + 5;
				}
				uj--;
				if (uj<5)
				{
					uj = uj + 5;
				}
				msg[k] = key[ti][tj];
				msg[k + 1] = key[ui][uj];
			}
			else if (tj == uj)//same col
			{
				ti--;
				ui--;
				if (ti<0)
				{
					ti = ti + 5;
				}
				if (ui<0)
				{
					ui = ui + 5;
				}
				msg[k] = key[ti][tj];
				msg[k + 1] = key[ui][uj];
			}
			else//nothing same
			{
				msg[k] = key[ti][uj];
				msg[k + 1] = key[ui][tj];
			}
			printf(" %c %c\t", msg[k], msg[k + 1]);
		}


		printf("\n\nPlain Text:%s", msg);
	}
	else
	{
		printf("Invalid Choice");
	}

	getchar();
	getchar();
}
