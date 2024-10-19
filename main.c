#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Domain.h"
#include "dfs_bfs.h"

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

int main() {
    DomainNode* root = createNode("root");  //根节点表示顶级域

    int total = 7;//总域名数
    //插入域名
    char domains[][50] =
    {
        "www.google.com",
        "mail.google.com",
        "www.baidu.cn",
        "news.baidu.cn",
        "www.apple.com",
        "www.csdn.net",
        "www.example.com"
    };

    for (int i = 0; i < total; i++) 
    {
        char parts[10][50];
        char domainCopy[50];
        strcpy(domainCopy, domains[i]);

        int length = splitDomain(domainCopy, parts);//分割成了几部分
        insertDomain(root, parts, length);
    }

    printf("深度优先搜索结果：\n");
    dfs(root->firstChild, 0);  //跳过根节点的显示

    printf("\n层次优先搜索结果：\n");
    bfs(root->firstChild);  

    return 0;
}
