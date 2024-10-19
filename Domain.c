#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Domain.h"
#include "dfs_bfs.h"
#include "read.h"

//创建节点
DomainNode* createNode(const char* domain)
{
    DomainNode* node = (DomainNode*)malloc(sizeof(DomainNode));
    if (node == NULL)
    {
        return NULL;
    }
    strcpy(node->domain, domain);
    node->firstChild = NULL;
    node->nextSibling = NULL;
    return node;
}

//插入域名到树中
DomainNode* insertDomain(DomainNode* root, char domains[][50], int length)
{
    DomainNode* current = root;
    for (int i = 0; i < length; i++)
    {
        DomainNode* child = current->firstChild;
        DomainNode* prev = NULL;

        while (child && strcmp(child->domain, domains[i]) != 0)
        {
            prev = child;
            child = child->nextSibling;//在同级节点里找
        }

        if (!child)//不存在，需插入
        {
            DomainNode* newNode = createNode(domains[i]);
            if (prev)//有同级节点
            {
                prev->nextSibling = newNode;
            }
            else//无同级节点 
            {
                current->firstChild = newNode;
            }
            current = newNode;//current降级
        }
        else//已存在 
        {
            current = child;
        }
    }
    return root;
}