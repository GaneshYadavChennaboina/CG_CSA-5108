#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define size 5
void findposition(char matrix[size][size],char ch,int *row,int *col)
{
	if(ch=='J')
	ch='I';
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			if(matrix[i][j]==ch)
			{
				*row=i;
				*col=j;
				return;
			}
		}
	}
 } 
 
 void encrypt(char matrix[size][size],char a,char b,char *result)
 {
 	int row1,col1,row2,col2;
 	findposition(matrix,a,&row1,&col1);
 	findposition(matrix,b,&row2,&col2);
 	
 	if(row1==row2)
 	{
 		result[0]=matrix[row1][(col1+1)%size];
 		result[1]=matrix[row2][(col2+1)%size];
	}
	 else if(col1==col2)
	 {
	 	result[0]=matrix[(row1+1)%size][col1];
	 	result[1]=matrix[(row1+2)%size][col2];
	 }
	 else
	 {
	 	result[0]=matrix[row1][col1];
	 	result[1]=matrix[row2][col2];
	 }
 }
 int main()
 {
 	char matrix[size][size]={
 		                     {'M', 'F', 'H', 'I', 'K'},
                             {'U', 'N', 'O', 'P', 'Q'},
                             {'Z', 'V', 'W', 'X', 'Y'},
                             {'E', 'L', 'A', 'R', 'G'},
                            {'D', 'S', 'T', 'B', 'C'}
	                        };
	                        char message[]="MUSTSEEYOUOVERCADOGANWESTCOMINGATONCE";
	                        int len=strlen(message);
	                        for(int i=0;i<len;i++)
	                        {
	                        	if(message[i]=='J')
	                        	message[i]='I';
	                        	message[i]=toupper(message[i]);
							}
							
							char encryptedmessage[len *2];
							int count=0;
							for(int i=0;i<len;i+=2)
							{
								char a=message[i];
								char b=(i+1<len)?message[i+1]:'X';
								encrypt(matrix,a,b,&encryptedmessage[count]);
								count+=2;
							}
							printf("encrypted message:%s\n",encryptedmessage);
							
 }
