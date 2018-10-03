#include "wictor.h"

using namespace std;

void menu()
{
    printf("\n\n\tQual o tipo da conversao: ");
    printf("\n");
    printf("\n\n\t\t1 - Binario para decimal ");
    printf("\n\n\t\t2 - Decimal para binario ");
    printf("\n\n");
    printf("\n\n\t\t0 - Sair ");
    printf("\n\n");
}

int main()
{
    int op,valor;
    while(0 == 0){
        menu();
        inputInt("\n\n\t\tOpcao: ",&op);
        if(op == 1){
            limparTela();
            inputInt("\n\n\t\tEntre com o valor: ",&valor);
            printf("\n\n\t\tResultado: %d\n\n",bin2dec(valor));
            Continue();
            limparTela();
        }else if(op == 2){
            limparTela();
            inputInt("\n\n\t\tEntre com o valor: ",&valor);
            printf("\n\n\t\tResultado: %d\n\n",dec2bin(valor));
            Continue();
            limparTela();
        }else if(op == 0){
            exit(0);
        }else{
            printf("Opcao Invalida!!!");
            Continue();
            limparTela();
        }
    }

    return 0;
}
