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
	printf("���г�ʼ����ɣ���ѡ��Ҫ������е���������.\n");
portal:    //���͵㣡����
	printf("1Ϊint��2Ϊfloat,3Ϊchar.\n");
	scanf_s("%d", &Type);
	switch (Type)
	{
	case 1:
		printf("ѡ�������Ϊ����(int),��������������.\n");
		scanf_s("%d", &Data1);
		EnAQueue(&Q, Data1);
		EnTQueue(&T, 1);
		break;
	case 2:
		printf("ѡ�������Ϊ������(float),�����븡��������.\n");
		scanf_s("%f", &Data2);
		EnAQueue(&Q, &Data2);                                          
		EnTQueue(&T, 2);
		break;
	
	case 3:
		printf("ѡ�������Ϊ�ַ��ͣ�char��������һ���ַ�.\n");
		getchar();
		scanf_s("%c", &C);
		EnAQueue(&Q, &C);
		EnTQueue(&T, 3);
		break;
	default:printf("ERROR\n");
	}
	printf("¼�����������\n 1/0(��1����һ������0��������");
	getchar();
	scanf_s("%d", &ans);
	switch (ans)
	{
	case 0:
	{
		printf("��ô������¼��");
		goto portal;//TELEPORT��
		break; // ???
	}
	case 1:
	{
		printf("�������Ὣ֮ǰ¼������������\n");
		TraverseAQueueT(&Q, &T);
		printf("\n�ã�Ӧ�����������\n");
		printf("���ҾͰѶ���ɾ��\n");
		ClearATQueue(&Q, &T);

		printf("ɾ����ɣ���������");
		break;
	}
	default:
		printf("�Ȳ���1��Ҳ����0\n EMMMMMMMMM\n  �Ҿ͵��ǽ�������");
		return 0;
		break;
	}
	printf("���Գ�������ͽ�����\n");
	printf("����������˵�����������е�����ˣ�BKSN");
	return 0;
}