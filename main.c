#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Domain.h"
#include "dfs_bfs.h"
#include "read.h"



int main() {
    DomainNode* root = createNode("root");  
    readfile_construct(root, "website.txt");
    

    printf("深度优先搜索结果：\n");
    dfs(root->firstChild, 0);  //跳过根节点的显示

    printf("\n层次优先搜索结果：\n");
    bfs(root->firstChild);  

    return 0;
}
