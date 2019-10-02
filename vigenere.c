#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

char cipher_text[14],plain_text[14],key[14];
int num_key[14],num_pt[14],num_ct[14];
int p_length=0,k_length=0;

int get_alpha_order(char c)
{
	if(isalpha(c))
	{
		return tolower(c) - 'a';
	} 
	else 
	{
		printf("\nNot a valid alphabet");
		return 26;
	}
}


char conv_num_char(int i)
{
	if(i > 25)
	{
		printf("\nCharacter Bound overshot\n");
		return 'e';
	}
	else
	{
		return 'A' + i;	
	}
}


void test()
{
	char str[5]={'A','B','C','D'};
	int arr[5];
	int i=0;
    int length=strlen(str);
    for(i=0;i<length;++i)
    {
    	arr[i]=	get_alpha_order(str[i]);
    }   
   
   for(i=0;i<4;++i)
   printf("unprocessed=%d ",arr[i]);
   
   for(i=0;i<strlen(str);++i)
   {
   	str[i]=conv_num_char(arr[i]);
   }
   printf("\nProcessed=%s",str);
}


void encrypt(){
int i=0;


printf("\nEnter the key\t");
	scanf("%s",key);
	printf("\nEnter the plaintext\t");
	scanf("%s",plain_text);
    p_length=strlen(plain_text);
	k_length=strlen(key);
	//p_length=p_length-1;
	//k_length=k_length-1;
	for(i=0;(strlen(key))!=p_length;++i)
	{
    //if(())
    key[k_length+i]=key[i];
	
	}
    
    for(i=0;i<p_length;++i)
    {
    	num_pt[i]=get_alpha_order(plain_text[i]);
        num_key[i]=get_alpha_order(key[i]);
    }	

     

    
    printf("\nEn Num key\n");
    for(i=0;i<p_length;++i)
    printf("%d\t",num_key[i]);
    
    printf("\nEn Num pt\n");
    for(i=0;i<p_length;++i)
    printf("%d\t",num_pt[i]);
    


     for(i=0;i<p_length;++i)
    {
    	num_ct[i]=(num_pt[i]+num_key[i%k_length])%26;
    }	
    
    
     printf("\nEn Num ct\n");
    for(i=0;i<p_length;++i)
    printf("%d\t",num_ct[i]);

    for(i=0;i<p_length;++i)
    {
    	cipher_text[i]=conv_num_char(num_ct[i]);
    }	



printf("\nThe plaintext is=%s",plain_text);
printf("\nThe key is=%s",key);

printf("\nThe cipher text is=%s",cipher_text);


}

void decrypt()
{
int i=0,c_length=0,k_length=0;

    //c_length=strlen(cipher_text);
	//k_length=strlen(key);
	//p_length=p_length-1;
	//k_length=k_length-1;
	
     
    for(i=0;i<c_length;++i)
    {
    	num_ct[i]=get_alpha_order(cipher_text[i]);
        num_key[i]=get_alpha_order(key[i]);
    }	

     for(i=0;i<c_length;++i)
    {
    	num_pt[i]=abs((num_ct[i]-num_key[i%k_length]))%26;
    }	
    
    printf("\nDe Num ct\n");
    for(i=0;i<c_length;++i)
    printf("%d\t",num_ct[i]);
    
    printf("\nDe Num key\n");
    for(i=0;i<c_length;++i)
    printf("%d\t",num_key[i]);
    
    printf("\nDe pt\n");
    for(i=0;i<c_length;++i)
    printf("%d\t",num_pt[i]);
    
    for(i=0;i<c_length;++i)
    {
    	plain_text[i]=conv_num_char(num_pt[i]);
    }	



printf("\nThe ciphertext is=%s",cipher_text);
printf("\nThe key is=%s",key);

printf("\nThe decrypted plaintext is=%s",plain_text);
}

int main()
{
//test();	
encrypt();	
decrypt();
return 0;	
}