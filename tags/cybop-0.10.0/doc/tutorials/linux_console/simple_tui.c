/***************************************************************************
 *   Copyright (C) 2005 by Dennis.Reichenbach                              *
 *   dennis.reichenbach@gmx.net                                            *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include <stdio.h>
#include <termios.h>
#include <unistd.h>

void position(int Zeile, int Spalte)
	{
	printf("\033[%d;%dH",Zeile,Spalte);
	}

int main() {

	struct termios alt,neu;
	char eingabe;
	int Abbruch = 1;
	int i;
	printf("\033[2J");	
	position(5,10);
	printf("\033[44m---------------------------------------------\n");
	position(6,10);	
	printf("|\033[46m File Edit View Extra Settings Help        \033[44m|\n");
	position(7,10);	
	printf("|                                           |\n");
	position(8,10);	
	printf("|                                           |\n");
	position(9,10);	
	printf("|                                           |\n");
	position(10,10);	
	printf("|                                           |\n");
	position(11,10);	
	printf("|                                           |\n");
	position(12,10);	
	printf("|                                           |\n");
	position(13,10);	
	printf("|                                           |\n");
	position(14,10);	
	printf("| [1] Show ............                     |\n");
	position(15,10);	
	printf("| [2] \033[31mShow ............\033[0m\033[44m                     |\n");
	position(16,10);	
	printf("| [0] \033[4mEXIT/STOP\033[0m\033[44m                             |\n");
	position(17,10);	
	printf("|                                           |\n");
	position(18,10);	
	printf("|                                           |\n");
	position(19,10);	
	printf("|                                           |\n");
	position(20,10);	
	printf("---------------------------------------------\n\033[0m");
	while (Abbruch != 0) {
	position(18,52);
		tcgetattr(fileno(stdin),&alt);
		neu=alt;
		neu.c_lflag &= ~ICANON;
		neu.c_lflag &= ~ECHO;
		tcsetattr(fileno(stdin),TCSANOW,&neu);
		eingabe=getc(stdin);
		tcsetattr(fileno(stdin),TCSANOW,&alt);	
	i = eingabe;
	switch (i)
		{
		case '1': position(18,12);
		printf("\033[44;5m[1] gedrückt \033[0m");
		break;
		case '2': position(18,12);
		printf("\033[44;5m[2] gedrückt \033[0m");
		break;
		case '0': position(18,12);
		printf("\033[44;5m[0] EXIT/STOP\033[0m");
		position(22,1);
		Abbruch = 0;
		break;
		}
		}
return 0;
}
