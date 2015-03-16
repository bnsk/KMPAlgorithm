/*Maximum text length supported is 1000 and maximum pattern length supported is 100*/
#include<stdio.h>
#include<string.h>

int counter=0; //calculates the total number of comparisions made in the KMP algorithm...
void picalculator(char pattern[],int pi[],int patlen)
{
	int i,j;
	pi[0]=0;  //pi[first character in the pattern]=0
	j=0;
	i=1;
	while(i<patlen){ // that i is less than the length of pattern
		if(pattern[i]==pattern[j]){
			pi[i]=j+1;
			i++;
			j++;
                        
		}else if(j>0){
			j=pi[j-1];
		}else {
			pi[i]=0;
			i++;
		}counter++;
	} //end of while

}



int kmp_matcher(char text[], char pattern[])
{
	int i,j,F[100];	// the maximum size of Pattern String
	int patlen=strlen(pattern);
	int textlen=strlen(text);
	picalculator(pattern,F,patlen);
	i=0;
	j=0;
	while(i<textlen){
		if(text[i]==pattern[j]){
                       
			if(j==patlen-1)
				return i-j; // means, in (i-j)th position, there is a match occur
			else{
				i++;
				j++;
			}
		}else if(j>0){
			j=F[j-1];
		}else{
			i++;
		} counter++;
	}
	return -1; // No match found
}


int main()
{
	char T[1000],P[100];
          printf("\nPlease enter the text: \n");
	while(gets(T)){
                printf("\nPlease enter the pattern: \n");
		gets(P);
		int pos=kmp_matcher(T,P);
		if(pos!=-1){
			printf("\nString Occur at position:%d \n",pos+1);
                        printf("The number of comparisions required is:%d \n",counter);
		        counter=0; 
                }else{
 			printf("\nNo match found.\n");
                        counter=0; 
                     }
               printf("\nPlease enter the text: \n");
	}

 return 0;
}//end of main...








