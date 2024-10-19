#pragma once
#include "Domain.h"
//深度优先遍历
void dfs(DomainNode* node, int level);
//层次优先遍历
void bfs(DomainNode* root);
// 分割域名，按从右到左的顺序存储
int splitDomain(char* domain, char result[][50]);