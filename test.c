#include"AQUEUE.h"
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS  //���˶�û�ã���VS��ͷ
 //�����������Ҹ���ˣ�������仰�Ҿ�����������(VSNB
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
	printf("���г�ʼ����ɣ���ѡ��Ҫ������е���������.\n");
    portal:    //���͵㣡����
	printf("1Ϊint��2Ϊfloat,3Ϊstring.\n");
	scanf_s("%d", &Type);
	switch (Type)
	{
	case 1:
	{
		printf("ѡ�������Ϊ����(int)����������������.\n");
		scanf_s("%d", &Data1);
		EnAQueue(&Q, &Data1);
		EnTQueue(&T, 1);
		break;
	}
	case 2:
	{
		printf("ѡ�������Ϊ������(float)�������븡��������.\n");
		scanf_s("%f", &Data2);
		EnAQueue(&Q, &Data2);
		EnTQueue(&T, 2);
		break;
	}

	case 3:
	{
		printf("ѡ�������Ϊ�ַ�����string����������һ���ַ���.\n");
		scanf_s("%s", &Data3);
		EnAQueue(&Q, &Data3);
		EnTQueue(&T, 3);
		break;
	}
	default:printf("ERROR\n");
	}
	printf("¼����������� Y/N  \n");
    AGA:
	getchar();
	scanf_s("%c", &ans);
	if (ans == 'N' || 'n')
	{
		printf("��ô������¼��");
		goto portal;//TELEPORT��ATION������
	}
	else if (ans == 'Y' || 'y')
	{
		printf("�������Ὣ֮ǰ¼������������\n");
		TraverseAQueueT(&Q, &T);
		printf("\n�ã�Ӧ�����������\n");
		printf("���ҾͰѶ���ɾ��");
		DestoryAQueue(&Q);
		DestoryTQueue(&T);
		printf("ɾ����ɣ���������");
	}
	else
	{
		printf("�Ȳ���Y��Ҳ����N\n EMMMMMMMMM\n  �Ҿ͵�ʲô������\n(��Ҫ����������Y/N");
		goto AGA;
	}
	printf("���Գ�������ͽ�����\n");
	printf("��л����ʹ�ã����Լ�˵�⻰��ʱ��о�����΢��");
	return 0;
}