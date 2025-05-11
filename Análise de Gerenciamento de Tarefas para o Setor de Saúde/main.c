#include <stdio.h>
#include <string.h>

#define maximo_de_tarefas 100

typedef struct {
   int id;
   char titulo[100];
   int concluida;
   char prioridade[10];
} tarefa;

int main() {
    tarefa tarefas[maximo_de_tarefas];
    int totalTarefas = 0, opcao, idTarefa, c;
    int rodando = 1;
    int i;

    while (rodando) {
        printf("\e[1;1H\e[2J");
        printf("======================================\n");
        printf(" Gerenciamento de tarefas versao 1.0 \n");
        printf("======================================\n");
        printf("1 - Adicionar uma Tarefa\n");
        printf("2 - Lista de tarefas\n");
        printf("3 - Atualizar uma tarefa\n");
        printf("4 - Deletar uma tarefa\n");
        printf("5 - Sair do programa\n");
        printf("======================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
             case 1:
                if (totalTarefas < maximo_de_tarefas) {
                    while ((c = getchar()) != '\n' && c != EOF);

                    printf("\nDigite o nome da tarefa: ");
                    fgets(tarefas[totalTarefas].titulo, sizeof(tarefas[totalTarefas].titulo), stdin);
                    tarefas[totalTarefas].titulo[strcspn(tarefas[totalTarefas].titulo, "\n")] = 0;

                    printf("Digite a prioridade (Alta, Media ou Baixa): ");
                    fgets(tarefas[totalTarefas].prioridade, sizeof(tarefas[totalTarefas].prioridade), stdin);
                    tarefas[totalTarefas].prioridade[strcspn(tarefas[totalTarefas].prioridade, "\n")] = 0;

                    tarefas[totalTarefas].id = totalTarefas + 1;
                    tarefas[totalTarefas].concluida = 0;
                    totalTarefas++;

                    printf("\nA tarefa foi adicionada com sucesso!\n");
                    printf("\nDeseja adicionar outra tarefa? [s/n]: ");

                    char novaTarefa;
                    scanf(" %c", &novaTarefa);
                    if (novaTarefa != 's') {
                        break;
                    }
                } else {
                    printf("\nO numero limite de tarefas foi atingido!\n");
                }
                break;
                
            case 2:
                printf("\e[1;1H\e[2J");
                if (totalTarefas == 0) {
                    printf("\nNenhuma tarefa foi cadastrada ate o momento!\n");
                } else {
                    for (i = 0; i < totalTarefas; i++) {
                        printf("\nID: %d | Titulo: %s | Prioridade: %s | Status: %s",
                            tarefas[i].id,
                            tarefas[i].titulo,
                            tarefas[i].prioridade,
                            tarefas[i].concluida ? "Concluida" : "Pendente");
                    }
                }

                printf("\n\nPressione Enter para continuar...");
                while ((c = getchar()) != '\n' && c != EOF);
                getchar();
                break;


            case 3:
                if (totalTarefas == 0) {
                    printf("\nNenhuma tarefa cadastrada!\n");
                } else {
                    printf("\nDigite o ID da tarefa para atualizar: ");
                    scanf("%d", &idTarefa);

                    if (idTarefa > 0 && idTarefa <= totalTarefas) {
                        printf("\nO que voce deseja fazer?\n");
                        printf("1 - Atualizar o titulo\n");
                        printf("2 - Marcar como concluida\n");
                        printf("Escolha uma opcao: ");
                        int acao;
                        scanf("%d", &acao);

                        switch (acao) {
                            case 1:
                                while ((c = getchar()) != '\n' && c != EOF); 
                                printf("\nDigite o novo titulo da tarefa: ");
                                fgets(tarefas[idTarefa - 1].titulo, sizeof(tarefas[idTarefa - 1].titulo), stdin);
                                tarefas[idTarefa - 1].titulo[strcspn(tarefas[idTarefa - 1].titulo, "\n")] = 0;
                                printf("\nO titulo da tarefa foi atualizado com sucesso!\n");
                                break;

                            case 2:
                                tarefas[idTarefa - 1].concluida = 1;
                                printf("\nA tarefa foi marcada como CONCLUIDA!\n");
                                break;

                            default:
                                printf("\nOpcao invalida!\n");
                                break;
                        }
                    } else {
                        printf("\nID da tarefa invalido!\n");
                    }
                }
                   printf("\nPressione Enter para continuar...");
                while ((c = getchar()) != '\n' && c != EOF);
                getchar();
                break;

               
            case 4:
                if (totalTarefas == 0) {
                    printf("\nNenhuma tarefa cadastrada!\n");
                } else {
                    printf("\nDigite o ID da tarefa para deletar: ");
                    scanf("%d", &idTarefa);

                    if (idTarefa > 0 && idTarefa <= totalTarefas) {
                        for (i = idTarefa - 1; i < totalTarefas - 1; i++) {
                            tarefas[i] = tarefas[i + 1];
                        }
                        totalTarefas--;
                        printf("\nTarefa deletada com sucesso!\n");
                    } else {
                        printf("\nID invalido!\n");
                    }
                }

                printf("\nPressione Enter para continuar...");
                while ((c = getchar()) != '\n' && c != EOF);
                getchar();
                break;

            case 5:
                rodando = 0;
                break;

            default:
                printf("\nOpcao invalida!\n");
                printf("\nPressione Enter para continuar...");
                while ((c = getchar()) != '\n' && c != EOF);
                getchar();
                break;
        }
    }

    printf("Saindo do programa...\n");
    return 0;
}
