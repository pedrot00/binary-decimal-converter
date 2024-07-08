#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


void limparBuffer();		// função que limpa o buffer do teclado antes da leitura de variáveis/ controle de fluxo;
void decToBin(int num);		// função que permite entrada do decimal e saída em binário;
int binToDec(char *str);	// função que permite entrada do binário e saíde em decimal;


int main() {
	
//  -------------------- ESCOPO --------------------//
	
int escolha, num;	// variáveis de entrada menu e número;
char bin[64];		// variável que permite entrada do número binário;
int r; 				// variável do tipo inteiro que chamará funções do tipo inteiro;
	
	
	
//  -------------------- INÍCIO --------------------//
do {
    system("cls");			// alterando background i/o;
    system("color 4F");
    	
    printf("\n");
    printf("|------------ MENU ------------|\n");
    printf("|1 - Decimal para binario.     |\n");
    printf("|2 - Binario para decimal.     |\n");
    printf("|3 - Decimal para hexadecimal  |\n");
    printf("|4 - Sair.                     |\n");
    printf("|------------------------------|\n");
    printf("\n|Escolha uma opcao: ");
    scanf("%d", &escolha);

//  -------------------- ESCOLHA --------------------//


    switch (escolha) {			//fluxo escolha laço switch case;
        case 1:
            limparBuffer();
            system("cls");
            	
            printf("\n|Voce escolheu a opcao 1: Transformar decimal em binario.");
            printf("\n|Insira o numero decimal: ");
			scanf("%d", &num);
				
			decToBin(num);
            system("pause");
            break;
                
        case 2:
            limparBuffer();
            system("cls");
            	
            printf("|Voce escolheu a opcao 2: Transformar binario em decimal.\n");
            printf("|Insira um numero binario: ");
            scanf ("%s", &bin);
                
            r = binToDec(bin);
            printf ("%d\n\n", r);
            system("pause");
            break;
            
        case 3:
            printf("|Voce escolheu a opcao 3.\n");
            break;
            
        case 4:
            system("cls");
            printf("\|Voce escolheu a opcao 4: Sair\n");
            printf("|Aperte qualquer tecla para sair do programa.\n");
            return 0;
            break;
            
        default:
            system("cls");
            printf("|Opcao invalida. Por favor, escolha novamente.\n\n");
            system("pause");
            break;
        }
} while (escolha != 4);

return 0;
}

void limparBuffer(){
	int c;
	
	while((c= getchar()) != '\n' && c != EOF) {}		// o buffer é limpado assim que apertado enter;	
}

//  -----------------------------------------------  //
void decToBin(int num){
	system("cls");
	
	int cont = 0;			// variável contadora;
	
	int bin[32] = {0};		// array armazenado os valores da conversão por divisão;
	int binInv[32] = {0};	// array invertida armazenando o binário na ordem certa;
	int numInicial = num;	
	
	for (int i = 0; num>=1; i++){
		
		if(num%2 == 0){
			bin[i] = 0; 	 // classe de equivalência par;
			num = (num/2);
		}
		
		else{
			bin[i] = 1;		// classe de equivalência impar;
			num = (num/2);
		}
		cont++;
	}	
	
	int i, j; 
	for(i = cont - 1, j=0; i>=0; i--, j++){
		binInv[j] = bin[i];		//processo de inversão da array;
	}
	
	
	printf("\n|Numero em decimal: %d", numInicial);

	printf("\n|Numero em binario: ");
	for(i = 0; i<cont; i++){			// loop saída do número binário;
		printf("%d", binInv[i]);
	}
	printf("\n\n");

}

//  -----------------------------------------------  //
int binToDec(char *str) {
	system("cls");
	
	int dec =  0;				// variável que guarda o decimal;
	int l = strlen(str);		// variável l(length que guarda o tamanho da array de caracteres;
	
	for (int i = l - 1, j = 0; i>=0; i--, j++){
		if(str[i] == '1'){			//sempre que for lido na array o valor 1 ele irá fazer a potência com o índice
			int k = pow(2, j);		// adequado
			dec += k;				// soma dos valores pós potência
		}
	}
	
	printf ("\n|Numero em binario: %s", str);		//impressão padrão;
	printf ("\n|Numero em decimal: ");
	
	return dec;
}
