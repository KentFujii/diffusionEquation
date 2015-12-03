#include<stdio.h>
#include <stdlib.h>
#include <time.h>	
#include<math.h>
#define M 201   /*x‚Ì•ªŠ„”*/
#define N 101     /*t‚Ì•ªŠ„”*/

int main(void) {
FILE *outputfile;

int j,n;      /*x¨j,t¨n*/
double u[M][N];  /* u[x][t] */  
double xmax,xmin,tmax,tmin,c,h,k,r,x,t;
double pi,f[M],E1,E2,E[M][N],S;
xmax=100.0;
xmin=-100.0;
tmax=10.0;
tmin=0.0;
c=1.0;    /*ŠgUŒW”*/
pi=atan(1.0)*4.0;

h=(double)(xmax-xmin)/(M-1);        /*x‚Ì•ªŠ„*/
k=(double)(tmax-tmin)/(N-1);            /*t‚Ì•ªŠ„*/
r=c*k/(h*h);

for(j=0;j<M-1;j++){   
u[j][0]=0;                    
}
//u[10][0]=100.0; 	/* ‰ŠúğŒ*/

for(n=0;n<N;n++){

u[0][n]=0.0;                   /* ‹«ŠEğŒ*/	
u[M-1][n]=0.0;      
}


/*‚±‚±‚É”MŒ¹‚ğ‰Á‚¦‚é*/
for(n=1;n<N;n++){   /*”MŠj‚ğ¶¬*/
for(j=0;j<M;j++){

x=(double)(xmin+h*j);
t=(double)(tmin+k*n);
E1=pow(4*c*pi*t,0.5);
E2=exp(-(x*x)/(4*c*t));
E[j][n]=E2/E1;
}
}

//“ü—Í
for(j=0;j<M;j++){
x=(double)(xmin+h*j);
f[j] = x;
//f[j] =(double)1.0/((rand() % 100 ) + 1);
}


for(n=0;n<N-1;n++){  /*·•ª‰»‚Ì®*/
for(j=1;j<M-1;j++){
u[j][n+1]=(1.0-2.0*r)*u[j][n]+r*(u[j+1][n]+u[j-1][n])+k*E[j][n]*f[j];   

}
}

for(n=0;n<N;n++){
for(j=0;j<M;j++){

x=(double)(xmin+h*j);
t=(double)(tmin+k*n);

//printf("x=%lf, t=%lf, u=%lf \n",x,t,u[j][n]);
}
//printf("\n");
}


for(j=0;j<M;j++){
printf("f(x)=%lf\n",f[j]);
}
printf("\n");

n=N-1;
t=(double)(tmin+k*n);
printf("t=%lf\n\n",t);

for(j=0;j<M;j++){

x=(double)(xmin+h*j);
	printf("x=%lf u(x,1)=%lf\n",x,u[j][N-1]);/*j¨x,n¨t*/
}
if(r<=1.0/2.0){
	printf("available\n");
}else{
	printf("unavailable\n");
}

 //‡–â‘è‚Ì‰ğ‚ğ‘‚«o‚·ƒvƒƒOƒ‰ƒ€
outputfile=fopen("example_out.1.dat","w");    


for(j=0;j<M;j++){
n=N-1;
x=(double)(xmin+h*j);
t=(double)(tmin+k*n);
	fprintf(outputfile,"%lf %lf\n",x,u[j][N-1]);/*j¨x,n¨t*/

}
fclose(outputfile);

//ŠÏ‘ªƒf[ƒ^‚ğ‘‚«o‚·ƒvƒƒOƒ‰ƒ€
outputfile=fopen("example_in.1.dat","w");    

for(j=0;j<M;j++){
n=N-1;
x=(double)(xmin+h*j);
t=(double)(tmin+k*n);
	fprintf(outputfile,"%lf\n",u[j][N-1]);/*j¨x,n¨t*/
}

return 0;
}