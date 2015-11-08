#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<string.h>

int main()
{
	char ip[8], key[10], ls1[10], k1[8], k2[8], t[10], temp, ls2[10], ipt[8], ti[8], op[8];
	char p10[10] = { 3, 5, 2, 7, 4, 10, 1, 9, 8, 6 }, p8[8] = { 6, 3, 7, 4, 8, 5, 10, 9 }, in[8] = { 2, 6, 3, 1, 4, 8, 5, 7 }, p4[4] = { 2, 4, 3, 1 }, ipi[8] = { 4, 1, 3, 5, 7, 2, 8, 6 };
	int s0[4][4] = { { 1, 0, 3, 2 }, { 3, 2, 1, 0 }, { 0, 2, 1, 3 }, { 3, 1, 3, 2 } };
	int s1[4][4] = { { 0, 1, 2, 3 }, { 2, 0, 1, 3 }, { 3, 0, 1, 0 }, { 2, 1, 0, 3 } };
	int i, j, p = 0, q = 0, ch;

	printf("\nenter the key:-\n");
	scanf("%s", key);

	printf("\n\napplying p10:-\n");           //p10 logic
	for (i = 0; i<10; i++)
	{
		temp = p10[i];
		t[i] = key[temp - 1];
		printf("%c ", t[i]);
	}
	printf("\n\napplying ls-1 :-"); 			//ls-1 logic
	for (i = 0; i<5; i++)							//1st 5 bitts
	{
		if (i == 0)
		{
			temp = t[i];
			ls1[i] = t[(i + 1) % 5];
			continue;
		}
		if (i == 4)
		{
			ls1[i] = temp;
			continue;
		}
		ls1[i] = t[(i + 1) % 5];
	}

	for (i = 5; i<10; i++)							//2nd 5 bits
	{
		if (i == 5)
		{
			temp = t[i];
			ls1[i] = t[((i + 1) % 5) + 5];
			continue;
		}
		if (i == 9)
		{
			ls1[i] = temp;
			continue;
		}
		ls1[i] = t[((i + 1) % 5) + 5];
	}
	printf("\nthe ls-1 is:-\n %s", ls1);

	printf("\n\napplying ls-2 :-"); 			//ls-2 logic

	for (i = 0; i<5; i++)							//1st 5 bitts
	{
		if (i == 0)
		{
			temp = ls1[i];
			ls2[i] = ls1[(i + 1) % 5];
			continue;
		}
		if (i == 4)
		{
			ls2[i] = temp;
			continue;
		}
		ls2[i] = ls1[(i + 1) % 5];
	}

	for (i = 5; i<10; i++)							//2nd 5 bits
	{
		if (i == 5)
		{
			temp = ls1[i];
			ls2[i] = ls1[((i + 1) % 5) + 5];
			continue;
		}
		if (i == 9)
		{
			ls2[i] = temp;
			continue;
		}
		ls2[i] = ls1[((i + 1) % 5) + 5];
	}


	for (i = 0; i<5; i++)							//1st 5 bitts again
	{
		if (i == 0)
		{
			temp = ls2[i];
			ls2[i] = ls2[(i + 1) % 5];
			continue;
		}
		if (i == 4)
		{
			ls2[i] = temp;
			continue;
		}
		ls2[i] = ls2[(i + 1) % 5];
	}

	for (i = 5; i<10; i++)							//2nd 5 bits again
	{
		if (i == 5)
		{
			temp = ls2[i];
			ls2[i] = ls2[((i + 1) % 5) + 5];
			continue;
		}
		if (i == 9)
		{
			ls2[i] = temp;
			continue;
		}
		ls2[i] = ls2[((i + 1) % 5) + 5];
	}

	printf("\nthe ls-2 is:-\n %s", ls2);

	printf("\n\napplying p8 to ls-1 for k1:-\n");           //p8 logic k1
	for (i = 0; i<8; i++)
	{
		temp = p8[i];
		k1[i] = ls1[temp - 1];
		printf("%c ", k1[i]);
	}

	printf("\n\napplying p8 ls-2 for k2:-\n");           //p8 logic k2
	for (i = 0; i<8; i++)
	{
		temp = p8[i];
		k2[i] = ls2[temp - 1];
		printf("%c ", k2[i]);
	}

	printf("enter the choise:-\n\t 1] Sender\n\t 2] Reciever\n");
	scanf("%d", &ch);
	if (ch == 1)
	{

		printf("enter the ip:-\n");
		scanf("%s", ip);

		printf("\n\napplying IP-Initial Permutation :-\n");           //Initial Permutation
		for (i = 0; i<8; i++)
		{
			temp = in[i];
			ipt[i] = ip[temp - 1];
			printf("%c ", ipt[i]);
		}

		printf("\n\napplying EP- Permutation :-\n");           //EP
		for (i = 0; i<4; i++)
		{
			t[i] = ipt[((i + 3) % 4) + 4];
			printf("%c ", t[i]);
		}
		for (i = 4; i<8; i++)
		{
			t[i] = ipt[((i - 3) % 4) + 4];
			printf("%c ", t[i]);
		}
		printf("\n\napplying XOR :-\n");           //XOR between k1 and EP
		for (i = 0; i<8; i++)
		{
			ti[i] = (int)t[i] ^ (int)k1[i];
			printf("%c ", ti[i] + 48);
		}





		for (i = 0; i<10; i++)
		{
			t[i] = NULL;
		}





		for (i = 0; i<8; i = i + 4)							// S0 and S1 logic
		{
			if (ti[0 + i] == 0)
			{
				if (ti[3 + i] == 0)
				{
					p = 0;
				}
				else
				{
					p = 1;
				}
			}
			else
			{
				if (ti[3 + i] == 0)
				{
					p = 2;
				}
				else
				{
					p = 3;
				}
			}

			if (ti[1 + i] == 0)
			{
				if (ti[2 + i] == 0)
				{
					q = 0;
				}
				else
				{
					q = 1;
				}
			}
			else
			{
				if (ti[2 + i] == 0)
				{
					q = 2;
				}
				else
				{
					q = 3;
				}
			}
			printf("\np = %d", p);
			printf("\nq = %d", q);
			if (i == 0)
			{
				switch (s0[p][q])
				{
				case 0:
					strcat(t, "0");
					strcat(t, "0");
					break;

				case 1:
					strcat(t, "0");
					strcat(t, "1");
					break;

				case 2:
					strcat(t, "1");
					strcat(t, "0");
					break;

				case 3:
					strcat(t, "1");
					strcat(t, "1");
					break;

				default:
					printf("nothing");
				}
			}
		}
		switch (s1[p][q])
		{
		case 0:
			strcat(t, "0");
			strcat(t, "0");
			break;

		case 1:
			strcat(t, "0");
			strcat(t, "1");
			break;

		case 2:
			strcat(t, "1");
			strcat(t, "0");
			break;

		case 3:
			strcat(t, "1");
			strcat(t, "1");
			break;

		default:
			printf("nothing");
		}


		printf("\n\nbefore p4:- \n%s\n", t);

		printf("\n\napplying P4 :-\n");   		//p4 logic
		for (i = 0; i<4; i++)
		{
			temp = p4[i];
			t[i + 4] = t[temp - 1];
			printf("%c ", t[i + 4]);
		}


		for (i = 0; i<8; i++)
		{
			ti[i] = NULL;
		}

		printf("\n\napplying XOR :-\n");           //XOR between p4 and l
		for (i = 0; i<4; i++)
		{
			ti[i + 4] = (int)t[i + 4] ^ (int)ipt[i];
			ti[i + 4] = ti[i + 4] + 48;
			//printf("%c ",ti[i+4]);
		}
		printf("\n\n\n\n");
		for (i = 4; i<8; i++)
		{
			ti[i - 4] = ipt[i];
			//printf("%c ",ti[i-4]);
		}

		for (i = 0; i<8; i++)
		{
			ipt[i] = ti[i];
			printf("%c ", ti[i]);
		}





		printf("\n\n\n\n\n\n\nthe second pass now:----------------------------------\n\n\n\n\n\n\n");











		for (i = 0; i<10; i++)
		{
			t[i] = NULL;
		}





		printf("\n\napplying EP- Permutation :-\n");           //EP
		for (i = 0; i<4; i++)
		{
			t[i] = ipt[((i + 3) % 4) + 4];
			printf("%c ", t[i]);
		}
		for (i = 4; i<8; i++)
		{
			t[i] = ipt[((i - 3) % 4) + 4];
			printf("%c ", t[i]);
		}
		printf("\n\napplying XOR :-\n");           //XOR between k1 and EP
		for (i = 0; i<8; i++)
		{
			ti[i] = (int)t[i] ^ (int)k2[i];
			printf("%c ", ti[i] + 48);
		}





		for (i = 0; i<10; i++)
		{
			t[i] = NULL;
		}





		for (i = 0; i<8; i = i + 4)							// S0 and S1 logic
		{
			if (ti[0 + i] == 0)
			{
				if (ti[3 + i] == 0)
				{
					p = 0;
				}
				else
				{
					p = 1;
				}
			}
			else
			{
				if (ti[3 + i] == 0)
				{
					p = 2;
				}
				else
				{
					p = 3;
				}
			}

			if (ti[1 + i] == 0)
			{
				if (ti[2 + i] == 0)
				{
					q = 0;
				}
				else
				{
					q = 1;
				}
			}
			else
			{
				if (ti[2 + i] == 0)
				{
					q = 2;
				}
				else
				{
					q = 3;
				}
			}
			printf("\np = %d", p);
			printf("\nq = %d", q);
			if (i == 0)
			{
				switch (s0[p][q])
				{
				case 0:
					strcat(t, "0");
					strcat(t, "0");
					break;

				case 1:
					strcat(t, "0");
					strcat(t, "1");
					break;

				case 2:
					strcat(t, "1");
					strcat(t, "0");
					break;

				case 3:
					strcat(t, "1");
					strcat(t, "1");
					break;

				default:
					printf("nothing");
				}
			}
		}
		switch (s1[p][q])
		{
		case 0:
			strcat(t, "0");
			strcat(t, "0");
			break;

		case 1:
			strcat(t, "0");
			strcat(t, "1");
			break;

		case 2:
			strcat(t, "1");
			strcat(t, "0");
			break;

		case 3:
			strcat(t, "1");
			strcat(t, "1");
			break;

		default:
			printf("nothing");
		}


		printf("\n\nbefore p4:- \n%s\n", t);

		printf("\n\napplying P4 :-\n");   		//p4 logic
		for (i = 0; i<4; i++)
		{
			temp = p4[i];
			t[i + 4] = t[temp - 1];
			printf("%c ", t[i + 4]);
		}


		for (i = 0; i<8; i++)
		{
			ti[i] = NULL;
		}

		printf("\n\napplying XOR :-\n");           //XOR between p4 and l
		for (i = 0; i<4; i++)
		{
			ti[i] = (int)t[i + 4] ^ (int)ipt[i];
			ti[i] = ti[i] + 48;
			//printf("%c ",ti[i+4]);
		}
		printf("\n\n\n\n");
		for (i = 4; i<8; i++)
		{
			ti[i] = ipt[i];
			//printf("%c ",ti[i-4]);
		}

		for (i = 0; i<8; i++)
		{
			ipt[i] = ti[i];
			printf("%c ", ti[i]);
		}


		printf("\n\napplying IP^-1  :-\n\n");
		for (i = 0; i<8; i++)
		{
			temp = ipi[i];
			op[i] = ti[temp - 1];
			printf("%c ", op[i]);
		}
	}
	//-------------------------------------------------------------------------------------------------------------------------------
	else
	{
		printf("enter the op:-\n");
		scanf("%s", ip);

		printf("\n\napplying IP-Initial Permutation :-\n");           //Initial Permutation
		for (i = 0; i<8; i++)
		{
			temp = in[i];
			ipt[i] = ip[temp - 1];
			printf("%c ", ipt[i]);
		}

		printf("\n\napplying EP- Permutation :-\n");           //EP
		for (i = 0; i<4; i++)
		{
			t[i] = ipt[((i + 3) % 4) + 4];
			printf("%c ", t[i]);
		}
		for (i = 4; i<8; i++)
		{
			t[i] = ipt[((i - 3) % 4) + 4];
			printf("%c ", t[i]);
		}
		printf("\n\napplying XOR :-\n");           //XOR between k1 and EP
		for (i = 0; i<8; i++)
		{
			ti[i] = (int)t[i] ^ (int)k2[i];
			printf("%c ", ti[i] + 48);
		}





		for (i = 0; i<10; i++)
		{
			t[i] = NULL;
		}





		for (i = 0; i<8; i = i + 4)							// S0 and S1 logic
		{
			if (ti[0 + i] == 0)
			{
				if (ti[3 + i] == 0)
				{
					p = 0;
				}
				else
				{
					p = 1;
				}
			}
			else
			{
				if (ti[3 + i] == 0)
				{
					p = 2;
				}
				else
				{
					p = 3;
				}
			}

			if (ti[1 + i] == 0)
			{
				if (ti[2 + i] == 0)
				{
					q = 0;
				}
				else
				{
					q = 1;
				}
			}
			else
			{
				if (ti[2 + i] == 0)
				{
					q = 2;
				}
				else
				{
					q = 3;
				}
			}
			printf("\np = %d", p);
			printf("\nq = %d", q);
			if (i == 0)
			{
				switch (s0[p][q])
				{
				case 0:
					strcat(t, "00");
					break;

				case 1:
					strcat(t, "01");
					break;

				case 2:
					strcat(t, "10");
					break;

				case 3:
					strcat(t, "11");
					break;

				default:
					printf("nothing");
				}
			}
		}

		switch (s1[p][q])
		{
		case 0:
			strcat(t, "00");
			break;

		case 1:
			strcat(t, "01");
			break;

		case 2:
			strcat(t, "10");
			break;

		case 3:
			strcat(t, "11");
			break;

		default:
			printf("nothing");
		}


		printf("\n\nbefore p4:- \n%s\n", t);

		printf("\n\napplying P4 :-\n");   		//p4 logic
		for (i = 0; i<4; i++)
		{
			temp = p4[i];
			t[i + 4] = t[temp - 1];
			printf("%c ", t[i + 4]);
		}


		for (i = 0; i<8; i++)
		{
			ti[i] = NULL;
		}

		printf("\n\napplying XOR :-\n");           //XOR between p4 and l
		for (i = 0; i<4; i++)
		{
			ti[i + 4] = (int)t[i + 4] ^ (int)ipt[i];
			ti[i + 4] = ti[i + 4] + 48;
			//printf("%c ",ti[i+4]);
		}
		printf("\n\n\n\n");
		for (i = 4; i<8; i++)
		{
			ti[i - 4] = ipt[i];
			//printf("%c ",ti[i-4]);
		}

		for (i = 0; i<8; i++)
		{
			ipt[i] = ti[i];
			printf("%c ", ti[i]);
		}





		printf("\n\n\n\n\n\n\nthe second pass now:----------------------------------\n\n\n\n\n\n\n");











		for (i = 0; i<10; i++)
		{
			t[i] = NULL;
		}





		printf("\n\napplying EP- Permutation :-\n");           //EP
		for (i = 0; i<4; i++)
		{
			t[i] = ipt[((i + 3) % 4) + 4];
			printf("%c ", t[i]);
		}
		for (i = 4; i<8; i++)
		{
			t[i] = ipt[((i - 3) % 4) + 4];
			printf("%c ", t[i]);
		}
		printf("\n\napplying XOR :-\n");           //XOR between k1 and EP
		for (i = 0; i<8; i++)
		{
			ti[i] = (int)t[i] ^ (int)k1[i];
			printf("%c ", ti[i] + 48);
		}





		for (i = 0; i<10; i++)
		{
			t[i] = NULL;
		}





		for (i = 0; i<8; i = i + 4)							// S0 and S1 logic
		{
			if (ti[0 + i] == 0)
			{
				if (ti[3 + i] == 0)
				{
					p = 0;
				}
				else
				{
					p = 1;
				}
			}
			else
			{
				if (ti[3 + i] == 0)
				{
					p = 2;
				}
				else
				{
					p = 3;
				}
			}

			if (ti[1 + i] == 0)
			{
				if (ti[2 + i] == 0)
				{
					q = 0;
				}
				else
				{
					q = 1;
				}
			}
			else
			{
				if (ti[2 + i] == 0)
				{
					q = 2;
				}
				else
				{
					q = 3;
				}
			}
			printf("\np = %d", p);
			printf("\nq = %d", q);
			if (i == 0)
			{
				switch (s0[p][q])
				{
				case 0:
					strcat(t, "00");
					break;

				case 1:
					strcat(t, "01");
					break;

				case 2:
					strcat(t, "10");
					break;

				case 3:
					strcat(t, "11");
					break;

				default:
					printf("nothing");
				}
			}
		}

		switch (s1[p][q])
		{
		case 0:
			strcat(t, "00");
			break;

		case 1:
			strcat(t, "01");
			break;

		case 2:
			strcat(t, "10");
			break;

		case 3:
			strcat(t, "11");
			break;

		default:
			printf("nothing");
		}


		printf("\n\nbefore p4:- \n%s\n", t);

		printf("\n\napplying P4 :-\n");   		//p4 logic
		for (i = 0; i<4; i++)
		{
			temp = p4[i];
			t[i + 4] = t[temp - 1];
			printf("%c ", t[i + 4]);
		}


		for (i = 0; i<8; i++)
		{
			ti[i] = NULL;
		}

		printf("\n\napplying XOR :-\n");           //XOR between p4 and l
		for (i = 0; i<4; i++)
		{
			ti[i] = (int)t[i + 4] ^ (int)ipt[i];
			ti[i] = ti[i] + 48;
			//printf("%c ",ti[i+4]);
		}
		printf("\n\n\n\n");
		for (i = 4; i<8; i++)
		{
			ti[i] = ipt[i];
			//printf("%c ",ti[i-4]);
		}

		for (i = 0; i<8; i++)
		{
			ipt[i] = ti[i];
			printf("%c ", ti[i]);
		}


		printf("\n\napplying IP^-1  :-\n\n");
		for (i = 0; i<8; i++)
		{
			temp = ipi[i];
			op[i] = ti[temp - 1];
			printf("%c ", op[i]);
		}
	}

	getchar();
	getchar();
	return 0;
}
