#include <stdio.h>
#include <stdlib.h>
#include "LQueue.h"
#include "menu.h" 



int main(void) {
	LQueue Q;
	int count = 0;
	while (1) {
		menu();
		char userKey = getch(); 
		switch (userKey) {
			case '1': { // ��ʼ������ 
				system("cls");
				count++;
				InitLQueue(&Q);
				printf("��ʼ���ɹ���\n");
				system("pause");
			
				break;
			}
			
			case '2': {// ��� 
				system("cls");
				if (!count) {
					printf("���ȳ�ʼ�����У�\n");
					system("pause");
				
					break;
				}
				int type; 
				printf("������������������(1����������2����С����3�����ַ���4�����ַ���)\n");
				scanf("%d", &type);
				switch(type) { // ��ͬ�������������ֵͬ������type����� 
					case 1:{
						int data;
						printf("���������ݣ�");
						int judge = scanf("%d", &data);
						if (judge == 0) {
							printf("�Ƿ����룡\n");
							while (getchar() != '\n');
						}
						else{
							(EnLQueue(&Q, &data, type));
							printf("���ӳɹ���\n");	
						}
						break;
					}
					
					case 2:{
						double data;
						printf("���������ݣ�");
						int judge = scanf("%lf", &data);
						if (judge == 0) {
							printf("�Ƿ����룡\n");
							while (getchar() != '\n');
						}
						else{
							(EnLQueue(&Q, &data, type));
							printf("���ӳɹ���\n");	
						}						
						break;
					}
					
					case 3:{
						char* data;
						int judge = scanf("%s", &data);
						if (judge == 0) {
							printf("�Ƿ����룡\n");
							while (getchar() != '\n');
						}
						else{
							EnLQueue(&Q, &data, type);
							printf("���ӳɹ���\n");
							while (getchar() != '\n');	
						}
						break;
					}		
					
					case 4:{
						char data[30];
						printf("����������:");
						int judge = scanf("%s", data);
						if (judge == 0) {
							printf("�Ƿ����룡\n");
							while (getchar() != '\n');
						}
						else{
							EnLQueue(&Q, data, type);
							printf("���ӳɹ���\n");	
						}
						break;
					}
					default:{
						printf("�������ʹ���\n");
						while(getchar() != '\n');
						break;
					}
				}
				system("pause");
			
				break;
				
			}
			
			case '3': {// ���� 
				system("cls");
				if (!count) {
					printf("���ȳ�ʼ�����У�\n");
					system("pause");
				
					break;
				}
				if (DeLQueue(&Q)) 
					printf("���ӳɹ���\n");
				else {
					printf("����ʧ�ܣ�\n");
					printf("����Ϊ�գ�\n"); 
			    }
				system("pause");
			
				break;
			}
			
			case '4': {// �����ͷ���� 
				system("cls");
				if (!count) {
					printf("���ȳ�ʼ�����У�\n");
					system("pause");
					
					break;
				}
				if (IsEmptyLQueue(&Q)) {
					printf("����Ϊ�գ�\n");
					system("pause");
									
					break;
				}
				void* data; //����ͷ������������� 
				if (Q.front->next->type == 1) {
					data = (int*)malloc(sizeof(int));
					if (GetHeadLQueue(&Q, data))
					printf("��ͷ����Ϊ��%d\n", *(int*)data);
				} 
				if (Q.front->next->type == 2) {
					data = (double*)malloc(sizeof(double));
					if (GetHeadLQueue(&Q, data))
					printf("��ͷ����Ϊ��%.2lf\n", *(double*)data);					
				}
				if (Q.front->next->type == 3) {
					data = (char*)malloc(sizeof(char));
					if (GetHeadLQueue(&Q, data))
					printf("��ͷ����Ϊ��%c\n", *(char*)data);					
				}

				if (Q.front->next->type == 4) {
					data = (char*)malloc(sizeof(char)*30);
					if (GetHeadLQueue(&Q, data))
					printf("��ͷ����Ϊ��%s\n", *(char*)data);					
				}
				system("pause");
				
				break;
			}
			
			case '5': {// ��ն��� 
				system("cls");
				if (!count) {
					printf("���ȳ�ʼ�����У�\n");
					system("pause");
				
					break;
				}
				if (IsEmptyLQueue(&Q))
				printf("��ʱ��Ϊ�ն��У�\n");
				else {
					ClearLQueue(&Q);
					printf("��ճɹ���\n");
				}
				system("pause");
			
				break;
			}
			
			case '6': {
				system("cls");
				if (!count) {
					printf("���ȳ�ʼ�����У�\n");
					system("pause");
					
					break;
				}
				int length;
				length = LengthLQueue(&Q);
				printf("��ʱ���еĳ���Ϊ��%d\n", length);
				system("pause");
			
				break;
			}
			
			case '7': {
				system("cls");
				if (!count) {
					printf("���ȳ�ʼ�����У�\n");
					system("pause");
				
					break;
				}
				if (IsEmptyLQueue(&Q)) 
				printf("�ǿն��У�\n");
				if(!(IsEmptyLQueue(&Q))) 
				printf("���ǿն��У�\n");
				system("pause");
				
				break;
			}

			case '8': {
				system("cls");
				if (!count) {
					printf("���ȳ�ʼ�����У�\n");
					system("pause");
				
					break;
				}
				if (TraverseLQueue(&Q, LPrint));
				else 
				printf("��ʱ����Ϊ�գ�\n");
				system("pause");
			
				break;				
			}
			 
			case '0': {
				if (!count) {
					system("cls");
					printf("���ȳ�ʼ�����У�\n");
					system("pause");
					
					break;
				}
				printf("���ٳɹ���\n");
				system("pause"); 
				return 0; 
				break;
			}
			
			default: {
				printf("�������˷Ƿ��ַ������������룡\n");
				system("pause");
			
				break;
			}
		}
		 
	}
	return 0;
}
