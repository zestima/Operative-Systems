#include <stdio.h>
#include <stdlib.h>

int myrand () {
  static int valor = 45;
  valor = 73 * valor + 2713;
  valor = (valor % 101);
  return (valor%4);
}

int min(int a,int b,int c,int d){
	if(a==-1)
		return 0;
	if(b==-1)
		return 1;
	if(c==-1)
		return 2;
	if(d==-1)
		return 3;
	if(a<=b && a<=c && a<=d)
		return 0;
	if(b<=a && b<=c && b<=d)
		return 1;
	if(c<=b && c<=a && c<=d)
		return 2;
	if(d<=b && d<=c && d<=a)
		return 3;
	return -1;
}

int max(int a,int b,int c,int d){
	if(a==-1)
		return 0;
	if(b==-1)
		return 1;
	if(c==-1)
		return 2;
	if(d==-1)
		return 3;
	if(a>=b && a>=c && a>=d)
		return 0;
	if(b>=a && b>=c && b>=d)
		return 1;
	if(c>=b && c>=a && c>=d)
		return 2;
	if(d>=b && d>=c && d>=a)
		return 3;
	return -1;
}

void LRU(int n,int *modelos){
	int *montra=(int*)malloc(4*sizeof(int));
	montra[0]=1;
	montra[1]=2;
	montra[2]=3;
	montra[3]=4;
	int conta=0,i,j,flag,aux1=-1,aux2=-1,aux3=-1,aux4=-1;
	for(i=0;i<n;i++){
		flag=0;
		for(j=0;j<4;j++){
			if(montra[j]==modelos[i]){
				flag=1;
				break;
			}
		}
		if(flag==1){
			continue;
		}
		else{
			aux1=-1;
			aux2=-1;
			aux3=-1;
			aux4=-1;
			for(j=0;j<i;j++){
				if(modelos[j]==montra[0])
					aux1=j;
				if(modelos[j]==montra[1])
					aux2=j;
				if(modelos[j]==montra[2])
					aux3=j;
				if(modelos[j]==montra[3])
					aux4=j;
			}
			int x=min(aux1,aux2,aux3,aux4);
			montra[x]=modelos[i];
			conta++;
		}
	}
	printf("LRU : %d\n",conta);
}

void FIFO(int n,int *modelos){
	int *montra=(int*)malloc(4*sizeof(int));
	montra[0]=1;
	montra[1]=2;
	montra[2]=3;
	montra[3]=4;
	int conta=0,i,j,flag,aux=0;
	for(i=0;i<n;i++){
		flag=0;
		for(j=0;j<4;j++){
			if(montra[j]==modelos[i]){
				flag=1;
				break;
			}
		}
		if(flag==1){
			continue;
		}
		else{
			if(aux>3)
				aux=0;
			montra[aux]=modelos[i];
			aux++;
			conta++;
		}
	}
	printf("FIFO : %d\n",conta);
}

void RAND(int n,int *modelos){
	int *montra=(int*)malloc(4*sizeof(int));
	montra[0]=1;
	montra[1]=2;
	montra[2]=3;
	montra[3]=4;
	int conta=0,i,j,flag;
	for(i=0;i<n;i++){
		flag=0;
		for(j=0;j<4;j++){
			if(montra[j]==modelos[i]){
				flag=1;
				break;
			}
		}
		if(flag==1)
			continue;
		else{
			int x=myrand();
			montra[x]=modelos[i];
			conta++;
		}
	}
	printf("Rand : %d\n",conta);
}

void IDEAL(int n,int *modelos){
	int *montra=(int*)malloc(4*sizeof(int));
	montra[0]=1;
	montra[1]=2;
	montra[2]=3;
	montra[3]=4;
	int conta=0,i,j,flag,aux1=-1,aux2=-1,aux3=-1,aux4=-1;
	for(i=0;i<n;i++){
		flag=0;
		for(j=0;j<4;j++){
			if(montra[j]==modelos[i]){
				flag=1;
				break;
			}
		}
		if(flag==1){
			continue;
		}
		else{
			aux1=-1;
			aux2=-1;
			aux3=-1;
			aux4=-1;
			for(j=i;j<n;j++){
				if(modelos[j]==montra[0] && aux1==-1)
					aux1=j;
				if(modelos[j]==montra[1] && aux2==-1)
					aux2=j;
				if(modelos[j]==montra[2] && aux3==-1)
					aux3=j;
				if(modelos[j]==montra[3] && aux4==-1)
					aux4=j;
			}
			int x=max(aux1,aux2,aux3,aux4);
			montra[x]=modelos[i];
			conta++;
		}
	}
	printf("IDEAL : %d\n",conta);
	
	
}

int main(int argc, char **argv)
{
	int n;
	scanf("%d\n",&n);
	if(n>=100)
		return 0;
	int *modelos=(int*)malloc(n*sizeof(int));
	int i,valor;
	for(i=0;i<n;i++){
		scanf("%d",&valor);
		if(valor<1 || valor>10)
			return 0;
		modelos[i]=valor;
	}
	LRU(n,modelos);
	RAND(n,modelos);
	FIFO(n,modelos);
	IDEAL(n,modelos);
	return 0;
}

