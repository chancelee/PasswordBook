#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
#include "data.h"
#include "ctrl.h"
//���������ܣ�ÿ���ַ������5
//���ļ��е����ݶ������ڴ沢����
void InitP()
{
	FILE *pFile = nullptr;

	//1.��
	if (fopen_s(&pFile, "pwd.txt", "ab+"))	//rb+���ܶ�Ҳ��д����w�ᱻ���ǣ���r���ܴ�0��ʼ��
		printf("ʧ��\n");
	//��ȡ������
	fseek(pFile, 0, SEEK_END);
	int n = ftell(pFile);
	gCount = n / 400;
	fseek(pFile, 0, SEEK_SET);
	for (int i = 0; i < gCount; i++)
	{
		fread(cWeb[i], CHM, 1, pFile);
		for (int j = 0; j < CHM; j++)
		{
			cWeb[i][j] ^= 5;
		}
		fread(cUser[i], CHM, 1, pFile);
		for (int j = 0; j < CHM; j++)
		{
			cUser[i][j] ^= 5;
		}
		fread(cPwd[i], CHM, 1, pFile);
		for (int j = 0; j < CHM; j++)
		{
			cPwd[i][j] ^= 5;
		}
		fread(cNote[i], CHM, 1, pFile);
		for (int j = 0; j < CHM; j++)
		{
			cNote[i][j] ^= 5;
		}
	}
	//3.�ر�
	fclose(pFile);
}
//���ڴ��е����ݼ��ܲ�д���ļ�
void SaveP()
{
	FILE *pFile = nullptr;
	//1.��
	if (fopen_s(&pFile, "pwd.txt", "wb+"))
		printf("ʧ��\n");
	//2.����д��
	for (int i = 0; i < gCount; i++)
	{
		for (int j = 0; j < CHM; j++)
		{
			cWeb[i][j] ^= 5;

		}
		fwrite(cWeb[i], CHM, 1, pFile);
		for (int j = 0; j < CHM; j++)
		{
			cUser[i][j] ^= 5;

		}
		fwrite(cUser[i], CHM, 1, pFile);
		for (int j = 0; j < CHM; j++)
		{
			cPwd[i][j] ^= 5;

		}
		fwrite(cPwd[i], CHM, 1, pFile);
		for (int j = 0; j < CHM; j++)
		{
			cNote[i][j] ^= 5;

		}
		fwrite(cNote[i], CHM, 1, pFile);
	}
	//3.�ر�
	fclose(pFile);
}