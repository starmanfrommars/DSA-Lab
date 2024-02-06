#include<stdio.h>
#include<stdlib.h> 
#include<string.h>


void patternmatch() {
	int i=0,j=0,p=0;
	while(str[i]!='\0')
	{
		if(str[j]==pat[p])
		{
			p++; j++;
			if(pat[p]=="\0")
			{
				flag = 1;
				for(int k=0 ; rep[k]!='\0' ; k++)
					ans[l] = rep[k];
				p=0; i=j;
			}
		}
		else
		{
			ans[l] = str[i];
			j++; l++;
			j=i;
			p=0;
		}
	}
	ans[l]='\0';
}
void main() {
	 
}
