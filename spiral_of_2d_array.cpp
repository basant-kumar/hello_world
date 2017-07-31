#include <iostream>
#include <cstdio>

using namespace std;

void print_spiral(int *arr,int m,int n){
    int t=0,b=m-1,l=0,r=n-1,dir=0;
    while(t<=b && l<=r){
        if(dir==0){
            for(int i=l;i<=r;++i){
                //printf("%d ",arr[t][i]);
                printf("%d ",*((arr+t*n)+i));
            }
            t++;
        }
        else if(dir==1){
            for(int i=t;i<=b;++i){
                //printf("%d ",arr[i][r]);
                printf("%d ",*((arr+i*n)+r));
            }
            r--; 
        }
        else if(dir==2){
            for(int i=r;i>=l;--i){
                //printf("%d ",arr[b][i]);
                printf("%d ",*((arr+b*n)+i));
            }
            b--;
        }
        else if(dir==3){
            for(int i=b;i>=t;--i){
                //printf("%d ",arr[i][l]);
                printf("%d ",*((arr+i*n)+l));
            }
            l++;
        }
        dir=(dir+1)%4;
    }
}

int main(){
    int m,n;
    printf("enter the size of 2d array as m and n\n");
    scanf("%d%d",&m,&n);
    int arr[m][n];
    printf("enter the elements of the 2d array.......\n");
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            scanf("%d",&arr[i][j]);
        }
    }

    print_spiral((int*)arr,m,n);

    return 0;
}