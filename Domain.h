#pragma once
//节点结构体
typedef struct DomainNode
{
    char domain[50];                 //域名部分
    struct DomainNode* firstChild;   //指向第一个孩子节点（下级）
    struct DomainNode* nextSibling;  //指向下一个兄弟节点（同级）
} DomainNode;

DomainNode* createNode(const char* domain);
DomainNode* insertDomain(DomainNode* root, char domains[][50], int length);
