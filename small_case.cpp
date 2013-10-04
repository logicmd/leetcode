#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;


char *strcpy(char *dest, const char *src) {
    if(src==NULL || dest==NULL) return NULL;
    int dest_size = strlen(dest);
    int src_size = strlen(src);

    // 如果src字符串和dst字符串范围有重叠部分
    // const属性会保护src字符串不被覆盖

    char *res = dest;
    for(int i=0; i<min(dest_size, src_size); i++) {
        *dest = *src;
        dest++; src++;
    }

    if(dest_size>src_size)
        *dest = '\0';

    // 如果src字符串的长度比dst的长度长，
    // 则截断src字符串，只拷贝部分src结果过去
    // 因为无法保证dest+dest_size不被其他指针所指

    return res;
}

int FindMedian(int *A, int size_A, int *B, int size_B) {
    return dfs(A, size_A, B, size_B, 0, size_A-1);

}

int dfs(int *A, int na, int *B, int nb, int s, int e) {
    // 二分，假定中位数在A

    int c = (na+nb-1)/2;
    int m = (s+e)/2;

    if(s>e)
        return dfs(B, nb, A, na, 0, nb-1);

    if(A[m]>=B[c-m-1] && A[m]<=B[c-m])
        return A[m];

    if(A[m]<B[c-m-1])
        return dfs(A, na, B, nb, m+1, e);

    //if(A[m]>B[c-m])
    return dfs(A, na, B, nb, s, m-1);

}

int main() {
    return 0;
}
