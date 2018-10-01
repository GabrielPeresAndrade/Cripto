#include <stdio.h>
#include <stdlib.h>
void inicializacao(unsigned char chave[],unsigned char s[]);
int tamanho(unsigned char chave[]);
unsigned char *geracao_de_fluxo(unsigned char chave[],unsigned char s[],unsigned char texto[]);
unsigned char * converteHexa(unsigned char texto[]);

int main() {
    unsigned char *texto= (unsigned char *) calloc (15000, sizeof (unsigned char));
    unsigned char chave[256];
    int opc;
    unsigned char s[15000];
    unsigned char *cifrado;
    while(opc!=5)
    {
        printf("\nQual opcao deseja?\n1-Entrar com um Texto e uma Chave\n2-Entrar com um Hexa e uma Chave\n3-Encriptografar\n4-Descriptografar\n5-sair\n");
        scanf("%d",&opc);
        getchar();
        switch(opc)
        {
            case 1:
                printf("digite o Texto : ");
                scanf("%[^\n]", texto);
                getchar();
                
                printf("digite a Chave : ");
                scanf("%[^\n]", chave);
                getchar();
                break;
            case 2:
                printf("digite o Hexa : ");
                scanf("%[^\n]", texto);
                texto = converteHexa(texto);
                getchar();
                
                printf("digite a Chave : ");
                scanf("%[^\n]", chave);
                getchar();
                break;
            case 3:
                printf("\n\nCifrado: ");
                inicializacao(chave, s);
                cifrado = geracao_de_fluxo(chave, s, texto);
                break;
            case 4:
                printf("\n\nDescifrado: ");
                inicializacao(chave, s);
                texto = geracao_de_fluxo(chave, s, cifrado);
                break;
            case 5:

                break;
        }
    }
   



    printf("\nFim\n");



    return 1;
}

void inicializacao(unsigned char chave[],unsigned char s[]) {
    int i, j;
    unsigned char tmp;
    unsigned char t[256];
    int tam = tamanho(chave);
    for (i = 0; i < 256; i++) {
        s[i] = i;
        t[i] = chave[i % tam ];
    }

    for (i = 0, j = 0; i < 256; i++) {
        j = ((j + s[i] + t[i]) % 256);
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}

int tamanho(unsigned char chave[]) {
    int i;
    for (i = 0; chave[i] != '\0'; i++);
    return i;
}

unsigned char *geracao_de_fluxo(unsigned char chave[],unsigned char s[],unsigned char texto[]) {
    int i, j, t, k;
    unsigned char tmp;
    unsigned char * cifrado = (unsigned char *) calloc (tamanho(texto), sizeof (unsigned char));
    int tam = tamanho(texto);
    
    for (i = 0, k = 0, j = 0; i < tam; k++) { // ou i+8
        i = (i + 1) % 256;
        j = (j + s[i]) % 256;
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        t = (s[i] + s[j]) % 256;
        cifrado[k] = texto[k] ^ s[t]; 
    }
    
    cifrado[k] = '\0';
    printf(" %s\n", cifrado);
    
    return(cifrado);
}

unsigned char * converteHexa(unsigned char texto[])
{
    int i,j;
    int temp;
    unsigned char * txt = (unsigned char *) calloc (tamanho(texto), sizeof (unsigned char));
    for(i = 0,j=0 ; ((texto[i] != '\0') &&  (texto[i+1] != '\0')); i=i+2,j++)
    {
        if((texto[i]=='a')||(texto[i]=='A'))
        {
            temp = 10*16;
        }else
        {
            if((texto[i]=='b')||(texto[i]=='B'))
            {
                temp = 11*16;
            }
            else
            {
                 if((texto[i]=='c')||(texto[i]=='C'))
                {
                    temp = 12*16;
                }
                else
                {
                     if((texto[i]=='d')||(texto[i]=='D'))
                    {
                        temp = 13*16;
                    }
                    else
                    {
                         if((texto[i]=='e')||(texto[i]=='E'))
                        {
                            temp = 14*16;
                        }
                        else
                        {
                            if((texto[i]=='f')||(texto[i]=='F'))
                            {
                                temp=15*16;
                            }
                            else
                            {
                                temp=(int)texto[i];
                            }   
                        }   
                    }   
                }   
            }
        }
        printf("%d->",temp);
        if((texto[i+1]=='a')||(texto[i+1]=='A'))
        {
            temp=temp+10;
        }else
        {
            if((texto[i+1]=='b')||(texto[i+1]=='B'))
            {
                temp=temp+11;
            }
            else
            {
                 if((texto[i+1]=='c')||(texto[i+1]=='C'))
                {
                    temp=temp+12;
                }
                else
                {
                     if((texto[i+1]=='d')||(texto[i+1]=='D'))
                    {
                        temp=temp+13;
                    }
                    else
                    {
                         if((texto[i+1]=='e')||(texto[i+1]=='E'))
                        {
                            temp=temp+14;
                        }
                        else
                        {
                            if((texto[i+1]=='f')||(texto[i+1]=='F'))
                            {
                                temp=temp+15;
                            }
                            else
                            {
                                temp=temp+(int)texto[i+1];
                            }   
                        }   
                    }   
                }   
            }
        }
        printf("%d=",temp);
        txt[j]=temp;
        printf("%c\n",txt[j] );  
    }
    txt[j]='\0';
    printf("o texto era :%s\n",txt);
    return txt;
}