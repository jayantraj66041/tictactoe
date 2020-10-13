#include<stdio.h>
#include<conio.h>

int draw(char *choice)
{
    int a;
    for(a=0;a<9;a++)
        if(*(choice+a)==32)
            break;
    if(a==9)
        return 1;
    else
        return 0;
}

char winner(char *choice)
{
    if((*(choice+0)=='X'&&*(choice+1)=='X'&&*(choice+2)=='X')||
       (*(choice+3)=='X'&&*(choice+4)=='X'&&*(choice+5)=='X')||
       (*(choice+6)=='X'&&*(choice+7)=='X'&&*(choice+8)=='X')||
       (*(choice+0)=='X'&&*(choice+3)=='X'&&*(choice+6)=='X')||
       (*(choice+1)=='X'&&*(choice+4)=='X'&&*(choice+7)=='X')||
       (*(choice+2)=='X'&&*(choice+5)=='X'&&*(choice+8)=='X')||
       (*(choice+0)=='X'&&*(choice+4)=='X'&&*(choice+8)=='X')||
       (*(choice+2)=='X'&&*(choice+4)=='X'&&*(choice+6)=='X'))
        return 'X';
    else if((*(choice+0)=='O'&&*(choice+1)=='O'&&*(choice+2)=='O')||
       (*(choice+3)=='O'&&*(choice+4)=='O'&&*(choice+5)=='O')||
       (*(choice+6)=='O'&&*(choice+7)=='O'&&*(choice+8)=='O')||
       (*(choice+0)=='O'&&*(choice+3)=='O'&&*(choice+6)=='O')||
       (*(choice+1)=='O'&&*(choice+4)=='O'&&*(choice+7)=='O')||
       (*(choice+2)=='O'&&*(choice+5)=='O'&&*(choice+8)=='O')||
       (*(choice+0)=='O'&&*(choice+4)=='O'&&*(choice+8)=='O')||
       (*(choice+2)=='O'&&*(choice+4)=='O'&&*(choice+6)=='O'))
        return 'O';
    else
        return '\0';
}

void main()
{
    char choice[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '}, player1[20],player2[20],init='X';
    printf("Enter first player name: ");
    gets(player1);
    printf("Enter second player name: ");
    gets(player2);
    system("cls");
    while(1){
        system("cls");
        printf(" %c | %c | %c \n---|---|---\n %c | %c | %c \n---|---|---\n %c | %c | %c \n",
               choice[0],choice[1],choice[2],choice[3],choice[4],choice[5],choice[6],choice[7],choice[8]);
        if(init=='X')
            printf("\n%s[X]: ",player1);
        if(init=='O')
            printf("\n%s[O]: ",player2);
        if(winner(choice)||draw(choice))
            break;
        int c = getch();
        if(c>=49 && c<=57){
            if(c==49)
                if(choice[6]!=' '){
                    printf("\nInvalid Selection");
                    continue;
                }
                else
                    choice[6] = init;
            else if(c==50)
                if(choice[7]!=' '){
                    printf("\nInvalid Selection");
                    continue;
                }
                else
                    choice[7] = init;
            else if(c==51)
                if(choice[8]!=' '){
                    printf("\nInvalid Selection");
                    continue;
                }
                else
                    choice[8] = init;
            else if(c==52)
                if(choice[3]!=' '){
                    printf("\nInvalid Selection");
                    continue;
                }
                else
                    choice[3] = init;
            else if(c==53)
                if(choice[4]!=' '){
                    printf("\nInvalid Selection");
                    continue;
                }
                else
                    choice[4] = init;
            else if(c==54)
                if(choice[5]!=' '){
                    printf("\nInvalid Selection");
                    continue;
                }
                else
                    choice[5] = init;
            else if(c==55)
                if(choice[0]!=' '){
                    printf("\nInvalid Selection");
                    continue;
                }
                else
                    choice[0] = init;
            else if(c==56)
                if(choice[1]!=' '){
                    printf("\nInvalid Selection");
                    continue;
                }
                else
                    choice[1] = init;
            else
                if(choice[2]!=' '){
                    printf("\nInvalid Selection");
                    continue;
                }
                else
                    choice[2] = init;
            if(init=='X')
                init = 'O';
            else
                init = 'X';
        }
        else if(c==27){
            exit(1);
        }
        else{
            printf("\nInvalid Choice");
        }
    }
    if(winner(choice)=='X')
        printf("\n%s Win the match",player1);
    else if(winner(choice)=='O')
        printf("\n%s Win the match",player2);
    else
        printf("\nMatch Draw");
    getch();
}
