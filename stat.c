#include<stdio.h>
#include <stdlib.h>
#include <time.h>	
#include<math.h>
#define M 52   /*データ数*/

int main(void) {
FILE *inputfile;

double d[M],D[M],a[M],A,v[M],V;
int j;

//観測データを入力
inputfile=fopen("inputdata.dat","r"); 
for(j=0;j<=M-1;j++){	
	fscanf(inputfile,"%lf",&d[j]);
		if(d[j]==EOF) break;	
	printf("d[%d]=%lf\n",j,d[j]);
	}
fclose(inputfile);

for(j=0;j<=M-1;j++){
	D[j]=1.0-d[j];
}


for(j=1;j<=M-1;j++){
	a[0]=D[0];
	a[j]=(a[j-1]+D[j]);
}

A=a[M-1]/M;
printf("average=%lf\n",A);

for(j=1;j<=M-1;j++){
	v[0]=(D[0]-A)*(D[0]-A);
	v[j]=v[j-1]+(D[j]-A)*(D[j]-A);
}

V=v[M-1]/M;

printf("various=%lf\n",V);

return 0;
}