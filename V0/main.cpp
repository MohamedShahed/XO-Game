#include <iostream>
using namespace std ;
void print (char arr[][8]);
bool Insert(char arr[][8], char ch, int c, int &r);
char Iswinner(char arr[][8], int c, int r);
int main()
{
    char arr[6][8];  //one more cell for null character

    for(int i=0; i<6; i++)
    {
        for(int j=0; j<7; j++)
            arr[i][j]=' ';
    }

    bool status=true;
    int input=0, counter=0, r=0;
    system("clear");
    print (arr);

    while (status){

        cin>>input;
        if(input<1 || input>7) //validation
        {
            cout<<"wrong...try again\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        char ch;  // switching between players
        if(counter==0 || counter%2==0 )
            ch='X';
        else
            ch='O';
        bool valid=Insert(arr, ch, input-1, r);// insert character

        if(valid==false)
        {
            cout<<"this column is complete...try again\n\n";
            continue;
        }
        counter++;


        print (arr);

        char ans=Iswinner(arr, input-1, r);
        if(ans=='X')
        {
            cout<<"X win\n\n";
            status=false;

        }
        else if(ans=='O')
        {
            cout<<"O is win\n\n";
            status=false;
        }
        else if(ans==' ')
        {
            cout<<"fair no one win \n\n";
            status =false;
        }


    }



    return 0;
}

void print (char arr[][8])
{

    for(int i=0; i<6; i++)
    {
        for(int j=0; j<7; j++)
            cout<<arr[i][j]<<" | ";
        cout<<"\n===========================\n";
    }
    cout<<"\n\n*******************************************************************************\n\n";
}

bool Insert(char arr[][8], char ch, int c, int&r)
{
    if(arr[0][c]!=' ')return false;
    for(int i=5; i>=0; i--)
    {
        if(arr[i][c]==' ')
        {
            arr[i][c]=ch;
            r=i;
            break;
        }

    }
    return true;
}


char Iswinner(char arr[][8], int c, int r)
{
    if(r>=3)
    {

        if(c>=3)
        {
            bool s=true;
            for(int i=1; i<4; i++)
                s&=arr[r][c]==arr[r-i][c];
            if(s)return arr[r][c];

            s=true;
            for(int i=1; i<4; i++)
                s&=arr[r][c]==arr[r][c-i];
            if(s)return arr[r][c];

            s=true;
            for(int i=1; i<4; i++)
                s&=arr[r][c]==arr[r-i][c-i];
            if(s)return arr[r][c];

        }

        if(c<=3)
        {
            bool s=true;
            for(int i=1; i<4; i++)
                s&=arr[r][c]==arr[r][c+i];
            if(s)return arr[r][c];

            s=true;
            for(int i=1; i<4; i++)
                s&=arr[r][c]==arr[r-i][c];
            if(s)return arr[r][c];

            s=true;
            for(int i=1; i<4; i++)
                s&=arr[r][c]==arr[r-i][c+i];
            if(s)return arr[r][c];

        }

    }

    if(r<=2)
    {
        if(c>=3)
        {
            bool  s=true;
            for(int i=1; i<4; i++)
                s&=arr[r][c]==arr[r+i][c];
            if(s)return arr[r][c];

            s=true;
            for(int i=1; i<4; i++)
                s&=arr[r][c]==arr[r+i][c-i];
            if(s)return arr[r][c];

            s=true;
            for(int i=1; i<4; i++)
                s&=arr[r][c]==arr[r][c-i];
            if(s)return arr[r][c];

        }
        if(c<=3)
        {
            bool  s=true;
            for(int i=1; i<4; i++)
                s&=arr[r][c]==arr[r+i][c];
            if(s)return arr[r][c];

            s=true;
            for(int i=1; i<4; i++)
                s&=arr[r][c]==arr[r][c+i];
            if(s)return arr[r][c];

            s=true;
            for(int i=1; i<4; i++)
                s&=arr[r][c]==arr[r+i][c+i];
            if(s)return arr[r][c];

        }

    }
    bool s=true;
    for(int i=0; i<7; i++)
    {
        s&=arr[0][i]!=' ';
    }
    if(s)return ' ';
}
