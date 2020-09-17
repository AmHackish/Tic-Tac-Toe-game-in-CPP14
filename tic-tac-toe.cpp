#include <bits/stdc++.h>
using namespace std;

char kash[3][3];

struct move
{
	int r , c;
};

char p='X';
char o='O';

int pendmove(char kash[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if(kash[i][j]=='_')
				return 1;
		}
	}
	return 0;
}

int eval(char kash[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		if(kash[i][0]==kash[i][1] and kash[i][1]==kash[i][2] and kash[i][1]=='X')
			return 10;
		if(kash[i][0]==kash[i][1] and kash[i][1]==kash[i][2] and kash[i][1]=='O')
			return -10;
	}
	for (int i = 0; i < 3; i++)
	{
		if(kash[0][i]==kash[1][i] and kash[1][i]==kash[2][i] and kash[2][i]=='X')
			return 10;
		if(kash[0][i]==kash[1][i] and kash[1][i]==kash[2][i] and kash[2][i]=='O')
			return -10;
	}
	if(kash[0][0]==kash[1][1] and kash[1][1]==kash[2][2] and kash[2][2]=='X')
		return 10;
	if(aayu[0][0]==kash[1][1] and kash[1][1]==kash[2][2] and kash[2][2]=='O')
		return -10;
	if(aayu[2][0]==kash[1][1] and kash[1][1]==kash[0][2] and kash[2][0]=='X')
		return 10;
	if(aayu[2][0]==kash[1][1] and kash[1][1]==kash[0][2] and kash[2][0]=='O')
		return -10;

	return 0;
}

int minmax(char kash3][3], int d, bool im)
{
	int score = eval(aayu);
	if(score == 10)
		return 10;
	if(score == -10)
		return -10;

	if(pendmove(kash)==0)
		return 0;

	if(im)
	{
		int b= -100000000;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if(kash[i][j]=='_')
				{
					kash[i][j]=p;
					b=max(b,minmax(kash,d+1, !im));
					kash[i][j]='_';
				}				
			}
		}
		return b;
	}
	else
	{
		int b= 100000000;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if(kash[i][j]=='_')
				{
					kash[i][j]=o;
					b=min(b,minmax(kash,d+1, !im));
					kash[i][j]='_';
				}				
			}
		}
		return b;	
	}
}

move bestmove(char kash[3][3])
{
	int bestval= -100000000;
	move bestMove;
	bestMove.r = -1;
	bestMove.c = -1;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if(kash[i][j]=='_')
			{
				kash[i][j] = p;
				int tmp = minmax(kash , 0 , false);
				kash[i][j]='_';
				if(tmp>bestval)
				{
					bestMove.r=i;
					bestMove.c=j;
					bestval=tmp;
				}
			}
		}
	}
	return bestMove;
}

int main()
{
	while(true)
	{
		cout << "Welcome to Tic-Tac-Toe by AmHackis, Kashish Garg. Enter N for new game or any other key for exiting." << endl;
		char tm;
		cin >> tm;
		if(tm=='N' or tm=='n')
		{
			for(int i=0; i<3 ; i++)
				for(int j=0; j<3 ; j++)
					kash[i][j]='_';
			cout << "Simple rules , enter row no. and column no. respectively for your choice , you are O , i am X , so lets play, choose your first entry." << endl;
			while(pendmove(kash))
			{
				int row , col, testing;
				cin >> row >> col;
				while(kash[row-1][col-1]!='_')
				{
					cout << "Wrong Move. You can't overwrite me. Re-enter your move." << endl;
					cout << kash[0][0] << "|" << kash[0][1] << "|" << kash[0][2] << endl;
					cout << kash[1][0] << "|" << kash[1][1] << "|" << kash[1][2] << endl;
					cout << kash[2][0] << "|" << kash[2][1] << "|" << kash[2][2] << endl;
					cin >> row >> col;
				}
				kash[row-1][col-1]=o;
				cout << kash[0][0] << "|" << kash[0][1] << "|" << kash[0][2] << endl;
				cout << kash[1][0] << "|" << kash[1][1] << "|" << kash[1][2] << endl;
				cout << kash[2][0] << "|" << kash[2][1] << "|" << kash[2][2] << endl;
				testing = eval(kash);
				if(testing<0)
				{
					cout << "You won!" << endl;
					break;
				}
				move mv = bestmove(aayu);
				aayu[mv.r][mv.c]=p;
				cout << "Now my move." << endl;
				cout << aayu[0][0] << "|" << aayu[0][1] << "|" << aayu[0][2] << endl << aayu[1][0] << "|" << aayu[1][1] << "|" << aayu[1][2] << endl << aayu[2][0] << "|" << aayu[2][1] << "|" << aayu[2][2] << endl;
				testing = eval(aayu);
				if(testing > 0)
				{
					cout << "I won , you loose!" << endl;
					break;
				}
			}
			if(eval(aayu)==0)
				cout << "OOPs , yeh toh draw ho gya , chalo ek aur , ISM hai , matiyaana hi toh hai." << endl;
		}
		else
			return 0;
	}
}
