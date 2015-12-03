#include<stdio.h>
#include <stdlib.h>
#include <time.h>	
#include<math.h>
#define M 101   /*x‚Ì•ªŠ„”*/
#define N 101     /*t‚Ì•ªŠ„”*/

int main(void) {
FILE *outputfile;

int j,n;      /*x¨j,t¨n*/
double u[M][N];  /* u[x][t] */  
double xmax,xmin,tmax,tmin,c,h,k,r,x,t;
double pi,f[M],E1,E2,E[M][N],S;
xmax=100.0;
xmin=-100.0;
tmax=100.0;
tmin=0.0;
c=1.0;    /*ŠgUŒW”*/
pi=atan(1.0)*4.0;

h=(double)(xmax-xmin)/(M-1);        /*x‚Ì•ªŠ„*/
k=(double)(tmax-tmin)/(N-1);            /*t‚Ì•ªŠ„*/
r=c*k/(h*h);



for(n=1;n<N;n++){   /*”MŠj‚ğ¶¬*/
for(j=0;j<M;j++){

x=(double)(xmin+h*j);
t=(double)(tmin+k*n);
E1=pow(4*c*pi*t,0.5);
E2=exp(-(x*x)/(4*c*t));
E[j][n]=E2/E1;
}
}

outputfile=fopen("gauss.dat","w");    

//for(n=1;n<N;n++){ 
for(j=0;j<M;j++){
//t=(double)(tmin+k*n);
//x=(double)(xmin+h*j);
	fprintf(outputfile,"%lf %lf\n",x,E[j][n]*x);/*j¨x,n¨t*/

}
//}
fclose(outputfile);

return 0;
}