#include<stdio.h>
#include <stdlib.h>
#include <time.h>	
#include<math.h>
#define M 101   /*x,y‚Ì•ªŠ„”*/

int main(void) {
FILE *outputfile;

double x,xmax,xmin,h;
int j;
double B[M];	

xmax=5.0; xmin=-5.0;

h=(double)(xmax-xmin)/(M-1);        //x‚Ì•ªŠ„

//—]Œë·ŠÖ”
for(j=0;j<M;j++){
	x=(double)(xmin+h*j);
	B[j]=erfc(x);
	printf("x=%lf	erfc=%lf\n",x,B[j]);
}

outputfile=fopen("erfc.dat","w");    

for(j=0;j<M;j++){

x=(double)(xmin+h*j);
	fprintf(outputfile,"%lf	%lf\n",x,1.0-B[j]);//j¨x,i¨y

}
fclose(outputfile);
return 0;
}