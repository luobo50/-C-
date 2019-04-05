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
  //循环队列结构
typedef int ElemType;

typedef struct Aqueue
{
	ElemType *data[MAXQUEUE];   //数据域
	int front;
	int rear;
	size_t length;
	int maxSize;       //队列长度
} AQueue;
typedef enum
{
	FALSE = 0, TRUE = 1
} Status;

//DataType的类型依赖于具体应用


/**************************************************************
 *    Prototype Declare Section
 **************************************************************/

 /**
  *  @name        : void InitAQueue(AQueue *Q)
  *    @description : 初始化队列
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
 *    @description : 查看队头元素
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
 *    @description : 确定队列长度
 */
int LengthAQueue(AQueue *Q)
{
	return (Q->rear - Q->front + MAXQUEUE) % MAXQUEUE;
}
/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : 入队操作
*/
Status EnAQueue(AQueue *Q, ElemType *data)
{
	if (IsFullAQueue(Q))
		return FALSE;
	Q->data[Q->rear] = data;//元素入队
	Q->rear = (Q->rear + 1) % MAXQUEUE;//指针加一
	return TRUE;
}
/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : 出队操作
*/
Status DeAQueue(AQueue *Q, ElemType *pElement)
{
	if (IsEmptyAQueue(Q))
	{ 
		printf("队列为空，GG\n");
		return FALSE;
	}
	pElement=Q->data[Q->front];
	Q->length--;
	Q->front = (Q->front + 1) % MAXQUEUE;
}
/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 */
void ClearAQueue(AQueue *Q)
{
	Q->front = Q->rear = 0;
}
/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
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
 *    @description : 操作函数
 *    @param         q 指针q
 *  @notice      : None
 */
void APrint(void *q)
{

}

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
#endif // AQUEUE_H_INCLUDED