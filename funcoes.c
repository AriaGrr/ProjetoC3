#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clearBuffer()
{
  char c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

// Retorna o estado da tarefa
char *estado(int e)
{
  char *estado;
  if (e == 1)
  {
    estado = "Completo";
  }
  else if (e == 2)
  {
    estado = "Em andamento";
  }
  else if (e == 3)
  {
    estado = "Não iniciado";
  }
  else
  {
    printf("Erro!");
  }
  return estado;
}

// Retorna a categoria da tarefa
char *categoria(int c)
{
  char *categoria;
  if (c == 1)
  {
    categoria = "Tarefas de casa";
  }
  else if (c == 2)
  {
    categoria = "Tarefas de estudos";
  }
  else if (c == 3)
  {
    categoria = "Tarefas pessoais";
  }
  else if (c == 4)
  {
    categoria = "Tarefas do trabalho";
  }
  else if (c == 5)
  {
    categoria = "Outras tarefas";
  }
  else
  {
    printf("Erro!");
  }
  return categoria;
}

// Cria uma nova tarefa e adiciona na lista
int criarTarefa(ListaDeTarefas *lt)
{
  if (lt->qtd < 100)
  {
    printf("Criar tarefa:\n");
    clearBuffer();
    printf("Escolha a categoria: \n");
    printf("1 - Tarefas de casa\n");
    printf("2 - Tarefas de estudos\n");
    printf("3 - Tarefas pessoais\n");
    printf("4 - Tarefas do trabalho\n");
    printf("5 - Outras\n");
    scanf("%d", &lt->tarefas[lt->qtd].categoria);
    clearBuffer();
    printf("Digite a descrição (até 300 caracteres): ");
    fgets(lt->tarefas[lt->qtd].descricao, sizeof(lt->tarefas[lt->qtd].descricao), stdin);
    clearBuffer();

    printf("Digite a prioridade (de 1 a 9): ");
    scanf("%d", &lt->tarefas[lt->qtd].prioridade);
    // Não foi possivel fazer as verificações necessarias com o while

    printf("Escolha o estado da tarefa:\n");
    printf("1 - Completo\n");
    printf("2 - Em andamento\n");
    printf("3 - Não iniciado\n");
    scanf("%d", &lt->tarefas[lt->qtd].estado);
    // Não foi possivel fazer as verificações necessarias com o while

    lt->qtd++;
    return 0;
  }
  else
  {
    printf("Lista de tarefas está cheia.\n");
    return 1;
  }
}

// Deleta uma tarefa da lista
int deletarTarefa(ListaDeTarefas *lt)
{
  if (lt->qtd > 0)
  {
    printf("Deletar tarefa:\n");
    int pos;

    printf("Digite a posição da tarefa (1 a 100): ");
    scanf("%d", &pos);
    pos--;

    if (pos >= 0 && pos < lt->qtd)
    {
      for (int i = pos; i < lt->qtd - 1; i++)
      {
        lt->tarefas[i] = lt->tarefas[i + 1];
      }

      lt->qtd--;
      return 0;
    }
    else
    {
      printf("Posição invalida.\n");
      return 1;
    }
  }
  else
  {
    printf("Lista de tarefas vazia.\n");
    return 1;
  }
}

// Mostra a lista de tarefas e retorna 0 se a lista não estiver vazia
int listarTarefas(ListaDeTarefas lt)
{
  printf("Lista de tarefas\n");
  printf("Quantidade de tarefas: %d\n", lt.qtd);
  printf("\n");

  if (lt.qtd == 0)
  {
    printf("A lista de tarefas está vazia.\n");
    return 1;
  }

  for (int i = 0; i < lt.qtd; i++)
  {
    printf("-> %d. Prioridade: %2d; Categoria: %s; Estado: %s; Descricao: %s \n", i + 1, lt.tarefas[i].prioridade, categoria(lt.tarefas[i].categoria), estado(lt.tarefas[i].estado), lt.tarefas[i].descricao);
  }

  return 0;
}

// Altera um campo de uma tarefa escolhida
int alterarTarefa(ListaDeTarefas *lt)
{
  printf("Alterar Tarefa\n");
  printf("1 - Exibir escolhas\n");
  printf("2 - Já sei a posição da tarefa\n");
  printf("0 - Voltar\n");
  int opcao;
  scanf("%d", &opcao);
  if (opcao == 0)
  {
    return 0;
  }
  else if (opcao == 1)
  {
    system("clear");
    listarTarefas(*lt);
  }
  else if (opcao != 2)
  {
    printf("Opção invalida\n");
    return 0;
  }
  printf("Qual tarefa você deseja alterar?");
  int posicao;
  scanf("%d", &posicao);
  if (posicao > lt->qtd || posicao < 0)
  {
    printf("Posição inválida!");
    return 0;
  }
  else
  {
    system("clear");
    printf("Qual campo você deseja alterar?\n");
    printf("1 - Descrição\n");
    printf("2 - Categoria\n");
    printf("3 - Prioridade\n");
    printf("4 - Estado\n");
    printf("0 - Voltar\n");
    int opcao2;
    scanf("%d", &opcao2);
    if (opcao2 == 1)
    {
      system("clear");
      printf("Descrição: ");
      char descricao[300];
      scanf("%s", descricao);
      strcpy(lt->tarefas[posicao - 1].descricao, descricao);
      printf("Descrição alterada com sucesso!");
      return 0;
    }
    else if (opcao2 == 2)
    {
      system("clear");
      printf("Escolha a categoria: \n");
      printf("1 - Tarefas de casa\n");
      printf("2 - Tarefas de estudos\n");
      printf("3 - Tarefas pessoais\n");
      printf("4 - Tarefas do trabalho\n");
      printf("5 - Outras\n");
      int categoria;
      scanf("%d", &categoria);
      lt->tarefas[posicao - 1].categoria = categoria;
    }
    else if (opcao2 == 3)
    {
      system("clear");
      printf("Prioridade: ");
      int prioridade;
      scanf("%d", &prioridade);
      lt->tarefas[posicao - 1].prioridade = prioridade;
    }
    else if (opcao2 == 4)
    {
      system("clear");
      printf("Escolha o novo estado da tarefa:\n");
      printf("1 - Completo\n");
      printf("2 - Em andamento\n");
      printf("3 - Não iniciado\n");
      int estado;
      scanf("%d", &estado);
      lt->tarefas[posicao - 1].estado = estado;
    }
    else if (opcao2 == 0)
    {
      system("clear");
      return 0;
    }
    else
    {
      system("clear");
      printf("Opção inválida!");
      return 0;
    }
  }
  return 0;
}

// Listar as tarefas por prioridade
int listarPrioridade(ListaDeTarefas lt)
{
  int filtrarPrior;
  printf("Digite a prioridade: ");
  scanf("%d", &filtrarPrior);
  int contador = 0;
  if (filtrarPrior > 9 || filtrarPrior < 1)
  {
    printf("Prioridade inválida!");
    return 0;
  }
  else
  {
    for (int i = 0; i < lt.qtd; i++)
    {
      if (lt.tarefas[i].prioridade == filtrarPrior)
      {
        contador = 1;
        printf("-> %d. Prioridade: %2d; Categoria: %s; Estado: %s; Descricao: %s \n", i + 1, lt.tarefas[i].prioridade, categoria(lt.tarefas[i].categoria), estado(lt.tarefas[i].estado), lt.tarefas[i].descricao);
      }
    }
  }
  if (contador == 0)
  {
    printf("Erro ao encontrar a tarefa(s) com essa prioridade\n ");
  }
  return 0;
}

// Listar as tarefas por categoria
int listarCategoria(ListaDeTarefas lt)
{
  int filtrarCategoria;
  int contador = 0;
  printf("Escolha a categoria: \n");
  printf("1 - Tarefas de casa\n");
  printf("2 - Tarefas de estudos\n");
  printf("3 - Tarefas pessoais\n");
  printf("4 - Tarefas do trabalho\n");
  printf("5 - Outras\n");
  scanf("%d", &filtrarCategoria);
  for (int ordem = 9; ordem >= 0; ordem--)
  {
    for (int i = 0; i < lt.qtd; i++)
    {

      if (lt.tarefas[i].categoria == filtrarCategoria)
      {
        if (lt.tarefas[i].prioridade == ordem)
        {
          contador = 1;
          printf("\n");
          printf("-> %d. Prioridade: %2d; Categoria: %s; Estado: %s; Descricao: %s\n", i + 1, lt.tarefas[i].prioridade, categoria(lt.tarefas[i].categoria), estado(lt.tarefas[i].estado), lt.tarefas[i].descricao);
        }
      }
    }
  }
  if (contador == 0)
  {
    printf("Erro ao encontrar a tarefa(s) com essa categoria \n ");
  }
  return 0;
}

// Listar por prioridade e categoria
int listarPCTarefa(ListaDeTarefas lt)
{
  int filtrarPrior;
  int contador = 0;
  printf("Digite a prioridade (1 a 9): ");
  scanf("%d", &filtrarPrior);

  int filtrarCategoria;
  printf("Escolha a categoria: \n");
  printf("1 - Tarefas de casa\n");
  printf("2 - Tarefas de estudos\n");
  printf("3 - Tarefas pessoais\n");
  printf("4 - Tarefas do trabalho\n");
  printf("5 - Outras\n");
  scanf("%d", &filtrarCategoria);
  for (int ordem = 9; ordem >= 0; ordem--)
  {
    for (int i = 0; i < lt.qtd; i++)
    {

      if (lt.tarefas[i].categoria == filtrarCategoria)
      {
        if (lt.tarefas[i].prioridade == filtrarPrior)
        {
          if (lt.tarefas[i].prioridade == ordem)
          {
            contador = 1;
            printf("\n");
            printf("-> %d. Prioridade: %2d; Categoria: %s; Estado: %s; Descricao: %s\n", i + 1, lt.tarefas[i].prioridade, categoria(lt.tarefas[i].categoria), estado(lt.tarefas[i].estado), lt.tarefas[i].descricao);
          }
        }
      }
    }
  }
  if (contador == 0)
  {
    printf("Erro ao encontrar a tarefa(s) com essa categoria e prioridade \n ");
  }
  return 0;
}

// Listar por estado
int listarEstado(ListaDeTarefas lt)
{
  printf("Listar Tarefas por Estado\n");
  printf("Digite o estado: \n");
  printf("1 - Completo\n");
  printf("2 - Em andamento\n");
  printf("3 - Não iniciado\n");
  int estad;
  scanf("%d", &estad);
  if (estad > 3 || estad < 1)
  {
    printf("Estado inválido!");
    return 0;
  }
  else
  {
    system("clear");
    printf("Tarefas com estado %d:\n", estad);
    for (int i = 0; i < lt.qtd; i++)
    {
      if (lt.tarefas[i].estado == estad)
      {
        printf("\n");
        printf("-> %d. Prioridade: %2d; Categoria: %s; Estado: %s; Descricao: %s\n", i + 1, lt.tarefas[i].prioridade, categoria(lt.tarefas[i].categoria), estado(lt.tarefas[i].estado), lt.tarefas[i].descricao);
      }
    }
  }
  return 0;
}

// Adicional, não feito.
int exportarTarefas(ListaDeTarefas lt, char exportado[])
{
  printf("Exportar tarefas\n");
  return 0;
}

// Exportar por prioridade
int exportarPrioridade(ListaDeTarefas lt, char exportado[])
{
  printf("Exportar tarefas por prioridade\n");
  printf("Digite a prioridade (de 1 a 9): ");
  char arquivo[30];
  int prioridade;
  scanf("%d", &prioridade);
  if (prioridade > 9 || prioridade < 1)
  {
    printf("Prioridade inválida!");
    return 0;
  }
  else
  {
    system("clear");
    sprintf(arquivo, "prioridade:%d.txt", prioridade);
    FILE *f = fopen(arquivo, "w");

    if (f == NULL)
    {
      printf("Falha ao abrir o arquivo");
    }
    fprintf(f, "Tarefas da prioridade %d:\n", prioridade);

    for (int i = 0; i < lt.qtd; i++)
    {
      if (lt.tarefas[i].prioridade == prioridade)
      {
        fprintf(f, "-> %d. Prioridade: %2d; Categoria: %s; Estado: %s; Descricao: %s\n", i + 1, lt.tarefas[i].prioridade, categoria(lt.tarefas[i].categoria), estado(lt.tarefas[i].estado), lt.tarefas[i].descricao);
      }
    }
    fclose(f);
  }
  return 0;
}

// Exportar por categoria
int exportarCategoria(ListaDeTarefas lt, char exportado[])
{
  printf("Exportar tarefas por categoria \n");
  printf("Escolha a categoria: \n");
  printf("1 - Tarefas de casa\n");
  printf("2 - Tarefas de estudos\n");
  printf("3 - Tarefas pessoais\n");
  printf("4 - Tarefas do trabalho\n");
  printf("5 - Outras\n");
  char arquivo[30];
  int categ;
  int contador = 0;
  scanf("%d", &categ);
  system("clear");
  sprintf(arquivo, "Categoria:%s.txt", categoria(categ));
  FILE *f = fopen(arquivo, "w");
  if (f == NULL)
  {
    printf("Falha ao abrir o arquivo");
  }
  fprintf(f, "Tarefas da categoria %s:\n", categoria(categ));
  for (int ordem = 9; ordem >= 0; ordem--)
  {
    for (int i = 0; i < lt.qtd; i++)
    {
      if (lt.tarefas[i].categoria == categ)
      {
        if (lt.tarefas[i].prioridade == ordem)
        {
          contador++;
          fprintf(f, "-> %d. Prioridade: %2d; Categoria: %s; Estado: %s; Descricao: %s\n", i + 1, lt.tarefas[i].prioridade, categoria(lt.tarefas[i].categoria), estado(lt.tarefas[i].estado), lt.tarefas[i].descricao);
        }
      }
    }
  }
  if (contador == 0)
  {
    printf("Erro ao encontrar a tarefa(s) com essa categoria \n ");
  }
  fclose(f);
  return 0;
}

// Exportar por prioridade e categoria
int exportarPCTarefa(ListaDeTarefas lt, char exportado[])
{
  printf("Exportar tarefas por categoria e prioridade\n");
  char arquivo[30];
  int filtrarPrior, filtrarCategoria;
  int contador = 0;
  printf("Digite a prioridade (1 a 9): ");
  scanf("%d", &filtrarPrior);
  printf("Escolha a categoria: \n");
  printf("1 - Tarefas de casa\n");
  printf("2 - Tarefas de estudos\n");
  printf("3 - Tarefas pessoais\n");
  printf("4 - Tarefas do trabalho\n");
  printf("5 - Outras\n");
  scanf("%d", &filtrarCategoria);
  sprintf(arquivo, "Categoria:%d_Prioridade:%d.txt", filtrarCategoria, filtrarPrior); // Erro na função para colocar a categoria em string, logo ela será um número
  FILE *f = fopen(arquivo, "w");
  if (lt.qtd == 0)
  {
    fprintf(f, "Não tem tarefa para listar");
  }
  fprintf(f, "Tarefas da categoria %s e prioridade %d:\n", categoria(filtrarCategoria),
          filtrarPrior);
  for (int ordem = 9; ordem >= 0; ordem--)
  {

    for (int i = 0; i < lt.qtd; i++)
    {

      if (lt.tarefas[i].categoria == filtrarCategoria)
      {

        if (lt.tarefas[i].prioridade == filtrarPrior)
        {

          if (lt.tarefas[i].prioridade == ordem)
          {

            contador++;
            fprintf(f, "-> %d. Prioridade: %2d; Categoria: %s; Estado: %s; Descricao: %s\n", i + 1, lt.tarefas[i].prioridade, categoria(lt.tarefas[i].categoria), estado(lt.tarefas[i].estado), lt.tarefas[i].descricao);
          }
        }
      }
    }
  }
  if (contador == 0)
  {
    printf("Erro ao encontrar a tarefa(s) com essa categoria e prioridade \n ");
  }
  fclose(f);
  return 0;
}

// Funções para print de menus
void printMenu()
{
  printf("Menu\n");
  printf("1 - Criar tarefa\n");
  printf("2 - Deletar tarefa\n");
  printf("3 - Listar tarefas\n");
  printf("4 - Exportar tarefas\n");
  printf("5 - Alterar tarefa\n");
  printf("0 - Sair\n");
  printf("Digite a opção desejada: ");
}

void menuExportar()
{
  printf("Arquivo gerado em TXT\n");
  printf("Escolha a exportação:\n");
  printf("1 - Exportar tudo (opção indisponivel)\n");
  printf("2 - Exportar por prioridade\n");
  printf("3 - Exportar por categoria\n");
  printf("4 - Exportar por prioridade e categoria\n");
}

void menuListagem()
{
  printf("Escolha a listagem desejada:\n");
  printf("1 - Listar todas as tarefas\n");
  printf("2 - Listar tarefas por prioridade\n");
  printf("3 - Listar tarefas por categoria\n");
  printf("4 - Listar tarefas por estado\n");
  printf("5 - Listar tarefas por prioridade e categoria\n");
}

// Salva a lista de tarefas em um arquivo
// fwrite
int salvarLista(ListaDeTarefas lt, char nome[])
{
  FILE *arquivo;
  arquivo = fopen(nome, "wb");

  if (arquivo == NULL)
  {
    printf("Erro ao abrir o arquivo.\n");
    return 1;
  }

  fwrite(&lt.tarefas, sizeof(Tarefa), lt.qtd, arquivo);

  fclose(arquivo);
  return 0;
}

// Carrega a lista de tarefas de um arquivo
// fread
int carregarLista(ListaDeTarefas *lt, char nome[])
{
  FILE *arquivo;
  arquivo = fopen(nome, "rb");

  if (arquivo == NULL)
  {
    printf("Erro ao abrir o arquivo.\n");
    return 1;
  }

  lt->qtd = 0; // Inicialize o contador de tarefas carregadas

  while (fread(&lt->tarefas[lt->qtd], sizeof(Tarefa), 1, arquivo) == 1)
  {
    lt->qtd++;
  }

  fclose(arquivo);
  return 0;
}