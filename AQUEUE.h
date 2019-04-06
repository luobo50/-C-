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
	void *data[MAXQUEUE];   //数据域
	int front;
	int rear;
	size_t length;       //队列长度
} AQueue;

typedef struct TYPEqueue
{
	int type[MAXQUEUE];   //数据域
	int front;
	int rear;
	size_t length;       //队列长度
} TQueue;



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
Status EnAQueue(AQueue *Q, void *data)
{
	if (IsFullAQueue(Q))
		return FALSE;
	Q->data[Q->rear] = data;//元素入队
	Q->rear = (Q->rear+1) % MAXQUEUE;//指针加一
	Q->length++;
	return TRUE;
}
Status EnTQueue(TQueue *T, int data)
{
	if (IsFullAQueue(T))
		return FALSE;
	T->type[T->rear] = data;//元素入队
	T->rear = (T->rear + 1) % MAXQUEUE;//指针加一
	T->length++;
	return TRUE;
}
/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : 出队操作
*/
Status DAQueue(AQueue *Q)//这个是原版
{
	if (IsEmptyAQueue(Q))
	{
		printf("队列为空，GG\n");
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
		printf("队列为空，GG\n");
		return FALSE;
	}

	Q->length--;
	Q->front = (Q->front + 1) % MAXQUEUE;
	T->front = (Q->front + 1) % MAXQUEUE;
	return TRUE;
}
/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 */
void ClearATQueue(AQueue *Q,TQueue *T)
{
	Q->front = Q->rear = 0;
	T->front = T->rear = 0;
}
/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
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
				printf("那可全完了，又出BUG了\n");
				printf("哼，哼，啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊（目力");
				break;
			}
		}
	}
	printf("\n");
	return TRUE;
}
/**
 *  @name        : void APrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 *  @notice      : None
 */
void APrint(void *q)
{
	printf("其实我不知道这个函数要干嘛，如果你调用了它的话\n\n\n\n");
	printf("那我也只好卖个萌了，哎嘿~XD");
}

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
#endif // AQUEUE_H_INCLUDED