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

#include "GG.h"

//DEFINIÇÕES
#define MAX 2
#define MIN 1

//DECLARAÇÃO DE CARTAS
int GG;
int CartasDefesa[10]  = {50, 35, 35, 20, 20, 20, 10, 10, 10, 10};
int CartasAtaque[10]  = {70, 50 , 50 , 40, 40, 40, 20, 20, 20, 20};
int CartasVida[10]  = {40, 40, 25, 25, 25, 20, 20, 10, 10, 10};
int SETA = 0;
int Cont = 0;

//DECLARAÇÃO DE STRUCT PARA PERSONAGENS
personagem personagens[2];
//DECLARAÇÃO DE STRUCT PARA
IA Deni;


/* MENU
=============================================================================*/

/* Ínicio da Função  */
//Função para mostrar o Menu inicial do jogo
int menuv2()
{

#define MENU_MAX 5
#define MENU_MIN 1

	int position = 1, arrowPress;
	do
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 14);
		setlocale(LC_ALL, "portuguese");
		cout << " - - - - - - - - - - - - - - - - - - - " << endl;
		cout << "|      Welcome to Gears Of War       |" << endl;
		cout << " - - - - - - - - - - - - - - - - - - - " << endl;
		arrow(1, position);
		cout << "   |  [1] - Um jogador           |    " << endl;
		arrow(2, position);
		cout << "   |  [2] - Dois Jogadores       |    " << endl;
		arrow(3, position);
		cout << "   |  [3] - Manual de Instrução  |    " << endl;
		arrow(4, position);
		cout << "   |  [4] - Créditos             |    " << endl;
		arrow(5, position);
		cout << "   |  [5] - Sair do Jogo         |    " << endl;
		cout << " - - - - - - - - - - - - - - - - - - -" << endl;
		cout << " Informe sua opção: Use as setas  para cima e baixo" << endl;
		arrowPress = getch();
		system("CLS");
		fflush(stdin);

		if (arrowPress == 80 && position != MENU_MAX)
			position++;
		else if (arrowPress == 72 && position != MENU_MIN)
			position--;
		else
			position = position;
	}
	while (arrowPress != 13);

	return position;
} /* Fim da Função  */

/* Ínicio da Função  */
//Função para receber as escolhas feitas no Menu
void switchcase(int op)
{
	switch(op)
	{
	case 1:
		system("cls");
		Classes(1);
		break;
	case 2:
		system("cls");
		Classes(2);
		break;
	case 3:
		ManualDeInstrucao();
		break;
	case 4:
		Creditos();
		break;
	case 5:
		cout << "\n Fim de Jogo \n";
		break;
	default:
		cout << "\n Opção Inválida \n" << endl;
		system("pause");
		system("cls");
		main();
		break;
	}
} /* Fim da Função  */

/* 1 JOGADOR
=============================================================================*/

/* Ínicio da Função  */
//Função para
void CombateUm()
{
	int esc, Dano = 0, DD, AtaqueR;
	int position = 1, arrowPress;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 4);

	if(personagens[0].life <= 0)
	{
	cout << "       (X)             (X)              " <<endl;		
	cout << "        (X)           (X)               " <<endl;
	cout << "         (X)         (X)                " <<endl;
	cout << "           (X)     (X)                  " <<endl;
	cout << "             (X) (X)                    " <<endl;
	cout << "               (X)                      " <<endl;
	
	cout << "               (X)                      " <<endl;
	cout << "                                        " <<endl;
	cout << "               (X)                      " << " IA: " << Deni.nome << " Venceu !!!" <<endl;
	cout << "               (X)                      " <<endl;
	cout << "               (X)                      " <<endl;
	cout << "               (X)                      " <<endl;
	cout << "               (X)                      " <<endl;
	
	cout << "        (X)(X)(X)(X)(X)             (X)    " <<endl;
	cout << "              (X)                          " <<endl;
	cout << "              (X)                   (X)    " <<endl;
	cout << "              (X)                   (X)    " <<endl;
	cout << "              (X)                   (X)    " <<endl;
	cout << "              (X)                   (X)    " <<endl;
	cout << "                                    (X)    " <<endl;
	
	cout << "           (X)(X)(X)            (X)(X)(X)(X)   " <<endl;
	cout << "         (X)       (X)          (X)      (X)   " <<endl;
	cout << "        (X)         (X)         (X)      (X)   " <<endl;
	cout << "        (X)         (X)         (X)(X)(X)(X)   " <<endl;
	cout << "         (X)       (X)          (X)      (X)   " <<endl;
	cout << "           (X)(X)(X)            (X)      (X)   " <<endl;
    cout << "                                (X)      (X)   " <<endl;
	
	
	cout << "            (X)(X)(X)                   " <<endl;
	cout << "            (X)     (X)                 " <<endl;
	cout << "            (X)    (X)                  " <<endl;
	cout << "            (X)(X)(X)                   " <<endl;
	cout << "            (X)    (X)                  " <<endl;
	cout << "            (X)     (X)                 " <<endl;
	cout << "            (X)       (X)               " <<endl;
	
    cout << "               (X)                      " <<endl;
	cout << "                                        " <<endl;
	cout << "               (X)                      " <<endl;
	cout << "               (X)                      " <<endl;
	cout << "               (X)                      " <<endl;
	cout << "               (X)                      " <<endl;
	cout << "               (X)                      " <<endl;
	
    cout << "          (X)(X)(X)(X)                  " <<endl;
	cout << "          (X)      (X)                  " <<endl;
	cout << "          (X)      (X)                  " <<endl;
	cout << "          (X)(X)(X)(X)                  " <<endl;
	cout << "          (X)      (X)                  " <<endl;
	cout << "          (X)      (X)                  " <<endl;
	cout << "          (X)      (X)                  " <<endl;	
	system("pause");
	}
	else if(Deni.life <= 0)
	{
		int i = 0;
		Vitoria(i);
	}
	else
	{
		do
		{
			system("Cls");
			setlocale(LC_ALL, "portuguese");
			cout << " - - - - - - - - - - - - - - - - - - - " << setiosflags (ios::left) << "" << setw(20) << "|     JOGADOR 1 " << setw(10) << " |    JOGADOR  2      |" << endl;
			cout << "|      Welcome to Gears Of War       |" << setiosflags (ios::left) << "" << setw(15) << " | Vida: " << setw(5) << personagens[0].life << setw(10) << "  |    Vida: " << setw(5) << Deni.life << setw(5) << endl;
			cout << " - - - - - - - - - - - - - - - - - - - " << setiosflags (ios::left) << "" << setw(15) << "| Ataque: " << setw(5) << personagens[0].attack << setw(10) << " |    Ataque: " << setw(5) << Deni.attack << setw(5) << endl;
			cout << "               JOGADOR 1:             " << setiosflags (ios::left) << "" << setw(15) << " | Defesa: " << setw(5) << personagens[0].defense << setw(10) << "  |    Defesa: " << setw(5) << Deni.defense << setw(5) << endl;;
			cout << " - - - - - - - - - - - - - - - " << setiosflags (ios::left) << "" << setw(15) << "        | Altura: " << setw(5) << personagens[0].altura  << setw(10) << "      |    Altura: " << setw(5) << Deni.altura << setw(5) << endl;
			cout << "                               " << setiosflags (ios::left) << "" << setw(15) << "        | Idade: " << setw(5) << personagens[0].idade    << setw(10) << "       |    Idade: " << setw(5) << Deni.idade   << setw(5) << endl;
			cout << "                               " << setiosflags (ios::left) << "" << setw(10) << "        | Nome: " << setw(2) << personagens[0].nome     << setw(10) << "           |    Nome: " << setw(5) << Deni.nome     << setw(5) << endl;
			arrow(1, position);
			cout << "   |  [1] - Ataque           |    " << endl;
			arrow(2, position);
			cout << "   |  [2] - Puxar Carta      |    " << endl;
			cout << " - - - - - - - - - - - - - - - " << endl;
			cout << "Informe sua opção: use as setas cima/baixo" << endl;
			arrowPress = getch();

			system("CLS");

			fflush(stdin);

			if (arrowPress == 80 && position != MAX)
				position++;
			else if (arrowPress == 72 && position != MIN)
				position--;
			else
				position = position;

		}
		while (arrowPress != 13);
		esc = position;

		if(esc == 1)
		{
			if(personagens[0].attack > Deni.defense)
			{
				Dano = personagens[0].attack - Deni.defense;
				AtaqueR = rand() % Dano;

				cout << " O Ataque foi de " << AtaqueR << " !!!\n";
				Sleep(2000);
				Deni.life = Deni.life - AtaqueR;
			}
			else
			{
				cout << " Seu personagem é FRACO!!! " << endl;
				cout << " Puxe uma carta na proxima rodada... " << endl;
				Sleep(2000);
			}
		}
		else if(esc == 2)
		{
			DD = Cartas();
			if(GG == 1)
			{
				personagens[0].life += CartasVida[DD];
				cout << "\nCarta de vida! O persornagem ganhou: " << CartasVida[DD] << " de vida.\n";
				Sleep(2000);
			}
			else if(GG == 2)
			{
				personagens[0].defense += CartasDefesa[DD];
				cout << "\nCarta de defesa! O persornagem ganhou: " << CartasDefesa[DD] << " de defesa.\n";
				Sleep(2000);
			}
			else if(GG == 3)
			{
				personagens[0].attack += CartasAtaque[DD];
				cout << "\nCarta de Ataque! O persornagem ganhou: " << CartasAtaque[DD] << " de ataque.\n";
				Sleep(2000);
			}
			else if(GG == 4)
			{
				personagens[0].life -= 10;
				personagens[0].defense -= 10;
				personagens[0].attack -= 10;
				cout << "\nCarta Coringa!!! O persornagem perdeu 10 de todos os atríbutos\n";
				Sleep(2000);
			}
			GG = 0;
		}
		else
		{
			cout << "\n Opção Inválida! escolha uma das opções acima. \n";
			Sleep(2000);
		}

		system("cls");

		CombateDois();
	}
} /* Fim da Função  */

/* Ínicio da Função  */
//Função para
void CombateDois()
{
	int esc, Dano = 0, DD, AtaqueR, tempo = 1000;


	//Temporizador
	cout << "\nIA pensando...\n";
	Sleep(tempo);
	tempo = rand() % 5000;

	system("Cls");

	if(personagens[0].life <= 0)
	{
	cout << "       (X)             (X)              " <<endl;		
	cout << "        (X)           (X)               " <<endl;
	cout << "         (X)         (X)                " <<endl;
	cout << "           (X)     (X)                  " <<endl;
	cout << "             (X) (X)                    " <<endl;
	cout << "               (X)                      " <<endl;
	
	cout << "              (X)                       " <<endl;
	cout << "                                        " <<endl;
	cout << "              (X)                       " << " IA:" << Deni.nome << " Venceu !!!" << endl;
	cout << "              (X)                       " <<endl;
	cout << "              (X)                       " <<endl;
	cout << "              (X)                       " <<endl;
	cout << "              (X)                       " <<endl;

	cout << "        (X)(X)(X)(X)(X)             (X)    " <<endl;
	cout << "              (X)                          " <<endl;
	cout << "              (X)                   (X)    " <<endl;
	cout << "              (X)                   (X)    " <<endl;
	cout << "              (X)                   (X)    " <<endl;
	cout << "              (X)                   (X)    " <<endl;
	cout << "                                    (X)    " <<endl;
	
	cout << "           (X)(X)(X)            (X)(X)(X)(X)   " <<endl;
	cout << "         (X)       (X)          (X)      (X)   " <<endl;
	cout << "        (X)         (X)         (X)      (X)   " <<endl;
	cout << "        (X)         (X)         (X)(X)(X)(X)   " <<endl;
	cout << "         (X)       (X)          (X)      (X)   " <<endl;
	cout << "           (X)(X)(X)            (X)      (X)   " <<endl;
    cout << "                                (X)      (X)   " <<endl;
	
	cout << "         (X)(X)(X)                      " <<endl;
	cout << "         (X)     (X)                    " <<endl;
	cout << "         (X)    (X)                     " <<endl;
	cout << "         (X)(X)(X)                      " <<endl;
	cout << "         (X)    (X)                     " <<endl;
	cout << "         (X)     (X)                    " <<endl;
	cout << "         (X)       (X)                  " <<endl;
	
    cout << "             (X)                        " <<endl;
	cout << "                                        " <<endl;
	cout << "             (X)                        " <<endl;
	cout << "             (X)                        " <<endl;
	cout << "             (X)                        " <<endl;
	cout << "             (X)                        " <<endl;
	cout << "             (X)                        " <<endl;
	
    cout << "          (X)(X)(X)(X)                  " <<endl;
	cout << "          (X)      (X)                  " <<endl;
	cout << "          (X)      (X)                  " <<endl;
	cout << "          (X)(X)(X)(X)                  " <<endl;
	cout << "          (X)      (X)                  " <<endl;
	cout << "          (X)      (X)                  " <<endl;
	cout << "          (X)      (X)                  " <<endl;	
	system("pause");
	}
	else if(Deni.life <= 0)
	{
		int i = 0;
		Vitoria(i);
	}
	else
	{
		//Random para gerar a escolha
		esc = rand() % 2;

		if(esc == 0)
		{
			if(Deni.attack > personagens[0].defense)
			{
				Dano = Deni.attack - personagens[0].defense;
				AtaqueR = rand() % Dano;

				cout << " O Ataque foi de " << AtaqueR << " !!!\n";
				Sleep(2000);
				personagens[0].life = personagens[0].life - AtaqueR;
			}
			else
			{
				cout << " Seu personagem é FRACO!!! " << endl;
				cout << " Puxe uma carta na proxima rodada... " << endl;
				Sleep(2000);
			}
		}
		else if(esc == 1)
		{
			DD = Cartas();
			if(GG == 1)
			{
				Deni.life += CartasVida[DD];
				cout << "\nCarta de vida! O persornagem ganhou: " << CartasVida[DD] << " de vida.\n";
				Sleep(2000);
			}
			else if(GG == 2)
			{
				Deni.defense += CartasDefesa[DD];
				cout << "\nCarta de defesa! O persornagem ganhou: " << CartasDefesa[DD] << " de defesa.\n";
				Sleep(2000);
			}
			else if(GG == 3)
			{
				Deni.attack += CartasAtaque[DD];
				cout << "\nCarta de Ataque! O persornagem ganhou: " << CartasAtaque[DD] << " de ataque.\n";
				Sleep(2000);
			}
			else if(GG == 4)
			{
				Deni.life -= 10;
				Deni.defense -= 10;
				Deni.attack -= 10;
				cout << "\nCarta Coringa!!! O persornagem perdeu 10 de todos os atríbutos\n";
				Sleep(2000);
			}
			GG = 0;
		}
		else
		{
			cout << "\n Opção Inválida! escolha uma das opções acima. \n";
			Sleep(3000);
		}
		system("cls");

		CombateUm();
	}
} /* Fim da Função  */

/* 2 JOGADOR
=============================================================================*/

/* Ínicio da Função  */
//Função para
void combate1()
{
	
	int Ataque;
	int esc, Dano = 0, DD, AtaqueR;
	int position = 1, arrowPress;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 4);

	if(personagens[1].life <= 0)
	{
		int i = 0;
		Vitoria(i);
	}
	else if(personagens[0].life <= 0)
	{
		int i = 1;
		Vitoria(i);
	}
	else
	{
		do
		{
			setlocale(LC_ALL, "portuguese");
			cout << " - - - - - - - - - - - - - - - - - - - " << setiosflags (ios::left) << "" << setw(20) << "|     JOGADOR 1 " << setw(10) << " |    JOGADOR  2      |" << endl;
			cout << "|      Welcome to Gears Of War       |" << setiosflags (ios::left) << "" << setw(15) << " | Vida: " << setw(5) << personagens[0].life << setw(10) << "  |    Vida: " << setw(5) << personagens[1].life << setw(5) << endl;
			cout << " - - - - - - - - - - - - - - - - - - - " << setiosflags (ios::left) << "" << setw(15) << "| Ataque: " << setw(5) << personagens[0].attack << setw(10) << " |    Ataque: " << setw(5) << personagens[1].attack << setw(5) << endl;
			cout << "               JOGADOR 1:             " << setiosflags (ios::left) << "" << setw(15) << " | Defesa: " << setw(5) << personagens[0].defense << setw(10) << "  |    Defesa: " << setw(5) << personagens[1].defense << setw(5) << endl;;
			cout << " - - - - - - - - - - - - - - - " << setiosflags (ios::left) << "" << setw(15) << "        | Altura: " << setw(5) << personagens[0].altura  << setw(10) << "      |    Altura: " << setw(5) << personagens[1].altura << setw(5) << endl;
			cout << "                               " << setiosflags (ios::left) << "" << setw(15) << "        | Idade: " << setw(5) << personagens[0].idade    << setw(10) << "       |    Idade: " << setw(5) << personagens[1].idade   << setw(5) << endl;
			cout << "                               " << setiosflags (ios::left) << "" << setw(10) << "        | Nome: " << setw(2) << personagens[0].nome     << setw(10) << "           |    Nome: " << setw(5) << personagens[1].nome     << setw(5) << endl;
			arrow(1, position);
			cout << "   |  [1] - Ataque           |    " << endl;
			arrow(2, position);
			cout << "   |  [2] - Puxar Carta       |    " << endl;
			cout << " - - - - - - - - - - - - - - - " << endl;
			cout << "Informe sua escolha: Use as setas cima/baixo" << endl;
			arrowPress = getch();
			system("CLS");
			fflush(stdin);

			if (arrowPress == 80 && position != MAX)
				position++;
			else if (arrowPress == 72 && position != MIN)
				position--;
			else
				position = position;
		}
		while (arrowPress != 13);
		esc = position;

		if(esc == 1)
		{
			if(personagens[0].attack > personagens[1].defense)
			{
				Dano = personagens[0].attack - personagens[1].defense;
				AtaqueR = rand() % Dano;
				do
				{
					cout << " - - - - - - - - - - - - - - - - - - - " << setiosflags (ios::left) << "" << setw(20) << "|     JOGADOR 1 " << setw(10) << " |    JOGADOR  2      |" << endl;
					cout << "|      Welcome to Gears Of War       |" << setiosflags (ios::left) << "" << setw(15) << " | Vida: " << setw(5) << personagens[0].life << setw(10) << "  |    Vida: " << setw(5) << personagens[1].life << setw(5) << endl;
					cout << " - - - - - - - - - - - - - - - - - - - " << setiosflags (ios::left) << "" << setw(15) << "| Ataque: " << setw(5) << personagens[0].attack << setw(10) << " |    Ataque: " << setw(5) << personagens[1].attack << setw(5) << endl;
					cout << "               Ataques             " << setiosflags (ios::left) << "" << setw(15) << "    | Defesa: " << setw(5) << personagens[0].defense << setw(10) << "    |    Defesa: " << setw(5) << personagens[1].defense << setw(5) << endl;;
					cout << " - - - - - - - - - - - - - - - " << setiosflags (ios::left) << "" << setw(15) << "        | Altura: " << setw(5) << personagens[0].altura  << setw(10) << "      |    Altura: " << setw(5) << personagens[1].altura << setw(5) << endl;
					cout << "                               " << setiosflags (ios::left) << "" << setw(15) << "        | Idade: " << setw(5) << personagens[0].idade    << setw(10) << "       |    Idade: " << setw(5) << personagens[1].idade   << setw(5) << endl;
					cout << "                               " << setiosflags (ios::left) << "" << setw(10) << "        | Nome: " << setw(2) << personagens[0].nome     << setw(10) << "           |    Nome: " << setw(5) << personagens[1].nome     << setw(5) << endl;
					arrow(1, position);
					cout << "   |  [1] - Ataque Leve          |    " << endl;
					arrow(2, position);
					cout << "   |  [2] - Ataque Pesado       |    " << endl;
					cout << " - - - - - - - - - - - - - - - " << endl;
					cout << "Informe sua escolha: Use as setas cima/baixo" << endl;
					arrowPress = getch();
					system("CLS");
					fflush(stdin);

					if (arrowPress == 80 && position != MAX)
						position++;
					else if (arrowPress == 72 && position != MIN)
						position--;
					else
						position = position;
				}
				while (arrowPress != 13);

				if(position == 1)
				{
					Dano = Dano/2;
					Ataque = rand() % Dano/2;
					cout << "\n O Ataque foi de " << Ataque << " !!!\n";
					Sleep(2000);
					personagens[1].life = personagens[1].life - Ataque;
				}
				else if(position == 2)
				{
					AtaqueR = rand() % Dano;
					cout << "\n O Ataque foi de " << AtaqueR << " !!!\n";
					Sleep(2000);
					personagens[1].life = personagens[1].life - AtaqueR;
				}
			}
			else
			{
				cout << "\n Seu personagem é FRACO!!! " << endl;
				cout << " Puxe uma carta na próxima rodada... " << endl;
				Sleep(2000);
			}
		}
		else if(esc == 2)
		{
			DD = Cartas();
			if(GG == 1)
			{
				personagens[0].life += CartasVida[DD];
				cout << "\nCarta de vida! O persornagem ganhou: " << CartasVida[DD] << " de vida.\n";
				Sleep(2000);
			}
			else if(GG == 2)
			{
				personagens[0].defense += CartasDefesa[DD];
				cout << "\nCarta de defesa! O persornagem ganhou: " << CartasDefesa[DD] << " de defesa.\n";
				Sleep(2000);
			}
			else if(GG == 3)
			{
				personagens[0].attack += CartasAtaque[DD];
				cout << "\nCarta de Ataque! O persornagem ganhou: " << CartasAtaque[DD] << " de ataque.\n";
				Sleep(2000);
			}
			else if(GG == 4)
			{
				personagens[0].life -= 10;
				personagens[0].defense -= 10;
				personagens[0].attack -= 10;
				Sleep(2000);
			}
			GG = 0;
		}
		else
		{
			cout << "\n Opção Inválida! escolha uma das opções acima. \n";
			Sleep(3000);
		}

		system("cls");

		combate2();
	}
} /* Fim da Função  */

/* Ínicio da Função  */
//Função para
void combate2()
{
	int Ataque;
	int esc, Dano = 0, DD, AtaqueR;
	int position = 1, arrowPress;

	if(personagens[0].life <= 0)
	{
		int i = 1;
		Vitoria(i);
	}
	else if(personagens[1].life <= 0)
	{
		int i = 0;
		Vitoria(i);
	}
	else
	{
		do
		{
			setlocale(LC_ALL, "portuguese");
			cout << " - - - - - - - - - - - - - - - - - - - " << setiosflags (ios::left) << "" << setw(20) << "|     JOGADOR 1 " << setw(10) << " |    JOGADOR  2      |" << endl;
			cout << "|      Welcome to Gears Of War       |" << setiosflags (ios::left) << "" << setw(15) << " | Vida: " << setw(5) << personagens[0].life << setw(10) << "  |    Vida: " << setw(5) << personagens[1].life << setw(5) << endl;
			cout << " - - - - - - - - - - - - - - - - - - - " << setiosflags (ios::left) << "" << setw(15) << "| Ataque: " << setw(5) << personagens[0].attack << setw(10) << " |    Ataque: " << setw(5) << personagens[1].attack << setw(5) << endl;
			cout << "               JOGADOR 2:             " << setiosflags (ios::left) << "" << setw(15) << " | Defesa: " << setw(5) << personagens[0].defense << setw(10) << "    |    Defesa: " << setw(5) << personagens[1].defense << setw(5) << endl;;
			cout << " - - - - - - - - - - - - - - - " << setiosflags (ios::left) << "" << setw(15) << "        | Altura: " << setw(5) << personagens[0].altura  << setw(10) << "      |    Altura: " << setw(5) << personagens[1].altura << setw(5) << endl;
			cout << "                               " << setiosflags (ios::left) << "" << setw(15) << "        | Idade: " << setw(5) << personagens[0].idade    << setw(10) << "       |    Idade: " << setw(5) << personagens[1].idade   << setw(5) << endl;
			cout << "                               " << setiosflags (ios::left) << "" << setw(10) << "        | Nome: " << setw(2) << personagens[0].nome     << setw(10) << "           |    Nome: " << setw(5) << personagens[1].nome     << setw(5) << endl;
			arrow(1, position);
			cout << "   |  [1] - Ataque           |    " << endl;
			arrow(2, position);
			cout << "   |  [2] - Puxar Carta       |    " << endl;
			cout << " - - - - - - - - - - - - - - - " << endl;
			cout << "Informe sua escolha: Use as setas cima/baixo" << endl;
			arrowPress = getch();

			system("CLS");

			fflush(stdin);

			if (arrowPress == 80 && position != MAX)
				position++;
			else if (arrowPress == 72 && position != MIN)
				position--;
			else
				position = position;
		}
		while (arrowPress != 13);

		esc = position;

		if(esc == 1)
		{
			if(personagens[1].attack > personagens[0].defense)
			{
				Dano = personagens[1].attack - personagens[0].defense;
				do
				{
					cout << " - - - - - - - - - - - - - - - - - - - " << setiosflags (ios::left) << "" << setw(20) << "|     JOGADOR 1 " << setw(10) << " |    JOGADOR  2      |" << endl;
					cout << "|      Welcome to Gears Of War       |" << setiosflags (ios::left) << "" << setw(15) << " | Vida: " << setw(5) << personagens[0].life << setw(10) << "  |    Vida: " << setw(5) << personagens[1].life << setw(5) << endl;
					cout << " - - - - - - - - - - - - - - - - - - - " << setiosflags (ios::left) << "" << setw(15) << "| Ataque: " << setw(5) << personagens[0].attack << setw(10) << " |    Ataque: " << setw(5) << personagens[1].attack << setw(5) << endl;
					cout << "               Ataques             " << setiosflags (ios::left) << "" << setw(15) << "    | Defesa: " << setw(5) << personagens[0].defense << setw(10) << "  |    Defesa: " << setw(5) << personagens[1].defense << setw(5) << endl;;
					cout << " - - - - - - - - - - - - - - - " << setiosflags (ios::left) << "" << setw(15) << "        | Altura: " << setw(5) << personagens[0].altura  << setw(10) << "      |    Altura: " << setw(5) << personagens[1].altura << setw(5) << endl;
					cout << "                               " << setiosflags (ios::left) << "" << setw(15) << "        | Idade: " << setw(5) << personagens[0].idade    << setw(10) << "       |    Idade: " << setw(5) << personagens[1].idade   << setw(5) << endl;
					cout << "                               " << setiosflags (ios::left) << "" << setw(10) << "        | Nome: " << setw(2) << personagens[0].nome     << setw(10) << "           |    Nome: " << setw(5) << personagens[1].nome     << setw(5) << endl;
					arrow(1, position);
					cout << "   |  [1] - Ataque Leve          |    " << endl;
					arrow(2, position);
					cout << "   |  [2] - Ataque Pesado       |    " << endl;
					cout << " - - - - - - - - - - - - - - - " << endl;
					cout << "Informe sua escolha: Use as setas cima/baixo" << endl;
					arrowPress = getch();
					system("CLS");
					fflush(stdin);

					if (arrowPress == 80 && position != MAX)
						position++;
					else if (arrowPress == 72 && position != MIN)
						position--;
					else
						position = position;
				}
				while (arrowPress != 13);

				if(position == 1)
				{
					Dano = Dano/2;
					Ataque = rand() % Dano/2;
					cout << "\n O Ataque foi de " << Ataque << " !!!\n";
					Sleep(2000);
					personagens[0].life = personagens[0].life - Ataque;
				}
				else if(position == 2)
				{
					AtaqueR = rand() % Dano;
					cout << "\n O Ataque foi de " << AtaqueR << " !!!\n";
					Sleep(2000);
					personagens[0].life = personagens[0].life - AtaqueR;
				}
			}
			else
			{
				cout << "\n Seu personagem é FRACO!!! " << endl;
				cout << " Puxe uma carta na próxima rodada... " << endl;
				Sleep(2000);
			}
		}
	else if(esc == 2)
	{
		DD = Cartas();
		if(GG == 1)
		{
			personagens[1].life += CartasVida[DD];
			cout << "\nCarta de vida! O persornagem ganhou: " << CartasVida[DD] << " de vida.\n";
			Sleep(2000);
		}
		else if(GG == 2)
		{
			personagens[1].defense += CartasDefesa[DD];
			cout << "\nCarta de defesa! O persornagem ganhou: " << CartasDefesa[DD] << " de defesa.\n";
			Sleep(2000);
		}
		else if(GG == 3)
		{
			personagens[1].attack += CartasAtaque[DD];
			cout << "\nCarta de Ataque! O persornagem ganhou: " << CartasAtaque[DD] << " de ataque.\n";
			Sleep(2000);
		}
		else if(GG == 4)
		{
			personagens[0].life -= 10;
			personagens[0].defense -= 10;
			personagens[0].attack -= 10;
			cout << "\nCarta Coringa!!! O persornagem perdeu 10 de todos os atríbutos\n";
			Sleep(2000);
		}
		GG = 0;
	}
	else
	{
		cout << "\n Opção Inválida! escolha uma das opções acima. \n";
		Sleep(2000);
	}

	system("cls");
	combate1();
}
}/* Fim da Função  */



/* CLASSES
=============================================================================*/

/* Ínicio da Função  */
//Função para
void Classes(int x)
{
	system("cls");
	cout << " - - - - - - - - - - - - - - - - - - - -" << endl;
	cout << " Bem vindo ao menu de seleção de Classes " << endl;
	cout << " - - - - - - - - - - - - - - - - - - - -" << endl;

#define CLASSES_MAX 5
#define CLASSES_MIN 1

	int position = 1, arrowPress;

	do
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 14);

		setlocale(LC_ALL, "portuguese");

		if(x == 3)
			cout << "Classe do Segundo Jogador " << endl;
		cout << " - - - - - - - - - - - - - - - - - - - " << endl;
		cout << "|      Welcome to Gears Of War       |" << endl;
		cout << " - - - - - - - - - - - - - - - - - - - " << endl;
		arrow(1, position);
		cout << "   |  [1] - GUERREIRO              |    " << endl;
		arrow(2, position);
		cout << "   |  [2] - CAÇADOR                |    " << endl;
		arrow(3, position);
		cout << "   |  [3] - MAGO                   |    " << endl;
		arrow(4, position);
		cout << "   |  [4] - LADINO                 |    " << endl;
		arrow(5, position);
		cout << "   |  [5] - PALADINO               |    " << endl;
		cout << " - - - - - - - - - - - - - - - - - - -" << endl;
		cout << " Informe sua opção: Use as setas cima/baixo" << endl;
		arrowPress = getch();

		system("CLS");

		fflush(stdin);

		if (arrowPress == 80 && position != CLASSES_MAX)
			position++;
		else if (arrowPress == 72 && position != CLASSES_MIN)
			position--;
		else
			position = position;
	}
	while (arrowPress != 13);

	switch(position)
	{
	case 1:
		GUERREIRO(x);
		break;
	case 2:
		CACADOR(x);
		break;
	case 3:
		MAGO(x);
		break;
	case 4:
		LADINO(x);
		break;
	case 5:
		PALADINO(x);
		break;
	default:
		cout << " Opção Inválida";
		break;
	}
}/* Fim da Função  */

/* Ínicio da Função  */
//Função para
void PALADINO(int x)
{

	cout << " - - - - - - - - - - - - - - - - - - - -" << endl;
	cout << "       Classe escolhida: Paladino      " << endl;
	cout << " - - - - - - - - - - - - - - - - - - - -" << endl;

	// Atributos PreConfig dos Paladino

	personagens[Cont].attack = 50;
	personagens[Cont].defense = 70;
	personagens[Cont].agilidade = 30;
	personagens[Cont].resistencia_magia = 60;
	personagens[Cont].peso = 90;
	personagens[Cont].life = 150;

	// Fim atributos
	if(x == 3)
	{
		cout << " Informe o nome do seu Paladino:  ";
		getline(cin, personagens[Cont].nome);
		cout << " Informe sua Idade: ";
		cin >> personagens[Cont].idade;
		cout << " Informe sua Altura: ";
		cin >> personagens[Cont].altura;
		system("cls");

		cout << " Bem vindo, " << personagens[Cont].nome << endl;
		cout << " Seus atributos são: " << endl;
		cout << " - - - - - - - - - - -" << endl;
		cout << "| Ataque: " << personagens[Cont].attack << "         |" << endl;
		cout << "| Defesa: " << personagens[Cont].defense << "         |" << endl;
		cout << "| Agilidade: " << personagens[Cont].agilidade << "      |" << endl;
		cout << "| Resistência: " << personagens[Cont].resistencia_magia << "    |" << endl;
		cout << "| Peso: " << personagens[Cont].peso << "           |" << endl;
		cout << " - - - - - - - - - - -" << endl;

		Sleep(3000);
		system("cls");

		combate1();
	}

	else if(x == 2)
	{
		cout << " Informe o nome do seu Paladino:  ";
		getline(cin, personagens[Cont].nome);
		cout << " Informe sua Idade: ";
		cin >> personagens[Cont].idade;
		cout << " Informe sua Altura: ";
		cin >> personagens[Cont].altura;
		system("cls");

		cout << " Bem vindo, " << personagens[Cont].nome << endl;
		cout << " Seus atributos são: " << endl;
		cout << " - - - - - - - - - - -" << endl;
		cout << "| Ataque: " << personagens[Cont].attack << "         |" << endl;
		cout << "| Defesa: " << personagens[Cont].defense << "         |" << endl;
		cout << "| Agilidade: " << personagens[Cont].agilidade << "      |" << endl;
		cout << "| Resistência: " << personagens[Cont].resistencia_magia << "    |" << endl;
		cout << "| Peso: " << personagens[Cont].peso << "           |" << endl;
		cout << " - - - - - - - - - - -" << endl;

		Cont++;
		Sleep(3000);

		Classes(3);
	}
	else
	{

		// Dados da IA

		Deni.nome = "Deni - O Caçador";
		Deni.idade = 23;
		Deni.altura = 1.90;
		Deni.attack = 100.00;
		Deni.defense = 100.00;
		Deni.life = 150.00;
		Deni.agilidade = 50;
		Deni.resistencia_magia = 30;
		Deni.peso = 70;

		// Fim Dados

		cout << " Informe o nome do seu Paladino:  ";
		getline(cin, personagens[0].nome);
		cout << " Informe sua Idade: ";
		cin >> personagens[0].idade;
		cout << " Informe sua Altura: ";
		cin >> personagens[0].altura;

		system("cls");

		cout << " Bem vindo, " << personagens[Cont].nome << endl;
		cout << " Seus atributos são: " << endl;
		cout << " - - - - - - - - - - -" << endl;
		cout << "| Ataque: " << personagens[Cont].attack << "         |" << endl;
		cout << "| Defesa: " << personagens[Cont].defense << "         |" << endl;
		cout << "| Agilidade: " << personagens[Cont].agilidade << "      |" << endl;
		cout << "| Resistência: " << personagens[Cont].resistencia_magia << "    |" << endl;
		cout << "| Peso: " << personagens[Cont].peso << "           |" << endl;
		cout << " - - - - - - - - - - -" << endl;

		Sleep(3000);
		CombateUm();
	}

}/* Fim da Função  */

/* Ínicio da Função  */
//Função para
void LADINO(int x)
{

	cout << " - - - - - - - - - - - - - - - - - - - -" << endl;
	cout << "       Classe escolhida: Ladino      " << endl;
	cout << " - - - - - - - - - - - - - - - - - - - -" << endl;

	// Atributos PreConfig dos Ladino

	personagens[Cont].attack = 60;
	personagens[Cont].defense = 20;
	personagens[Cont].agilidade = 100;
	personagens[Cont].resistencia_magia = 35;
	personagens[Cont].peso = 35;
	personagens[Cont].life = 70;

	// Fim atributos

	if(x == 3)
	{
		cout << " Informe o nome do seu Ladino:  ";
		getline(cin, personagens[Cont].nome);
		cout << " Informe sua Idade: ";
		cin >> personagens[Cont].idade;
		cout << " Informe sua Altura: ";
		cin >> personagens[Cont].altura;
		system("cls");

		cout << " Bem vindo, " << personagens[Cont].nome << endl;
		cout << " Seus atributos são: " << endl;
		cout << " - - - - - - - - - - -" << endl;
		cout << "| Ataque: " << personagens[Cont].attack << "         |" << endl;
		cout << "| Defesa: " << personagens[Cont].defense << "         |" << endl;
		cout << "| Agilidade: " << personagens[Cont].agilidade << "     |" << endl;
		cout << "| Resistência: " << personagens[Cont].resistencia_magia << "    |" << endl;
		cout << "| Peso: " << personagens[Cont].peso << "           |" << endl;
		cout << " - - - - - - - - - - -" << endl;

		Sleep(3000);
		system("cls");

		combate1();
	}
	else if(x == 2)
	{

		cout << " Informe o nome do seu Ladino:  ";
		getline(cin, personagens[Cont].nome);
		cout << " Informe sua Idade: ";
		cin >> personagens[Cont].idade;
		cout << " Informe sua Altura: ";
		cin >> personagens[Cont].altura;
		system("cls");

		cout << " Bem vindo, " << personagens[Cont].nome << endl;
		cout << " Seus atributos são: " << endl;
		cout << " - - - - - - - - - - -" << endl;
		cout << "| Ataque: " << personagens[Cont].attack << "         |" << endl;
		cout << "| Defesa: " << personagens[Cont].defense << "         |" << endl;
		cout << "| Agilidade: " << personagens[Cont].agilidade << "     |" << endl;
		cout << "| Resistência: " << personagens[Cont].resistencia_magia << "    |" << endl;
		cout << "| Peso: " << personagens[Cont].peso << "           |" << endl;
		cout << " - - - - - - - - - - -" << endl;

		Cont++;

		Sleep(3000);
		Classes(3);
	}
	else
	{
		// Dados da IA

		Deni.nome = "Deni - O Guerreiro";
		Deni.idade = 23;
		Deni.altura = 1.90;
		Deni.attack = 100.00;
		Deni.defense = 100.00;
		Deni.life = 150.00;
		Deni.agilidade = 50;
		Deni.resistencia_magia = 30;
		Deni.peso = 70;

		// Fim Dados

		cout << " Informe o nome do seu Ladino:  ";
		getline(cin, personagens[0].nome);
		cout << " Informe sua Idade: ";
		cin >> personagens[0].idade;
		cout << " Informe sua Altura: ";
		cin >> personagens[0].altura;
		system("cls");

		cout << " Bem vindo, " << personagens[Cont].nome << endl;
		cout << " Seus atributos são: " << endl;
		cout << " - - - - - - - - - - -" << endl;
		cout << "| Ataque: " << personagens[Cont].attack << "         |" << endl;
		cout << "| Defesa: " << personagens[Cont].defense << "         |" << endl;
		cout << "| Agilidade: " << personagens[Cont].agilidade << "     |" << endl;
		cout << "| Resistência: " << personagens[Cont].resistencia_magia << "    |" << endl;
		cout << "| Peso: " << personagens[Cont].peso << "           |" << endl;
		cout << " - - - - - - - - - - -" << endl;

		Sleep(3000);
		CombateUm();
	}
}/* Fim da Função  */

/* Ínicio da Função  */
//Função para
void MAGO(int x)
{

	cout << " - - - - - - - - - - - - - - - - - - - -" << endl;
	cout << "       Classe escolhida: Mago      " << endl;
	cout << " - - - - - - - - - - - - - - - - - - - -" << endl;

	// Atributos PreConfig dos Mago

	personagens[Cont].attack = 40;
	personagens[Cont].defense = 30;
	personagens[Cont].agilidade = 50;
	personagens[Cont].resistencia_magia = 80;
	personagens[Cont].peso = 50;
	personagens[Cont].life = 80;
	personagens[Cont].inteligencia = 100;

	// Fim atributos

	if(x == 3)
	{
		cout << " Informe o nome do seu Mago:  ";
		getline(cin, personagens[Cont].nome);
		cout << " Informe sua Idade: ";
		cin >> personagens[Cont].idade;
		cout << " Informe sua Altura: ";
		cin >> personagens[Cont].altura;
		system("cls");

		cout << " Bem vindo, " << personagens[Cont].nome << endl;
		cout << " Seus atributos são: " << endl;
		cout << " - - - - - - - - - - -" << endl;
		cout << "| Ataque: " << personagens[Cont].attack << "         |" << endl;
		cout << "| Defesa: " << personagens[Cont].defense << "         |" << endl;
		cout << "| Agilidade: " << personagens[Cont].agilidade << "      |" << endl;
		cout << "| Resistência: " << personagens[Cont].resistencia_magia << "    |" << endl;
		cout << "| Peso: " << personagens[Cont].peso << "           |" << endl;
		cout << " - - - - - - - - - - -" << endl;

		Sleep(3000);
		system("cls");

		combate1();
	}
	else if(x == 2)
	{
		cout << " Informe o nome do seu Mago:  ";
		getline(cin, personagens[Cont].nome);
		cout << " Informe sua Idade: ";
		cin >> personagens[Cont].idade;
		cout << " Informe sua Altura: ";
		cin >> personagens[Cont].altura;
		system("cls");

		cout << " Bem vindo, " << personagens[Cont].nome << endl;
		cout << " Seus atributos são: " << endl;
		cout << " - - - - - - - - - - -" << endl;
		cout << "| Ataque: " << personagens[Cont].attack << "         |" << endl;
		cout << "| Defesa: " << personagens[Cont].defense << "         |" << endl;
		cout << "| Agilidade: " << personagens[Cont].agilidade << "      |" << endl;
		cout << "| Resistência: " << personagens[Cont].resistencia_magia << "    |" << endl;
		cout << "| Peso: " << personagens[Cont].peso << "           |" << endl;
		cout << " - - - - - - - - - - -" << endl;

		Cont++;
		Sleep(3000);

		Classes(3);
	}
	else
	{

		// Dados da IA

		Deni.nome = "Deni - Paladino";
		Deni.idade = 23;
		Deni.altura = 1.90;
		Deni.attack = 100.00;
		Deni.defense = 100.00;
		Deni.life = 150.00;
		Deni.agilidade = 50;
		Deni.resistencia_magia = 30;
		Deni.peso = 70;

		// Fim Dados

		cout << " Informe o nome do seu Mago:  ";
		getline(cin, personagens[0].nome);
		cout << " Informe sua Idade: ";
		cin >> personagens[0].idade;
		cout << " Informe sua Altura: ";
		cin >> personagens[0].altura;
		system("cls");

		cout << " Bem vindo, " << personagens[Cont].nome << endl;
		cout << " Seus atributos são: " << endl;
		cout << " - - - - - - - - - - -" << endl;
		cout << "| Ataque: " << personagens[Cont].attack << "         |" << endl;
		cout << "| Defesa: " << personagens[Cont].defense << "         |" << endl;
		cout << "| Agilidade: " << personagens[Cont].agilidade << "      |" << endl;
		cout << "| Resistência: " << personagens[Cont].resistencia_magia << "    |" << endl;
		cout << "| Peso: " << personagens[Cont].peso << "           |" << endl;
		cout << " - - - - - - - - - - -" << endl;

		Sleep(3000);

		CombateUm();
	}

}/* Fim da Função  */

/* Ínicio da Função  */
//Função para
void CACADOR(int x)
{

	cout << " - - - - - - - - - - - - - - - - - - - -" << endl;
	cout << "       Classe escolhida: Caçador      " << endl;
	cout << " - - - - - - - - - - - - - - - - - - - -" << endl;

	// Atributos PreConfig dos Caçador

	personagens[Cont].attack = 80;
	personagens[Cont].defense = 40;
	personagens[Cont].agilidade = 100;
	personagens[Cont].resistencia_magia = 40;
	personagens[Cont].peso = 45;
	personagens[Cont].life = 90;

	// Fim atributos

	if(x == 3)
	{
		cout << " Informe o nome do seu Caçador:  ";
		getline(cin, personagens[Cont].nome);
		cout << " Informe sua Idade: ";
		cin >> personagens[Cont].idade;
		cout << " Informe sua Altura: ";
		cin >> personagens[Cont].altura;
		system("cls");

		cout << " Bem vindo, " << personagens[Cont].nome << endl;
		cout << " Seus atributos são: " << endl;
		cout << " - - - - - - - - - - -" << endl;
		cout << "| Ataque: " << personagens[Cont].attack << "         |" << endl;
		cout << "| Defesa: " << personagens[Cont].defense << "         |" << endl;
		cout << "| Agilidade: " << personagens[Cont].agilidade << "     |" << endl;
		cout << "| Resistência: " << personagens[Cont].resistencia_magia << "    |" << endl;
		cout << "| Peso: " << personagens[Cont].peso << "           |" << endl;
		cout << " - - - - - - - - - - -" << endl;

		Sleep(3000);
		system("cls");

		combate1();
	}
	else if(x == 2)
	{
		cout << " Informe o nome do seu Caçador:  ";
		getline(cin, personagens[Cont].nome);
		cout << " Informe sua Idade: ";
		cin >> personagens[Cont].idade;
		cout << " Informe sua Altura: ";
		cin >> personagens[Cont].altura;
		system("cls");

		cout << " Bem vindo, " << personagens[Cont].nome << endl;
		cout << " Seus atributos são: " << endl;
		cout << " - - - - - - - - - - -" << endl;
		cout << "| Ataque: " << personagens[Cont].attack << "         |" << endl;
		cout << "| Defesa: " << personagens[Cont].defense << "         |" << endl;
		cout << "| Agilidade: " << personagens[Cont].agilidade << "     |" << endl;
		cout << "| Resistência: " << personagens[Cont].resistencia_magia << "    |" << endl;
		cout << "| Peso: " << personagens[Cont].peso << "           |" << endl;
		cout << " - - - - - - - - - - -" << endl;

		Cont++;
		Sleep(3000);

		Classes(3);
	}
	else
	{

		// Dados da IA

		Deni.nome = "Deni - Ladino";
		Deni.idade = 23;
		Deni.altura = 1.90;
		Deni.attack = 100.00;
		Deni.defense = 100.00;
		Deni.life = 150.00;
		Deni.agilidade = 50;
		Deni.resistencia_magia = 30;
		Deni.peso = 70;

		// Fim Dados

		cout << " Informe o nome do seu Caçador:  ";
		getline(cin, personagens[0].nome);
		cout << " Informe sua Idade: ";
		cin >> personagens[0].idade;
		cout << " Informe sua Altura: ";
		cin >> personagens[0].altura;
		system("cls");

		cout << " Bem vindo, " << personagens[Cont].nome << endl;
		cout << " Seus atributos são: " << endl;
		cout << " - - - - - - - - - - -" << endl;
		cout << "| Ataque: " << personagens[Cont].attack << "         |" << endl;
		cout << "| Defesa: " << personagens[Cont].defense << "         |" << endl;
		cout << "| Agilidade: " << personagens[Cont].agilidade << "     |" << endl;
		cout << "| Resistência: " << personagens[Cont].resistencia_magia << "    |" << endl;
		cout << "| Peso: " << personagens[Cont].peso << "           |" << endl;
		cout << " - - - - - - - - - - -" << endl;

		Sleep(3000);

		CombateUm();
	}

}/* Fim da Função  */

/* Ínicio da Função  */
//Função para
void GUERREIRO(int x)
{

	cout << " - - - - - - - - - - - - - - - - - - - -" << endl;
	cout << "       Classe escolhida: Guerreiro      " << endl;
	cout << " - - - - - - - - - - - - - - - - - - - -" << endl;

	// Atributos PreConfig dos Guerreiro

	personagens[Cont].attack = 90;
	personagens[Cont].defense = 60;
	personagens[Cont].agilidade = 40;
	personagens[Cont].resistencia_magia = 30;
	personagens[Cont].peso = 70;
	personagens[Cont].life = 100;

	// Fim atributos

	if(x == 3)
	{
		cout << " Informe o nome do seu Guerreiro:  ";
		getline(cin, personagens[Cont].nome);
		cout << " Informe sua Idade: ";
		cin >> personagens[Cont].idade;
		cout << " Informe sua Altura: ";
		cin >> personagens[Cont].altura;
		system("cls");

		cout << " Bem vindo, " << personagens[Cont].nome << endl;
		cout << " Seus atributos são: " << endl;
		cout << " - - - - - - - - - - -" << endl;
		cout << "| Ataque: " << personagens[Cont].attack << "         |" << endl;
		cout << "| Defesa: " << personagens[Cont].defense << "         |" << endl;
		cout << "| Agilidade: " << personagens[Cont].agilidade << "      |" << endl;
		cout << "| Resistência: " << personagens[Cont].resistencia_magia << "    |" << endl;
		cout << "| Peso: " << personagens[Cont].peso << "           |" << endl;
		cout << " - - - - - - - - - - -" << endl;

		Sleep(3000);
		system("cls");

		combate1();
	}
	else if(x == 2)
	{
		cout << " Informe o nome do seu Guerreiro:  ";
		getline(cin, personagens[Cont].nome);
		cout << " Informe sua Idade: ";
		cin >> personagens[Cont].idade;
		cout << " Informe sua Altura: ";
		cin >> personagens[Cont].altura;
		system("cls");

		cout << " Bem vindo, " << personagens[Cont].nome << endl;
		cout << " Seus atributos são: " << endl;
		cout << " - - - - - - - - - - -" << endl;
		cout << "| Ataque: " << personagens[Cont].attack << "         |" << endl;
		cout << "| Defesa: " << personagens[Cont].defense << "         |" << endl;
		cout << "| Agilidade: " << personagens[Cont].agilidade << "      |" << endl;
		cout << "| Resistência: " << personagens[Cont].resistencia_magia << "    |" << endl;
		cout << "| Peso: " << personagens[Cont].peso << "           |" << endl;
		cout << " - - - - - - - - - - -" << endl;

		Cont++;
		Sleep(3000);

		Classes(3);
	}
	else
	{

		// Dados da IA

		Deni.nome = "Deni - O Mago";
		Deni.idade = 23;
		Deni.altura = 1.90;
		Deni.attack = 100.00;
		Deni.defense = 100.00;
		Deni.life = 150.00;
		Deni.agilidade = 50;
		Deni.resistencia_magia = 30;
		Deni.peso = 70;

		// Fim Dados

		cout << " Informe o nome do seu Guerreiro:  ";
		getline(cin, personagens[0].nome);
		cout << " Informe sua Idade: ";
		cin >> personagens[0].idade;
		cout << " Informe sua Altura: ";
		cin >> personagens[0].altura;
		system("cls");

		cout << " Bem vindo, " << personagens[Cont].nome << endl;
		cout << " Seus atributos são: " << endl;
		cout << " - - - - - - - - - - -" << endl;
		cout << "| Ataque: " << personagens[Cont].attack << "         |" << endl;
		cout << "| Defesa: " << personagens[Cont].defense << "         |" << endl;
		cout << "| Agilidade: " << personagens[Cont].agilidade << "      |" << endl;
		cout << "| Resistência: " << personagens[Cont].resistencia_magia << "    |" << endl;
		cout << "| Peso: " << personagens[Cont].peso << "           |" << endl;
		cout << " - - - - - - - - - - -" << endl;

		Sleep(3000);
		CombateUm();
	}

}/* Fim da Função  */

/* MANUAL DE INSTRUÇÕES
=============================================================================*/

/* Ínicio da Função  */
//Função para
void ManualDeInstrucao()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 2);
	cout << "**********************************************************************MANUAL DE INSTRUÇÕES****************************************************************************" << endl;
	cout << "_______________________________________________________________________________________________________________________________________________________________________" << endl;
	cout << "| Cada Jogador Escolhe o Nome do Personagem, Sua Altura a Defesa e o Seu Ataque.                                                                                      |" << endl;
	cout << "| São disponibilizadas cinco classes de Persongem(GUERREIRO, CAÇADOR, MAGO, LADINO, PALADINO).                                                                        |" <<endl;
	cout << "| De acordo com a classe de personagem escolhido, seus atributos serão incrementados.                                                                                 |" << endl;
	cout << "| O jogo existem várias cartas de ação, que são divididas em três tipos.                                                                                              |" << endl;
	cout << "| Sendo elas cartas de ataque, defesa e cartas de vida, as mesmas são geradas aleatoriamente.                                                                         |" << endl;
	cout << "|                                                                                                                                                                     |" << endl;
	cout << "| São dez cartas para cada tipo, sendo que as cartas de ataque tem 50% de chance de serem adquiridas, a defesa tem 30% de chance e a vida tem 20%.                    |" << endl;
	cout << "| Existe também a carta coringa que retira dez pontos de cada atributo.                                                                                               |" << endl;
	cout << "| O joga funciona por turnos. Em cada partida o jogador escolhe entre realizar um ataque ou puxar uma carta.                                                          |" << endl;
	cout << "| Caso o Jogador escolha opção de ataque existe a opção de ataque leve ou ataque pesado.                                                                              |" << endl;
	cout << "| O jogo possui dois módulos, sendo a versão singleplay que o jogador enfrenta uma IA (inteligencia artificial).                                                      |" << endl;
	cout << "| E a versão multiplayer que são dois jogadores simultaneamente.                                                                                                      |" << endl;
	cout << "|_____________________________________________________________________________________________________________________________________________________________________|" << endl;
	system("pause");
	main();
}/* Fim da Função  */

/* CRÉDITOS
============================================================================*/

/* Ínicio da Função  */
//Função para
void arrow (int position, int arrowPosition)
{
	(position == arrowPosition) ? cout << "-> " : cout << "  ";
} /* Fim da Função  */

/* Ínicio da Função  */
//Função para
ostream& boldOn(ostream& os)
{
	return os << "\e[1m";
}/* Fim da Função  */

/* Ínicio da Função  */
//Função para
ostream& boldOff(ostream& os)
{
	return os << "\e[0m";
}/* Fim da Função  */

/* Ínicio da Função  */
//Função para
void imprimirArcoIris(string x)
{
	cout << "|";
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int k = 10, tam = x.length();

	for(int i = 0; i < tam; i++)
	{
		SetConsoleTextAttribute(hConsole, k);
		if (k > 14)
		{
			k = 10;
		}

		((i + 1) % 2 != 0) ? cout << char(toupper(x[i])) : cout << x[i];
		Sleep(70);
		k++;

	}
	SetConsoleTextAttribute(hConsole, 0);

}/* Fim da Função  */

/* Ínicio da Função  */
//Função para
void Creditos()
{

	string guilherme = "Guilherme A. Silva.", edenilson = "Edenilson do N. Silva.", joao = "João Luis M. de Lima.",
		   antonio = "Antonio Rodriguês da S. Junior",	gabriel = "Gabriel F. da S. Fernandes", paulo = "Paulo Sergio M. M. de Oliveira.";

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 6);
	cout << "|" << boldOn << "Créditos:" << boldOff << "|" << endl;
	SetConsoleTextAttribute(hConsole, 0);
	cout << "------------------------" << endl;
	cout << "|" << boldOn << "Author" << "                " <<  boldOff << "|" << endl;
	imprimirArcoIris(guilherme);
	cout << "   |" << endl;
	cout << "---------------------------------------------------" << endl;
	cout << "                       " << "|" << boldOn << "Desenvolvedor de Conteúdo" << boldOff << " |" << endl;
	cout << "                       ";
	imprimirArcoIris(antonio);
	cout << "|" << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "|" << boldOn << "Coordenador de Produção" << boldOff << "|" << "                          " << "|" << boldOn << " Coordenador de Projetos         " << boldOff << "  |" << endl;
	imprimirArcoIris(edenilson);
	cout << "|";
	cout << "                          ";
	imprimirArcoIris(joao);
	cout << "|";
	cout << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "                       " << "|" << boldOn << "Estagiário " << boldOff << "    |" << endl;
	cout << "                       ";
	imprimirArcoIris(gabriel);
	cout << "|" << endl;
	cout << "                       ------------------------------------------------------------" << endl;
	cout << "                       " << " " << "                          " << "|" << boldOn << "Estagiário " << boldOff << "            |" << endl;
	cout << "                       " << " " << "                          ";
	imprimirArcoIris(paulo);
	cout << "|" << endl;
	cout << "                                                  ---------------------------------" << endl;
} /* Fim da Função  */

/* OUTRAS FUNÇÕES
=============================================================================*/

/* Ínicio da Função  */
//Função para
void Vitoria(int i)
{	
	if(i==0){
	cout << "       (X)             (X)                              " <<endl;	
	cout << "        (X)           (X)                               " <<endl;
	cout << "         (X)         (X)                     (X)(X)(X)  " <<endl;
	cout << "           (X)     (X)                          (X)     " <<endl;
	cout << "             (X) (X)                            (X)     " <<endl;
	cout << "               (X)                              (X)     " <<endl;
	cout << "                                          (X)   (X)     " <<endl;
	cout << "                                            (X)(X)      " <<endl;
	cout << "                                                        " <<endl;
	cout << "                                                        " <<endl;
	cout << "                                                        " <<endl;         
	  
	  	
	cout << "               (X)                        (X)(X)(X)    " <<endl;
	cout << "                                        (X)       (X)  " <<endl;
	cout << "               (X)                     (X)         (X) " <<endl;
	cout << "               (X)                     (X)         (X) " <<endl;
	cout << "               (X)                      (X)       (X)  " <<endl;
	cout << "               (X)                        (X)(X)(X)    " <<endl;
	cout << "               (X)                       " <<endl;
    cout << endl;
	cout << "          (X)(X)(X)(X)(X)               (X)(X)(X)(X)      (X)   " <<endl;
	cout << "                (X)                     (X)            (X)(X)   " <<endl;
	cout << "                (X)                     (X)               (X)   " <<endl;
	cout << "                (X)                     (X)   (X)(X)      (X)   " <<endl;
	cout << "                (X)                     (X)      (X)      (X)   " <<endl;
	cout << "                (X)                     (X)(X)(X)(X)   (X)(X)(X)" <<endl;
	cout << endl;
	cout << "             (X)(X)(X)                  (X)(X)(X)(X)   " <<endl;
	cout << "           (X)       (X)                (X)      (X)   " <<endl;
	cout << "          (X)         (X)               (X)      (X)   " <<endl;
	cout << "          (X)         (X)               (X)(X)(X)(X)   " <<endl;
	cout << "           (X)       (X)                (X)      (X)   " <<endl;
	cout << "             (X)(X)(X)                  (X)      (X)   " <<endl;
    cout << "                                        (X)      (X)   " <<endl;
    
	cout << endl;
	cout << "            (X)(X)(X)                   (X)(X)(X)      " <<endl;
	cout << "            (X)     (X)                 (X)    (X)     " <<endl;
	cout << "            (X)    (X)                  (X)     (X)    " <<endl;
	cout << "            (X)(X)(X)                   (X)     (X)    " <<endl;
	cout << "            (X)    (X)                  (X)     (X)    " <<endl;
	cout << "            (X)     (X)                 (X)     (X)    " <<endl;
	cout << "            (X)       (X)               (X)(X)(X)      " <<endl;
	cout << endl;
    cout << "               (X)                       (X)(X)(X)     " <<endl;
	cout << "                                       (X)       (X)   " <<endl;
	cout << "               (X)                    (X)         (X)  " <<endl;
	cout << "               (X)                    (X)         (X)  " <<endl;
	cout << "               (X)                     (X)       (X)   " <<endl;
	cout << "               (X)                       (X)(X)(X)     " <<endl;
	cout << "               (X)                       " <<endl;
	cout << endl;
    cout << "          (X)(X)(X)(X)                 (X)(X)(X)       " <<endl;
	cout << "          (X)      (X)                 (X)     (X)     " <<endl;
	cout << "          (X)      (X)                 (X)    (X)      " <<endl;
	cout << "          (X)(X)(X)(X)                 (X)(X)(X)       " <<endl;
	cout << "          (X)      (X)                 (X)    (X)      " <<endl;
	cout << "          (X)      (X)                 (X)     (X)     " <<endl;
	cout << "          (X)      (X)                 (X)       (X)   " <<endl;
	system("pause");	
	}else if(i==1){
	cout << "       (X)             (X)                              " <<endl;	
	cout << "        (X)           (X)                               " <<endl;
	cout << "         (X)         (X)                     (X)(X)(X)  " <<endl;
	cout << "           (X)     (X)                          (X)     " <<endl;
	cout << "             (X) (X)                            (X)     " <<endl;
	cout << "               (X)                              (X)     " <<endl;
	cout << "                                          (X)   (X)     " <<endl;
	cout << "                                            (X)(X)      " <<endl;
	cout << "                                                        " <<endl;
	cout << "                                                        " <<endl;
	cout << "                                                        " <<endl;         
	  
	  	
	cout << "               (X)                        (X)(X)(X)    " <<endl;
	cout << "                                        (X)       (X)  " <<endl;
	cout << "               (X)                     (X)         (X) " <<endl;
	cout << "               (X)                     (X)         (X) " <<endl;
	cout << "               (X)                      (X)       (X)  " <<endl;
	cout << "               (X)                        (X)(X)(X)    " <<endl;
	cout << "               (X)                       " <<endl;

	cout << "          (X)(X)(X)(X)(X)               (X)(X)(X)(X)      (X)(X)    " <<endl;
	cout << "                (X)                     (X)            (X)    (X)   " <<endl;
	cout << "                (X)                     (X)                 (X)     " <<endl;
	cout << "                (X)                     (X)   (X)(X)      (X)       " <<endl;
	cout << "                (X)                     (X)      (X)    (X)         " <<endl;
	cout << "                (X)                     (X)(X)(X)(X)   (X)(X)(X)(X) " <<endl;
	
	cout << "             (X)(X)(X)                  (X)(X)(X)(X)   " <<endl;
	cout << "            (X)       (X)               (X)      (X)   " <<endl;
	cout << "           (X)         (X)              (X)      (X)   " <<endl;
	cout << "           (X)         (X)              (X)(X)(X)(X)   " <<endl;
	cout << "            (X)       (X)               (X)      (X)   " <<endl;
	cout << "              (X)(X)(X)                 (X)      (X)   " <<endl;
    cout << "                                        (X)      (X)   " <<endl;
	
	cout << "            (X)(X)(X)                   (X)(X)(X)      " <<endl;
	cout << "            (X)     (X)                 (X)    (X)     " <<endl;
	cout << "            (X)    (X)                  (X)     (X)    " <<endl;
	cout << "            (X)(X)(X)                   (X)     (X)    " <<endl;
	cout << "            (X)    (X)                  (X)     (X)    " <<endl;
	cout << "            (X)     (X)                 (X)     (X)    " <<endl;
	cout << "            (X)       (X)               (X)(X)(X)      " <<endl;
	
    cout << "               (X)                       (X)(X)(X)     " <<endl;
	cout << "                                       (X)       (X)   " <<endl;
	cout << "               (X)                    (X)         (X)  " <<endl;
	cout << "               (X)                    (X)         (X)  " <<endl;
	cout << "               (X)                     (X)       (X)   " <<endl;
	cout << "               (X)                       (X)(X)(X)     " <<endl;
	cout << "               (X)                       " <<endl;
	
    cout << "          (X)(X)(X)(X)                 (X)(X)(X)       " <<endl;
	cout << "          (X)      (X)                 (X)     (X)     " <<endl;
	cout << "          (X)      (X)                 (X)    (X)      " <<endl;
	cout << "          (X)(X)(X)(X)                 (X)(X)(X)       " <<endl;
	cout << "          (X)      (X)                 (X)    (X)      " <<endl;
	cout << "          (X)      (X)                 (X)     (X)     " <<endl;
	cout << "          (X)      (X)                 (X)       (X)   " <<endl;
	system("pause");		
	}
}/* Fim da Função  */

/* Ínicio da Função  */
//Função para
int Cartas()
{
	int Test1, Test2, Test3;
	int CartaVida, CartaAtaque, CartaDefesa;
	Test1 = rand() % 100;
	Test2 = rand() % 100;
	Test3 = rand() % 100;

	// RAND VIDA
	if(Test1 > 0 && Test1 <= 20)
	{
		if(Test2 > 0 && Test2 <= 20)
		{
			if(Test3 > 0 && Test3 <= 20)
			{
				GG = 1;
				return CartaVida = rand() % 9;
			}
		}
	}

	// RAND DEFESA
	if(Test1 > 20 && Test1 <= 50)
	{
		if(Test2 > 20 && Test2 <= 50)
		{
			if(Test3 > 20 && Test3 <= 50)
			{
				GG = 2;
				return CartaDefesa = rand() % 9;
			}
		}
	}
	// RAND ATAQUE
	if(Test1 > 50 && Test1 <= 100)
	{
		if(Test2 > 50 && Test2 <= 100)
		{
			if(Test3 > 50 && Test3 <= 100)
			{
				GG = 3;
				return CartaAtaque = rand() % 9;
			}
		}
	}
	// RAND VIDA V2
	if(Test1 > 0 && Test1 <= 20)
	{
		if((Test2 > 0 && Test2 <= 20) || (Test3 > 0 && Test3 <= 20))
		{
			GG = 1;
			return CartaVida = rand() % 9;
		}
	}
	else if(Test2 > 0 && Test2 <= 20 && Test3 > 0 && Test3 <= 20)
	{
		GG = 1;
		return CartaVida = rand() % 9;
	}

	// RAND DEFESA V2
	if(Test1 > 20 && Test1 <= 50)
	{
		if((Test2 > 20 && Test2 <= 50) || (Test3 > 20 && Test3 <= 50))
		{
			GG = 2;
			return CartaDefesa = rand() % 9;
		}
	}
	else if(Test2 > 20 && Test2 <= 50 && Test3 > 20 && Test3 <= 50)
	{
		GG = 2;
		return CartaDefesa = rand() % 9;
	}

	// RAND ATAQUE V2
	if(Test1 > 50 && Test1 <= 100)
	{
		if((Test2 > 50 && Test2 <= 100) || (Test3 > 50 && Test3 <= 100))
		{
			GG = 3;
			return CartaAtaque = rand() % 9;
		}
	}
	else if(Test2 > 50 && Test2 <= 100 && Test3 > 50 && Test3 <= 100)
	{
		GG = 3;
		return CartaAtaque = rand() % 9;
	}
	// RAND CARTA CORINGA
	else
	{
		GG = 4;
		return 0;
	}

	return 0;

} /* Fim da Função  */

/* Ínicio da Função  */
//Função para limitar a quantidade máxima de defesa
int defense(int i)
{
	//Variáveis ultilizadas
	int defensee, AVG;

	cout << " Insira sua defesa novamente: ";
	cin >> defensee;

	AVG = personagens[i].attack + defensee;
	if(AVG > 100)
	{
		system("cls");
		cout << " Valor Máximo de defesa permitida: " << 100 - personagens[i].attack << endl;
		return defense(i);
	}
	else
		return defensee;
} /* Fim da Função  */

/* Ínicio da Função  */
//Função para limitar a quantidade máxima de ataque
int attack()
{
	int attackk;

	cout << " Insira o ataque novamente: ";
	cin >> attackk;

	if(attackk > 100)
	{
		system("cls");
		return attack();
	}
	else
		return attackk;
} /* Fim da Função  */
