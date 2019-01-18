#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(int k,char plain_text[])
{
	int length,i=0;
	
	
    length=strlen(plain_text);
    
    for	(i=0;i<length;++i)
    {
      plain_text[i]=plain_text[i]+k;
    }
    
    printf("\nThe Encrypted message is=%s",plain_text);
    fflush(stdout);
}

void decrypt(int k,char cipher_text[])
{
    
    int length,i=0;
	
	length=strlen(cipher_text);
    
    for	(i=0;i<length;++i)
    {
      cipher_text[i]=cipher_text[i]-k;
    }
    
    printf("\nThe Decrypted message is=%s",cipher_text);
    fflush(stdout);	
}
int main(int argc,char* argv[])
{
    int k,length,i=0;
	char plain_text[100];
	printf("\nEnter key");
	scanf("%d",&k);
	printf("\nEnter plain text to be encrypted\n");
	scanf("%s",plain_text);
    encrypt(k,plain_text);
    decrypt(k,plain_text);
return 0;
}