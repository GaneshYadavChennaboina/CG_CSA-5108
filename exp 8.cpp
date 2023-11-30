#include<stdio.h>
#include<string.h>
#define alphabet_size 26
void generatecipherkey(char keyword[],char cipherkey[])
{
	int keywordlength=strlen(keyword);
	int currentindex=0;
	
	strcpy(cipherkey,keyword);
	currentindex+=keywordlength;
	
	for(char letter='A';letter<='Z';letter++)
	{
		if(strchr(keyword, letter)==NULL)
		{
			cipherkey[currentindex++]=letter;
		}
	}
	cipherkey[currentindex]='\0';
}
void monoalphabeticencrypt(char plaintext[],char cipherkey[],char ciphertext[])
{
	for(int i=0;i<strlen(plaintext);i++)
	{
		if(plaintext[i]>='A' && plaintext[i]<='Z')
		{
			int index=plaintext[i]-'A';
			ciphertext[i]=cipherkey[index];
		}
		else
		{
			ciphertext[i]=plaintext[i];
		}
	}
	ciphertext[strlen(plaintext)]='\0';
}
int main()
{
	char keyword[]="CIPHER";
	char cipherkey[alphabet_size+1];
	char plaintext[]="HELLO WORLD";
	char ciphertext[100];
	
	generatecipherkey(keyword,cipherkey);
	monoalphabeticencrypt(plaintext,cipherkey,ciphertext);
	
	printf("keyword:%s\n",keyword);
	printf("cipher key:%s\n",cipherkey);
	printf("plain text:%s\n",plaintext);
	printf("ciphertext:%s\n",ciphertext);
}
