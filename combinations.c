#include <stdio.h>
#include <stdlib.h>

void givenumbers(int *,int *);
int search(int *,int *,int *);
void zeygos1(int *, int *);
void zeygos2(int *, int *);
int *desmeusi(int);
void taxinomisi(int *, int);
void combinations(int *,int*, int, int , int, int, int);
int check1(int *, int, int, int ,int , int ,int ,int, int);
int check2(int *, int, int, int ,int , int ,int ,int, int);
void messages(int , int , int , int );
void freearray(int *, int);
void message(int *, int *, int );
int main(int argc, char *argv[]) {
	
	system("chcp 1253");
	
	int n,i,x1,x2,y1,y2;
	
	int *array;
	int *plithos;
	do{
	printf("Εισάγετε το πλήθος των αριθμών που θέλετε να εισάγετε(7 έως 49): ");
	scanf("%d",&n);
	}
	while(n <=6 || n >=49);
	array=desmeusi(n);
	plithos=desmeusi(n);
	givenumbers(array,&n);
	zeygos1(&x1,&x2);
	zeygos2(&y1,&y2);
	taxinomisi(array,n);
	combinations(array,plithos,n,x1,x2,y1,y2);
	freearray(array,n);
	freearray(plithos,n);
	return 0;
}

void givenumbers(int *array, int *pt){
	int a,n,x;
	n=0;
	printf("Εισάγετε αριθμούς από το 1 έως το 49\n");
	
	do{
		do{
			printf("Εισάγετε το %d στοιχείο: ",n+1);
			scanf("%d",&a);
			if(a>49)
			printf("Πρέπει να δώσετε αριθμούς από το 1 εώς το 49\n" );
			if (n>0){
			x=search(array , &n ,&a);
			if (x==0)
			printf("δώστε άλλον αριθμό(τον έχετε εισάγει ήδη)\n");
			}
			else x=1;
		}
		while (a>49 || x==0 );
		*(array+n)=a;
		n++;
	}
	while(n!= *pt);
}

int search (int *array,int *n, int *a){
	int i,x;
	x=1;
	for(i=0; i< *n ; i++){
		if (*(array+i)== *a )
		x=0;
	}
	return x;

}

void zeygos1( int *x1, int * x2){
	 int a,b;
	printf("εισάγετε έναν αριθμό από το 0 έως το 6\n");
	do{
		scanf("%d",&a);
		if (a>6 || a< 0)
		printf("Εισάγατε λάθος αριθμό\n");
	}
	while(a<0 || a>6);
	printf("Εισάγετε έναν αριθμό από το %d έως το 6\n",a);
	do{
		scanf("%d",&b);
		if (a>b || b>6)
		printf("Εισάγατε λάθος αριθμό\n");
	}
	while(b<a || b>6);
	*x1=a;
	*x2=b;
}

void zeygos2( int *y1, int * y2){
	int a,b;
	printf("εισάγετε έναν αριθμό από το 21 έως το 279\n");
	do{
		scanf("%d",&a);
		if (a>279 || a< 21)
		printf("Εισάγατε λάθος αριθμό\n");
	}
	while(a<21 || a>279);
	printf("Εισάγετε έναν αριθμό από το %d έως το 279\n",a);
	do{
		scanf("%d",&b);
		if (a>b || b>279)
		printf("Εισάγατε λάθος αριθμό\n");
	}
	while(b<a || b>279);
	*y1=a;
	*y2=b;
}

int *desmeusi(int n){
	int	*pin;
	pin=(int*)calloc(n,sizeof(int));
	return pin;
}

void taxinomisi(int *array,int n){
	int i,j,b;
	for(i=1; i<n;i++){
		for(j=n-1;j!=i-1;j--){
			if (*(array+(j-1))>*(array+j)){
				b=*(array+(j-1));
				*(array+(j-1))=*(array+j);
				*(array+j)=b;
			
			}
		}
	}
}

void combinations(int *array,int *pl,int o,int x1, int x2, int y1, int y2){
	int i,j,k,l,m,n;
	int pl1=0;
	int pl2=0;
	int totalpl=0;
	int printpl=0;
	for(i=0;i<=o-6;i++ ){
			for(j=i+1;j<=o-5;j++ ){
					for(k=j+1;k<=o-4;k++ ){
							for(l=k+1;l<=o-3;l++ ){
									for(m=l+1;m<=o-2;m++ ){
											for(n=m+1;n<=o-1;n++){
												totalpl++;
												if(check1(array,i,j,k,l,m,n,x1,x2)){
													if(check2(array,i,j,k,l,m,n,y1,y2)){
														*(pl+i)=*(pl+i)+1;
														*(pl+j)=*(pl+j)+1;
														*(pl+k)=*(pl+k)+1;
														*(pl+l)=*(pl+l)+1;
														*(pl+m)=*(pl+m)+1;
														*(pl+n)=*(pl+n)+1;
														printf("%d  %d  %d  %d  %d  %d \n",*(array+i),*(array+j),*(array+k),*(array+l),*(array+m),*(array+n));
														printpl++;
													}
													else pl2++;
											}
											else pl1++;
										}
									}
							}
					}
			}
	}
	messages(totalpl,printpl,pl1,pl2);
	message(pl,array,o);
}

int check1(int *array,int i,int j,int k,int l,int m,int n,int x1, int x2){
	int plithos=0;
	if (*(array+i)%2)
		plithos++;
	if (*(array+j)%2)
			plithos++;
	if (*(array+k)%2)
			plithos++;
	if (*(array+l)%2)
		plithos++;
	if (*(array+m)%2)
		plithos++;
	if (*(array+n)%2)
		plithos++;										
	if (plithos>=x1 && plithos<=x2)
		return 1;
	else return 0;
}


int check2(int *array,int i,int j, int k, int l,int m, int n, int y1, int y2){
	int s;
	s=*(array+i)+*(array+j)+*(array+k)+*(array+l)+*(array+m)+*(array+n);
	if (s>=y1 & s<=y2)
		return 1;
	else return 0;
}


void messages(int a, int b, int c, int d){

	printf("Το συνολικό πλήθος των συνδυασμών είναι: %d\n",a);
	printf("Το πλήθος των συνδυασμών που τυπώθηκαν είναι: %d\n", b);
	printf("Το πλήθος των συνδυασμών που δεν πληρούσαν τον πρώτο όρο είναι: %d\n",c);
	printf("Το πλήθος των συνδυασμών που πληρούσαν τον πρώτο, αλλα δεν πληρούσαν τον δεύτερο όρο είναι: %d\n",d);
}


void freearray(int *array, int n){
	free(array);
}

void message(int *pl, int *ar, int o){
	int i;
	for(i=0;i<o;i++){
		printf("Η συχνότητα εμφάνισης του αριθμού %d είναι: %d\n",*(ar+i),*(pl+i));
		
	}
}
