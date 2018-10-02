#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int conta_origem(unsigned int texto);

int main()
{
	unsigned int i,quantidade,texto,cifrada,mensagem;

	printf("Digite o Texto Claro\n");
	scanf("%u",&texto);
	getchar();
	
	printf("Digite o Texto Cifrado\n");
	scanf("%u",&cifrada);
	getchar();
	
	printf("Digite quantas mensagens cifradas eu tenho\n");
	scanf("%u",&quantidade);
	getchar();

	for(i = 0 ; i < quantidade ; i++)
	{
		printf("Digite a Mensagem Capturada\n");
		scanf("%d",&mensagem);
		getchar();
		if (conta_origem(cifrada)==conta_origem(mensagem))
		{
			printf("Sao da mesma agencia\n");
		}

	}
	
	
	return 1;
}

unsigned int conta_origem(unsigned int texto)
{
	return (texto >> 24 & 0xff);
}
