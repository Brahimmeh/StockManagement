#include<stdio.h>
#include<stdlib.h>


typedef struct {
	
char codePr[10] ;
int QtePr;


} Produit ;

int main ()
{   printf("------------------------- DEBUT DU PROGRAMME --------------------------------------- \n");
	FILE*f,*f1,*f2;
	char Nom[50],Title[50];
	Produit liste[100],aide,ajout[100];
	int N=0,i,k,a;
	
printf("\n\n\n           ******************************Menu***************************\n");
printf("1-Classer un fichier existant \n2-Ajouter puis Classer un fichier \n ");
printf("Entrer votre choix: \n");
scanf("%d",&a);
	
while(a==2){
	
	f=fopen("Ajout.txt","w");
	printf("entrer le nom de fichier du stock a ajouter \n");
	fflush(stdin);
	gets(Nom);

	printf("entrer le nombre des produit a ajouter \n");
	scanf("%d",&N);
	fprintf(f,"Produit     Quantite\n");
	for(i=0;i<N;i++)
	{
		printf("entrer le code du produit num %d \n",i+1);
		fflush(stdin);
		gets(ajout[i].codePr);
		printf("entrer la quantite du produit '%s' \n",ajout[i].codePr);
		scanf("%d",&ajout[i].QtePr);
		if(i==(N-1))
	    fprintf(f,"%s         %d",ajout[i].codePr,ajout[i].QtePr);
        else
	    fprintf(f,"%s         %d\n",ajout[i].codePr,ajout[i].QtePr);
	}
	
	
	
	
    printf("voulez vous ajouter un autre fichier ? (repondez par 1 pour NON et 2 pour OUI ) \n ");
	scanf("%d",&a);
	fclose(f);
    rename("Ajout.txt",Nom);
}



	printf("entrer le nom du fichier souhaite a classer \n");
	fflush(stdin);
	gets(Nom);
	
	f1=fopen(Nom,"r");
	f2=fopen("aide.txt","w");
	
	
	if(f1==NULL || f2==NULL)
	{
		printf("il y a un problem d'overture \n");
		exit(1);
	}
//debut du traitement	
else
	{i=N=0;
//lecture des informations du fichier		
		fgets(Title,50,f1);
		
while(!feof(f1))
{
	fscanf(f1,"%s%d",liste[i].codePr,&liste[i].QtePr);
	N++;
	i++;
}

//trie en ordre croissant
do{k=0;

	for (i=0;i<N-1;i++)
	{  
	        

	        if(liste[i].QtePr>liste[i+1].QtePr)
	  	
	  	{ 
	  		aide=liste[i];
	  		liste[i]=liste[i+1];
	  		liste[i+1]=aide;
	  		k++;
		  }
	  }
		
	}while(k!=0);
	
//ecriture du nouvelle liste dans le fichier
	fputs(Title,f2);
	for (i=0;i<N;i++)
	fprintf(f2,"%s       %d\n",liste[i].codePr,liste[i].QtePr);
//suppression d'ancien fichier et renommer le fichier aide
fclose(f1);
fclose(f2);

remove(Nom);
rename("aide.txt",Nom);}


printf("------------------------- FIN DU PROGRAMME AUREVOIR --------------------------------------- \n");



}
