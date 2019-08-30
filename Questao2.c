#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int pos(int x, int y, int z, int np, int nc, int nl){
    return (z*(nc*nl)) + (x*nl) + y;
}


float Distancia(int x1,int y1,int z1,int x2,int y2,int z2){
float dis;

dis = sqrt(pow(x1-x2,2)+pow(y1-y2,2)+pow(z1-z2,2));

return dis;
}

void Esfera(int *x,int tam,int np,int nl,int nc,int raio){

int xc =8,yc =8,zc =8;
float dist;
printf("Digite o centro da esfera: %d %d %d",xc,yc,zc);


for(int i = 0;i<nl;i++){
    for(int j = 0;j<nc;j++){
        for(int k = 0;k<np;k++){
                printf(" %f",Distancia(xc,yc,zc,i,j,k));
           if(Distancia(xc,yc,zc,i,j,k)<raio){
              x[pos(i,j,k,np,nc,nl)] = 1;
           }
            else{
                    x[pos(i,j,k,np,nc,nl)] = 0;
            }
        }
    }

}




}

int main(){
    int *x;
    int np,nc,nl;
    int raio = 8;
    np = 15; nc = 15; nl = 15;

    x = (int*) malloc((np*nl*nc)*sizeof(int));

    Esfera(x,np*nl*nc,np,nl,nc,raio);

for(int i = 0;i<nl;i++){
    for(int j = 0;j<nc;j++){
        for(int k = 0;k<np;k++){
           printf("%d",x[pos(i,j,k,np,nc,nl)]);

        }
        printf("\n");
    }
    printf("\n");

}


    return 0;
}
