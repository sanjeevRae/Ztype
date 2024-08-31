#include<iostream>
#include<conio.h>     //It stand for console input output i.e it takes input from keyboard and displays it on screen.
#include<dos.h>    //this Library has functions that are used for handling interrupts,producing sound,date and time functions.
#include<windows.h>  //this is a base header file for win32 programming it contains declaration of almost all basic windows macros and different typedef
#include<time.h>     //the time.h header file contains deinitions of functions to get and manipulate date and time information.


#define SCREEN_W 100
#define SCREEN_H 29
#define WIN_WIDTH 80

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;     //a COORD structure that specifies the new cursor position in characters.

char keys[10];
int keyPos[10][2];
int score =0;

void gotoxy(int x, int y){      //places cursor at a desired location on screen.
CursorPosition.X =x;
CursorPosition.Y =y;
SetConsoleCursorPosition(console, CursorPosition);
}


void setcursor(bool visible, DWORD size)
{
	if(size ==0)
	size =20;
	
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console, &lpCursor);
}

void drawBorder()
{
	for(int i=0;i<SCREEN_W;i++)
	{
		gotoxy(i,SCREEN_H);
		cout<<"+";
	}
	for(int i=0;i<SCREEN_H;i++)
	{
		gotoxy(0,i);
		cout<<"+";
		gotoxy(SCREEN_W,i);
		cout<<"+";
	}
	
	for(int i=0;i<SCREEN_H;i++)
	{
		gotoxy(WIN_WIDTH,i);
		cout<<"+";
	}
}


void genAlphabet(int ind)
{
	keys[ind] =65+rand()%25;
	keyPos[ind][0] = 2+rand()%(WIN_WIDTH-2);
	keyPos[ind][1]= 1;
}


void drawAlphabet(int ind)
{
	if(keyPos[ind][0] !=0)
	{
		gotoxy(keyPos[ind][0],keyPos[ind][1]);
		cout<<keys[ind];
	}
}

void eraseAlphabet(int ind)
{
	if(keyPos[ind][0] != 0)
	{
		gotoxy(keyPos[ind][0],keyPos[ind][1]);
		cout<<" ";
	}
}


void resetAlphabet(int ind)
{
	eraseAlphabet(ind);
	genAlphabet(ind);
}

void gameover()
{
	system("cls");
	cout<<endl;
	cout<<"\t\t------------------------"<<endl;
	cout<<"\t\t-------GAME OVER--------"<<endl;
	cout<<"\t\t------------------------"<<endl<<endl;
	cout<<"\t\t Press any key to go back to menu.";
	getch();
}


void updateScore()
{
	gotoxy(WIN_WIDTH + 7,5);
	cout<<"Score: "<<score<<endl;
}

void instructions()
{
	system("cls");
	cout<<"INSTRUCTIONS";
	cout<<"\n--------------";
	cout<<"\n On Left side you will see falling characters ";
	cout<<"\n You have to keep them away from touching floor";
	cout<<"\n Press respective Key from keyboard to keep playing";
	cout<<"\n\n Press 'escape' to exit";
	cout<<"\n\n Press any Key to go back to menu";
	getch();
}

void play()
{
	score =0;
	for(int i=0;i<10;i++)
	{
		keyPos[i][0] =keyPos[i][1] =1;
	}
	system("cls");
	drawBorder();
	updateScore();
	
	for(int i=0;i<10;i++)
	genAlphabet(i);
	
	gotoxy(WIN_WIDTH + 5,2);
	cout<<"Typing Tutor";
	gotoxy(WIN_WIDTH +6, 4);
	cout<<"---------";
	gotoxy(WIN_WIDTH + 6,6);
	cout<<"----------";
	
	gotoxy(18,5);
	cout<<"Press any key to start";
	getch();
	gotoxy(18,5);
	cout<<"                       ";
	
	while(1)
	{
		if(kbhit())
		{
			char ch = getch();
			for(int i=0;i<10;i++)
			{
				if(ch ==keys[i] || ch-32 ==keys[i])
				{
					resetAlphabet(i);
					score++;
					updateScore();
				}}
				if (ch ==27)
				{
					break;
				}}
				for(int i=0;i<10;i++)
				drawAlphabet(i);
				
				Sleep(300);
				
				for(int i=0;i<10;i++)
				{
					eraseAlphabet(i);
					keyPos[i][1] +=1;
					if(keyPos[i][1] > SCREEN_H)
					{
						gameover();
						return;
					}
				}
			}
		}
		
		
		int main()
		{
		 setcursor(0,0);
		 srand((unsigned)time(NULL));               // Initialize random number generator
		 
		 do{
		 	system("cls");
		 	gotoxy(10,5);
		 	cout<<"--------------------------";
		 	gotoxy(10,6);
		 	cout<<"|     TYPING TUTOR       |";
		 	gotoxy(10,7);
		 	cout<<"--------------------------";
		 	gotoxy(10,9);
		 	cout<<"1. Start Game";
		 	gotoxy(10,10);
		 	cout<<"2. Instructions";
		 	gotoxy(10,11);
		 	cout<<"3. Ouit";
		 	gotoxy(10,13);
		 	cout<<" Select Option: ";
		 	char op = getche();
		 	
		 	if (op=='1') play();
		 	else if(op =='2')  instructions();
		 	else if(op =='3')  exit(0);
		 	
		 }
		 while(1);
		 
		 return 0;
	}



