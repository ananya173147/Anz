#include<stdio.h>
#include<conio.h>
void board();    //Prototype of board function
void AI();      //Prototype of AI function
char s[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}}; //Declaring 2-D array to display the board
char human='X',ai='O';
int main()
{
    int i,t,count=0;
    board();
    printf("Who should go first, HUMAN (Enter 0) or COMPUTER (Enter 1)?\n");
//giving choice to the user to choose who should play first
    scanf("%d",&t);
//if user gives any default value
    while(t!=0 && t!=1)
    {
        printf("Please enter either 0 or 1\n");
        scanf("%d",&t);
    }
    if(t == 1)
    {
        s[0][0]='O';
        board();
        count = 1;
    }
    if(t == 0 || count == 1)
    {
//Loop for taking user's input
        for(i=0;i<5;i++)
        {
            int x,flag=0;
            printf("Enter position to place your 'X':");
            scanf("%d",&x);
            if (x==1&&(s[0][0]!='X'&&s[0][0]!='O'))
                s[0][0]='X';
            else if (x==2&&(s[0][1]!='X'&&s[0][1]!='O'))
                s[0][1]='X';
            else if (x==3&&(s[0][2]!='X'&&s[0][2]!='O'))
                s[0][2]='X';
            else if (x==4&&(s[1][0]!='X'&&s[1][0]!='O'))
                s[1][0]='X';
            else if (x==5&&(s[1][1]!='X'&&s[1][1]!='O'))
                s[1][1]='X';
            else if (x==6&&(s[1][2]!='X'&&s[1][2]!='O'))
                s[1][2]='X';
            else if (x==7&&(s[2][0]!='X'&&s[2][0]!='O'))
                s[2][0]='X';
            else if (x==8&&(s[2][1]!='X'&&s[2][1]!='O'))
                s[2][1]='X';
            else if (x==9&&(s[2][2]!='X'&&s[2][2]!='O'))
                s[2][2]='X';
            else
            {
                printf("Invalid move: please type a nummber which is not already occupied...");
                i=i-1;
                flag=1;
            }
//Checking for the win

    //condition for human to win

        if((s[0][0] == s[0][1] && s[0][0] == s[0][2] && (s[0][0] == human)) ||             //first row
          (s[1][0] == s[1][1] && s[1][0] == s[1][2] && (s[1][0] == human)) ||              //second row
          (s[2][0] == s[2][1] && s[2][0] == s[2][2] && (s[2][0] == human)) ||              //third row
          (s[0][0] == s[1][0] && s[0][0] == s[2][0] && (s[0][0] == human)) ||              //first column
          (s[0][1] == s[1][1] && s[0][1] == s[2][1] && (s[0][1] == human)) ||              //second column
          (s[0][2] == s[1][2] && s[0][2] == s[2][2] && (s[0][2] == human)) ||              //third column
          (s[0][0] == s[1][1] && s[0][0] == s[2][2] && (s[0][0] == human)) ||              //diagonal 1
          (s[0][2] == s[1][1] && s[0][2] == s[2][0] && (s[0][2] == human)))                //diagonal 2
        {
            printf("Congratulations, you win!");
            return 0;
        }

        else if(flag==0)

        AI(); //Playing AI moves
        board(); //display the board with the moves of both human and AI

    //condition for AI to win

        if ((s[0][0] == s[0][1] && s[0][0] == s[0][2] && (s[0][0] == ai)) ||                //first row
            (s[1][0] == s[1][1] && s[1][0] == s[1][2] && (s[1][0] == ai)) ||                //second row
            (s[2][0] == s[2][1] && s[2][0] == s[2][2] && (s[2][0] == ai)) ||                //third row
            (s[0][0] == s[1][0] && s[0][0] == s[2][0] && (s[0][0] == ai)) ||                //first column
            (s[0][1] == s[1][1] && s[0][1] == s[2][1] && (s[0][1] == ai)) ||                //second column
            (s[0][2] == s[1][2] && s[0][2] == s[2][2] && (s[0][2] == ai)) ||                //third column
            (s[0][0] == s[1][1] && s[0][0] == s[2][2] && (s[0][0] == ai)) ||                //diagonal 1
            (s[0][2] == s[1][1] && s[0][2] == s[2][0] && (s[0][2] == ai)))                  //diagonal 2
        {
            printf("AI has won!");
            return 0;
        }

    // tie  displays the message when the board is completely filled

        if ((s[0][0]=='X'||s[0][0]=='O') &&
            (s[0][1]=='X'|| s[0][1]=='O') &&
            (s[0][2]=='X'||s[0][2]=='O') &&
            (s[1][0]=='X'||s[1][0]=='O') &&
            (s[1][1]=='X'||s[1][1]=='O') &&
            (s[1][2]=='X'||s[1][2]=='O') &&
            (s[2][0]=='X'||s[2][0]=='O') &&
            (s[2][1]=='X'||s[2][1]=='O') &&
            (s[2][2]=='X'||s[2][2]=='O'))
        {
            printf("It's a tie!");
            return 0;
        }
    }
    }
}


//function definition of board function

  void board()
{

    printf("\n\n Tic Tac Toe\n\n");
    printf("HUMAN (X)  vs  COMPUTER (O)\n\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", s[0][0], s[0][1], s[0][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", s[1][0], s[1][1], s[1][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", s[2][0], s[2][1], s[2][2]);
    printf("     |     |     \n\n");

}


//function definition of AI

void AI()

{
//case 1: checks for the winning condition

    if (s[0][0] == '1' && ((s[0][1] == ai && s[0][2] == ai) || (s[1][0] == ai && s[2][0] == ai) || (s[1][1] == ai && s[2][2] == ai)))
    s[0][0]='O';
    else if (s[0][1] == '2' && ((s[0][0] == ai && s[0][2] == ai) || (s[1][1] == ai && s[2][1] == ai)))
    s[0][1]='O';
    else if (s[0][2] == '3' && ((s[0][0] == ai && s[0][1] == ai) || (s[1][2] == ai && s[2][2] == ai) || (s[1][1] == ai && s[2][0] == ai)))
    s[0][2]='O';
    else if (s[1][0] == '4' && ((s[0][0] == ai && s[2][0] == ai) || (s[1][1] == ai && s[1][2] == ai)))
    s[1][0]='O';
    else if (s[1][1] == '5' && ((s[1][0] == ai && s[1][2] == ai) || (s[0][0] == ai && s[2][2] == ai) || (s[0][2] == ai && s[2][0] == ai)))
    s[1][1]='O';
    else if (s[1][2] == '6' && ((s[1][0] == ai && s[1][1] == ai) || (s[0][2] == ai && s[2][2] == 'O')))
    s[1][2]='O';
    else if (s[2][0] == '7' && ((s[2][1] == ai && s[2][2] == ai) || (s[0][0] == ai && s[1][0] == ai) || (s[0][2] == ai && s[1][1] == ai)))
    s[2][0]='O';
    else if (s[2][1] == '8' && ((s[2][0] == ai && s[2][2] == ai) || (s[0][1] == ai && s[1][1] == ai)))
    s[2][1]='O';
    else if (s[2][2] == '9' && ((s[2][0] == ai && s[2][1] == ai) || (s[0][2] == ai && s[1][2] == ai) || (s[0][0] == ai && s[1][1] == ai)))
    s[2][2]='O';

//case 2: checks for the blocking condition

    else if (s[0][0] == '1' && ((s[0][1] == human && s[0][2] == human) || (s[1][0] == human && s[2][0] == human) || (s[1][1] == human && s[2][2] == human)))
    s[0][0]='O';
    else if (s[0][1] == '2' && ((s[0][0] == human && s[0][2] == human) || (s[1][1] == human && s[2][1] == human)))
    s[0][1]='O';
    else if (s[0][2] == '3' && ((s[0][0] == human && s[0][1] == human) || (s[1][2] == human && s[2][2] == human) || (s[1][1] == human && s[2][0] == human)))
    s[0][2]='O';
    else if (s[1][0] == '4' && ((s[0][0] == human && s[2][0] == human) || (s[1][1] == human && s[1][2] == human)))
    s[1][0]='O';
    else if (s[1][1] == '5' && ((s[1][0] == human && s[1][2] == human) || (s[0][0] == human && s[2][2] == human) || (s[0][2] == human && s[2][0] == human)))
    s[1][1]='O';
    else if (s[1][2] == '6' && ((s[1][0] == human && s[1][1] == human) || (s[0][2] == human && s[2][2] == human)))
    s[1][2]='O';
    else if (s[2][0] == '7' && ((s[2][1] == human && s[2][2] == human) || (s[0][0] == human && s[1][0] == human) || (s[0][2] == human && s[1][1] == human)))
    s[2][0]='O';
    else if (s[2][1] == '8' && ((s[2][0] == human && s[2][2] == human) || (s[0][1] == human && s[1][1] == human)))
    s[2][1]='O';
    else if (s[2][2] == '9' && ((s[2][0] == human && s[2][1] == human) || (s[0][2] == human && s[1][2] == human) || (s[0][0] == human && s[1][1] == human)))
    s[2][2]='O';

// case 3: center

    else if (s[1][1] == '5')
    s[1][1]='O';

// case 4: opposite corner

    else if (s[0][0]== 'X'&& s[1][1]==ai && s[2][2]== human)
    s[0][1]= 'O';
    else if (s[0][2]== 'X'&& s[1][1]==ai && s[2][0]== human)
    s[0][1]= 'O';
    else if (s[0][0] == '1' && (s[0][2] == 'X'  || s[2][0] == 'X'))
    s[0][0]='O';
    else if (s[0][2] == '3' && (s[0][0] == 'X' || s[2][2] == 'X'))
    s[0][2]='O';
    else if (s[2][2] == '9' && (s[0][2] == 'X'  || s[2][0] == 'X'))
    s[2][2]='O';
    else if (s[2][0] == '7' && (s[0][0] == 'X'  || s[2][2] == 'X'))
    s[2][0]='O';


// case 5: empty corner

    else if (s[0][0] == '1')
    s[0][0]='O';
    else if (s[0][2] == '3')
    s[0][2]='O';
    else if (s[2][0] == '7')
    s[2][0]='O';
    else if (s[2][2] == '9')
    s[2][2]='O';

// case 6: empty side

    else if (s[0][1] == '2')
    s[0][1]='O';
    else if (s[1][2] == '6')
    s[1][2]='O';
    else if (s[2][1] == '8')
    s[2][1]='O';
    else if (s[1][0] == '4')
    s[1][0]='O';
}
