#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

int main(int argc, char const *argv[]) {
  srand((unsigned int)time(NULL));
  int execution_time, memory_size, task_size, speed, max_delta, i=0;
  int *memory;
  float delta_time, val, total_time = 0.00;
  printf("Digite o tempo de execucao da simulacao\n");
  scanf("%d", &execution_time);
  printf("Digite o tamanho maximo da memoria\n");
  scanf("%d", &memory_size);
  printf("Digite o intervalo maximo de execucao das tarefas\n");
  scanf("%d", &max_delta);
  printf("Digite o tempo necessario para a execucao de um byte da tarefa\n");
  scanf("%d", &speed);

  /*Aloca espaço da memória*/
  memory = (int *) malloc(sizeof(int)*memory_size);

  /*Execução das tarefas em tempo aleatório*/
  while(1)
  {
    delta_time = (((float)rand()) / RAND_MAX)*max_delta;
    /*Executar as tarefas aqui*/
    total_time += delta_time;
    printf("%f %f\n", delta_time, total_time);
    if(total_time > execution_time) break;
    sleep(delta_time);
  }
  return 0;
}
