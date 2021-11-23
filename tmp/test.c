#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

static int pos=0;
static char str[100000];

void bruh(int n,int *arr,int len){
	if(len==n){
		int i=0;
		int this=0;
		while(i<n*2){
			if(arr[this]==i){
				str[pos]='(';
				pos+=1;
				this+=1;
			}else{
				str[pos]=')';
				pos+=1;
			}
			i+=1;
		}
		str[pos]='\n';
		pos+=1;
		return;
	}
	int i=arr[len-1]+1;
	while(i<len*2+1){
		arr[len]=i;
		bruh(n,arr,len+1);
		i+=1;
	}
}

int main(){
	int i;
	int a;
	int arr[1000];
	//int str[1000];
#ifndef DEBUG
	/* while(scanf("%d",&a)!=EOF) { */
		/* bruh(a,arr,1); */
	/* } */
	printf("456\n");
#endif
#ifdef DEBUG
	/* scanf("%d",&a); */
	/* bruh(a, arr, 1); */
	printf("123\n");
#endif
	str[pos]='\0';
	printf("%s",str);
}







