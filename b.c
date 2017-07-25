#include <stdio.h>
#include <unistd.h> 
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#define BUFFSIZE 100
int main(int argc,char *argv[]){
	const char barran='\n';
	int f=open(argv[1],O_RDONLY);
	if(f<0)
		return 0;
	char s[255];
	int n,nbuf=0,i=0;
	char buffer[BUFFSIZE];
	while(scanf("%s %d",&s[0],&n)){
		if(strcmp(&s[0],"+")==0){
			lseek(f,n,SEEK_CUR);
		}
		if(strcmp(&s[0],"-")==0){
			lseek(f,-n,SEEK_CUR);
		}
		if(strcmp(&s[0],"i")==0){
			lseek(f,n,SEEK_SET);
		}
		if(strcmp(&s[0],"f")==0){
			lseek(f,-n,SEEK_END);
		}
		if(strcmp(&s[0],"r")==0){
			if(n+nbuf<=BUFFSIZE){
				i=read(f,&buffer[nbuf],n);
				if(i<0)
					break;
				nbuf+=i;
			}
		}
		if(strcmp(&s[0],"s")==0 && n==0){
			break;	
		}
	}
	write(1,&buffer,nbuf);
	write(1,&barran,1);
	
	
	
	
	
	
	
	return 0;
}
