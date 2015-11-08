#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>

void main()
{
	char msg[50], enc[50];
	int key, choice;
	int i;
	int x;

	printf("\n\t1] Sender:- \n\t2] Reciever:-");
	scanf("%d", &choice);

	if (choice == 1)
	{
		printf("Enter Plain text:");
		scanf("%s", msg);

		printf("\nEnter key:");
		scanf("%d", &key);
		key = key % 26;

		printf("encrypted text is:");

		for (i = 0; msg[i] != NULL; i++)
		{
			x = (int)msg[i] + key;

			if (x>'z')
			{
				x = x - 26;
			}

			enc[i] = (char)x;
			printf("%c", enc[i]);
		}
	}
	else
	{

		printf("Enter message Cipher Text:");
		scanf("%s", enc);

		printf("\nEnter key:");
		scanf("%d", &key);
		key = key % 26;

		printf("plain text is:");

		for (i = 0; enc[i] != NULL; i++)
		{
			x = (int)enc[i] - key;

			if (x<'a')
			{
				x = x + 26;
			}

			msg[i] = (char)x;
			printf("%c", msg[i]);
		}

	}
	getchar();
	getchar();
}