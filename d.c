#include <stdio.h>
#include <stdlib.h>

typedef struct grafo{
	int roboid;
	struct grafo *next;
}GRAFO;

GRAFO *makeNode(){
	GRAFO *nv=(GRAFO*)malloc(sizeof(GRAFO));
	nv->next=NULL;
	return (nv);
}

GRAFO *insert(GRAFO *G, GRAFO *nv){
	nv->next=G;
	return (nv);
}

int DFSutil(GRAFO **G,int *visitado,int index,int *percorrido){
	visitado[index]=1;
	GRAFO *nv=G[index];
	while(nv!=NULL){
		if (percorrido[nv->roboid] == 0){//não o percorri
			percorrido[nv->roboid] = 1; //já percorri esta lista (estou nela atm)
			if(DFSutil(G,visitado,nv->roboid,percorrido)==1)
					return 1;
		}
		if(visitado[nv->roboid]==1)
				return 1;
		nv=nv->next;
	}
	visitado[index]=-1;
	return 0;
}

void DFS(GRAFO **G,int size){
	int i;
	int visitado[size],percorrido[size];
	for (i=0;i<size;i++){ 
		visitado[i]=-1;//não visitado
		percorrido[i]=0;//não percorrido
	}
	for(i=0;i<size;i++){
		if(DFSutil(G,visitado,i,percorrido)==1){
			printf("Robots Deadlock\n");
			return;
		}
		
	}
	printf("No Problem\n");
	return;
}

int main(){
	int i=0,robos,ncomp,componentes,cont=0,j,valor;
	scanf("%d %d",&robos,&componentes);
	if(robos<0 || componentes>30)
		return 0;
	GRAFO **G=(GRAFO**)malloc(robos*sizeof(GRAFO*)),*nv;
	int comp[componentes];
	for(i=0;i<componentes;i++){
		comp[i]=-1;
	}
	i=0;
	while(i<(2*robos)){
		scanf("%d",&ncomp); //ler componentes
		if(cont==robos){
			cont=0;
		}
		while(ncomp!=0){
			if(i<robos){ //se as tiverem meter no vetor
				scanf("%d",&valor);
				for(j=0;j<componentes;j++){
						comp[valor-1]=cont;
				}
			}
			else{ //se as quiserem meter no grafo
				scanf("%d",&valor);
				for(j=0;j<componentes;j++){
					if(comp[valor-1]!=-1 && j==valor-1){//apenas colocar indisponíveis
						nv=makeNode();
						nv->roboid=comp[valor-1];
						G[cont]=insert(G[cont],nv);
					}
				}
			}	
			ncomp--;
		}	
		cont++;	
		i++;
	}
	DFS(G,robos);
	return 0;
	
	
	
	
	
}
