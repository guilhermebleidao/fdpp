#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *PrintHello(void *threadid)
{
	int tid;
	tid = (int)threadid; // Fazendo decasting da memoria para inteiro
	printf("Hello World! It's me, thread #%d!\n", tid);
	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	pthread_t threads[NUM_THREADS];
	int rc, t;

	for (t = 0; t < NUM_THREADS; t++)
	{
		printf("In main: creating thread %d\n", t);
		rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
		if (rc) // Se rc é 0 (false), a thread foi criada com sucesso
		{
			printf("ERROR code is %d\n", rc);
			exit(-1);
		}
	}

	// Segurando a thread principal para o programa não fechar antes de todas as outras executarem
	system( "read -n 1 -s -p \"Press any key to continue...\"" );
	// Para windows: system("pause");

	pthread_exit(NULL);
}
