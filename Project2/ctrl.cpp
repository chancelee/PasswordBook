#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
#include "data.h"
#include "ctrl.h"

char cWeb[MAX][CHM];
char cUser[MAX][CHM];
char cPwd[MAX][CHM];
char cNote[MAX][CHM];
int gCount = 0;

void ShowAll()
{
	InitP();
	printf("��%d����¼\n------------------------------------------\n", gCount);
	for (int i = 0; i < gCount; i++)
	{
		printf("��%d����¼��\n-------------------------------------------\n", i + 1);
		printf("վ�㣺%s\n�û�����%s\n���룺%s\n��ע��%s\n", cWeb[i], cUser[i], cPwd[i], cNote[i]);
		printf("-------------------------------------------\n");
	}


	system("pause");
}
void AddP()
{
	InitP();
	printf("������Ŀ��վ�㡢�û��������롢��ע��Ϣ\n");
	scanf_s("%s %s %s %s", cWeb[gCount], CHM, cUser[gCount], CHM, cPwd[gCount], CHM, cNote[gCount], CHM);
	gCount++;
	SaveP();
	printf("��ӳɹ�\n");
}
int FindP()
{
	InitP();
	printf("������վ������\n");
	char cKey[CHM];//�ؼ���
	scanf_s("%s", cKey, CHM);
	int nFd = -1;
	for (int i = 0; i < gCount; i++)
	{
		if (!strcmp(cKey, cWeb[i]))
		{
			nFd = i;
			break;
		}
	}
	if (nFd == -1)
		printf("û���ҵ�\n");
	else
	{
		printf("��%d�����ϣ�\n", nFd + 1);
		printf("-------------------------------------------\n");
		printf("վ������%s\n�û�����%s\n���룺%s\n��ע��%s\n", cWeb[nFd], cUser[nFd], cPwd[nFd], cNote[nFd]);
	}
	return nFd;
}
void DeleteP()
{
	int nIdx = FindP();
	if (nIdx == -1)
		printf("�޷�ɾ��\n");
	else
	{
		for (int i = nIdx; i < gCount - 1; i++)
		{
			strcpy_s(cWeb[i], CHM, cWeb[i + 1]);
			strcpy_s(cUser[i], CHM, cUser[i + 1]);
			strcpy_s(cPwd[i], CHM, cPwd[i + 1]);
			strcpy_s(cNote[i], CHM, cNote[i + 1]);
		}
		gCount--;

		SaveP();
		printf("ɾ���ɹ�\n");
	}
	system("pause");
}
void AlertP()
{
	int nIdx = FindP();
	if (nIdx == -1)
		printf("�޷�ɾ��\n");
	else
	{
		printf("-------------------------------------------\n");
		printf("�������µ��û��������롢��ע\n");
		scanf_s("%s %s %s", cUser[nIdx], CHM, cPwd[nIdx], CHM, cNote[nIdx], CHM);
		SaveP();
		printf("�޸ĳɹ�\n");
	}
	system("pause");
}