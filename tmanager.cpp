#include<stdio.h>
int main(int argc, char const *argv[]) {
  int execution_time, memory_size, task_size, speed, max_delta;
  float delta_time;
  printf("Digite o tempo de execução da simulação\n");
  scanf("%d\n", &execution_time);
  printf("Digite o tamanho máximo da memória\n");
  scanf("%d\n", &memory_size);
  printf("Digite o intervalo máximo de execução das tarefas\n");
  scanf("%d\n", &max_delta);
  printf("Digite o tempo necessário para a execução de um byte da tarefa\n");
  scanf("%d\n", &speed);
  return 0;
}
