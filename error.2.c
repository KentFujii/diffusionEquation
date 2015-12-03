#include<stdio.h>
#include <stdlib.h>
#include <time.h>	
#include<math.h>
#define M 101   /*x,yの分割数*/
#define N 101     /*tの分割数*/

int main(void) {
FILE *inputfile;
FILE *outputfile;

double x,t,y,z,xmax,xmin,tmax,tmin,h,k,pi;
int j,n,i,q;
double B[M][M],s[M][M],S[M][M],u[M],f[M];	

xmax=100.0; xmin=-100.0;
tmax=100.0; tmin=0.0;
pi=atan(1.0)*4.0;

h=(double)(xmax-xmin)/(M-1);        //xの分割
k=(double)(tmax-tmin)/(N-1);        //tの分割

n=N-1;
t=(double)(tmin+k*n);		//時間の指定
printf("t=%lf\n\n",t);

//観測データを入力
inputfile=fopen("example_in.2.dat","r"); 
for(j=0;j<M;j++){	
	fscanf(inputfile,"%lf",&u[j]);
		if(u[j]==EOF) break;
	x=(double)(xmin+h*j);	
	printf("x=%lf u(x)=%lf\n",x,u[j]);
	}
fclose(inputfile);


//余誤差関数
for(j=0;j<M;j++){
for(i=0;i<M;i++){
	x=(double)(xmin+h*j);
	y=(double)(xmin+h*i);
	z=(fabs(x-y)+fabs(y))/(2*sqrt(t));
	B[j][i]=erfc(z)/(2*sqrt(pi));
        //printf("x=%lf y=%lf %lf\n",x,y,B[j][i]);//B=erfc(x,y)
}
	//printf("\n");	
}
printf("\n");	

for(j=0;j<M;j++){	//シンプソン積分法 畳み込み

y=(double)(xmin+h*0);
s[j][0]=B[j][0]*y*y*h/3.0;
y=(double)(xmin+h*(M-1));
s[j][M-1]=B[j][M-1]*y*y*h/3.0;

for(i=1; i<=(M-1)/2;i++){
	y=(double)(xmin+h*(2*i-1));
	s[j][2*i-1]=4.0*B[j][2*i-1]*y*y*h/3.0;
}

for(i=2; i<=(M-1)/2;i++){
	y=(double)(xmin+h*(2*i-2));
	s[j][2*i-2]=2.0*B[j][2*i-2]*y*y*h/3.0;
}
S[j][0]=s[j][0];
for(i=1; i<M;i++){
	S[j][i]=(S[j][i-1]+s[j][i]);//積分結果=S[j][M-1]=integralB(x)xx
}
	x=(double)(xmin+h*j);
	printf("x=%lf ΣB3=%lf\n",x,S[j][M-1]);
}
printf("\n");

for(j=0;j<M;j++){	//f(x)=u(x)/integralB(x)
	f[j]=u[j]/S[j][M-1];
	x=(double)(xmin+h*j);
	printf("%lf\n",f[j]);
}


//解を書き出すプログラム f(x)
outputfile=fopen("error_2.dat","w");    


for(j=0;j<M;j++){

x=(double)(xmin+h*j);
	fprintf(outputfile,"%lf %lf %lf\n",x,f[j],1.0);//j→x,i→y

}
fclose(outputfile);
return 0;
}