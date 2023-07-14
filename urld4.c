#include <stdio.h>
#include <ctype.h>

void decode(char *input){
	char *ptr = input;
	char c,ch1='\0',ch2='\0';
	while(*ptr){
		if(*ptr!='%'){
			printf("%c",*ptr);
		}
		else{
			ptr++;
			if(isdigit(*ptr)){
				ch1 = (*ptr-'0')*16;
				ptr++;
				if(isdigit(*ptr)){
					ch2 = *ptr-'0';
				}
				else{
					ch2 = *ptr-'A'+10;
				}
				c = ch1 + ch2;
			}
			else{
				ch1 = (*ptr-'A'+10)*16;
				ptr++;
				if(isdigit(*ptr)){
                                        ch2 = *ptr-'0';
                                }
                                else{
                                        ch2 = *ptr-'A'+10;
                                }
				c = ch1 + ch2;
			}
			printf("%c",c);
		}
		ptr++;
	}
}




int isError(char *input){
	char *ptr = input;
	while(*ptr){
		if(*ptr=='%'){
			ptr++;
			if(((*ptr < 'A' || *ptr > 'F') && !isdigit(*ptr)) || (((*(ptr+1) < 'A' || *(ptr+1) > 'F')) && !isdigit(*(ptr+1))))
			{	
				printf("error format\n");
				return 1;
			}
		}
		else{
			ptr++;
		}
	}
	return 0;
}




int main(){
	char input[10000];
	int check=0;

	while(fgets(input,10000,stdin)){
		check =isError(input);	
		if(check){
			continue;
		}
		decode(input);
	}
}
