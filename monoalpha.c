#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>

void main()
{
	char key[26], msg[50], enc[50];
	char comp[26];
	int i, j, choice;
	char x;


	for (i = 0; i < 26; i++)
	{
		comp[i] = 97 + i;
	}
	printf("\t1. Sender\n\t2. Receiver\n");
	scanf("%d", &choice);
	if (choice == 1)
	{
		printf("enter plain text : ");
		scanf("%s", msg);

		printf("enter the key :");
		scanf("%s", key);

		for (i = 0; msg[i] != NULL; i++)
		{
			j = 0;
			while (msg[i] != comp[j])
			{
				j++;
			}
			enc[i] = key[j];
			printf("%c", enc[i]);
		}
	}
	else
	{
		printf("enter encrypted text:");
		scanf("%s", enc);

		printf("enter the key:");
		scanf("%s", key);

		for (i = 0; enc[i] != NULL; i++)
		{
			j = 0;
			while (enc[i] != key[j])
			{
				j++;
			}
			msg[i] = comp[j];
			printf("%c", msg[i]);
		}

	}
	getchar();
	getchar();
}


