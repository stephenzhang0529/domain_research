#pragma once
#include "Domain.h"
//������ȱ���
void dfs(DomainNode* node, int level);
//������ȱ���
void bfs(DomainNode* root);
// �ָ������������ҵ����˳��洢
int splitDomain(char* domain, char result[][50]);