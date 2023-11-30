#include<stdio.h>
#include<string.h>
int main()
{
	char plaintext_alphabet[]="abcdefghijklmnopqrstuvwxyz";
	char ciphertext_alphabet[]="zyxwvutsrqponmlkjihgfedcba";
	
	int lookup_table[26],i;
	for(i=0;i<26;i++)
	{
		lookup_table[i]=ciphertext_alphabet[plaintext_alphabet[i]-'a'];
	}
	char plaintext[100];
	printf("enter plaintext message:");
	scanf("%s",plaintext);
	
	char ciphertext[100];
	for(i=0;i<strlen(plaintext);i++)
	{ 
		ciphertext[i]=lookup_table[plaintext[i]-'a'];
	}
	printf("the cipher text message is: %s\n",ciphertext);
}
