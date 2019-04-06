#include"AQUEUE.h"
#include<string.h>
#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int main()
{
	int Type;
	int Data1=0;
	float Data2=0.000;
	char C=0;
	int ans=0;
	AQueue Q;
	TQueue T;
	InitAQueue(&Q);
	InitTQueue(&T);
	printf("队列初始化完成，请选择要进入队列的数据类型.\n");
portal:    //传送点！这里
	printf("1为int，2为float,3为char.\n");
	scanf_s("%d", &Type);
	switch (Type)
	{
	case 1:
		printf("选择的类型为整形(int),请输入整形数据.\n");
		scanf_s("%d", &Data1);
		EnAQueue(&Q, Data1);
		EnTQueue(&T, 1);
		break;
	case 2:
		printf("选择的类型为浮点型(float),请输入浮点型数据.\n");
		scanf_s("%f", &Data2);
		EnAQueue(&Q, &Data2);                                          
		EnTQueue(&T, 2);
		break;
	
	case 3:
		printf("选择的类型为字符型（char）请输入一个字符.\n");
		getchar();
		scanf_s("%c", &C);
		EnAQueue(&Q, &C);
		EnTQueue(&T, 3);
		break;
	default:printf("ERROR\n");
	}
	printf("录入操作结束？\n 1/0(按1到下一步，按0能再输入");
	getchar();
	scanf_s("%d", &ans);
	switch (ans)
	{
	case 0:
	{
		printf("那么，继续录入");
		goto portal;//TELEPORT！
		break; // ???
	}
	case 1:
	{
		printf("接下来会将之前录入的数据再输出\n");
		TraverseAQueueT(&Q, &T);
		printf("\n好，应该是输出完鸟\n");
		printf("那我就把队列删了\n");
		ClearATQueue(&Q, &T);

		printf("删除完成，溜了溜了");
		break;
	}
	default:
		printf("既不是1，也不是0\n EMMMMMMMMM\n  我就当是结束好了");
		return 0;
		break;
	}
	printf("测试程序到这里就结束了\n");
	printf("看到这行字说明程序能运行到最后了，BKSN");
	return 0;
}