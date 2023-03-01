#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *funcao_thread(void *threadid)
{
	long tid;
	tid = (long)threadid;
	printf("Thread ID: %ld\n", tid);
	pthread_exit((void *)NULL);
}

int main(void)
{
	pthread_t threads[5];
	long retorno, i;

	for (i = 0; i < 5; i++)
	{
		retorno = pthread_create(&threads[i], NULL, funcao_thread, (void *)i);
		if (retorno)
		{
			printf("ERROR code is %ld\n", retorno);
			exit(-1);
		}
	}

	// Fazendo a thread main aguardar a finalizacao das outras
	for (i = 0; i < 5; i++)
	{
		pthread_join(threads[i], NULL);
	}

	pthread_exit(NULL);
}
