#include<iostream>
using namespace std;

class TicTacToe
{
	char box[9];
	int player,choice;
	public:
	TicTacToe()
	{
			char x='1';
			for(int i=0;i<9;i++,x++)
				{
					box[i]=x;
				}
		player=1;
	}
	void Input();
	int WinCondition();
	void Dashboard();
	void winner();
};

void TicTacToe::Input()
{
	cout<<"\n\n\tplayer "<<player<<" Enter your box number : ";
	cin>>choice;
	if(player==1)
	{
		box[choice-1]='X';	
		player++;
	}
	else if(player==2)
	{
		box[choice-1]='O';
		player--;
	}
	Dashboard();
}

int TicTacToe::WinCondition()
{
       	 if(box[0]==box[1]&& box[0]==box[2])return 1;
    else if(box[3]==box[4]&& box[3]==box[5])return 1;   	 
	else if(box[6]==box[7]&& box[6]==box[8])return 1;
	else if(box[0]==box[3]&& box[0]==box[6])return 1;
	else if(box[1]==box[4]&& box[1]==box[7])return 1;
	else if(box[2]==box[5]&& box[2]==box[8])return 1;
	else if(box[0]==box[4]&& box[0]==box[8])return 1;
	else if(box[6]==box[4]&& box[6]==box[2])return 1;
	else if(box[0]!='1'&&box[1]!='2'&&box[2]!='3'&&box[3]!='4'&&box[4]!='5'&&box[5]!='6'&&box[6]!='7'&&box[7]!='8'&&box[8]!='9')return 0;
	else return -1;	
}

void TicTacToe::Dashboard()
{
	system("cls");
	cout<<"\n\n\t\tTic Tac Toe \n";
	cout<<"\n\n\tPlayer 1 (X)  	 Player 2 (O) \n\n\n";
	cout<<"\t\t"<<" "<<box[0]<<" | "<<box[1]<<" | "<<box[2]<<"\n";
	cout<<"\t\t"<<"---|---|---\n";
	cout<<"\t\t"<<" "<<box[3]<<" | "<<box[4]<<" | "<<box[5]<<"\n";
	cout<<"\t\t"<<"---|---|---\n";
	cout<<"\t\t"<<" "<<box[6]<<" | "<<box[7]<<" | "<<box[8]<<"\n";
	
}

void TicTacToe::winner()
{
	if(WinCondition())
	{
		if(player==1)
			{
				system("cls");
				cout<<"Player 2 Has Won";
			}
		else
			{
				system("cls");
				cout<<"player 1 Has Won";
			}
	}
	else
		{
			system("cls");
			cout<<"Game Draw";
		}
		char x='1';
	for(int i=0;i<9;i++,x++)
	{
		box[i]=x;
	}
}


int main()
{
	TicTacToe o;
	again:
	o.Dashboard();
	do
	{
	o.Input();
	}while(o.WinCondition()==-1);
	o.winner();
	cout<<"\ndo you want to play again (y/n) : ";
	char c;
	cin>>c;
	if(c=='y'||c=='y')
		{
			goto again;
		}
	else
	return 0;
}
