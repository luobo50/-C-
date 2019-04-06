#include"AQUEUE.h"
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS  //加了都没用，向VS低头
 //后来发现是我搞错了，但是这句话我就留在了这里(VSNB
int main()
{
	int Type;
	int Data1=0;
	float Data2=0;
	char Data3[1000] = { 0 };
	char ans;
	AQueue Q;
	TQueue T;
	InitAQueue(&Q);
	InitTQueue(&T);
	printf("队列初始化完成，请选择要进入队列的数据类型.\n");
    portal:    //传送点！这里
	printf("1为int，2为float,3为string.\n");
	scanf_s("%d", &Type);
	switch (Type)
	{
	case 1:
	{
		printf("选择的类型为整形(int)，请输入整形数据.\n");
		scanf_s("%d", &Data1);
		EnAQueue(&Q, &Data1);
		EnTQueue(&T, 1);
		break;
	}
	case 2:
	{
		printf("选择的类型为浮点型(float)，请输入浮点型数据.\n");
		scanf_s("%f", &Data2);
		EnAQueue(&Q, &Data2);
		EnTQueue(&T, 2);
		break;
	}

	case 3:
	{
		printf("选择的类型为字符串（string），请输入一个字符串.\n");
		scanf_s("%s", &Data3);
		EnAQueue(&Q, &Data3);
		EnTQueue(&T, 3);
		break;
	}
	default:printf("ERROR\n");
	}
	printf("录入操作结束？ Y/N  \n");
    AGA:
	getchar();
	scanf_s("%c", &ans);
	if (ans == 'N' || 'n')
	{
		printf("那么，继续录入");
		goto portal;//TELEPORT（ATION？）！
	}
	else if (ans == 'Y' || 'y')
	{
		printf("接下来会将之前录入的数据再输出\n");
		TraverseAQueueT(&Q, &T);
		printf("\n好，应该是输出完鸟\n");
		printf("那我就把队列删了");
		DestoryAQueue(&Q);
		DestoryTQueue(&T);
		printf("删除完成，溜了溜了");
	}
	else
	{
		printf("既不是Y，也不是N\n EMMMMMMMMM\n  我就当什么都看见\n(并要求重新输入Y/N");
		goto AGA;
	}
	printf("测试程序到这里就结束了\n");
	printf("感谢您的使用（对自己说这话的时候感觉可真微妙");
	return 0;
}