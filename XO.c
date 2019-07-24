#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include "Beep melody.h"
bool spr(char arr[3][3], bool* win);
int Menu(int *choice);
void wypisz(char arr[3][3]);
 
int Menu(int *choice)
{
    printf("\n\n------------------- M E N U   W Y B O R U -------------\n\n");
    printf("\t\tCo chcesz zrobic?\n");
    printf("\t\t0. Wyjscie z Menu\n\t\t1. NOWA GRA\n\t\t2.RANKING PUNKTOWY\n\n");
    printf("-------------------------------------------------------\n\n");
    printf("\tOpcja:  ");
    scanf("%d",choice);
    system("cls");
    return *choice;
}
 
void wypisz(char arr[3][3])
{
    printf("\t  0   1   2\n");
    printf("\t-------------\n");
    printf("      0");
    printf("\t| %c | %c | %c |\n",arr[0][0],arr[0][1],arr[0][2]);
    printf("\t----+---+----\n");
    printf("      1");
    printf("\t| %c | %c | %c |\n",arr[1][0],arr[1][1],arr[1][2]);
    printf("\t----+---+----\n");
    printf("      2");
    printf("\t| %c | %c | %c |\n",arr[2][0],arr[2][1],arr[2][2]);
    printf("\t-------------\n");
}
 
bool spr(char arr[3][3], bool *win)
{
 
    if((arr[0][0]=='X'&& arr[0][1]=='X' && arr[0][2]=='X')|| (arr[1][0]=='X'&& arr[1][1]=='X' && arr[1][2] =='X') || (arr[2][0]=='X'&& arr[2][1]=='X' && arr[2][2]=='X'))
    {
        *win=true;      
    }
    if((arr[0][0]=='O'&& arr[0][1]=='O' && arr[0][2]=='O')|| (arr[1][0]=='O'&& arr[1][1]=='O' && arr[1][2] =='O') || (arr[2][0]=='O'&& arr[2][1]=='O' && arr[2][2]=='O'))
    {
        *win=true;      
    }
    if((arr[0][0]=='X'&& arr[1][0]=='X' && arr[2][0]=='X')|| (arr[0][1]=='X'&& arr[1][1]=='X' && arr[2][1] =='X') || (arr[0][2]=='X'&& arr[1][2]=='X' && arr[2][2]=='X'))
    {
        *win=true;      
    }
     if((arr[0][0]=='O'&& arr[1][0]=='O' && arr[2][0]=='O')|| (arr[0][1]=='O'&& arr[1][1]=='O' && arr[2][1] =='O') || (arr[0][2]=='O'&& arr[1][2]=='O' && arr[2][2]=='O'))
    {
        *win=true;      
    }
    if((arr[0][0]=='X'&& arr[1][1]=='X' && arr[2][2]=='X')|| (arr[0][2]=='X'&& arr[1][1]=='X' && arr[2][0] =='X'))
    {
        *win=true;      
    }
    if((arr[0][0]=='O'&& arr[1][1]=='O' && arr[2][2]=='O')|| (arr[0][2]=='O'&& arr[1][1]=='O' && arr[2][0] =='O'))
    {
        *win=true;      
    }
    return *win;
}
 
int main()
{
    int circle_points=0,sharp_points=0, deadheat_points=0;
    int choice=0;
    bool win=false;
    char arr[3][3];
        for(int i=0;i<3;i++)
        {
            arr[0][i]=' ';
            arr[1][i]=' ';
            arr[2][i]=' ';
        }
    int x1,x2,y1,y2;
    int kolejka=0;
   
    while(true)
   {
        Menu(&choice);
        {
            if(choice==0)
            {
                getchar();
                exit(1);
            }
            if(choice==1)      
            {
                memset(arr, ' ', 9);
                printf("\tGRA W KOLKO I KRZYZYYK!\n\n");
                Sleep(2000);
                printf("\t*****ZACZYNAMY*****\n\n");
                Sleep(1000);
           
                wypisz(arr);
 				win=false;
 				kolejka=0;
    while(win!=true || kolejka == 9)
    {
       
        printf("KOLKO: Wprowadz wspolrzedne!\n");
        printf("Wiersz:");
        scanf("%d",&x1);
        printf("Kolumna:");
        scanf("%d",&y1);
   
    kolejka++;
         if(kolejka==9)
    {
        printf("***** REMIS *****");
        deadheat_points++;
            Beep(1567, 200);
            Beep(1567, 200);
            Beep(1567, 200);
            Beep(1244, 1000);
        break;
    }
    arr[x1][y1]='O';
     wypisz(arr);

    spr(arr,&win);
    if(win==true)
    {
        circle_points++;
        printf("\t\n*****  Kolko wygral!  *****");
        printf("\n\n\tSPROBUJ JESZCZE RAZ!");
   
            refrenBass();
        break;
    }
    printf("KRZYZYK: Wprowadz wspolrzedne!\n");
    printf("Wiersz:");
    scanf("%d",&x2);
    printf("Kolumna:");
    scanf("%d",&y2);
   
    kolejka++;
         if(kolejka==9)
    {
        printf("***** REMIS *****");
        deadheat_points++;
            Beep(1567, 200);
            Beep(1567, 200);
            Beep(1567, 200);
            Beep(1244, 1000);
        break;
    }
    arr[x2][y2]='X';
     wypisz(arr);
     
    spr(arr,&win);
    if(win==true)
    {
        sharp_points++;
        printf("\t\n*****  Krzyzyk wygral!  *****");
        printf("\n\n\tSPROBUJ JESZCZE RAZ!");
            refrenBass();
        break;
    }
    }
  
}
    else if(choice==2)
    {
        printf("\t\t------R A N K I N G -----\n\n");
        printf("\tPunkty gracza Kolko:  %d\n\n",circle_points);
        printf("\tPunkty gracza Krzyzyk:  %d\n\n",sharp_points);
        printf("\tRemisow:  %d\n\n",deadheat_points);
   
    }
  }
 }
}


