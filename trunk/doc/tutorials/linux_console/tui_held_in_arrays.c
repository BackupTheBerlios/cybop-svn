#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* termios.h und unistd.h werden für das setzen der Konsolen Flags benötigt */
#include <termios.h>
#include <unistd.h>

/* Variablendeklaration */
/* Die Matrix mit 11 Zeilen * 42 Spalten vom Typ char wird deklariert */
char matrix[11][42];
int TastenAbfrage;
int TestAufPfeiltaste;

/* Strukturtyp für die Änderung der Konsolen Flags wird deklariert, termios ist ein Strukturtyp aus termios.h */
/* der Struct termios sieht folgendermassen aus: struct termios { 
								tcflag_t c_iflag; Eingabe-Flag
								tcflag_t c_oflag; Ausgabe-Flag
								tcflag_t c_cflag; Kontroll-Flag
								tcflag_t c_lflag; Lokale Flags
								cc_t c_cc[NCCS];  Steuerzeichen
								}; */
struct termios alt,neu;

/* Escape Sequenzen mit Variablenübergabe werden als Funktionen deklariert */
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

/* Escape Sequenzen ohne Variablenübergabe werden als Funktionen deklariert */
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

/* Escape Sequenzen ohne Variablenübergabe können auch als Konstanten deklariert werden z.B.: */
#define Clear_Screen printf("\033[2J")
#define Background_Blue printf("\033[44m")
#define Background_Kobaltblue printf("\033[46m")
#define Background_Default printf("\033[0m")

/* Ermitteln und schreiben des aktuellen Directory in die Matrix*/
void GetDirName()
	{
	char dirname[100];
	/* auslesen des aktuellen Verzeichnisses aus der Konsole und Übergabe an Variable dirname */
	getcwd(dirname, 100);
	int i,Laenge;
	Laenge = strlen(dirname);
	for (i=0; i < Laenge; i++)
		{
		matrix[8][i+9] = dirname[i];
		}
	}

/* Ermitteln und schreiben des aktuellen Users in die Matrix */
void GetUserName()
	{
	int Laenge1,Laenge2;
	int i;
	char *user;
	char wer[] = "Wer bist Du?";
	/* getenv durchsucht die Liste der Umgebungsvariablen nach "USER". Wenn ein Eintrag existiert,
	wird ein Zeiger darauf zurückgegeben, ansonsten der NULL-Zeiger */
	user = getenv("USER");
	Laenge1 = strlen(user);
	Laenge2 = strlen(wer);
	/* Test ob ein Eintrag zu "USER" in einer Umgebungsvariable gefunden wurde */
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
	/* tcgetattr holt die Konsolenattribute */
	tcgetattr(fileno(stdin),&alt);
	neu=alt;
	neu.c_lflag &= ~ICANON; // Zeilenorientierter Eingabemodus
	neu.c_lflag &= ~ECHO; // Echofunktion
	/* tcsetattr setzt die Konsolenattribute */
	tcsetattr(fileno(stdin),TCSANOW,&neu); // TCSANOW: Änderungen sind sofort aktiv
	}
void EingabeRuecksetzen()
	{
	tcsetattr(fileno(stdin),TCSANOW,&alt);
	}

/* Tastaturabfrage als Funktion Deklariert */
void Abfrage()
	{
	EingabeAendern();
	Background_Blue;
	TastenAbfrage = getchar();
	EingabeRuecksetzen();
	Background_Default;
	}

/* Setzt benutzte Zellen der Matrix nach Ausgabe UserName oder DirName zurück */
void MatrixRuecksetzen()
	{
	int i;
	for (i=1; i < 41; i++)
		{
		matrix[8][i] = ' ';
		}
	}

/* Die Darstellung der Matrix wird als Funktion deklariert */
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
			/* Schreibe Matrix mit Attributen (Unterstrichen, Blinken, Hintergrund...)*/
			if (( i == 2 || i == 4 || i == 6 ) && j > 8 && j < 34)
				Background_Kobaltblue;							
			else	
				Background_Blue;			
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
			Background_Default;
			}
 		}
	}

/* Das Füllen der Matrix wird als Funktion Deklariert */
void fuelle_matrix(void)
	{
	int i,j;
	/* Text der der Buttons und Rahmen des Menüs wird in Matrix geschieben */
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
	int x = 1; // mit x wird in Funktion display_matrix übergeben auf welchem Button man ist
	int EndBedingung = 0;
	Clear_Screen;
	position(1,1);

	/* Initialisiere Matrix mit Leerzeichen ' ' */
	memset(matrix, ' ', sizeof(matrix));

	/* Matrix füllen */
	fuelle_matrix();
  
	/* stelle Matrix dar */
	display_matrix(x);
	
	while (1)
		{
		if (EndBedingung == 1)
			break;
		Abfrage(); // Tastenabfrage
		if (TastenAbfrage == 113) // 113 ist der int-Wert für "q"
			break;
		TestAufPfeiltaste = TastenAbfrage;
		switch(TestAufPfeiltaste)
			{
			/* bei betätigen der Pfeiltasten sendet Tastatur folgende Codes an die Konsole:
			 Pfeil hoch: \033[A 
			 Pfeil runter: \033[B 
			 Pfeil links: \033[D 
			 Pfeil rechts: \033[C, ich suche um die Pfeiltasten auszulesen nach den markanten Buchstaben A,B... */
			case 65: // Pfeiltaste hoch
				switch(x) // Abfrage wo die aktuelle Position im Menü ist und setzten der Variable x für Funktion display_matrix
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
				display_matrix(x);				
				break;
			case 66: // Pfeiltaste runter
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
				display_matrix(x);
				break;
			case 10: // 10 ist int-Wert für "ENTER"
				switch(x)
					{
					case 1:
						Clear_Screen;
						position(1,1);
						GetDirName();
						display_matrix(1);
						MatrixRuecksetzen();
						break;
					case 2:
						Clear_Screen;
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

	/* Beende Programm */
	return 0;
}
