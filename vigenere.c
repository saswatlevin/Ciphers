#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char cipher_text[14],plain_text[14],key[14];
int num_key[14],num_pt[14],num_ct[14];
int p_length=0,k_length=0;

int get_alpha_order(char c)
{
	if(c=='a'||c=='A')
		return 0;
	else if(c=='b'||c=='B')
		return 1;
    else if(c=='c'||c=='C')
		return 2;
    else if(c=='d'||c=='D')
		return 3;
    else if(c=='e'||c=='e')
		return 4;
    else if(c=='f'||c=='F')
		return 5;
	else if(c=='g'||c=='G')
		return 6;		
    else if(c=='h'||c=='H')
		return 7;
    else if(c=='i'||c=='I')
		return 8;
	else if(c=='j'||c=='J')
		return 9;
    else if(c=='k'||c=='K')
		return 10;
    else if(c=='l'||c=='L')
		return 11;
	else if(c=='m'||c=='M')
		return 12;
	else if(c=='n'||c=='N')
		return 13;
	else if(c=='o'||c=='O')
		return 14;
	else if(c=='p'||c=='P')
		return 15;
	else if(c=='q'||c=='Q')
		return 16;
    else if(c=='r'||c=='R')
		return 17;
	else if(c=='s'||c=='S')
		return 18;
	else if(c=='t'||c=='T')
		return 19;
	else if(c=='u'||c=='U')
		return 20;
	else if(c=='v'||c=='V')
		return 21;
	else if(c=='w'||c=='W')
		return 22;
	else if(c=='x'||c=='X')
		return 23;
	else if(c=='y'||c=='Y')
		return 24;
	else if(c=='z'||c=='Z')
		return 25;
	else
	{
		printf("\nNot a valid alphabet");
		return 26;
	}
}


char conv_num_char(int i)
{
	if(i==0)
		return 'A';
	else if(i==1)
		return 'B';
	else if(i==2)
		return 'C';
	else if(i==3)
		return 'D';
	else if(i==4)
		return 'E';
	else if(i==5)
		return 'F';
	else if(i==6)
		return 'G';
	else if(i==7)
		return 'H';
	else if(i==8)
		return 'I';
	else if(i==9)
		return 'J';
	else if(i==10)
		return 'K';
    else if(i==11)
		return 'L';
	else if(i==12)
		return 'M';
	else if(i==13)
		return 'N';
	else if(i==14)
		return 'O';
	else if(i==15)
		return 'P';
	else if(i==16)
		return 'Q';
	else if(i==17)
		return 'R';
	else if(i==18)
		return 'S';
	else if(i==19)
		return 'T';
	else if(i==20)
		return 'U';
	else if(i==21)
		return 'V';
	else if(i==22)
		return 'W';
	else if(i==23)
		return 'X';
	else if(i==24)
		return 'Y';
	else if(i==25)
		return 'Z';
	else
	{	
		printf("\nCharacter Bound overshot\n");
		return 'e';
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