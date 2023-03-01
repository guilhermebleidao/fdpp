/*
	Opções para o programa não "xiar":
	#pragma once
	#define _CRT_SECURE_NO_WARNINGS 1
	#define _WINDSOCK_DEPRECATED_NO_WARNINGS 1
*/

#define _CRT_SECURE_NO_WARNINGS 1
#define _WINDSOCK_DEPRECATED_NO_WARNINGS 1

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

void *thread(void *vargp); // void * usado como coringa para cria um ponteiro para memória de qualquer tipo

int main()
{
	pthread_t tid; // Estrutura que define uma thread
	printf("Hello World da thread principal!\n");
	
	// Criando uma thread. Parametros: endereco thread, opcoes, funcao, parametros para thread
    pthread_create(&tid, NULL, thread, NULL);

	// Esperando a thread finalizar. Parametros: thread, endereco de destino valor de retorno
	pthread_join(tid, NULL);

	// Retornando da thread principal
	pthread_exit((void *)NULL);
	
}

void *thread(void *vargp)
{
	printf("Hello World da thread criada pela thread principal!\n");
	pthread_exit((void *)NULL); // ou, return 0
}
