#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

#define o 3
#define  nl printf("\n");

//le menu//
void menu()
{
    
    printf("\t\t\t____________________________________________\n"); 
    printf("\t\t\t____________________________________________\n");
    printf("\t\t\t|                                          |\n");  
    printf("\t\t\t|        A quel jeu voulez vous jouer  ?   |\n");
    printf("\t\t\t|                                          |\n");
    printf("\t\t\t|           1-X/O                          |\n");
    printf("\t\t\t|           2-Calculator Game              |\n");
    printf("\t\t\t|           3-Casino Game                  |\n");
    printf("\t\t\t|           4-Quitter                      |\n");
    printf("\t\t\t|__________________________________________|\n");
    printf("\t\t\t__________________________________________\n");
       
}
//remplir les cases de XO //
void fillX0(int t[][3])
{
    int i,j;
    for(i=0;i<o;i++)
    {
       for(int j=0;j<o;j++)
       {
           t[i][j]=-1;
       }
    }
}

int m3ebi(int t[][o])
{
    int i,j;
    for(i=0;i<o;i++)
    {
       for(int j=0;j<o;j++)
       {
           if(t[i][j]==-1)
           {
               return 0;
           }
       }
    }
    return 1;
}

//afficher X O//
void show(int t[][o])
{
    int i,j;
    printf("\n____________________\n\n");
    for( i=0;i<o;i++)
    {
        
        for(j=0;j<o;j++)
        {
            if(t[i][j]==1)
            {
                printf("|X|\t"); 
            }
            else if(t[i][j]==2)
            {
                printf("|O|\t");
            }
            else printf("|*|\t");
        }
        printf("\n");
    }
    printf("____________________\n");
}
//determiner le  gagniant//
int win(int t[][o])
{
    int k=0;
    if((t[0][0]==t[0][1] && t[0][0]==t[0][2] && t[0][0]==1) || (t[1][0]==t[1][1] && t[1][0]==t[1][2] && t[1][0]==1) ||
     (t[2][0]==t[2][1] && t[2][0]==t[2][2] && t[2][0]==1) || (t[0][0]==t[1][0] && t[0][0]==t[2][0] && t[0][0]==1) || (t[0][1]==t[1][1] && t[0][1]==t[2][1] && t[0][1]==1) 
     || (t[0][2]==t[1][2] && t[0][2]==t[2][2] && t[0][2]==1)|| (t[0][0]==t[1][1] && t[0][0]==t[2][2] && t[0][0]==1) || (t[0][2]==t[1][1] && t[0][2]==t[2][0] && t[0][2]==1) )
    {
        k=1;
    }
    else if((t[0][0]==t[0][1] && t[0][0]==t[0][2] && t[0][0]==2) || (t[1][0]==t[1][1] && t[1][0]==t[1][2] && t[1][0]==2) ||
     (t[2][0]==t[2][1] && t[2][0]==t[2][2] && t[2][0]==2) || (t[0][0]==t[1][0] && t[0][0]==t[2][0] && t[0][0]==2) || (t[0][1]==t[1][1] && t[0][1]==t[2][1] && t[0][1]==2) 
     || (t[0][2]==t[1][2] && t[0][2]==t[2][2] && t[0][2]==2) || (t[0][0]==t[1][1] && t[0][0]==t[2][2] && t[0][0]==2) || (t[0][2]==t[1][1] && t[0][2]==t[2][0] && t[0][2]==2))
    {
        k=2;
    }
    return k;
} 

// jouer a XO //
void playX0(int t[][o], char name[10],char name1[10])
{
    int a,b,c,d;
    while(!m3ebi(t))
    {
        
        do
        {
            show(t);
            printf("==>%s c'est votre tour:",name);
            scanf("%d %d",&a,&b);
        } while (t[a-1][b-1]!=-1 || a>3 || a<1 || b<1 || b>3);
        t[a-1][b-1]=1;
        show(t);
        if(win(t)==1)
        {           
            show(t);
            system("cmd.exe /c cls");
            printf("___________________\n");
            printf("!!! %s a GAGNE !!!\n",name);
            printf("___________________\n");
            show(t);
            break;
            
        }
        if (m3ebi(t))
        {
            break;
        }
        do
        {
            printf("==>%s c'est votre tour:",name1);
            scanf("%d %d",&c,&d);
        } while (t[c-1][d-1]!=-1 || c>3 || c<1 || d<1 || d>3 );
        t[c-1][d-1]=2;
        if(win(t)==2)
        {   
            show(t);
            system("cmd.exe /c cls");       
            printf("___________________\n");
            printf(" !!! %s a GAGNE !!!\n",name1);
            printf("___________________\n");
            show(t);
            break;
        }
    }
    return;
}
//jeu de casino//
void casino ()
{
    int amount,bet_amount,guess,DICE;
    char k,vide[50],nom[10];
    gets(vide);
    printf("Entrez Votre Nom:");
    gets(nom);
    nl;
    srand(time(0));
    printf("Donner la somme d'argent en possession :");scanf("%d",&amount);
    mise:;
    do{
        printf("Donner la somme de la mise :");scanf("%d",&bet_amount);
    }while( bet_amount>amount);
    nl
    if(bet_amount<=amount)
    {
        do{
            gets(vide);
            printf("Voulez Vous Miser | sortir ? (O/N)");
            scanf("%c",&k);
        }while(toupper(k)!='O' && toupper(k)!='N');
    }
    if(toupper(k)=='O')
    {
        char f;
        do{
            DICE=rand()%10+1;
            do{
                system("cmd.exe /c cls");
                printf("Choisissez un nombre entre 1 et 9  |Bonne Chance! :)| :");
                scanf("%d",&guess);
            }while(guess<=0 || guess>10 );
            guess==DICE?printf("bravo %s vous avez gagnee %d Dinars",nom,bet_amount*10),amount+bet_amount*10:printf("Malheureusement vous avez perdu la mise\n vous avez maintenant %d Dinars\n",amount-bet_amount),amount=amount-bet_amount,bet_amount=0;
            do{
                gets(vide);
                printf("\nVoulez Vous ReMiser ? (O/N)");
                scanf("%c",&f);
            }while(toupper(f)!='O' && toupper(f)!='N');
            if(amount==0 || f=='N'){
                printf("Malheureusement vous avez perdu tout votre argent %s :( \n",nom);
                return;
            }
            else if (toupper(f)=='O'){goto mise;}
        }while(toupper(f)!='N');
    }
    else if(toupper(k)=='N')
    {
        return;
    }

}
//calculateur de produit//
void playcalculator()
{
    int a,b,k,x;
    srand(time(NULL));
    printf("\nSi Vous Voulez jouer tapez 1 sinon taper -1\n");
    scanf("%d",&k);
    while(k==1)
    {
        
        do 
        {
             a=rand()%100;
             b=rand()%100;
            
            do{
                printf("Donner la Solution de %d x %d=",a,b);
                scanf("%d",&x);
                if(x!=a*b)
                {
                    printf("Mauvaise reponse\n");
                    printf("Si Vous Voulez Continuer tapez ( Oui:1 | non:-1) ?\n");
                    scanf("%d",&k);                
                }
                else
                {
                    printf("Bravo la reponse est correcte \n");
                    printf("Si Vous Voulez Continuer tapez ( Oui:1 | non:-1) ?\n");
                    scanf("%d",&k);
                    if(k==-1) goto out;
                }
            }while(x!=a*b && k!=-1);
            
        }while(k==1);
    }
    out:;
    return;
}
int main() {
    system("CMD.EXE /c MODE 50,45");   
    system("CMD.EXE /c COLOR 2f");
    char name[10],name1[10];
    int t[3][3],n;
    malloc
    restart:;
    system("cmd.exe /c cls");
    printf("Nom :"); gets(name);
    printf("\t\t\t ________________________________\n");
    printf("\t\t\t|                                |\n");
    printf("\t\t\t|            Bienvenu            |\n");
    printf("\t\t\t             %s                \n",name);
    printf("\t\t\t|________________________________|\n\n\n"); 
    
    
    menu();
    do
    {
        printf("==>");
        scanf("%d",&n);
    } while (n!=1 && n!=3 && n!=2 && n!=4);
    if(n==1)
    { 
        printf("Joueur 2 :\n");scanf("%s",&name1);
        system("cmd.exe /c cls");
        fillX0(t);
        playX0(t,name,name1);goto restart;
    }
    else if(n==2)
    {
        playcalculator(name);goto restart;
    }
    else if(n==3)
    {
        casino();goto restart;
    }
    else 
    {
        printf("LA FIN DU JEU :) ");
        return 0;
    } 
}