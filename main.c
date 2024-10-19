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
    

    printf("����������������\n");
    dfs(root->firstChild, 0);  //�������ڵ����ʾ

    printf("\n����������������\n");
    bfs(root->firstChild);  

    return 0;
}
