#include <tchar.h>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include<iostream>
//#include<graphiics.h>

LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
int rech(int numRech);
     void creer_compte();
     void depot();
     void retrait();
     void transfert();
     void modification();
     void supprimer();
     void bloquer();
     void afficher();

TCHAR szClassName[ ] = _T("MAZABANK");

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;
    MSG messages;
    WNDCLASSEX wincl;

    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;
    wincl.style = CS_DBLCLKS;
    wincl.cbSize = sizeof (WNDCLASSEX);
    system("color 3");

    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;
    wincl.cbClsExtra = 0;
    wincl.cbWndExtra = 0;
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    if (!RegisterClassEx (&wincl))
        return 0;

    hwnd = CreateWindowEx (
           0,
           szClassName,
           _T(" Gestion du Banque"),
           WS_OVERLAPPEDWINDOW,
           CW_USEDEFAULT,
           CW_USEDEFAULT,
           5500,
           1000,
           HWND_DESKTOP,
           NULL,
           hThisInstance,
           NULL
           );
   HWND boutton = CreateWindow (TEXT ("static"),
    "  BANK PAM  ",
                                 WS_CHILD | WS_VISIBLE | SS_CENTER,
                                 150,60,
                                 1000,40,
                                 hwnd,
                                 (HMENU)0,
                                 NULL,
                                 NULL) ;
   HWND boutton1 = CreateWindow (TEXT ("button"),
                                 "*_*OUVRIR UN OU PLUSIEURS COMPTES*_*",
                                 WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                                 150,150,
                                 1000,40,
                                 hwnd,
                                 (HMENU)1,
                                 NULL,
                                 NULL) ;
                                 
HWND boutton2 = CreateWindow (TEXT ("button"),
                                 "*_*DEPOTS*_*",
                                 WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                                 150,200,
                                 1000,40,
                                 hwnd,
                                 (HMENU)2,
                                 NULL,
                                 NULL) ;
                                 
HWND boutton3 = CreateWindow (TEXT ("button"),
                                 "*_*RETRAITS*_*",
                                 WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                                 150,250,
                                 1000,40,
                                 hwnd,
                                 (HMENU)3,
                                 NULL,
                                 NULL) ;
                                 
 HWND boutton4 = CreateWindow (TEXT ("button"),
                                 "*_*TRANSFERT*_*",
                                 WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                                 150,300,
                                 1000,40,
                                 hwnd,
                                 (HMENU)4,
                                 NULL,
                                 NULL) ;
                                
HWND boutton5 = CreateWindow (TEXT ("button"),
                                 "*_*MODIFIER UN COMPTE*_* ",
                                 WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                                 150,350,
                                 1000,40,
                                 hwnd,
                                 (HMENU)5,
                                 NULL,
                                 NULL) ;
 
HWND boutton6 = CreateWindow (TEXT ("button"),
                                 "*_* SUPPRIMER UN COMPTE*_* ",
                                 WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                                 150,400,
                                 1000,40,
                                 hwnd,
                                 (HMENU)6,
                                 NULL,
                                 NULL) ;

HWND boutton7 = CreateWindow (TEXT ("button"),
                                 "*_* BLOQUER UN COMPTE*_* ",
                                 WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                                 150,450,
                                 1000,40,
                                 hwnd,
                                 (HMENU)7,
                                 NULL,
                                 NULL) ;

HWND boutton8 = CreateWindow (TEXT ("button"),
                                 " *AFFICHER LES COMPTES* ",
                                 WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                                 150,500,
                                 1000,40,
                                 hwnd,
                                 (HMENU)8,
                                 NULL,
                                 NULL) ;
                                 
HWND boutton9 = CreateWindow (TEXT ("button"),
                                 "*_* QUITTER LE PROGRAMME*_* ",
                                 WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                                 150,550,
                                 1000,40,
                                 hwnd,
                                 (HMENU)9,
                                 NULL,
                                 NULL) ;
                              
if(!hwnd)
	return FALSE;
    ShowWindow (hwnd, nCmdShow);
    UpdateWindow(hwnd);

    while (GetMessage (&messages, NULL, 0, 0))
    {
        TranslateMessage(&messages);
        DispatchMessage(&messages);
    }

    return messages.wParam;
}

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /*  messages */
    {
        case WM_RBUTTONUP:
             {
             case WM_COMMAND:
                 switch(LOWORD(wParam))
                {
                    case 1: MessageBeep(MB_OK);
                            DestroyWindow(hwnd);
                            creer_compte();
                            //DestroyWindow(hwnd);
                        break;
                    case 2: MessageBeep(MB_OK);
                            DestroyWindow(hwnd);
                             depot();
                        break;
                    case 3: MessageBeep(MB_OK);
                            DestroyWindow(hwnd);
                          retrait();
                        break;
                    case 4: MessageBeep(MB_OK);
                            DestroyWindow(hwnd);
                             transfert();
                        break;  
					case 5: MessageBeep(MB_OK);
                            DestroyWindow(hwnd);
                             modification();
                        break;
                        case 6: MessageBeep(MB_OK);
                            DestroyWindow(hwnd);
                             supprimer();
                        break;
                    case 7: MessageBeep(MB_OK);
                            DestroyWindow(hwnd);
                             bloquer();
                        break;
                    case 8: MessageBeep(MB_OK);
                            DestroyWindow(hwnd);
                            afficher();
                        break;	
                    case 9: MessageBeep(MB_OK);
                            DestroyWindow(hwnd);
                            exit(0);
                        break;	
						  
     }
            }
        case WM_CREATE:
            break;
        case WM_DESTROY:
            PostQuitMessage (0);  
                break;
        default:           
            return DefWindowProc (hwnd, message, wParam, lParam);
    }
    

    return 0;
}

typedef struct Bank B;
struct Bank
 {
    char nom[250];
 	char prenom[250];
 	char ad[250];
 	int code;
 	int tel;
 	int q=-1;
 	float solde;
 }; 
    B A;
    	int i = 0;
 
// la fonction rechercher
int rech(int numRech)
 {
      FILE *fpt= fopen("Bank.text","r");
       
        do{ 
          fscanf(fpt,"%s\t %s\t %s\t %d\t %d %f\t",&A.nom,&A.prenom,&A.ad,&A.code,&A.tel,&A.solde);
            // fflush(stdin);
             if(A.code == numRech)
           {

            fclose(fpt);
             return 1;
             }
             }while(!feof(fpt));
              fclose(fpt);
              return 0;
 }
void creer_compte()
            {
            	int n;
            
                FILE *fpt;
                fpt = fopen("Bank.text","a");
                printf("\t\t\t\tEntrer le nombre de compte a creer  :");
                scanf("%d",&n);
                while(i < n){
               
                  printf("\t\t\t\t Compte #%d\n",i+1);
                  printf("\t\t\t\tNom:  ");scanf("%s",&A.nom);
                  printf("\t\t\t\tPrenom:  "); scanf("%s",&A.prenom);
                  printf("\t\t\t\tAdresse :"); scanf("%s",&A.ad); 
                  printf("\t\t\t\tNumero De Compte:  "); scanf("%d",&A.code);
                  printf("\t\t\t\tTelephone: (+509) "); scanf("%d",&A.tel);
                          
                 do{
                 	 printf(" Vous avez besoin de 1000 G pour ouvrir ce compte\n");
                    printf(" Solde :"); scanf("%f",&A.solde);  
                    }while(A.solde<1000);
                    fprintf(fpt,"%s\n %s\n %s\n %d\n %d\n %0.2f\n\n",A.nom,A.prenom,A.ad,A.code,A.tel,A.solde);
                    if(A.solde>=1000)
                    printf("votre compte a ete creer avec succes!");
                 i++;
                      }
                    fclose(fpt);
           }  
// fonction depot d'argent
void depot()
{       float dep;
            int id1;
            printf("Saisir Votre Code: \n");
             scanf("%d",&id1);
            if (rech(id1)==1)
        {
            FILE *fpt,*F;
             fpt=fopen("Bank.text","r");
              F=fopen("tampBank.txt","a");
      do{
            fscanf(fpt,"%s\t %s\t %s\t %d\t %d %f\t",&A.nom,&A.prenom,&A.ad,&A.code,&A.tel,&A.solde);
           fflush(stdin);
           if(id1==A.code)
     {
            A.code=id1;
             printf(" ** Information sur votre compte  **\n\n");
                          printf(" Nom : %s\n",A.nom);
                          printf(" Prenom : %s \n",A.prenom);
                          printf(" Adresse : %s\n",A.ad);
                          printf(" Code : %d\n",A.code);
                          printf(" Telephone : %d\n",A.tel);
                          printf(" Solde : %0.2f\n\n\n",A.solde);
            printf("Saisir le montant que vous voulez deposer:");
            scanf("%f",&dep);
            A.solde = A.solde+dep;
             printf("Vous avez depose %.2f gourdes sur votre compte\n",dep);
     }
           fprintf(F,"%s\n %s\n %s\n %d\n %d\n %f\n\n",A.nom,A.prenom,A.ad,A.code,A.tel,A.solde);
     }while(!feof(fpt));
        fclose(fpt);
         fclose(F);
           remove("Bank.text");
           rename("tampBank.txt","Bank.text");
               
       }
                  else
                  printf("Ce code n'existe pas\n");
        }
// fonction retrait d'argent
void retrait()
{
           float ret;
            int id1;
            printf("Saisir Votre code: \n");
             scanf("%d",&id1);
            if (rech(id1)==1)
        {
            FILE *fpt,*F;
             fpt=fopen("Bank.text","r");
              F=fopen("tampBank.txt","a");
    do{
            fscanf(fpt,"%s\t %s\t %s\t %d\t %d %f\t",&A.nom,&A.prenom,&A.ad,&A.code,&A.tel,&A.solde);
           fflush(stdin);
           if(id1==A.code)
     {
            A.code=id1;
             printf(" ** Information sur votre compte  **\n\n");
                          printf(" Nom : %s\n",A.nom);
                          printf(" Prenom : %s \n",A.prenom);
                          printf(" Adresse : %s\n",A.ad);
                          printf(" Code : %d\n",A.code);
                          printf(" Telephone : %d\n",A.tel);
                          printf(" Solde : %0.2f\n\n\n",A.solde);
           
             printf("Combien voulez-vous retirer ?: ");
            scanf("%f",&ret);
              if(ret>A.solde){
             printf("\n\nDesole vous n'avez pas cette somme sur votre compte\n");
             printf("Ressayez! \n");
              }
              else{
            A.solde = A.solde-ret;
              printf("Vous avez retire %.2f gourdes sur votre compte\n",ret);
              	}
     }
           fprintf(F,"%s\n %s\n %s\n %d\n %d\n %f\n\n",A.nom,A.prenom,A.ad,A.code,A.tel,A.solde);
     }while(!feof(fpt));
        fclose(fpt);
         fclose(F);
           remove("Bank.text");
           rename("tampBank.txt","Bank.text");
              
       }
                  else
                  printf("Ce code n'existe pas\n");
}

// fonction du transfert d'argent
void transfert()
{
            float transf;
            int id2,id3;


// le compte pour retier l'argent
      
	         printf("\n\t\t\t Transfert d'argent d'un compte a un autre\n\n");
	         printf("\n");
                 printf(" Le code du compte pour retirer l'argent a transferer :");
             scanf("%d",&id2);
                if(rech(id2)==1)
          {   
                 FILE *fpt,*F;
               fpt=fopen("Bank.text","r");
                  F=fopen("tampBank.txt","a");
              do{
                fscanf(fpt,"%s\t %s\t %s\t %d\t %d %f\t",&A.nom,&A.prenom,&A.ad,&A.code,&A.tel,&A.solde);
                  fflush(stdin);
                   if(id2==A.code)
            {
                   A.code=id2;
                   
                       printf(" ** infos sur votre compte  **\n\n");
                              printf(" Nom : %s\n",A.nom);
                              printf(" Prenom : %s \n",A.prenom);
                              printf(" Adresse : %s\n",A.ad);
                              printf(" Code : %d\n",A.code);
                              printf(" Telephone : %d\n",A.tel);
                              printf(" Solde : %0.2f\n\n\n",A.solde);
                        
                       printf("Saisir le montant :\n");
                        do{
                       scanf("%f",&transf);
                        A.solde = A.solde-transf;
                      if(transf>A.solde){
                 printf("\n\nDesole vous n'avez pas cette somme sur votre compte\n\n");
                 printf(" SVP ! Saisair un autre montant \n\n");
                  }
                  }while(transf>A.solde);
                  printf(" Vous avez retire %.2f gourdes sur votre compte pour transferer sur autre\n",transf);
                  	}
         
                    fprintf(F,"%s\n %s\n %s\n %d\n %d\n %f\n\n",A.nom,A.prenom,A.ad,A.code,A.tel,A.solde);
                    }while(!feof(fpt));
                         fclose(fpt);
                        fclose(F);
                        remove("Bank.text");
                          rename("tampBank.txt","Bank.text");
                 printf("Vous avez retiter %.2f gourdes sur Ce compte\n",transf);
                      }                            
     else
           printf("Ce code n'existe pas\n");

// le compte du transfert d'argent
printf("\n");
printf(" Le code du compte pour transferer l'argent :");
scanf("%d",&id3);
if (rech(id3)==1)
{
FILE *fpt,*F;
fpt=fopen("Bank.text","r");
F=fopen("tampBank.txt","a");
do{
   fscanf(fpt,"%s\t %s\t %s\t %d\t %d %f\t",&A.nom,&A.prenom,&A.ad,&A.code,&A.tel,&A.solde);
 fflush(stdin);
    if(id3==A.code)
 {
   A.code=id3;
     printf(" ** infos sur ce compte  **\n\n");
          printf(" Nom : %s\n",A.nom);
          printf(" Prenom : %s \n",A.prenom);
          printf(" Adresse : %s\n",A.ad);
          printf(" Code : %d\n",A.code);
          printf(" Telephone : %d\n",A.tel);
          printf(" Solde : %0.2f\n\n\n",A.solde);
     A.solde = A.solde+transf;
       }
         fprintf(F,"%s\n %s\n %s\n %d\n %d\n %f\n\n",A.nom,A.prenom,A.ad,A.code,A.tel,A.solde);
       }while(!feof(fpt));
        fclose(fpt);
          fclose(F);
           remove("Bank.text");
              rename("tampBank.txt","Bank.text");
                  printf("Vous avez recu %.2f gourdes sur ce compte\n",transf);
          }
    else
            printf("Ce code n'existe pas\n");
}

             // la fonction  pour modifier un compte 
void modification()
{
int id4;
int rep;
printf("\n\t\t\t Modification d'un compte\n\n");
printf(" Le code du compte  :");
scanf("%d",&id4);
if (rech(id4)==1)
{
FILE *fpt,*F;
fpt=fopen("Bank.text","r");
F=fopen("tampBank.txt","a");
do{
fscanf(fpt,"%s\t %s\t %s\t %d\t %d %f\t",&A.nom,&A.prenom,&A.ad,&A.code,&A.tel,&A.solde);
fflush(stdin);
if(id4==A.code)
{                  
A.code = id4;

printf(" ** Infos sur votre compte  **\n\n");
printf(" Nom : %s\n",A.nom);
printf(" Prenom : %s \n",A.prenom);
printf(" Adresse : %s\n",A.ad);
printf(" Code : %d\n",A.code);
printf(" Telephone : %d\n",A.tel);
printf(" Solde : %0.2f\n\n\n",A.solde);
getch();

do{
printf("\t\t\t   Etes vous sure de vouloir le modifier \n\n");                                          	
printf(" \t\t\t1.-Oui\t\t  2.- Non\n\n");
scanf("%d",&rep);
}while(rep!= 1 && rep != 2);   	 
}         
}while(!feof(fpt));
system("cls");
if(rep==1){
printf(" Entrer les nouvelles modifications\n\n");
printf(" Nouveau Nom:  ");scanf("%s",&A.nom);
printf(" Nouveau prenom:  "); scanf("%s",&A.prenom);
printf(" Nouvelle Adresse :"); scanf("%s",&A.ad); 
printf(" Nouveau numero de Telephone: (+509) "); scanf("%d",&A.tel);
fprintf(F,"%s\n %s\n %s\n %d\n %d\n %f\n\n",A.nom,A.prenom,A.ad,A.code,A.tel,A.solde);
fclose(fpt);
fclose(F);
remove("Bank.text");
rename("tampBank.txt","Bank.text");
  }
else if(rep == 2)
printf(" Annulation de la modification ");

} 
else 
  printf("Ce compte n'existe pas\n");
}
// la fonction supprimer
void supprimer(){
int idS; int rep,test = 9;
printf("\n\t\t\t Suppression d'un compte\n\n");
printf(" Le code du compte  :");
scanf("%d",&idS);
if (rech(idS)==1)
{
do{
printf("\t\t\t     Etes vous sure \n\n");                                          	
printf(" \t\t\t1.-Oui\t\t  2.- Non\n");
scanf("%d",&rep);
}while(rep!= 1 && rep != 2);
if(rep==1){
FILE *fpt,*F;
fpt=fopen("Bank.text","r");
   F=fopen("tampBank.txt","a");
do{
test++;
fscanf(fpt,"%s\t %s\t %s\t %d\t %d %f\t",&A.nom,&A.prenom,&A.ad,&A.code,&A.tel,&A.solde);
fflush(stdin);
if(idS != A.code)
{  
fprintf(F,"%s\n %s\n %s\n %d\n %d\n %f\n\n",A.nom,A.prenom,A.ad,A.code,A.tel,A.solde);
}
}while(!feof(fpt));
fclose(fpt);
     fclose(F);
        remove("Bank.text");
        rename("tampBank.txt","Bank.text");
        printf("Ce compte a ete supprimer\n");
}
if(rep == 2)
   printf("Annulation de la suppression\n");
   }    else
          printf("Ce code n'existe pas\n");
}


//bloqueer
 void bloquer(){
 	int idB;
 	 printf("saisir le Code du compte pour le bloacage :");
scanf("%d",&idB);
if (rech(idB)==1)
{
FILE *fpt,*F;
fpt=fopen("Bank.text","r");
   F=fopen("tampBank.txt","a");
        do{
     fscanf(fpt,"%s %s %d %f\n",&A.nom,&A.prenom,&A.code,&A.solde);
     fflush(stdin);
     if(idB == A.code)
        {
       A.code=idB;                                                
    }
      fprintf(F,"%s\n %s\n %s\n %d\n %d\n %f\n\n",A.nom,A.prenom,A.ad,A.code,A.tel,A.solde);
         }while(!feof(fpt));
        fclose(fpt);
         fclose(F);
          
           printf("Ce compte a ete bloquer\n");
}
       else
    printf("Ce code n'existe pas\n");
 }
      // la focntion affichers
          void afficher(){
          	int idA;
      
   FILE *fpt,*F;
   fpt=fopen("Bank.text","r");  
printf(" ****Listes des comptes ***\n\n");	                                                 
do{
fscanf(fpt,"%s\t %s\t %s\t %d\t %d\t %f\t",&A.nom,&A.prenom,&A.ad,&A.code,&A.tel,&A.solde);
fflush(stdin);
if(fpt == NULL){
printf(" Compte vide \t");
}
else{
printf(" ** compte #%d **\n",i+1);
printf(" Nom : %s\n",A.nom);
printf(" Prenom : %s \n",A.prenom);
printf(" Adresse : %s\n",A.ad);
printf(" Code : %d\n",A.code);
printf(" Telephone : %d\n",A.tel);
printf(" Solde : %0.2f\n\n\n",A.solde);
  }

i++;
                                                 
}while(!feof(fpt));
fclose(fpt);

          }
      

