
/* convert given hexadecimal string to integer value */

#include<stdio.h>

#define MAXLEN 1024

unsigned long int htoi(char s[]){
	int c,i,j;
	unsigned long int n;
	
	
	n=0;
	for(i=0;s[i]!='\0';++i){
		c=s[i];
		if(i==0 && c=='0' &&(s[1]=='x' || s[1]=='X')){
			i=1; continue;
		}
		n*=16;
		if(c>='0' && c<='9')
			n+=c - '0';
		else if(c>='a' && c<='z')
			n+=c - 'a';
		else if(c>='A' && c<='Z')
			n+=c - 'A';
	}
	return n;
}


int get_line(char s[], int maxlen){
	int c, i, j;

	for(i=0, j=0; (c=getchar())!=EOF && c!='\n'; ++i){
		if(i<maxlen-1)
			s[j++]=c;
	}
	s[j]='\0';

	return j;	
}

int main(){
	int len;
	char line[MAXLEN];
	while((len=get_line(line, MAXLEN))>0){
		printf("%lu\n",htoi(line));
	}
	return 0;
}

