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