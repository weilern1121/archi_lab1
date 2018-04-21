#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//change the extern to my funcs
/*
void wordCounter (char * a, int length);
void wordCounter2 (char * a);
int getSentence(char* a);
*/


int main(int argc, char **argv) {
    int i,flag=0;
    FILE * output;
//    char inputText[1024];
    for(i=1; i<argc; i++){
      if(strcmp(argv[i],"-i")==0){
	i++;
	output= fopen(argv[i],"r");
      //check  that able to read from the file
      if(output == NULL) {
      	perror("Error opening file");
      	return(-1);
      }
	flag=1;
	}
    }
	//flag==0 -> text from typing 
	//flag==1 -> text from file
    if(flag==0)
        output=stdout;
    int w=0,c=0,l=0,n=0;
    i=1;
    //space=1 if there was a space in the previous char, else- space=0
    int space=0,counter=0,thereIsChar=0,charCount=0,maxChars=0,tmpchars=0,ncount=1;
    char tmp;
    if(flag==0)
       tmp= (char) fgetc(stdin);
    else
       tmp= (char) fgetc(output);
/*
    //if c and l are 0->the default is w->increase w
    if(c==0&&l==0)
        w++;
*/
    if (tmp != ' ' && tmp != '\t' && tmp != '\n'){
	thereIsChar = 1;
	//tmpchars=1;
	}
    while(tmp!=EOF) {
        //w block -> num of words
        
            if (tmp == ' ' || tmp == '\t' || tmp == '\n')
                space = 1;
            else {
               // thereIsChar = 1;
                if (space == 1) {
                    space = 0;
                    counter++;
                }
            }

        //c block -> numof chars that aren't space
            if (tmp != ' ' && tmp != '\t' && tmp != '\n')
                charCount++;
        
        //l block -> num of chars in the longest word        
            if (tmp != ' ' && tmp != '\t' && tmp != '\n'){
               tmpchars++;
	    if(tmpchars>maxChars)
                maxChars=tmpchars;

		}
            else{
                if(tmpchars>maxChars)
                    maxChars=tmpchars;
                tmpchars=0;
            }

        //n block -> num of \n
	if(tmp=='\n')
	   ncount++;

	//read the next char
            //fputc(tmp, output);
 	  if(flag==0)
	       tmp= (char) fgetc(stdin);
 	   else
 	       tmp= fgetc(output);
        
    }

    //the commands ->should be done by the insertion order
    for(i=1; i<argc; i++){
        if(strcmp(argv[i],"-w")==0){
		if(thereIsChar==1)
           	counter++;
	        printf("\nnum of words=%d \n",counter);
		w++;
            }
        else{
            if(strcmp(argv[i],"-c")==0){
                c++;
		printf("\nnum of chars=%d \n",charCount);
		}
            else{
                if(strcmp(argv[i],"-l")==0){
                    l++;
		    printf("\nnum of chars in the longest word=%d \n",maxChars);
		}
		else{
  	              if(strcmp(argv[i],"-n")==0){
  	                  n++;
			    printf("\nnum of lines=%d \n",ncount);
		}
            }
            }
        }
    }

    //need to check if there wasn't any w\l\c ->default print=w
    if(w==0&&c==0&&l==0&&n==0){
        if(thereIsChar==1)
            counter++;
        printf("\nnum of words=%d \n",counter);
    }
/*
    if(c>0)
        printf("\nnum of chars=%d",charCount);
    if(l>0)
        printf("\nnum of chars in the longest word=%d",maxChars);
*/

    if(output!=stdout)
        fclose(output);
    return 0;
}
