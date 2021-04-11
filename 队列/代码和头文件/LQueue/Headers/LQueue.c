#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "LQueue.h"

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q) {
	Q->front = (Node*)malloc(sizeof(Node));
	Q->rear = Q->front;
	Q->front->next = Q->rear->next = NULL;
	Q->length = 0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q) {
	Node *p, *q;
	p = Q->front->next;
	while (q != NULL) { // ѭ���������ͷ� 
		q = p->next;
		free(p);
		p = q;
	}
	free(Q->front); // �ͷ�ͷָ�� 
	Q->front = Q->rear = NULL;
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q) {
	if (Q->length == 0)
	return TRUE;
	else
	return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue *Q, void *e) {
	if (IsEmptyLQueue(Q))
	return FALSE;
	switch(Q->front->next->type) {
		case 1: {
			memcpy(e, Q->front->next->data, sizeof(int));
			break;
		}
		case 2: {
			memcpy(e, Q->front->next->data, sizeof(double));			
			break;
		}
		case 3: {
			memcpy(e, Q->front->next->data, sizeof(char));			
			break;
		}
		case 4: {
			memcpy(e, Q->front->next->data, sizeof(char)*30);
			break;
		}
	}
	return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q) {
	return Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue *Q, void *data, int type) {
	Node *p = (Node*)malloc(sizeof(Node));
	p->type = type;
	switch(p->type) {
		case 1:{
			p->data = (int*)malloc(sizeof(int));
			memcpy(p->data, data, sizeof(int));
			break;
		}
					
		case 2:{
			p->data = (double*)malloc(sizeof(double));
			memcpy(p->data, data, sizeof(double));
			break;
		}
					
		case 3:{
			p->data = (char*)malloc(sizeof(char));
			memcpy(p->data, data, sizeof(char));
			break;
		}
					
		case 4:{
			p->data = (char*)malloc(sizeof(char)*30);
			memcpy(p->data, data, sizeof(char)*30);	
			break;
		}
					
		default:{
			printf("������������\n");
			break;
		} 
	}
	Q->rear->next = p;// β��������½ڵ� 
	p->next = NULL;// β�����һ��Ϊ��
	Q->rear = p;// �ٽ�βָ��ָ�����һ����㼴�¼���Ľ�� 
	Q->length++; 
	return TRUE; 
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q) {
	if (IsEmptyLQueue(Q))
	return FALSE;
	Node *p; // ��ͷ���ӣ� ��ͷ���ָ���ͷ�ĺ�һ����� 
	p = Q->front->next;
	Q->front->next = p->next;
	Q->length--;
	free(p);
	return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q) {
	if (IsEmptyLQueue(Q))
	return;
	Node *p, *q;
	p = Q->front->next;
	while(q) {// �ͷ����нڵ� 
		q = p->next;
		free(p);
		p = q;
	}
	Q->rear = Q->front;// ͷβָ��ָ��ͷ��� 
	Q->front->next = Q->rear->next = NULL;
	Q->length = 0;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q, int type)) {
	if (IsEmptyLQueue(Q))
	return FALSE;
	Node *p;
	p = Q->front->next;
	int count = 1;
	while (p != NULL) {
		(*foo)(p->data, p->type);
		p = p->next;
		count++;
		if (count % 5 == 0)// ÿ������� 
		printf("\n");
	}
	return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q
 
 *  @notice      : None
 */
void LPrint(void *q, int type) {// ���ݲ�ͬ���������������ͬ��ֵ 
	if (type == 1)
	printf("%d ", *(int*)q);
	if(type == 3)
	printf("%c ", *(char*)q);
	if(type == 2)
	printf("%.2lf ", *(double*)q);
	if (type == 4)
	printf("%s ", (char*)q);
}
