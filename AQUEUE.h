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
	ElemType *data[MAXQUEUE];   //������
	int front;
	int rear;
	size_t length;
	int maxSize;       //���г���
} AQueue;
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

Status DestoryAQueue(AQueue *Q)
{
	free(Q);
	Q = NULL;

}
Status IsFullAQueue(const AQueue *Q)
{
	if ((Q->rear + 1) % MAXQUEUE == Q->front)
		return TRUE;

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
Status EnAQueue(AQueue *Q, ElemType *data)
{
	if (IsFullAQueue(Q))
		return FALSE;
	Q->data[Q->rear] = data;//Ԫ�����
	Q->rear = (Q->rear + 1) % MAXQUEUE;//ָ���һ
	return TRUE;
}
/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : ���Ӳ���
*/
Status DeAQueue(AQueue *Q, ElemType *pElement)
{
	if (IsEmptyAQueue(Q))
	{ 
		printf("����Ϊ�գ�GG\n");
		return FALSE;
	}
	pElement=Q->data[Q->front];
	Q->length--;
	Q->front = (Q->front + 1) % MAXQUEUE;
}
/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 */
void ClearAQueue(AQueue *Q)
{
	Q->front = Q->rear = 0;
}
/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 */
Status TraverseAQueue(const AQueue *Q)
{
	int i = Q->front;
	while (i != Q->rear)
	{
		printf("%d ", Q->data[i]);
		i = (i + 1) % MAXQUEUE;
	}
	printf("\n");
}
/**
 *  @name        : void APrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q
 *  @notice      : None
 */
void APrint(void *q)
{

}

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
#endif // AQUEUE_H_INCLUDED