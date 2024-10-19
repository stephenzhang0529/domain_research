#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Domain.h"
#include "dfs_bfs.h"
void readfile_construct(DomainNode* root, const char* filename) 
{
    FILE* file = fopen(filename, "r"); //打开文件
    if (!file) 
    {
        printf("无法打开文件 %s\n", filename);
        return;
    }

    char line[100]; //用于存储每一行数据
    while (fgets(line, sizeof(line), file))//逐行读取文件内容
    { 
        // 去除换行符
        line[strcspn(line, "\n")] = 0;

        // 分割并插入到树中
        char part[10][20];
        char domaincopy[100];
        strcpy(domaincopy, line); // 复制读取到的域名
        int length = splitDomain(domaincopy, part);
        insertDomain(root, part, length);
    }

    fclose(file); // 关闭文件
}