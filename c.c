#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>


int main(int argc, char *argv[])
{
	int flag=0;
	char s[250],c[250];
	scanf("%s %s",&s[0],&c[0]);
	struct stat mode1,mode2;
	if(stat(s,&mode1)<0){
		printf("Error\n");
		return 0;
	}
	if(stat(c,&mode2)<0){
		printf("Error\n");
		return 0;
	}
	if( (mode1.st_mode & S_IFDIR) == S_IFDIR ) {
		printf("Files Unhandled Types\n");
		return 0;	
	}
	if( (mode2.st_mode & S_IFDIR) == S_IFDIR ) {
		printf("Files Unhandled Types\n");
		return 0;	
	}
	if(((mode1.st_mode & S_IFREG) == S_IFREG) && ((mode2.st_mode & S_IFREG) == S_IFREG)){
		if(mode1.st_size==mode2.st_size)
			printf("Size Same\n");
		else{
				printf("Size Different\n");
				flag=1;
			}
		if(mode1.st_blocks==mode2.st_blocks)
			printf("Used Blocks Same\n");
		else{
				printf("Used Blocks Different\n");
				flag=1;
		}
		if((mode1.st_mode  & S_IRWXU) == (mode2.st_mode & S_IRWXU))
			printf("User Permissions Same\n");
		else{
				printf("User Permissions Different\n");
				flag=1;
			}
		if((mode1.st_mode & S_IRWXG )==(mode2.st_mode & S_IRWXG))
			printf("Group Permissions Same\n");
		else{
				printf("Group Permissions Different\n");
				flag=1;
			}
		if((mode1.st_mode & S_IRWXO)==(mode2.st_mode & S_IRWXO))
			printf("Other Permissions Same\n");
		else{
				printf("Other Permissions Different\n");
				flag=1;
			}
		if(flag==0)
			printf("Files Same\n");
		else{
				printf("Files Different\n");
			}
	}
	return 0;
}


