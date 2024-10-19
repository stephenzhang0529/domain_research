#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Domain.h"
#include "dfs_bfs.h"

//深度优先遍历,先child再sibling
void dfs(DomainNode* root, int level)
{
    if (!root)//无节点
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

//层次优先遍历，先sibling再child
void bfs(DomainNode* root)
{
    if (!root)//无节点
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
            //将所有孩子节点加入队列（这些孩子节点互为兄弟）
            queue[end++] = child;  
            child = child->nextSibling; 
        }

    }

}

// 分割域名，按从右到左的顺序存储
int splitDomain(char* domain, char result[][50])
{
    //分割
    int length = 0;
    char* token = strtok(domain, ".");
    while (token)
    {
        strcpy(result[length++], token);
        token = strtok(NULL, ".");//再次调用strtok,将第一个参数设为 NULL，表示继续对原始字符串进行分割
    }

    //反转域名顺序
    for (int i = 0; i < length / 2; i++)
    {
        char temp[50];
        strcpy(temp, result[i]);
        strcpy(result[i], result[length - i - 1]);
        strcpy(result[length - i - 1], temp);
    }

    return length;
}