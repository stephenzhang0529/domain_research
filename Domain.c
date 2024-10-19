#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Domain.h"
#include "dfs_bfs.h"
#include "read.h"

//�����ڵ�
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

//��������������
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
            child = child->nextSibling;//��ͬ���ڵ�����
        }

        if (!child)//�����ڣ������
        {
            DomainNode* newNode = createNode(domains[i]);
            if (prev)//��ͬ���ڵ�
            {
                prev->nextSibling = newNode;
            }
            else//��ͬ���ڵ� 
            {
                current->firstChild = newNode;
            }
            current = newNode;//current����
        }
        else//�Ѵ��� 
        {
            current = child;
        }
    }
    return root;
}