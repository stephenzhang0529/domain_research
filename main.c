#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Domain.h"
#include "dfs_bfs.h"

// �ָ������������ҵ����˳��洢
int splitDomain(char* domain, char result[][50]) 
{
    //�ָ�
    int length = 0;
    char* token = strtok(domain, ".");
    while (token) 
    {
        strcpy(result[length++], token);
        token = strtok(NULL, ".");//�ٴε���strtok,����һ��������Ϊ NULL����ʾ������ԭʼ�ַ������зָ�
    }

    //��ת����˳��
    for (int i = 0; i < length / 2; i++) 
    {
        char temp[50];
        strcpy(temp, result[i]);
        strcpy(result[i], result[length - i - 1]);
        strcpy(result[length - i - 1], temp);
    }

    return length;
}

int main() {
    DomainNode* root = createNode("root");  //���ڵ��ʾ������

    int total = 7;//��������
    //��������
    char domains[][50] =
    {
        "www.google.com",
        "mail.google.com",
        "www.baidu.cn",
        "news.baidu.cn",
        "www.apple.com",
        "www.csdn.net",
        "www.example.com"
    };

    for (int i = 0; i < total; i++) 
    {
        char parts[10][50];
        char domainCopy[50];
        strcpy(domainCopy, domains[i]);

        int length = splitDomain(domainCopy, parts);//�ָ���˼�����
        insertDomain(root, parts, length);
    }

    printf("����������������\n");
    dfs(root->firstChild, 0);  //�������ڵ����ʾ

    printf("\n����������������\n");
    bfs(root->firstChild);  

    return 0;
}
