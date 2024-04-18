#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct liste{
int info;
struct liste *suivant;
}liste;

                                                 //Prototype des fonctions
//La fonction d'initialisation
void initialiser(liste *tete);
//les fonctions de supression
void supprimer();
liste * supprimerF(liste * tete);
liste * supprimerM(liste *tete);
liste* supprimerD (liste * tete);
liste *supprimerAV(liste *tete);
liste *supprimerAP(liste *tete);
//les fonctions d'ajout
void ajouter();
liste* ajouterD(liste *tete);
liste * ajouterF(liste * tete);
liste * ajouterAP(liste * tete);
liste * ajouterAV(liste * tete);
//la fonction de recherche
void rechercher(liste *tete,int v);
//la fonction d'affichage
void afficher(liste *tete);
//la fonction de modification
liste *modifier(liste *tete, int x, int y);
//la fonction du menu principal
void MenuPrincipal();
//La fonction du tri
void trier(liste *tete);

//Menu supprimer
void supprimer(){
int choixs;
liste* tete=NULL;
 printf("\n\n");
    printf("\t\t\t\t\t*****Gestion de suppression*****\n\n\n ");
    printf("\t\t\t\t\t1- Supprimer au debut \n\n");
    printf("\t\t\t\t\t2- Supprimer a la fin\n\n");
	printf("\t\t\t\t\t3- Supprimer avant un element \n\n");
	printf("\t\t\t\t\t4- Supprimer apres un element\n\n");
	printf("\t\t\t\t\t5- Supprimer un element de votre choix\n\n");
	printf("\t\t\t\t\t6- Retour au menu principal\n\n");
	do{
		printf("\t\t\t Choix: ");
		scanf("%d",&choixs);
	}while(choixs>6 || choixs<1);
	if(choixs==1){
		system("cls");
		supprimerD(tete);
		supprimer();
	}
	else if(choixs==2){
		system("cls");
		supprimerF(tete);
		supprimer();
	}
	else if(choixs==3)
	{
	    system("cls");
		supprimerAV;
		supprimer();
	}
	else if (choixs==4)
	{
	    system("cls");
		supprimerAP;
		supprimer();
	}
	else if (choixs==5){
		system("cls");
		supprimerM;
		supprimer();
	}
	else if (choixs==6){
		MenuPrincipal();
	}
}


//Menu ajouter
void ajouter(){
int choixa;
liste* tete;
 printf("\n\n");
    printf("\t\t\t\t\t*****Gestion d'ajout*****\n\n\n ");
    printf("\t\t\t\t\t1- Ajouter au debut \n\n");
    printf("\t\t\t\t\t2- Ajouter a la fin\n\n");
	printf("\t\t\t\t\t3- Ajouter avant un element \n\n");
	printf("\t\t\t\t\t4- Ajouter apres un element\n\n");
	printf("\t\t\t\t\t5- Retour au menu principal\n\n");
	do{
		printf("\t\t\t Choix: ");
		scanf("%d",&choixa);
	}while(choixa>5 || choixa<1);
	if(choixa == 1){
		system("cls");
		tete = ajouterD(tete);
		ajouter();
	}
	else if(choixa==2){
		system("cls");
		tete = ajouterF(tete);
		ajouter();
	}
	else if(choixa == 3)
	{
	    system("cls");
		tete=ajouterAV(tete);
		ajouter();
	}
	else if (choixa==4)
	{
	    system("cls");
		tete=ajouterAP(tete);
		ajouter();
	}
	else if (choixa==5){
		MenuPrincipal();
	}

}

//la fonction de modification
liste *modifier(liste *tete){
liste *p ;
  int trouve=0;
  int v;int y;
  printf("Donnez l'element que vous voulez changer\n");
  scanf("%d",&v);
  printf("Donnez la nouvelle valeur\n");
  scanf("%d",&y);
  if(tete!=NULL){
  	p=tete;
  	while(p!=NULL && trouve==0){
	if(p->info==v){

	trouve=1;
}
	   else{
	   p=p->suivant;
	   }
  }
if(trouve==1){
	p->info=y;
}else printf("%d n'existe pas dans la liste\n",v);
return tete;}}

//Trier
void trier(liste *tete)
{
liste *p, *q, *min;
int aide;
for(p=tete ; p->suivant!=NULL ; p=p->suivant)
{
min=p;
for(q=p->suivant ; q!=NULL ; q=q->suivant)
{
if(q->info < min->info)
{
min=q;
}
}
aide=p->info;
p->info = min->info;
min->info = aide;
}
} 


void initialiser(liste *tete){
	tete=NULL;
}


//Ajouter au debut
liste* ajouterD(liste *tete){
int v;
printf("Donnez l'element a ajouter au debut\n");
scanf("%d",&v);
liste *p=(liste*)malloc(sizeof(liste));
p->info=v;
p->suivant=tete;
}


//Ajouter a la fin
liste * ajouterF(liste * tete)
{
  int v;
  printf("Donnez l'element a ajouter a la fin \n");
  scanf("%d",&v);
  liste * p=(liste *) malloc(sizeof(liste));
  p->info=v;
  p->suivant=NULL;
  if(tete==NULL)
     return p;
  else
   {
     liste * parcours=tete;
     while(parcours->suivant!=NULL)
      parcours=parcours->suivant;
     parcours->suivant=p;
   }
   return tete;

}

//Ajouter avant 
liste *ajouterAV(liste *tete){
	liste *precedent,*parcours,*p;
	int trouve=0,v;
printf("Donnez l'element que vous cherchez\n");
scanf("%d",&v);
if(tete!=NULL){
	parcours=tete;
	precedent=NULL;
	trouve=0;
if(parcours->info==v){
	p=ajouterD(tete);
	return p;
}	
while(parcours!=NULL && trouve==0){
	if(parcours->info==v){
		trouve=1;
	}else{
		precedent=parcours;
		parcours=parcours->suivant;
	}
if(trouve=1){
	p=(liste*)malloc(sizeof(liste));
	printf("Donnez la valeur que vous voulez ajouter avant %d\n",v);
	scanf("%d",&p->info);
	p->suivant=precedent->suivant;
	precedent->suivant=p;
}else {printf("%d n'existe pas dans la liste\n",v);}
}
}else("La liste est vide\n");
}	

//Afficher la liste
void afficher(liste * tete)
{
 liste * p=tete;
  while(p!=NULL)
  {

     printf("%d\t\t",p->info);
     p=p->suivant;
  }

printf("\n");
}

//Rechercher dans la liste
void rechercher(liste *tete)
{
  int x;
  liste *p ;
  printf("Donnez l'element que vous cherchez\n");
  scanf("%d",&x);
  int trouve=0;
  if(tete!=NULL){
  	p=tete;
  	while(p!=NULL && trouve==0){
	if(p->info==x){

	trouve=1;
	printf("%d se trouve dans la liste\n",x);
}
	   else{
	   p=p->suivant;
	   }
  }
}


}
//supprimer un element donn� par l'utilisateur
liste * supprimerM(liste *tete)
{
    int x;
    printf("\nDonnez l'element que vous voulez supprimer\n");
    scanf("%d",&x);
    if(tete->info==x){
      return supprimerD(tete);}
    else
     {
       liste * parcours=tete;
       while((parcours->suivant)->info!=x)
         parcours=parcours->suivant;
       parcours->suivant= (parcours->suivant)->suivant;
       return tete;
     }

  return tete;


}



//supprimer au debut
liste* supprimerD (liste * tete){
  liste *p=NULL;
  if(tete!=NULL){
  	p=tete;
  	p=p->suivant;
  	tete=tete->suivant;
  	
    }
else {
printf("La liste est vide");}
return tete;
}

//supprimer a la fin
liste * supprimerF(liste * tete)
{
   if(tete==NULL || tete->suivant ==NULL)
     return NULL;
   else
    {
       liste * parcours=tete;
       while((parcours->suivant)->suivant!=NULL)
         parcours=parcours->suivant;
       parcours->suivant=NULL;
       return tete;
    }

}


//supprimer apr�s un element
liste *supprimerAP (liste *tete){
	int x;
	printf("Donnez l'element que vous chercher\n");
    scanf("%d",&x);
	liste *p=tete,*asupp;
	while(p->info!=x && p->suivant!=NULL){
	p=p->suivant;
	}
	if(p->suivant!=NULL){
		asupp=p->suivant;
		p->suivant=p->suivant->suivant;
		free(asupp);
	}else printf("Element introuvable\n");
}






//supprimer avant un element
liste *supprimerAV(liste *tete){
	liste *asupp,*p=tete;
	int x;
	printf("Donnez l'element que vous chercher\n");
    scanf("%d",&x);
	if(tete->suivant->info!=x){
		while(p->suivant->suivant->info!=x && p!=NULL)
		p=p->suivant;
	}
	if(p!=NULL){
	asupp=p->suivant;
	p->suivant=p->suivant->suivant;
	free(asupp);
	}
	else{
		asupp=tete->suivant;
		tete->suivant=tete->suivant->suivant;
		free(asupp);
	}
	return tete;


}

//ajouter apres un element
liste * ajouterAP(liste * tete)
{
  int v;int y;
  printf("Donnez l'element que vous chercher\n");
  scanf("%d",&y);
  printf("Donnez la valeur que vous voulez ajouter apres %d\n",y);
  scanf("%d",&v);
  liste * p=(liste *) malloc(sizeof(liste));
  p->info=v;
  liste * parcours=tete;
  while(parcours->info!=y)
     parcours=parcours->suivant;
  p->suivant=parcours->suivant;
  parcours->suivant=p;
  return tete;

}
//Le Menu principal
//Menu principal
void MenuPrincipal(){
 int choix;
 liste *tete;
 int z,n;
system("color f0");


    system("cls");
    printf("\n\n");
    printf("\t\t\t\t\t*****Gestion des listes*****\n\n\n ");
    printf("\t\t\t\t\t1- Initialisation de la liste \n\n");
    printf("\t\t\t\t\t2- Ajouter a la liste\n\n");
	printf("\t\t\t\t\t3- Rechercher dans la liste \n\n");
	printf("\t\t\t\t\t4- Modifier la liste\n\n");
    printf("\t\t\t\t\t5- Supprimer de la liste \n\n");
    printf("\t\t\t\t\t6- Afficher la liste \n\n");
    printf("\t\t\t\t\t7- Trier la liste \n\n");
    printf("\t\t\t\t\t8- Quitter \n\n");
    do{
		printf("\t\t\t Choix: ");
		scanf("%d",&choix);
	}while(choix>8 || choix<1);
	switch(choix){
		case 1:
			printf("");
		    system("cls");
            initialiser(tete);
            MenuPrincipal();
			break;
	case 2:
		    system("cls");
			printf("\n\n");
    printf("\t\t\t\t\t*****Gestion d'ajout*****\n\n\n ");
    printf("\t\t\t\t\t1- Ajouter au debut \n\n");
    printf("\t\t\t\t\t2- Ajouter a la fin\n\n");
	printf("\t\t\t\t\t3- Ajouter avant un element \n\n");
	printf("\t\t\t\t\t4- Ajouter apres un element\n\n");
	printf("\t\t\t\t\t5- Retour au menu principal\n\n");
	do{
		printf("\t\t\t Choix: ");
		scanf("%d",&choix);
	}while(choix>5 || choix<1);
	if(choix==1){
		system("cls");
		tete=ajouterD(tete);
		MenuPrincipal();
	}
	else if(choix==2){
		system("cls");
		tete=ajouterF(tete);
		MenuPrincipal();
	}
	else if(choix==3)
	{
	    system("cls");
		tete=ajouterAV(tete);
		MenuPrincipal();
	}
	else if (choix==4)
	{
	    system("cls");
		tete=ajouterAP(tete);
		MenuPrincipal();
	}
	else if (choix==5){
		MenuPrincipal();
	}

			break;
		case 3:
		    system("cls");
			rechercher(tete);
			MenuPrincipal();
			break;
        case 4:
            system("cls");
            modifier(tete);
            break;
       case 5:
		    system("cls");
			supprimer();
		    break;
        case 6:
		    system("cls");
            afficher(tete);
            break;
 /*       case 7:
		    system("cls");
            trier(tete);
            break;*/
        case 8:
		    exit(0);
            break;
}
}






main(){
int a;
liste *tete;
tete=NULL;
system("color f0");
printf("Je n'est pas fais un menu car je n'ai pas reussi, Pour cela j'ai fait un programme qui teste toutes les fonctions une par une\n\n\n");

printf("\t\t\t\t****Test de la fonction ajouter au debut****\n");
tete=ajouterD(tete);
system("pause");
printf("L'affichage apres l'ajout du premier element\n");
afficher(tete);

printf("\t\t\t\t****Test de la fonction ajouter a la fin****\n");
printf("Ajoutez 7 valeurs par hasard\n");
for(a=0;a<7;a++){
tete=ajouterF(tete);
}
system("pause");
printf("L'affichage apres l'ajout de 7 elements\n");
afficher(tete);
printf("\t\t\t\t********Test de la fonction ajouter avant un element********\n");
ajouterAV(tete);
system("pause");
printf("L'affichage apres l'ajout d'un element avant\n");
afficher(tete);
printf("\t\t\t\t********Test de la fonction ajouter apres un element********\n");
ajouterAP(tete);
system("pause");
printf("L'affichage apres l'ajout d'un element apres\n");
afficher(tete);
system("pause");
printf("\t\t\t\t********Test de la fonction chercher********\n");
rechercher(tete);
system("pause");
printf("\t\t\t\t********Test de la fonction modifier********\n");
modifier(tete);
system("pause");
printf("L'affichage apres la modification\n");
afficher(tete);
system("pause");
printf("\t\t\t\t********Test de la fonction supprimer a la fin********\n");
supprimerF(tete);
system("pause");
printf("L'affichage apres la suppresion\n");
afficher(tete);
system("pause");
printf("\t\t\t\t********Test de la fonction supprimer avant un element********\n");
supprimerAV(tete);
system("pause");
printf("L'affichage apres la suppresion\n");
afficher(tete);
system("pause");
printf("\t\t\t\t********Test de la fonction supprimer apres un element********\n");
supprimerAP(tete);
system("pause");
printf("L'affichage apres la suppresion\n");
afficher(tete);system("pause");
printf("\t\t\t\t********Test de la fonction supprimer au milieu********\n");
supprimerM(tete);
system("pause");
printf("L'affichage apres la suppresion\n");
afficher(tete);
system("pause");
printf("\t\t\t\t********Test de la fonction trier********\n");
printf("L'affichage avant le tri\n");
afficher(tete);
system("pause");
printf("L'affichage apres le tri\n");
trier(tete);
afficher(tete);
}
