#include <stdio.h>
#include <string.h>

/* termios.h und unistd.h werden für das setzen der Konsolen Flags benötigt */
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>

/* Variablendeklaration */
/* Die Matrix mit 11*42 vom Typ char wird Deklariert */
char matrix[11][42];
int TastenAbfrage;
int TestAufPfeiltaste;

/* Strukturtyp für die Änderung der Konsolen Flags wird Deklariert */
struct termios alt,neu;

/* Escape Sequenzen werden als Funktionen Deklariert */
void position(int Zeile, int Spalte)
	{
	printf("\033[%d;%dH",Zeile,Spalte);
	}
void Down_Anzahl(int SpalteRunter)
	{
	printf("\033[%dB",SpalteRunter);
	}
void Right_Anzahl(int ZeileRechts)
	{
	printf("\033[%dC",ZeileRechts);
	}
void Clear_Screen()
	{
	printf("\033[2J");
	}
void Background_Blue()
	{
	printf("\033[44m");
	}
void Background_Kobaltblue()
	{
	printf("\033[46m");
	}
void Background_Default()
	{
	printf("\033[0m");
	}
void Blinken()
	{
	printf("\033[5m");
	}
void Unterstrichen()
	{
	printf("\033[4m");
	}
void Umkehrung()
	{
	printf("\033[7m");
	}
void TextRot()
	{
	printf("\033[31m");
	}

/* Ermitteln und schreiben des aktuellen Directory in die Matrix*/
void GetDirName()
	{
	char dirname[100];
	getcwd(dirname, 100) ;
	int i,Laenge;
	Laenge = strlen(dirname);
	for (i=0; i < Laenge; i++)
		{
		matrix[8][i+9] = dirname[i];
		}
	}

/* Ermitteln und schreiben des aktuellen Users in die Matrix*/
void GetUserName()
	{
	int Laenge1,Laenge2;
	int i;
	char *user;
	char wer[] = "Wer bist Du?";
	user = getenv("USER");
	Laenge1 = strlen(user);
	Laenge2 = strlen(wer);
	if(NULL != user)
		{
		for (i=0; i < Laenge1; i++)
			{
			matrix[8][i+9] = user[i];
			}
		}
	else
		{
		for (i=0; i < Laenge2; i++)
			{
			matrix[8][i+9] = wer[i];
			}
		}
	}

/* Das Setzen und Rücksetzen der Konsolen Flags wird als Funktionen Deklariert */
void EingabeAendern()
	{
	tcgetattr(fileno(stdin),&alt);
	neu=alt;
	neu.c_lflag &= ~ICANON;
	neu.c_lflag &= ~ECHO;
	tcsetattr(fileno(stdin),TCSANOW,&neu);
	}
void EingabeRuecksetzen()
	{
	tcsetattr(fileno(stdin),TCSANOW,&alt);
	}

/* Tastaturabfrage als Funktion Deklariert */
void Abfrage()
	{
	EingabeAendern();
	Background_Blue();
	TastenAbfrage = getchar();
	EingabeRuecksetzen();
	Background_Default();
	}

/* Setzt benutzte Zellen der Matrix nach Ausgabe UserName oder DirName zurück*/
void MatrixRuecksetzen()
	{
	int i;
	for (i=1; i < 41; i++)
		{
		matrix[8][i] = ' ';
		}
	}

/* Die Darstellung der Matrix wird als Funktion Deklariert */
void display_matrix(int Entscheidung)
	{
	int i,j;

	/* Reihe */
	for (i=0; i < 11; i++)
		{
		if (i < 1)
			Down_Anzahl(5);
		printf("\n");
		Right_Anzahl(10);

		/* Spalte */
		for (j=0; j < 42; j++)
			{
			/* Schreibe matrix */
			if (( i == 2 || i == 4 || i == 6 ) && j > 8 && j < 34)
				Background_Kobaltblue();							
			else	
				Background_Blue();			
			if (i == 2 && j > 14 && j < 22)
				Unterstrichen();
			if (i == 4 && j > 14 && j < 22)
				TextRot();
			if (i == 6 && j > 15 && j < 22 )
				Blinken();
			if (Entscheidung == 1 && i == 2 && j > 8 && j < 34)
				Umkehrung();
			if (Entscheidung == 2 && i == 4 && j > 8 && j < 34)
				Umkehrung();
			if (Entscheidung == 3 && i == 6 && j > 8 && j < 34)
				Umkehrung();
			printf("%c", matrix[i][j]);
			Background_Default();
			}
 		}
	}

/* Das Füllen der Matrix wird als Funktion Deklariert */
void fuelle_matrix(void)
	{
	int i,j;
	char ShowDir[] =  " Show Current Directory  ";
	char ShowUser[] = " Show Current User       ";
	char Exit[] =     " Exit (HotKey 'q')       ";
	for (i=0; i < 11; i++)
		{
		matrix[i][0] = '|';
		matrix[i][41] = '|';
		}
	for (j=0; j < 42; j++)
		{
		matrix[0][j] = '-';
		matrix[10][j] = '-';
		if (j < 24)
			{
			matrix[2][j+9] = ShowDir[j];
			matrix[4][j+9] = ShowUser[j];
			matrix[6][j+9] = Exit[j];
			}
		}
	}

/* Start des Hauptprogramms */
int main(void)
{
	int x = 1;
	int EndBedingung = 0;
	Clear_Screen();
	position(1,1);

	/* Initialisiere matrix mit leerzeichen ' ' */
	memset(matrix, ' ', sizeof(matrix));

	fuelle_matrix();
  
	/* Stelle matrix dar */
	display_matrix(x);
	
	while (1)
		{
		if (EndBedingung == 1)
			break;
		Abfrage();
		if (TastenAbfrage == 113)
			break;
		TestAufPfeiltaste = TastenAbfrage;
		switch(TestAufPfeiltaste)
			{
			case 65:
				switch(x)
					{
					case 1:
						x = 3;
						break;
					case 2:
						x = 1;
						break;
					case 3:
						x = 2;
						break;
					}
				position(1,1);
//				Clear_Screen();
				display_matrix(x);				
				break;
			case 66:
				switch(x)
					{
					case 1:
						x = 2;
						break;
					case 2:
						x = 3;
						break;
					case 3:
						x = 1;
						break;
					}
				position(1,1);
//				Clear_Screen();
				display_matrix(x);
				break;
			case 10:
				switch(x)
					{
					case 1:
						Clear_Screen();
						position(1,1);
						GetDirName();
						display_matrix(1);
						MatrixRuecksetzen();
						break;
					case 2:
						Clear_Screen();
						position(1,1);
						GetUserName();
						display_matrix(2);
						MatrixRuecksetzen();
						break;
					case 3:
						EndBedingung = 1;
						break;
					}
			}
		}	
	position(24,0);    
	/* Beende programm */
	return 0;
}
