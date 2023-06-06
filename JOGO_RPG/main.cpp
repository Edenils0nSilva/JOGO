/*
										PROJETO LIP I
										
	Disciplina: Laboratório de Introdução a Programação
	Ano/Semestre: 2022.1				
											Grupo 3 
											
	Alunos: Guilherme A. Silva       			|  Edenilson do N. Silva 
	        Joao Luis Moreno de Lima 			|  Antonio Rodrigues da Silva Junior
	        Gabriel Filipe da Silva Fernandes   |  Paulo Sergio Maia Mendes de Oliveira
	        
	Professora: Ceres Germanna Braga Morais
	Data: 25/08/2022
	Última modificação: 10/09/2022.
	
*/

/*	Bibliotecas utilizadas INICIO	*/

#include "GG.h"

/*	Bibliotecas utilizadas FIM  */

/* Variveis Globais INICIO */

int opc;

/* Variaveis Globais FIM */

/*
 INICIO DO PROGRAMA
*/
int main()
{
	system("cls");
	opc = menuv2();
	switchcase(opc);
	
	return 0;
}
/*
 FIM DO PROGRAMA
*/
