#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,*arr;
    printf("enter the number of elements;");
    scanf("%d",&n);
    //allocating memory
    arr=(int*)malloc(n*sizeof(int));
    if(arr==NULL){
        printf("memory of allocation failed\n");
        return 1;
    }
    //taking input
    printf("enter%d elements:\n",n);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    //printing elements
    printf("the elements are:\n");
    for(int i=0; i < n; i++){
        printf("%d ", arr[i]);
    }
    //freeing memory
    free(arr);
    printf("after free %d",*arr);
    return 0;
}
