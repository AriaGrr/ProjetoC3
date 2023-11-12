#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

// Nome: Marjorie Luize Martins Costa
// RA: 242230845


int main(){

    int cod;
    char arquivo[] = "tarefas";
    char exportado[] = "-";
    ListaDeTarefas lt;

    cod = carregarLista(&lt, arquivo);
    if (cod == 1) {
        lt.qtd = 0;
    }
    int opcao;
    do{    
        printMenu();
        scanf("%d", &opcao);
        printf("%d\n", opcao);
        if(opcao == 0){
            printf("Saindo...\n");
        }
        else if (opcao == 1){
            criarTarefa(&lt);
            // Limpar o terminal
            system("clear");
        } else if (opcao == 2){
            deletarTarefa(&lt);
            system("clear");
        } else if (opcao == 3){

            system("clear");
        
            menuListagem();
            int opcao2;
            scanf("%d", &opcao2);
            system("clear");
            if(opcao2 == 1){
              listarTarefas(lt);
            } else if (opcao2 == 2){
              listarPrioridade(lt);
            } else if (opcao2 == 3){
              listarCategoria(lt);
            } else if (opcao2 == 4){
              listarEstado(lt);
            } else if (opcao2 == 5){
              listarPCTarefa(lt);
            } else {
              printf("Opção não existe!\n");
            }
            printf("Pressione Enter para voltar ao menu...");
            clearBuffer();
            clearBuffer();
            system("clear"); 
          } else if (opcao == 4){
            system("clear");
            menuExportar();
            int opcao3;
            scanf("%d", &opcao3);
            system("clear");

            if (opcao3 == 1){
              exportarTarefas(lt, exportado);
            } else if (opcao3 == 2){
              exportarPrioridade(lt, exportado);
            } else if (opcao3 == 3){
              exportarCategoria(lt, exportado);
            } else if (opcao3 == 4){
              exportarPCTarefa(lt, exportado);
            } else{
              printf("Opção não existe!\n");
            }
          } else if (opcao == 5){
            system("clear");
            alterarTarefa(&lt);
          } else {
            printf("Opção não existe!\n");
        }
      cod = salvarLista(lt, arquivo);
    } while (opcao != 0);

    if (cod != 0){
        printf("Erro ao salvar tarefas!\n");
    }
    return 0;
}
