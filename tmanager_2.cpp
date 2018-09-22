#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <math.h>

#define MAXMEM 20
#define MAXTASK 5
#define MAXINTERVALO 2
#define TEMPO_TOTAL 30

int memory[MAXMEM], task[MAXTASK], espaco, bytes_cons = 0, i = 0;

int consumidor()
{
	int k, dif;
	bytes_cons+= 10; //pq 10

	espaco = espaco + bytes_cons; //espaço total

	for(k = 0; k < MAXMEM; k++)
	{
		memory[k] = memory[k+bytes_cons];
	}
	if (k == MAXMEM-1)
	{
		dif = MAXMEM - bytes_cons;

		while (dif < MAXMEM)
		{
			memory[dif] = 0;
			dif++;
		}
		i--;
	}
	bytes_cons = 0;
}

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

int main(int argc, char const *argv[]) {
  int  j = 1, descartadas = 0, n = 0, tasks_total = 0, tasks_desc = 0, maior = MAXTASK-(MAXTASK-1), menor = MAXTASK, executadas = 0, maior_temp, menor_temp, tempo = 0, maior_desc = MAXTASK-(MAXTASK-1), tempo_cons = 0, bytes_desc = 0, menor_desc = MAXTASK, maiordesc_temp, menordesc_temp;
	float  proporcao = 0;

	srand(time(NULL));

  //inicializa o programa preenchendo a memória com 0
	while (i <= MAXMEM - 1)
	{
		memory[i] = 0;
		i++;
	}

	i=0;
	espaco = MAXMEM;

  //gera as tarefas
	while (tempo <= TEMPO_TOTAL)
	{

		//n = rand()%MAXTASK + 1; //tamanho da tarefa
    n=1;
		maior_temp = n;
		menor_temp = n;

		if(maior_temp > maior)
		maior = maior_temp;
		else if (menor_temp < menor)
		menor = menor_temp;

		if (espaco >= n) //verifica se ainda existe espaço na memória
		{
			espaco = espaco - n;
			while(j <= n && i <= MAXMEM - 1)
			{
				task[j] = 1;
				memory[i] = task[j];
				if (j == n)
				{
					tasks_total++;
				}
				j++;
				i++;
			}
		}

		else if (espaco < n)
		{
			i = MAXMEM - espaco;
			descartadas++; //??
			tasks_total += descartadas;
			tasks_desc += descartadas;
			descartadas = 0; //??
			bytes_desc = bytes_desc + n;
			menordesc_temp = n;
			maiordesc_temp = n;
			if (menordesc_temp < menor_desc)
			menor_desc = menordesc_temp;
			else if (maiordesc_temp > maior_desc)
			maior_desc = maiordesc_temp;
		}

		delay(MAXINTERVALO);
    /*REVER ISSO AQUI*/
		//tempo++; //não deveria ser tempo+MAXINTERVALO?
    tempo += MAXINTERVALO;
		tempo_cons++;
    /*REVER ISSO AQUI*/
		j=1;

    /*REVER ISSO, POIS AS TAREFAS DEVEM SER CONSUMIDAS ASSIM QUE FOREM EXECUTADAS*/
		if (tempo_cons == 5) //pq 5
		{
			consumidor();
			tempo_cons = 0;
		}
    /*REVER ISSO, POIS AS TAREFAS DEVEM SER CONSUMIDAS ASSIM QUE FOREM EXECUTADAS*/
	}

	executadas = tasks_total - tasks_desc;
	proporcao = (float)executadas/(float)tasks_desc;

	printf("Tarefas Totais: %d \nTarefas Executadas: %d \nTarefas Descartadas: %d \nProporcao executadas/descartadas: %.3f \nMaior Tarefa Criada: %d \nMenor Tarefa Criada: %d \nMaior Tarefa Descatada: %d \nMenor Tarefa Descartada: %d", tasks_total, executadas, tasks_desc, proporcao, maior, menor, maior_desc, menor_desc);

  return 0;
}
