#include"AQUEUE.h"
#include<stdio.h>
int main()
{
	AQueue Q;TQueue T;
	InitAQueue(&Q);
	InitAQueue(&T);
	int a = 300;
	float b = 3.1415926f;
	char c[200] = { "WRYYYYYYYYYYYYYYYYYYYYYYYY" };

	EnAQueue(&Q,1);
	EnAQueue(&Q,a);
	EnAQueue(&Q, &b);
	EnAQueue(&Q, &c);
	EnAQueue(&Q, 2333);
	EnTQueue(&T, 1);
	EnTQueue(&T, 1);
	EnTQueue(&T, 2);
	EnTQueue(&T, 3);
	EnTQueue(&T, 1);
	printf("%d \n",  Q.data[0]);
	printf("%d \n",  Q.data[1]);
	printf("%f \n", *(float*)Q.data[2]);
	printf("%s \n", Q.data[3]);
	printf("%d \n", Q.data[4]);
	TraverseAQueueT(&Q, &T);

	system("pause");

	return 0;
}