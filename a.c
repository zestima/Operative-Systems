#include <stdio.h>
#include <string.h>
void streamCopy (FILE * entrada, int showLines,int showCaracters, int showWords, int showDigits)
{
	int l = 0, c = 0, p = 0, d = 0, state = 0;
	int ch = fgetc (entrada);
	while (ch != EOF){
		if ('\n' == ch){
			l++;
		}
		if (ch == ' ' || ch == '\n' || ch == '\t'){
			state = 0;
		}
		else if (state == 0){
			state = 1;
			p++;
		}
		if (ch >= '0' && ch <= '9'){
			d++;
		}
		c++;
		ch = fgetc (entrada);
	}
	if (showLines != 0)
		printf ("linhas %d ", l);
	if (showWords != 0)
		printf ("palavras %d ", p);
	if (showDigits != 0)
		printf ("digitos %d ", d);
	if (showCaracters != 0)
		printf ("chars %d ", c);
	printf ("\n");
}

int main(int argc, char **argv)
{
	int i;
	int showLines = 0;
	int showCaracters = 0;
	int showDigits = 0;
	int showWords = 0;
	if (argc == 1){
		showLines = 1;
		showWords = 1;
		showCaracters = 1;
		streamCopy (stdin, showLines, showCaracters, showWords, showDigits);
    }
    if(argc>1){
		for (i = 1; i < argc; i++){
			if (strcmp (argv[i], "-l") == 0)
				showLines = 1;
			if (strcmp (argv[i], "-p") == 0)
				showWords = 1;
			if (strcmp (argv[i], "-d") == 0)
				showDigits = 1;
			if (strcmp (argv[i], "-c") == 0)
				showCaracters = 1;
		}
		if (showLines == 0 && showWords == 0 && showCaracters == 0 && showDigits == 0){
			showLines = 1;
			showWords = 1;
			showCaracters = 1;
		}
		char s[255];
		strcpy (s, argv[argc - 1]);
		if (s[0] == '-'){
			streamCopy (stdin, showLines, showCaracters, showWords, showDigits);
		}
		else{
			FILE *fp;
			fp = fopen (argv[argc - 1], "r");
			if (fp == NULL){
				return 0;
			}
			streamCopy (fp, showLines, showCaracters, showWords,showDigits);
		}
	}
	return 0;
}

