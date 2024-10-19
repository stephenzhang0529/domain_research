#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Domain.h"
#include "dfs_bfs.h"
void readfile_construct(DomainNode* root, const char* filename) 
{
    FILE* file = fopen(filename, "r"); //���ļ�
    if (!file) 
    {
        printf("�޷����ļ� %s\n", filename);
        return;
    }

    char line[100]; //���ڴ洢ÿһ������
    while (fgets(line, sizeof(line), file))//���ж�ȡ�ļ�����
    { 
        // ȥ�����з�
        line[strcspn(line, "\n")] = 0;

        // �ָ���뵽����
        char part[10][20];
        char domaincopy[100];
        strcpy(domaincopy, line); // ���ƶ�ȡ��������
        int length = splitDomain(domaincopy, part);
        insertDomain(root, part, length);
    }

    fclose(file); // �ر��ļ�
}