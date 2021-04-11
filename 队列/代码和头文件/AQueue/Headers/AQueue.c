#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AQueue.h"


/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitAQueue(AQueue *Q) {
	Q->front = Q->rear = 0;
	Q->length = 0;
}


/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q) {
	int i;
	for(i = 0; i < MAXQUEUE; i++)
	free(Q->data[i]);
	return;
}



/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : �������Ƿ�����
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q) {
	if (Q->length == MAXQUEUE)
	return TRUE;
	else 
	return FALSE;
}

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q) {
	if (Q->length == 0)
	return TRUE;
	else
	return FALSE;
}



/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q ����ָ��Q�����Ԫ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadAQueue(AQueue *Q, void *e) {
	if (IsEmptyAQueue(Q))
	return FALSE;
	switch(type) {
		case 1: {
			memcpy(e, Q->data[Q->front], sizeof(int));
			break;
		}
		case 2: {
			memcpy(e, Q->data[Q->front], sizeof(double));			
			break;
		}
		case 3: {
			memcpy(e, Q->data[Q->front], sizeof(char));			
			break;
		}
		default: {
			break;
		}
	}
	return TRUE;	 
}		



/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : ���г���count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q) {
	return Q->length;
}	



/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ����˻�Ϊ��
 */
Status EnAQueue(AQueue *Q, void *data) {
	if (IsFullAQueue(Q))
	return FALSE;
	switch(type) {
		case 1:{
			Q->data[Q->rear] = (int*)malloc(sizeof(int)); 
			memcpy(Q->data[Q->rear], data, sizeof(int));//��ַ��data 
			break;
		}
					
		case 2:{
			Q->data[Q->rear] = (double*)malloc(sizeof(double));
			memcpy(Q->data[Q->rear], data, sizeof(double));
			break;
		}
					
		case 3:{
			Q->data[Q->rear] = (char*)malloc(sizeof(char));
			memcpy(Q->data[Q->rear], data, sizeof(char));
			break;
		}
										
		default:{
			printf("������������\n");
			break;
		}
	}
	Q->length++;
	datatype[Q->rear] = type;		
	Q->rear = (Q->rear + 1) % MAXQUEUE;
	return TRUE;	
}



/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q) {
	if (IsEmptyAQueue(Q))
	return FALSE;
	Q->length--;
	Q->front = (Q->front + 1) % MAXQUEUE;
	return TRUE;
}	



/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q) {
	Q->front = Q->rear = 0;
	Q->length = 0;
	return;
}	



/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q, int datatype)) {
	int i = Q->front;
	for (; i != Q->rear; i = (i + 1)%MAXQUEUE) {
		(*foo)(Q->data[i], datatype[i]);
	}
	return TRUE;
}	



/**
 *  @name        : void APrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q
 *  @notice      : None
 */
void APrint(void *q, int datatype) {
	if (datatype == 1)
	printf("%d ", *(int*)q);
	if (datatype == 2)
	printf("%.2lf ", *(double*)q);
	if(datatype == 3)
	printf("%c ", *(char*)q);
} 
