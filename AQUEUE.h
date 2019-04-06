#include<stdio.h>
#include<stdlib.h>
#ifndef AQUEUE_H_INCLUDED
#define AQUEUE_H_INCLUDED
/**************************************************************
 *    Macro Define Section
 **************************************************************/
#define MAXQUEUE 10
 /**************************************************************
  *    Struct Define Section
  **************************************************************/
  //ѭ�����нṹ
typedef int ElemType;

typedef struct Aqueue
{
	void *data[MAXQUEUE];   //������
	int front;
	int rear;
	size_t length;       //���г���
} AQueue;

typedef struct TYPEqueue
{
	int type[MAXQUEUE];   //������
	int front;
	int rear;
	size_t length;       //���г���
} TQueue;



typedef enum
{
	FALSE = 0, TRUE = 1
} Status;

//DataType�����������ھ���Ӧ��


/**************************************************************
 *    Prototype Declare Section
 **************************************************************/

 /**
  *  @name        : void InitAQueue(AQueue *Q)
  *    @description : ��ʼ������
  */
Status InitAQueue(AQueue *Q)
{
	Q->front = 0;
	Q->rear = 0;
	Q->length = 0;
	return TRUE;
}
Status InitTQueue(TQueue *T)
{
	T->front = 0;
	T->rear = 0;
	T->length = 0;
	return TRUE;
}

Status DestoryAQueue(AQueue *Q)
{
	free(Q->data);
	Q = NULL;
	return TRUE;

}
Status DestoryTQueue(TQueue *T)
{
	free(T->type);
	T = NULL;
	return TRUE;

}
Status IsFullAQueue(const AQueue *Q)
{
	if ((Q->rear + 1) % MAXQUEUE == Q->front)
		return TRUE;
	else
		return FALSE;
}
Status IsFullTQueue(const TQueue *Q)
{
	if ((Q->rear + 1) % MAXQUEUE == Q->front)
		return TRUE;
	else
		return FALSE;
}

Status IsEmptyAQueue(const AQueue *Q)
{
	if (Q->front == Q->rear)
		return TRUE;
	else
		return FALSE;
}
/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 */
Status GetHeadAQueue(AQueue *Q, void *e)
{
	if (Q->front == Q->rear)
		return FALSE;
	e = Q->data[Q->front];
	return TRUE;

}
/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : ȷ�����г���
 */
int LengthAQueue(AQueue *Q)
{
	return (Q->rear - Q->front + MAXQUEUE) % MAXQUEUE;
}
/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : ��Ӳ���
*/
Status EnAQueue(AQueue *Q, void *data)
{
	if (IsFullAQueue(Q))
		return FALSE;
	Q->data[Q->rear] = data;//Ԫ�����
	Q->rear = (Q->rear+1) % MAXQUEUE;//ָ���һ
	Q->length++;
	return TRUE;
}
Status EnTQueue(TQueue *T, int data)
{
	if (IsFullAQueue(T))
		return FALSE;
	T->type[T->rear] = data;//Ԫ�����
	T->rear = (T->rear + 1) % MAXQUEUE;//ָ���һ
	T->length++;
	return TRUE;
}
/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : ���Ӳ���
*/
Status DAQueue(AQueue *Q)//�����ԭ��
{
	if (IsEmptyAQueue(Q))
	{
		printf("����Ϊ�գ�GG\n");
		return FALSE;
	}

	Q->length--;
	Q->front = (Q->front + 1) % MAXQUEUE;
	return TRUE;
}
Status DATQueue(AQueue *Q,TQueue *T)
{
	if (IsEmptyAQueue(Q))
	{ 
		printf("����Ϊ�գ�GG\n");
		return FALSE;
	}

	Q->length--;
	Q->front = (Q->front + 1) % MAXQUEUE;
	T->front = (Q->front + 1) % MAXQUEUE;
	return TRUE;
}
/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 */
void ClearATQueue(AQueue *Q,TQueue *T)
{
	Q->front = Q->rear = 0;
	T->front = T->rear = 0;
}
/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 */
Status TraverseAQueueT(const AQueue *Q, const TQueue *T)
{
	int i = Q->front, j = T->front;
	while (i != Q->rear)
	{
		switch (T->type[j])
		{
		case 1:
			{
				printf("%d \n", Q->data[i]);
				i = (i + 1) % MAXQUEUE;
				j = (j + 1) % MAXQUEUE;
				break;
			}
		case 2:
			{
				printf("%f \n", *(float*)Q->data[i]);
				i = (i + 1) % MAXQUEUE;
				j = (j + 1) % MAXQUEUE;
				break;
			}
		case 3:
			{
				printf("%s \n", Q->data[i]);
				i = (i + 1) % MAXQUEUE;
				j = (j + 1) % MAXQUEUE;
				break;
			}
		default:
			{
				printf("�ǿ�ȫ���ˣ��ֳ�BUG��\n");
				printf("�ߣ��ߣ�������������������������������������������������������������Ŀ��");
				break;
			}
		}
	}
	printf("\n");
	return TRUE;
}
/**
 *  @name        : void APrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q
 *  @notice      : None
 */
void APrint(void *q)
{
	printf("��ʵ�Ҳ�֪���������Ҫ����������������Ļ�\n\n\n\n");
	printf("����Ҳֻ���������ˣ�����~XD");
}

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
#endif // AQUEUE_H_INCLUDED