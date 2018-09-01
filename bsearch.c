#include<stdio.h>
int arr[1000] = {0};
int bsearch(int val, int from, int to)
{

    int mid = (from + to)/2 ;
	if (val>arr[to] || val<arr[from])return -1;
	printf("%s: from=%d, to=%d mid=%d\n",__func__, from, to,mid);
    if ( from > to ){
	    printf("from > to returning -1\n");
        return -1;
    } else if(from == to && val == arr[from] ){
	    printf("from == to, returning 1\n");
        return 1;
    } else if( from == to && val != arr[from]){
	    printf("from == to, but val not found\n");
   		return -1; 
    } else if(arr[from] == val || arr[to] == val ){
	    int idx = arr[from] == val ? from : to ;
	    printf("%d Element found @ %d\n",__LINE__,idx);
		return 1;
	}
    if(arr[from] < val && arr[mid] > val ){
		return bsearch(val, from, mid);
	}else if(arr[mid+1] < val && arr[to] > val){
		return bsearch(val, mid+1, to);
	}else if(arr[mid+1] == val ) { 
	    printf("Element found @ %d\n",mid+1);
		return 1;
	}else if(arr[mid] == val){
	    printf("Element found @ %d\n", mid);
		return 1;
	}else{
		return -1;
	}
}

int main(void)
{
    int i = 0 ;
    int elem = -1 ;
	int j = 0;
    int inputs = 0 ;
    int k = 0;
	scanf("%d", &inputs);
	printf("Scanning %d lines\n", inputs);
	for ( k = 0 ; k < inputs ; k++ ){
			scanf("%d",&i);
			printf("list size : %d\n",i);
			for (j = 0 ; j < i ; j++){
					scanf("%d", &arr[j]);
			}

			scanf("%d", &elem);
			printf("Searching for %d\n", elem);
			printf("Return value is %d\n", bsearch(elem,0,j-1));
	}

}

