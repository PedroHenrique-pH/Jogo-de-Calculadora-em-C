#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#define tam 6
int M[tam][tam], i, j, soma = 0, sub = 0, mult = 0, divi = 0, certo = 0, k, l, tentativa = 0, escolha = 0, ganhou = 0;
float resposta, num1, num2;
void matrizrandomica();
void printmatriz();
void jogadas();
void naorepetir();
void respostacerta();
void usados();
void menu();
void acertoutodas();
void limpartela();
char continuar, operador;

int main (){
limpartela();
matrizrandomica();
menu();

if (escolha !=1){
if (escolha == 2)
{
    printf("Você saiu do jogo.\n\n");
    return 0;
}else
while(escolha < 1 || escolha > 2){   
    limpartela();
    escolha = 0;
    printf("Escolha inválida. Tente novamente.\n\n");
    menu();
    if (escolha == 2)
    {
    printf("Você saiu do jogo.\n\n");
    return 0;
    }
}
}
    

limpartela();

do 
{
    
    tentativa++;
    usados();
    printmatriz();
    acertoutodas();
    if (ganhou == 1)
    {
        printf("\nParabéns! você ganhou.\n");
        break;
    }

    if (tentativa >= 24)
    {
        printf("\nTentativas utilizadas: %d/24\n", tentativa);
        printf("\nVocê não possui mais tentativas\n");
        break;
    } printf("\nTentativa: %d/24\n", tentativa);

    jogadas();
    naorepetir();
    respostacerta();
    printf("\nDeseja jogar novamente? (s/n) \n");
    scanf(" %c", &continuar);
    getchar();
    limpartela();
    
    
    
    
} while (continuar == 's');
printf("FIM DE JOGO!\n");
return 0;
}

void matrizrandomica(){
    srand(time(NULL));
    for(i=0; i<tam; i++){
        for(j=0; j<tam; j++)
        {
            M[i][j] = rand() %9 + 1;      
        }
    } 
}

void printmatriz(){
    printf(">>>> Jogo de Calculadora <<<<");
    printf("\n");
	printf("\n col ");
	for (i=0;i<tam; i++)
        printf("  %d ", i);
	printf("\n lin _______________________");

	for(i=0;i<tam;i++)
	{
		printf("\n   %d |", i);
		for(j=0;j<tam;j++)
            if(M[i][j] == -1){
                printf("    ");
            }else {
			printf(" %d  ",M[i][j]);
            }
	}
	printf("\n");
}

void jogadas(){
    printf("\nEscolha o primeiro número\n");
    printf("Linha: ");
    scanf("%d", &k);
    printf("Coluna: ");
    scanf("%d", &l);

    num1 = M[k][l];

    while(num1 == -1 || k > 5 || k < 0 || l > 5 || l < 0)
    {
        printf("\nPosição inválida. Tente novamente.\n");
        printf("Escolha o primeiro número\n");
        printf("Linha: ");
        scanf("%d", &k);
        printf("Coluna: ");
        scanf("%d", &l);
        num1 = M[k][l];
    }
    

    printf("Escolha o segundo número\n");
    printf("Linha: ");
    scanf("%d", &i);
    printf("Coluna: ");
    scanf("%d", &j);

    num2 = M[i][j];

    while(num2 == -1 || (i == k && j == l) || i > 5 || i < 0 || j > 5 || j < 0)
    {
        printf("\nPosição inválida. Tente novamente.\n");
        printf("Escolha o segundo número\n");
        printf("Linha: ");
        scanf("%d", &i);
        printf("Coluna: ");
        scanf("%d", &j);
        num2 = M[i][j];
    }

    printf("Escolha uma operação: (+  -  /  *)\n");
    printf("Operação: ");
    scanf(" %c", &operador);
    getchar();

}

void naorepetir(){
switch (operador)
{
    case '+':
        if (soma >= 5)
        {
            do{
            printf("\nNão é mais possível fazer esta operação. Utilize outra.\n");
            printf("\nEscolha uma operação: (+  -  /  *)\n");
            printf("Operação: ");
            scanf(" %c", &operador);
            getchar();
            }while(operador == '+');

        } else soma++;

        break;

    case '-':
        if (sub >= 5)
        {
            do{
            printf("\nNão é mais possível fazer esta operação. Utilize outra.\n");
            printf("Escolha uma operação: (+  -  /  *)\n");
            printf("Operação: ");
            scanf(" %c", &operador);
            getchar();
            }while(operador == '-');

        } else sub++;

        break;

    case '*':
        if (mult >= 5)
        {
            do{
            printf("\nNão é mais possível fazer esta operação. Utilize outra.\n");
            printf("Escolha uma operação: (+  -  /  *)\n");
            printf("Operação: ");
            scanf(" %c", &operador);
            getchar();
            }while(operador == '*');

        } else mult++;

        break;

    case '/':
        if (divi >= 5)
        {
            do{
            printf("\nNão é mais possível fazer esta operação. Utilize outra.\n");
            printf("Escolha uma operação: (+  -  /  *)\n");
            printf("Operação: ");
            scanf(" %c", &operador);
            getchar();
            }while(operador == '/');

        } else divi++;

        break;
}
}

void respostacerta(){   
    int chance = 0;
    float correta = 0;
    char ver;
    certo = 0;
    printf("Digite o resultado de %.0f %c %.0f: ", num1, operador, num2);
    scanf("%f", &resposta);

    switch (operador)
    {
    case '+':
        correta = num1 + num2;
        break;
    case '-':
        correta = num1 - num2;
        break;
    case '*':
        correta = num1 * num2;
        break;
    case '/':
        correta = num1 / num2;
        break;
    }

    if (fabs(correta - resposta) <= 0.01)
    {
       printf("\nResultado correto!");
       certo = 1;
       
    } else {
        chance = 0;
        do{
            tentativa++;
            printf("\nResultado incorreto! tente novamente.\n");
            resposta = 0;
            printf("Digite o resultado de %.0f %c %.0f: ", num1, operador, num2);
            scanf("%f", &resposta);
            if (fabs(correta - resposta) <= 0.01)
            {
                printf("\nResultado correto!");
                certo = 1;
                break;
            } else chance++;
            resposta = 0;

        }while(chance < 2);
        if (chance >= 2)
        {
            printf("\nDeseja saber a resposta? (s/n)\n");
            scanf(" %c", &ver);
            getchar();
            if (ver == 's')
            {
                if (operador == '/')
                {
                    printf("\nA resposta certa era: %.2f\n", correta);
                } else printf("\nA resposta certa era: %.0f\n", correta);
                
                
            }
        }
    }
}

void usados(){
    if (certo == 1)
    {
        M[i][j] = -1;
        M[k][l] = -1;
    }   
}

void menu(){
    
    printf("\n>>> REGRAS DO JOGO <<<\n\n• O jogador deverá escolher um parde números da matriz e uma operação \naritmética e indicar o resultado da operação aritmética;\n\n• Cada vez que o jogador acertar o valor da operação, as posições \nescolhidas não estarão disponíveis e não irão mostrar números;\n\n• O jogador não pode sempre escolher a mesma operação matemática, \nhá um limite para cada operação;\n\n• Depois de três tentativas erradas o jogador pode pedir para ver a \nresposta;\n\n\nO jogo termina nas seguintes condições:\n• O jogador acerta todos os resultados das operações de todos os \npares em um máximo de 24 tentativas;\n\n• O jogador ultrapassa as 24 tentativas;\n\n• O jogador deseja terminar.\n\n• Se o resultado da divisão não for um número inteiro, o jogador\ndeverá inserir o número com apenas duas casas decimais além do ponto \n(atenção: utilizar ponto, não vírgula). \n\nexemplo: \nresultado encontrado: 1.777...\nresultado que deve ser escrito: 1.77\n\n");
    printf("Jogar: (1)   Sair: (2)\n");
    scanf("%d", &escolha);
    printf("\n");
    
}

void acertoutodas(){
    int acerto = 0;
    int f, g;
    for (f = 0; f < tam; f++)
        for (g = 0; g < tam; g++)
        {
            if (M[f][g] == -1)
            {
                acerto++;
            }
        }
        if (acerto == 36)
        {
            ganhou = 1;
        }else ganhou = 0;
}

void limpartela(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}