#include<iostream>
using namespace std;

enum dir    {UPLEFT=0, UPRIGHT, DOWNRIGHT, DOWNLEFT, RIGHT, DOWN, LEFT, UP};
int dir_r[]={-1      ,      -1,         1,        1,     0,    1,    0, -1};
int dir_c[]={-1      ,       1,         1,       -1,     1,    0,   -1,  0};


const int N=5;
char **board=NULL;
static int turn=0;

void initializeBoard()
{
    board=new char*[N];
    for(int i=0; i<N; i++)
        board[i]=new char[N+1];

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
            board[i][j]=' ';
    }

}
void free()
{
    for(int i=0; i<N ; i++)
    {
        delete[]board[i];
    }
    delete[]board;
}
void insert(char ch, int c)
{
    c--;
    for(int i=4; i>=0; i--)
    {
        if(board[i][c]==' '){
            board[i][c]=ch;
            break;
        }
    }

}
void fillBoard(int c)
{
    char ch;
    if(turn==0)
    {
        ch='X';
        turn=1;
    }
    else {
        ch='O';
        turn=0;
    }
    insert(ch, c);

}
void printBoard()
{

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
            cout<<board[i][j]<<" | ";
        cout<<"\n===================\n";
    }
    cout<<"\n\n*******************************************************************************\n\n";
}
bool validCol(int c)
{
    c--;
    for(int i=4; i>=0; i--)
    {
        if(board[i][c]==' ')return true;
    }
    return false;
}
int inputValidation()
{
    int input;
    while(true)
    {
        cin>>input;
        if(input<1 || input>5 ) {
            cout << "\nout of range try again : ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if(!validCol(input))
        {
            cout<<"col is full ): try again \n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else return input;
    }
}
bool validateDir(int r, int c, int dir)
{
    int newR=(3*dir_r[dir])+r;
    int newC=(3*dir_c[dir])+c;

    if(newR >=N || newR<0 || newC>=N || newC<0)return false;
    return true;
}
bool traverse(int r, int c, int dir)
{
    int newR=r, newC=c, counter=0;
    for(int i=0; i<4; i++)
    {
        newR+=dir_r[dir];
        newC+=dir_c[dir];

        if(board[r][c]!=' ' && board[r][c] == board[newR][newC])
        {
            counter++;
            if(counter==3)return true;
        }
        else return false;
    }
}
bool  decision()
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(validateDir(i, j, RIGHT) && traverse(i, j, RIGHT)){cout<<board[i][j]<<" is win \n"; return false ; }
            if(validateDir(i, j, UPLEFT) && traverse(i, j, UPLEFT)){cout<<board[i][j]<<" is win \n"; return false ; }
            if(validateDir(i, j, UPRIGHT) && traverse(i, j, UPRIGHT)){cout<<board[i][j]<<" is win \n"; return false ; }
            if(validateDir(i, j, DOWNRIGHT) && traverse(i, j, DOWNRIGHT)){cout<<board[i][j]<<" is win \n"; return false ; }
            if(validateDir(i, j, DOWNLEFT) && traverse(i, j, DOWNLEFT)){cout<<board[i][j]<<" is win \n"; return false ; }
            if(validateDir(i, j, DOWN) && traverse(i, j, DOWN)){cout<<board[i][j]<<" is win \n"; return false ; }
            if(validateDir(i, j, LEFT) && traverse(i, j, LEFT)){cout<<board[i][j]<<" is win \n"; return false ; }
            if(validateDir(i, j, UP) && traverse(i, j, UP)){cout<<board[i][j]<<" is win \n"; return false ; }

        }
    }
    return true;
}

int main()
{
    initializeBoard();
    printBoard();
    bool status=true; int input;
    while(status)
    {
        input= inputValidation();
        fillBoard(input);
        printBoard();
        status=decision();

    }

    free();
    return 0;

}
