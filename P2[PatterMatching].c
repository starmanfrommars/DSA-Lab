#include<stdio.h>

int flag=0,i,j,k,l,m,p;
char str[100], pat[100], rep[100],ans[100];

void readstr() {
	printf("Enter main string : ");
	scanf("%[^\n]",str);
	printf("Enter pattern string : ");
	scanf("%*c%[^\n]",pat);
	printf("Enter replace string : ");
	scanf("%*c%[^\n]",rep);
}

void matchpattern() {
	i=0,j=0,p=0;
	while(str[i]!='\0') {
		if(str[j]==pat[p]) {
			p++; j++;
			if(pat[p]=='\0') {
				flag=1;
				for(k=0 ; rep[k]!='\0' ; k++,l++) {
					ans[l]=rep[k];
				}
				p=0; i=j;
			}
		}
		else {
			ans[l]=str[i];
			i++; l++;
			j=i; p=0;
		}
	}
	ans[l]='\0';
}

void main() {
	readstr();
	matchpattern();
	
	if(flag==1) {
		printf("Pattern found\n");
		printf("Answer string is : %s\n",ans);
	}
	else {	
		printf("No pattern found\n");
	}
}
