#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Domain.h"
#include "dfs_bfs.h"

//������ȱ���,��child��sibling
void dfs(DomainNode* root, int level)
{
    if (!root)//�޽ڵ�
    {
        return;
    }
    for (int i = 0; i < level; i++)
    {
        printf("--");
    }
    printf("%s\n", root->domain);
    dfs(root->firstChild, level + 1);
    dfs(root->nextSibling, level);

}

//������ȱ�������sibling��child
void bfs(DomainNode* root)
{
    if (!root)//�޽ڵ�
    {
        return;
    }

    DomainNode* queue[100];
    int front = 0, end = 0;
    queue[end++] = root;

    while (front < end)
    {
        DomainNode* current = queue[front++];
        printf("%s\n", current->domain);

        DomainNode* child = current->firstChild;
        while (child)
        {
            //�����к��ӽڵ������У���Щ���ӽڵ㻥Ϊ�ֵܣ�
            queue[end++] = child;  
            child = child->nextSibling; 
        }

    }

}

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