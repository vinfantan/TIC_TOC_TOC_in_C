#include<string.h>
#include<conio.h>
#include<stdio.h>
#include <stdlib.h>
#include<time.h>
int mat[3][3];
int first=0,flag=-1;
int convertInt(char s[]);
int checkdraw(void);
void fill1blank(void);
int diagonal(int p);
int checkwinner(int p);
int firstfill(void);
int isblank(int box);
int fillrandom(int p);
int fillbox(int p);
int fillboxopenent(int p);
int checkbox(int p);
int frule1(int p);
int frule2(int p);
int frule3(int p);
int frule4(int p);
int frule5(int p);
int frule6(int p);
int frule7(int p);
int frule8(int p);
int rule1(int p);
int rule2(int p);
int rule3(int p);
int rule4(int p);
int rule5(int p);
int rule6(int p);
int rule7(int p);
int rule8(int p);
void printmat(void);
int insert(int box,int p);

int main()
{
       int box;
    char chance[100],boxuser[100];
      restart:{
                  flag=-1;
                  first=0; box=0;
     for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
           mat[i][j]=0;
              start:
             printf("\n \nDo you want to play first chance (enter Y or N) :");
             scanf("%s",chance);
             if(!strcmp(chance,"Y") || !strcmp(chance,"y") )
                {
                    flag=1;
                }
             else if(!strcmp(chance,"N") || !strcmp(chance,"n"))
             {
                 flag=2;
             }
             else{
                printf("\nenter correct input:\n");
                goto start;
             }
             if(flag==2)
             {
                 goto Computerchance;

             }
             printf("\n 0 is taken as blank :\n");
             printmat();


            do{
                    step:
           printf("\nenter your input box no:");
           scanf("%s",boxuser);
           if(convertInt(boxuser)==0)
           {
                  printf("\n enter correct input (1 - 9)\n");
                  goto step;
           }
           int c=insert(convertInt(boxuser),1);
            if(c==1)
            {
                goto step;
            }
            //checkdraw();
            if(checkdraw())
           {
               goto restart;
           }
            Computerchance:

            //printf(" \n oponents box %d",checkbox(1));
           if(checkwinner(1))
           {
               goto restart;
           }
           box=checkbox(2);
           if(box!=0)
           {
              // printf("\n checkbox(2) %d" ,box);
               insert(box,2);
            //   checkwinner(2);  //check you are  winner
               if(checkwinner(2))
           {
               goto restart;
           }
           }
    else{
           box=checkbox(1);
           if(box!=0)
           {   //printf("\n checkbox(1) %d" ,box);
               insert(box,2);
             //  checkwinner(2);  //check are you winner
           }
           else
           {
                  box=diagonal(2);
                   if(box==0){
                     box=fillboxopenent(1);
                     //box=0;
                    if(box==0)
                        {
                     box=fillbox(2);
                    if(box==0)
                      {
                            box=fillrandom(2);
                            if(box==0)
                            {
                                  box=firstfill();
                                   if(box==0)
                                   {
                                      fill1blank();
                                      //printf("it is finding blank");
                                    //  checkwinner(2);
                                      //checkdraw();
                                     }
                                   else{
                                    insert(box,2);
                                    //checkwinner(2);
                                   // printf("\n firstfill %d" ,box);
                                   }
                             }
                            else{

                                 // printf("\n\nfillrandom %d",box);
                                  //checkwinner(2);
                               }
                      }
                    else{

                       //printf("\n fillbox(2) %d ",box);
                     // checkwinner(2);
                    }
           }else{
                  // printf("\nfillboxoponent %d",box);
                 //checkwinner(2);
              }
           }else{
                }
          }

             }
             if(checkwinner(2))
           {
               goto restart;
           }
           if(checkdraw())
           {
               goto restart;
           }
           printmat();

            }while(1);
      }//restart
}
int convertInt(char s[])
{
      int d=0;
    if(!strcmp(s,"1")){ d=1; return d;}
    if(!strcmp(s,"2")){ d=2; return d;}
    if(!strcmp(s,"3")){ d=3; return d;}
    if(!strcmp(s,"4")){ d=4; return d;}
    if(!strcmp(s,"5")){ d=5; return d;}
    if(!strcmp(s,"6")){ d=6; return d;}
    if(!strcmp(s,"7")){ d=7; return d;}
    if(!strcmp(s,"8")){ d=8; return d;}
    if(!strcmp(s,"9")){ d=9; return d;}
    return 0;
    //if(strcmp(s,"1")){ d=1; return }
}
int checkdraw(void)
{
    int flag=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(mat[i][j]==0)
            {
                flag++;
            }
        }
    }
    if(flag==0)
    {
        printmat();
        printf("\n\n************************** Match   Draw *************************");
        printf("\n\n Do you want to play again,   press any key.....");
         getch();
        return 1;
        //exit(0);
    }
    return 0;
}
void fill1blank()
{
    int box=0,i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(mat[i][j]==0)
            {
                   if(i==0 && j==0){ box=1;}
                else if(i==0 && j==1){ box=2;}
                else if(i==0 && j==2){ box=3;}
                else if(i==1 && j==0){ box=4;}
                else if(i==1 && j==1){ box=5;}
                else if(i==1 && j==2){ box=6;}
                else if(i==2 && j==0){ box=7;}
                else if(i==2 && j==1){ box=8;}
                else if(i==2 && j==2){ box=9;}
                insert(box,2);
                printf("\n %d %d  %d",box,i,j);
                return;
            }
        }
    }
}
int diagonal(int p)
{
    if((mat[0][0]==1 && mat[2][2]==1) || (mat[0][2]==1 && mat[2][0]==1))
    {
         if(mat[0][1]==0 )
         {
             insert(2,p); return 2;
         }
         if(mat[2][1]==0 )
         {
             insert(8,p); return 8;
         }
         if(mat[1][0]==0 )
         {
             insert(4,p); return 4;
         }
         if(mat[1][2]==0 )
         {
             insert(6,p); return 6;
         }
    }
    return 0;
}
int checkwinner(int p)
{
    int flag=0;
   for(int i=0;i<3;i++)
   {
       flag=0;
       for(int j=0;j<3;j++)
       {
           if(mat[i][j]==p)
           {
                flag++;
                if(flag==3)
                {
                    printf(" \n **************  player %d won the match ******************** ",p);
                     printmat();
                      printf("\n\n Do you want to play again press any key.....");
                      getch();
                      return 1;
                    //exit(0);
                }
           }
       }
   }
     for(int i=0;i<3;i++)
   {
       flag=0;
       for(int j=0;j<3;j++)
       {
           if(mat[j][i]==p)
           {
                flag++;
                if(flag==3)
                {
                    printf(" \n **************   player %d won the match ******************** ",p);
                     printmat();
                      printf("\n\n Do you want to play again press any key.....");
                      getch();
                      return 1;
                   //exit(0);
                }
           }
       }
   }

   if((mat[0][0] ==p && mat[1][1]==p && mat[2][2]==p) || (mat[0][2]==p && mat[1][1]==p && mat[2][0]==p) )
   {
         printf(" \n **************  player %d won the match ******************** ",p);
          printmat();
           printf("\n\n Do you want to play again press any key.....");
                      getch();
                      return 1;
         //exit(0);
   }
   return 0;
}
int firstfill(void)
{
    int sd;

    if(first==0)
    {
            if(flag==1 && !isblank(5))
          {
             return 5;
          }
        //insert(5,p);
        step:

        srand(time(0));
        //srand();
        sd=(rand()%9+1);
        if(sd==2){ sd =3;}
        if(sd==4){ sd=1;}
         if(sd==6){ sd=9;}
          if(sd==8){ sd=7;}
        if(isblank(sd))
        {
            goto step;
           // printf("\n %d is not blank",sd);
        }
        first++;
         return sd;

    }
    else if(mat[1][1]==0)
    {
        return 5;
    }
    else
    {
        if(mat[0][0]==0)
        {
          //  insert(1,p);
           return 1;
        }
        if(mat[0][2]==0)
        {
          //  insert(3,p);
           return 3;
        }
                if(mat[2][0]==0)
        {
            //insert(7,p);
             return 7;
        }
                if(mat[2][2]==0)
        {
            //insert(9,p);
            return 9;
        }
    }
    return 0;
}
int isblank(int box)
{
    int h=0;
    for(int i=0;i<3;i++)
    {
         for(int j=0;j<3;j++)
    {
        h++;
        if(box==h)
        {
            if(mat[i][j]!= 0)
            {
                return 1;
            }
            return 0;
        }
    }}
}
int fillrandom(int p)
{
    int a=0;
    a=frule1(p);
        if(a==1){insert(3,p); return 1;}
        if(a==3){insert(1,p); return 1;}

    a=frule2(p);
        if(a==4){insert(6,p); return 1;}
        if(a==6){insert(4,p); return 1;}

    a=frule3(p);
        if(a==7){insert(9,p); return 1;}
        if(a==9){insert(7,p); return 1;}
    a=frule4(p);
        if(a==7){insert(1,p); return 1;}
        if(a==1){insert(7,p); return 1;}
    a=frule5(p);
        if(a==2){insert(8,p); return 1;}
        if(a==8){insert(2,p); return 1;}
    a=frule6(p);
      if(a==3){insert(9,p); return 1;}
        if(a==9){insert(3,p); return 1;}
    a=frule7(p);
     if(a==1){insert(9,p); return 1;}
        if(a==9){insert(1,p); return 1;}
    a=frule8(p);
      if(a==7){insert(3,p); return 1;}
        if(a==3){insert(7,p); return 1;}
     return 0;
}
int checkbox(int p)
{
    int a=0;
    a=rule1(p);
       if(a!=0)
    { return a;}
    a=rule2(p);
     if(a!=0)
    { return a;}
    a=rule3(p);
      if(a!=0)
    { return a;}
    a=rule4(p);
      if(a!=0)
    { return a;}
    a=rule5(p);
      if(a!=0)
    { return a;}
    a=rule6(p);
      if(a!=0)
    { return a;}
    a=rule7(p);
      if(a!=0)
    { return a;}
    a=rule8(p);
      if(a!=0)
    { return a;}

}
int fillbox(int p)
{
    int a=0,b=0,c=0;
      a=frule1(p);
       if(a==1 )
        {  if(frule6(p)!=0 || frule8(p)!=0)
           {
              insert(3,p); return 311;
           }
           else if(frule5(p)!=0)
           {
               insert(2,p); return 211;
           }
           else{
             //  insert(3,p);
           }
        }
        if(a==2)
        {
            if(frule4(p)!=0 || frule7(p)!=0){ insert(1,p); return 121;}
            else if(frule6(p)!=0 || frule8(p)!=0){ insert(3,p);  return 321;}

        }
        if(a==3)
        {
            if(frule4(p)!=0 || frule7(p)!=0){ insert(1,p);  return 121; }
            else if(frule5(p)!=0){ insert(2,p); return 231;}
            else{ }//insert(1,p);}
        }
    a=frule2(p);
   // printf("\n frule %d",a);
     if(a==4)
    {      if(frule5(p)!=0 || frule7(p)!=0 || frule8(p)!=0){ insert(5,p); return 542;}
           else if(frule6(p)!=0){ insert(6,p); return 642; }
           else {  }//insert(5,p);}
    }
    if(a==5)
    {
          if(frule4(p)!=0){ insert(4,p); return 152; }
           else if(frule6(p)!=0){ insert(6,p); return 652; }
           else { }
    }
    if(a==6)
    {
           if(frule5(p)!=0 || frule7(p)!=0 || frule8(p)!=0){ insert(5,p); return 562;}
           else if(frule4(p)!=0){ insert(4,p); return 462;}
           else { }
    }
    a=frule3(p);
    if(a==7)
    {
           if(frule6(p)!=0 || frule7(p)!=0){ insert(9,p); return 973;}
           else if(frule5(p)!=0){ insert(8,p); return 873;}

    }
    if(a==8)
    {
          if(frule4(p)!=0 || frule8(p)!=0){ insert(7,p);  return 783; }
           else if(frule6(p)!=0 || frule7(p)!=0){ insert(9,p); return 983;}

    }
    if(a==9)
    {
           if(frule4(p)!=0 || frule8(p)!=0){ insert(7,p); return 793;}
           else if(frule5(p)!=0){ insert(8,p); return 893;}
    }

    a=frule4(p);
    if(a==1)
    {
           if(frule3(p)!=0 || frule8(p)!=0){ insert(7,p); return 714;}
           else if(frule2(p)!=0){ insert(4,p); return 414;}
    }
    if(a==4)
    {
        if(frule3(p)!=0 || frule8(p)!=0){ insert(7,p); return 744;}
           else if(frule1(p)!=0 || frule7(p)!=0){ insert(1,p); return 144;}
    }
    if(a==7)
    {
          if(frule1(p)!=0 || frule7(p)!=0){ insert(1,p);  return 174;}
          else if(frule2(p)!=0){ insert(4,p); return 474;}

    }

    a=frule5(p);
    if(a==2)
    {
          if(frule8(p)!=0 || frule2(p)!=0 ||frule7(p)!=0){ insert(5,p); return 525;}
          else if(frule3(p)!=0){ insert(8,p);  return 825; }

    }
    if(a==5)
    {
         if(frule1(p)!=0){ insert(2,p);  return 255;}
          else if(frule3(p)!=0){ insert(8,p);  return 855;}

    }
    if(a==8)
    {
          if(frule8(p)!=0 || frule2(p)!=0 ||frule7(p)!=0){ insert(5,p); return 585;}
          else if(frule1(p)!=0){ insert(2,p); return 285;}

    }
    a=frule6(p);
    if(a==3){
          if(frule3(p)!=0 || frule7(p)!=0){ insert(9,p); return 936;}
          else if(frule2(p)!=0){ insert(6,p); return 636;}

    }
    if(a==6)
    { if(frule3(p)!=0 || frule7(p)!=0){ insert(9,p);  return 966;}
          else if(frule1(p)!=0 || frule8(p)!=0){ insert(3,p); return 366; }
    }
    if(a==9)
    {
        if(frule2(p)!=0){ insert(6,p); return 696; }
          else if(frule1(p)!=0 || frule8(p)!=0){ insert(3,p); return 396;}
    }
    a=frule7(p);
    if(a==1){
          if(frule2(p)!=0 || frule5(p)!=0 || frule8(p)!=0){ insert(5,p); return 517;}
          else if(frule3(p)!=0 || frule6(p)!=0){ insert(9,p);  return 917; }
    }
    if(a==5)
    {
         if(frule1(p)!=0 || frule4(p)!=0){ insert(1,p);  return 157;}
          else if(frule3(p)!=0 || frule6(p)!=0){ insert(9,p); return 957;}
    }
    if(a==9)
    {
         if(frule2(p)!=0 || frule5(p)!=0 || frule8(p)!=0){ insert(5,p); return 597;}
          else if(frule1(p)!=0 || frule4(p)!=0){ insert(1,p);  return 197; }
    }
    a=frule8(p);
    if(a==3){
          if(frule2(p)!=0 || frule5(p)!=0 || frule7(p)!=0){ insert(5,p);  return 538;}
          else if(frule3(p)!=0 || frule4(p)!=0){ insert(7,p);  return 738;}
    }
    if(a==5)
    {
         if(frule6(p)!=0 || frule1(p)!=0){ insert(3,p); return 358; }
          else if(frule3(p)!=0 || frule4(p)!=0){ insert(7,p);  return 758;}
    }
    if(a==7)
    {
         if(frule2(p)!=0 || frule5(p)!=0 || frule7(p)!=0){ insert(5,p); return 578;}
          else if(frule1(p)!=0 || frule6(p)!=0){ insert(3,p);  return 378;}
    }
    return 0;
}

int fillboxopenent(int p)
{
    int a=0,p1=2;
      a=frule1(p);
       if(a==1 )
        {  if(frule6(p)!=0 || frule8(p)!=0)
           {
              insert(3,p1); return 3;
           }
           else if(frule5(p)!=0)
           {
            //   insert(2,p1); return 2;
           }
           else{
             //  insert(3,p);
           }
        }
        if(a==2)
        {
            if(frule4(p)!=0 || frule7(p)!=0){ insert(1,p1); return 1;}
            else if(frule6(p)!=0 || frule8(p)!=0){ insert(3,p1);  return 3;}

        }
        if(a==3)
        {
            if(frule4(p)!=0 || frule7(p)!=0){ insert(1,p1);  return 1; }
           // else if(frule5(p)!=0){ insert(2,p1); return 2;}
            else{ }//insert(1,p);}
        }
   /* a=frule2(p);
   // printf("\n frule %d",a);
     if(a==4)
    {      if(frule5(p)!=0 || frule7(p)!=0 || frule8(p)!=0){ insert(5,p1); return 5;}
          // else if(frule6(p)!=0){ insert(6,p1); return 6; }
           else {  }//insert(5,p);}
    }
    if(a==5)
    {
          //if(frule4(p)!=0){ insert(4,p1); return 4; }
          // else if(frule6(p)!=0){ insert(6,p1); return 6; }
           else { }
    }
    if(a==6)
    {
           if(frule5(p)!=0 || frule7(p)!=0 || frule8(p)!=0){ insert(5,p1); return 5;}
           //else if(frule4(p)!=0){ insert(4,p1); return 4;}
           else { }
    }*/
    a=frule3(p);
    if(a==7)
    {
           if(frule6(p)!=0 || frule7(p)!=0){ insert(9,p1); return 9;}
          // else if(frule5(p)!=0){ insert(8,p1); return 8;}

    }
    if(a==8)
    {
          if(frule4(p)!=0 || frule8(p)!=0){ insert(7,p1);  return 7; }
           else if(frule6(p)!=0 || frule7(p)!=0){ insert(9,p1); return 9;}

    }
    if(a==9)
    {
           if(frule4(p)!=0 || frule8(p)!=0){ insert(7,p1); return 7;}
          // else if(frule5(p)!=0){ insert(8,p1); return 8;}
    }

    a=frule4(p);
    if(a==1)
    {
           if(frule3(p)!=0 || frule8(p)!=0){ insert(7,p1); return 7;}
          // else if(frule2(p)!=0){ insert(4,p1); return 4;}
    }
    if(a==4)
    {
        if(frule3(p)!=0 || frule8(p)!=0){ insert(7,p1); return 7;}
           else if(frule1(p)!=0 || frule7(p)!=0){ insert(1,p1); return 1;}
    }
    if(a==7)
    {
          if(frule1(p)!=0 || frule7(p)!=0){ insert(1,p1);  return 1;}
          //else if(frule2(p)!=0){ insert(4,p1); return 4;}

    }

  /*  a=frule5(p);
    if(a==2)
    {
          //if(frule8(p)!=0 || frule2(p)!=0 ||frule7(p)!=0){ insert(5,p1); return 5;}
           if(frule3(p)!=0){ insert(8,p1);  return 8; }

    }
    if(a==5)
    {
         if(frule1(p)!=0){ insert(2,p1);  return 2;}
          else if(frule3(p)!=0){ insert(8,p1);  return 8;}

    }
    if(a==8)
    {
          if(frule8(p)!=0 || frule2(p)!=0 ||frule7(p)!=0){ insert(5,p1); return 5;}
          else if(frule1(p)!=0){ insert(2,p1); return 2;}

    }*/
    a=frule6(p);
    if(a==3){
          if(frule3(p)!=0 || frule7(p)!=0){ insert(9,p1); return 9;}
       //   else if(frule2(p)!=0){ insert(6,p1); return 6;}

    }
    if(a==6)
    { if(frule3(p)!=0 || frule7(p)!=0){ insert(9,p1);  return 9;}
          else if(frule1(p)!=0 || frule8(p)!=0){ insert(3,p1); return 3; }
    }
    if(a==9)
    {
       // if(frule2(p)!=0){ insert(6,p1); return 6; }
        if(frule1(p)!=0 || frule8(p)!=0){ insert(3,p1); return 3;}
    }
    a=frule7(p);
    if(a==1){
        //  if(frule2(p)!=0 || frule5(p)!=0 || frule8(p)!=0){ insert(5,p1); return 5;}
        if(frule3(p)!=0 || frule6(p)!=0){ insert(9,p1);  return 9; }
    }
    if(a==5)
    {
         if(frule1(p)!=0 || frule4(p)!=0){ insert(1,p1);  return 1;}
          else if(frule3(p)!=0 || frule6(p)!=0){ insert(9,p1); return 9;}
    }
    if(a==9)
    {
        // if(frule2(p)!=0 || frule5(p)!=0 || frule8(p)!=0){ insert(5,p1); return 5;}
        if(frule1(p)!=0 || frule4(p)!=0){ insert(1,p1);  return 1; }
    }
    a=frule8(p);
    if(a==3){
        //  if(frule2(p)!=0 || frule5(p)!=0 || frule7(p)!=0){ insert(5,p1);  return 5;}
          if(frule3(p)!=0 || frule4(p)!=0){ insert(7,p1);  return 7;}
    }
    if(a==5)
    {
         if(frule6(p)!=0 || frule1(p)!=0){ insert(3,p1); return 3; }
          else if(frule3(p)!=0 || frule4(p)!=0){ insert(7,p1);  return 7;}
    }
    if(a==7)
    {
         //if(frule2(p)!=0 || frule5(p)!=0 || frule7(p)!=0){ insert(5,p1); return 5;}
           if(frule1(p)!=0 || frule6(p)!=0){ insert(3,p1);  return 3;}
    }
    return 0;
}

int frule1(int p)
{
    int flag=0,box=-1;
    for(int i=0;i<3;i++)
    {
        if(mat[0][i]==0)
        {
            flag++;
        }
        if(mat[0][i]==p)
        {
           box=i+1;
        }
    }
    if(flag==2 && box!=-1)
    {
        return box;
    }
    return 0;
}
int frule2(int p)
{
    int flag=0,box=-1;
    for(int i=0;i<3;i++)
    {
        if(mat[1][i]==0)
        {
            flag++;
        }
        if(mat[1][i]==p)
        {
           box=i+1+3;
        }
    }
    if(flag==2 && box!=-1)
    {
        return box;
    }
    return 0;
}
int frule3(int p)
{
    int flag=0,box=-1;
    for(int i=0;i<3;i++)
    {
        if(mat[2][i]==0)
        {
            flag++;
        }
        if(mat[2][i]==p)
        {
           box=i+1+6;
        }
    }
    if(flag==2 && box!=-1)
    {
        return box;
    }
    return 0;
}
int frule4(int p)
{
    int flag=0,box=-1;
    for(int i=0;i<3;i++)
    {
        if(mat[i][0]==0)
        {
            flag++;
        }
        if(mat[i][0]==p)
        {
           if(i==0){box=1;} if(i==1){box=4;} if(i==2){box=7;}
        }
    }
    if(flag==2 && box!=-1)
    {
        return box;
    }
    return 0;
}
int frule5(int p)
{
    int flag=0,box=-1;
    for(int i=0;i<3;i++)
    {
        if(mat[i][1]==0)
        {
            flag++;
        }
        if(mat[i][1]==p)
        {
           if(i==0){box=2;} if(i==1){box=5;} if(i==2){box=8;}
        }
    }
    if(flag==2 && box!=-1)
    {
        return box;
    }
    return 0;
}
int frule6(int p)
{
    int flag=0,box=-1;
    for(int i=0;i<3;i++)
    {
        if(mat[i][2]==0)
        {
            flag++;
        }
        if(mat[i][2]==p)
        {
           if(i==0){box=3;} if(i==1){box=6;} if(i==2){box=9;}
        }
    }
    if(flag==2 && box!=-1)
    {
        return box;
    }
    return 0;
}
int frule7(int p)
{
    int flag=0,box=-1;
     if(mat[0][0]==0)
     {
         flag++;
     }
     if(mat[0][0]==p)
     {
         box=1;
     }
     if(mat[1][1]==0)
     {
         flag++;
     }
     if(mat[1][1]==p)
     {
         box=5;
     }
     if(mat[2][2]==0)
     {
         flag++;
     }
     if(mat[2][2]==p)
     {
         box=9;
     }
    if(flag==2 && box!=-1)
    {
        return box;
    }
    return 0;
}
int frule8(int p)
{
    int flag=0,box=-1;
     if(mat[0][2]==0)
     {
         flag++;
     }
     if(mat[0][2]==p)
     {
         box=3;
     }
     if(mat[1][1]==0)
     {
         flag++;
     }
     if(mat[1][1]==p)
     {
         box=5;
     }
     if(mat[2][0]==0)
     {
         flag++;
     }
     if(mat[2][0]==p)
     {
         box=7;
     }
    if(flag==2 && box!=-1)
    {
        return box;
    }
    return 0;
}


int rule1(int p)
{
    int flag=0,box=-1;
    for(int i=0;i<3;i++)
    {
        if(mat[0][i]==p)
        {
            flag++;
        }
        if(mat[0][i]==0)
        {
           box=i+1;
        }
    }
    if(flag==2 && box!=-1)
    {
        return box;
    }
    return 0;
}
int rule2(int p)
{
    int flag=0,box=-1;
    for(int i=0;i<3;i++)
    {
        if(mat[1][i]==p)
        {
            flag++;
        }
        if(mat[1][i]==0)
        {
           box=i+1+3;
        }
    }
    if(flag==2 && box!=-1)
    {
        return box;
    }
    return 0;
}
int rule3(int p)
{
    int flag=0,box=-1;
    for(int i=0;i<3;i++)
    {
        if(mat[2][i]==p)
        {
            flag++;
        }
        if(mat[2][i]==0)
        {
           box=i+1+6;
        }
    }
    if(flag==2 && box!=-1)
    {
        return box;
    }
    return 0;
}
int rule4(int p)
{
    int flag=0,box=-1;
    for(int i=0;i<3;i++)
    {
        if(mat[i][0]==p)
        {
            flag++;
        }
        if(mat[i][0]==0)
        {
           if(i==0){box=1;} if(i==1){box=4;} if(i==2){box=7;}
        }
    }
    if(flag==2 && box!=-1)
    {
        return box;
    }
    return 0;
}
int rule5(int p)
{
    int flag=0,box=-1;
    for(int i=0;i<3;i++)
    {
        if(mat[i][1]==p)
        {
            flag++;
        }
        if(mat[i][1]==0)
        {
           if(i==0){box=2;} if(i==1){box=5;} if(i==2){box=8;}
        }
    }
    if(flag==2 && box!=-1)
    {
        return box;
    }
    return 0;
}
int rule6(int p)
{
    int flag=0,box=-1;
    for(int i=0;i<3;i++)
    {
        if(mat[i][2]==p)
        {
            flag++;
        }
        if(mat[i][2]==0)
        {
           if(i==0){box=3;} if(i==1){box=6;} if(i==2){box=9;}
        }
    }
    if(flag==2 && box!=-1)
    {
        return box;
    }
    return 0;
}
int rule7(int p)
{
    int flag=0,box=-1;
     if(mat[0][0]==p)
     {
         flag++;
     }
     if(mat[0][0]==0)
     {
         box=1;
     }
     if(mat[1][1]==p)
     {
         flag++;
     }
     if(mat[1][1]==0)
     {
         box=5;
     }
     if(mat[2][2]==p)
     {
         flag++;
     }
     if(mat[2][2]==0)
     {
         box=9;
     }
    if(flag==2 && box!=-1)
    {
        return box;
    }
    return 0;
}
int rule8(int p)
{
    int flag=0,box=-1;
     if(mat[0][2]==p)
     {
         flag++;
     }
     if(mat[0][2]==0)
     {
         box=3;
     }
     if(mat[1][1]==p)
     {
         flag++;
     }
     if(mat[1][1]==0)
     {
         box=5;
     }
     if(mat[2][0]==p)
     {
         flag++;
     }
     if(mat[2][0]==0)
     {
         box=7;
     }
    if(flag==2 && box!=-1)
    {
        return box;
    }
    return 0;
}
int insert(int n,int p)
{
      if(n==1)
    {
       if( mat[0][0]==0)
       {
           mat[0][0]=p;
       }
       else{
        printf(" \n %d is already filled enter again\n",n);
        return 1;
       }
       return 0;
    }
        if(n==2)
    {
               if( mat[0][1]==0)
       {
           mat[0][1]=p;
       }
       else{
        printf(" \n %d is already filled enter again\n",n);
        return 1;
       }
   return 0;
       // mat[0][1]=p;
    }
        if(n==3)
    {       if( mat[0][2]==0)
       {
           mat[0][2]=p;
       }
       else{
         printf(" \n %d is already filled enter again\n",n);
        return 1;
        }
        return 0;
        }

    if(n==4)
    {
       if( mat[1][0]==0)
       {
           mat[1][0]=p;
       }
       else{
        printf(" \n %d is already filled enter again\n",n);
        return 1;
       }
       return 0;
    //    mat[1][0]=p;
    }
        if(n==5)
    {
        if( mat[1][1]==0)
       {
           mat[1][1]=p;
       }
       else{
        printf(" \n %d is already filled enter again\n",n);
        return 1;
       }
       return 0;
        //mat[1][1]=p;
    }
        if(n==6)
    {
        if( mat[1][2]==0)
       {
           mat[1][2]=p;
       }
       else{
        printf(" \n %d is already filled enter again\n",n);
        return 1;
       }
       return 0;
         //mat[1][2]=p;
    }
        if(n==7)
    {
        if( mat[2][0]==0)
       {
           mat[2][0]=p;
       }
       else{
        printf(" \n %d is already filled enter again\n",n);
        return 1;
       }
       return 0;
       // mat[2][0]=p;
    }
        if(n==8)
    {
        if( mat[2][1]==0)
       {
           mat[2][1]=p;
       }
       else{
        printf(" \n %d is already filled enter again\n",n);
        return 1;
       }
       return 0;

       // mat[2][1]=p;
    }
        if(n==9)
    {
        if( mat[2][2]==0)
       {
           mat[2][2]=p;
       }
       else{
        printf(" \n %d is already filled enter again\n",n);
        return 1;
       }
       return 0;
       // mat[2][2]=p;
    }

}
void printmat(void)
{
   for(int i=0;i<3;i++)
   {
        // printf("______________________________________________\n");
        printf("\n");
        for(int j=0;j<3;j++)
        {

          printf("\t%d",mat[i][j]);
        }
        // printf("\n______________________________________________");

   }

        //   mat[i][j]=0;


}
