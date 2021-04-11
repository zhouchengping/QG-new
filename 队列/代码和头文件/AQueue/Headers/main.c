#include <stdio.h>
#include <stdlib.h>
#include "AQueue.h"
#include "menu.h"


int main(void) {
	AQueue Q;
	int count = 0;
	while (1) {
		menu();
		char i = getch(); 
		switch (i) {
			case '1': { // 初始化队列 
			system("cls"); 
				count++;
				system("cls");
				InitAQueue(&Q);
				printf("初始化成功！\n");
				system("pause");
				break;
			}
			
			case '2': {// 入队 
				system("cls");
				if (!count) {
					printf("请先初始化队列！\n");
					system("pause");
					break;
				} 
				printf("请输入数据数据类型(1代表整数，2代表小数，3代表字符)\n");
				scanf("%d", &type);
				switch(type) { // 不同数据类型输出不同值，利用type做检测 
					case 1:{
						int data;
						printf("请输入数据：");
						int judge = scanf("%d", &data);
						if (judge == 0) {
							printf("非法输入！\n");
							while (getchar() != '\n');
						}
						else{
							(EnAQueue(&Q, &data));
							printf("进队成功！\n");	
						}
						system("pause");
						break;
					}
					
					case 2:{
						double data;
						printf("请输入数据：");
						int judge = scanf("%lf", &data);
						if (judge == 0) {
							printf("非法输入！\n");
							while (getchar() != '\n');
						}
						else{
							(EnAQueue(&Q, &data));
							printf("进队成功！\n");	
						}
						system("pause");						
						break;
					}
					
					case 3:{
						char* data;
						int judge = scanf("%s", &data);
						if (judge == 0) {
							printf("非法输入！\n");
							while (getchar() != '\n');
						}
						else{
							EnAQueue(&Q, &data);
							printf("进队成功！\n");
							while (getchar() != '\n');	
						}
						system("pause");
						break;
					}		
					
					default:{
						printf("数据类型错误！\n");
						while(getchar() != '\n');
						system("pause");
						break;
					}
				}
			
				break;
				
			}
			
			case '3': {// 出队 
				system("cls");
				if (!count) {
					printf("请先初始化队列！\n");
					system("pause");
					break;
				}
				if (DeAQueue(&Q)) 
					printf("出队成功！\n");
				else {
					printf("出队失败！\n");
					printf("队列为空！\n"); 
			    } 
			    system("pause");
				break;
			}
			
			case '4': {// 输出队头数据 
				system("cls");
				if (!count) {
					printf("请先初始化队列！\n");
				system("pause");
					break;
				}
				if (IsEmptyAQueue(&Q)) {
					printf("队列为空！\n");
					system("pause");				
					break;
				}
				void* data; //检测队头数据类型做输出 
				if (datatype[Q.front] == 1) {
					data = (int*)malloc(sizeof(int));
					if (GetHeadAQueue(&Q, data))
					printf("队头数据为：%d\n", *(int*)data);
				} 
				if (datatype[Q.front] == 2) {
					data = (double*)malloc(sizeof(double));
					if (GetHeadAQueue(&Q, data))
					printf("队头数据为：%.2lf\n", *(double*)data);					
				}
				if (datatype[Q.front] == 3) {
					data = (char*)malloc(sizeof(char));
					if (GetHeadAQueue(&Q, data))
					printf("队头数据为：%c\n", *(char*)data);					
				}system("pause");
				break;
			}
			
			case '5': {// 清空队列 
				system("cls");
				if (!count) {
					printf("请先初始化队列！\n");
					system("pause");
					break;
				}
				if (IsEmptyAQueue(&Q))
				printf("此时已为空队列！\n");
				else {
					ClearAQueue(&Q);
					printf("清空成功！\n");
				}
				system("pause");
				break;
			}
			
			case '6': {
				system("cls");
				if (!count) {
					printf("请先初始化队列！\n");system("pause");
					break;
				}
				int length;
				length = LengthAQueue(&Q);
				printf("此时队列的长度为：%d\n", length);
				system("pause");
				break;
			}
			
			case '7': {
				system("cls");
				if (!count) {
					printf("请先初始化队列！\n");
			system("pause");
					break;
				}
				if (IsEmptyAQueue(&Q)) 
				printf("是空队列！\n");
				if(!(IsEmptyAQueue(&Q))) 
				printf("不是空队列！\n");
			system("pause");
				break;
			}

			case '8': {
				system("cls");
				if (!count) {
					printf("请先初始化队列！\n");
				system("pause");
					break;
				}
				if (IsFullAQueue(&Q))
				printf("当前队列已满！\n");
				else
				printf("当前队列未满！\n");
				system("pause");
				break;							
			}
			
			case '9': {
				system("cls");
				if (!count) {
					printf("请先初始化队列！\n");
				system("pause");
					break;
				}
				if (TraverseAQueue(&Q, APrint));
				else 
				printf("此时队列为空！\n");
			system("pause");
				break;
			} 
			
			case '0': 
			{system("cls"); 
				if (!count) {
					printf("请先初始化队列！\n");
					system("pause");
					break;
				}
				DestoryAQueue(&Q);
				printf("销毁成功！\n"); 
				system("pause"); 
				break;
			}
			
			default: {system("cls"); 
				printf("您输入了非法字符，请重新输入！\n");
				system("pause");
				break;
			}
		}
		 
	}	
	return 0;
}
