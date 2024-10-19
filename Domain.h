#pragma once
//�ڵ�ṹ��
typedef struct DomainNode
{
    char domain[50];                 //��������
    struct DomainNode* firstChild;   //ָ���һ�����ӽڵ㣨�¼���
    struct DomainNode* nextSibling;  //ָ����һ���ֵܽڵ㣨ͬ����
} DomainNode;

DomainNode* createNode(const char* domain);
DomainNode* insertDomain(DomainNode* root, char domains[][50], int length);
