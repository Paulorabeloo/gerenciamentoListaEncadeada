#include<stdio.h>
#include<stdlib.h>

typedef struct no
{
    int codigo;
    char nome[30];
    struct no *next;
}no;
    struct no *corrente, *inicio, *auxiliar;

void Exibir()
{
    if(inicio == NULL)
    {
        printf("\n Lista vazia");
        system("pause");
    }else{
        auxiliar = inicio;
        while(auxiliar != NULL)
        {
            printf("\n Codigo: %d", auxiliar->codigo);
            printf("\n Nome: %s\n", auxiliar->nome);
            system("pause");
            auxiliar =auxiliar->next;
        }
        }
    }

void Enterdata()
{
    printf("Informe o codigo:");
    scanf("%d", &corrente->codigo);
    printf("\nInforme o nome:");
    scanf("%s", corrente->nome);
}

void Inserir()
{
    if(inicio==NULL){
        corrente=(no*)malloc(sizeof(no));
        inicio = corrente;
        auxiliar = corrente;
        auxiliar->next=NULL;
        Enterdata();
    }else{
        corrente=(no*)malloc(sizeof(no));
        auxiliar->next=corrente;
        auxiliar = corrente;
        corrente->next=NULL;
        Enterdata();
    }
}

void Consulta()
{
    char xnome[20];
    int achou, k;

    if(inicio == NULL)
    {
        printf("\n Lista vazia...");
        system("pause");
    }else{
        printf("\nInforme o nome a ser consultado:");
        scanf("%s", &xnome);
        achou = 0;
        k = 0;
        auxiliar = inicio;
        while(auxiliar != NULL)
        {
            k++;
            if(strcmp(xnome,auxiliar->nome)==0){
                printf("\nRegistro encontrado na posicao %d", k);
                system("pause");
                achou = 1;
                break;
            }else{
                auxiliar=auxiliar->next;
            }
        }
        if(achou == 0){
            printf("\nRegistro nao consta na lista");
            system("pause");
        }
    }
}

void Excluir()
{
    char xnome[20];
    int achou = 0;

    if (inicio == NULL)
    {
        printf("\n Lista vazia...");
        system("pause");
        return;
    }
    printf("\nInforme o nome a ser excluido:");
    scanf("%s", xnome);
    auxiliar = inicio;
    corrente = NULL;

    // verifica se o primeiro nó é o que deve ser excluído
    if (strcmp(xnome, auxiliar->nome) == 0)
    {
        inicio = auxiliar->next;  // atualiza o ponteiro para o próximo nó
        free(auxiliar);  // libera a memória do nó removido
        printf("\nRegistro excluido com sucesso!");
        system("pause");
        return;
    }

    // percorre a lista
    while (auxiliar != NULL)
        {
        if (strcmp(xnome, auxiliar->nome) == 0)
        {
            // nó encontrado; ajusta os ponteiros
            achou = 1;
            corrente->next = auxiliar->next;
            free(auxiliar);
            printf("\nRegistro excluido com sucesso!");
            system("pause");
            return;
        }
        // atualiza os ponteiros para continuar a busca
        corrente = auxiliar;
        auxiliar = auxiliar->next;
    }

    if (achou == 0) {
        printf("\nRegistro nao encontrado");
        system("pause");
    }
}


int main()
{
    auxiliar = NULL;
    corrente = NULL;
    inicio = NULL;
    int op;
    do{
        system("cls");
        printf(" [1] Inclui elementos na lista");
        printf("\n [2] Exibir os elementos da lista");
        printf("\n [3] Pesquisar elemento da lista");
        printf("\n [4] Remove elementos da lista");
        printf("\n [5] Altera elementos da lista");
        printf("\nDigite a opcao desejada:");
        scanf("%d", &op);
    switch(op)
    {
    case 1:
    Inserir();
    break;

    case 2:
    Exibir();
    break;

    case 3:
    Consulta();
    break;

    case 4:
    Excluir();
    break;

    case 5:
    printf("\nFuncao a ser desenvolvida");
    break;

    default :
        printf("\nOpcao invalida ... Tente novamente");
        system("pause");

    }
        }while(op != 6);
}
