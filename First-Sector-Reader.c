#include <stdio.h>


int lireSecteur(char* lettreDisque){
    unsigned char flux[512];
    int j;
    //modification de la lettre du disque en un chemin que Cygwin comprend
    char chaine[10];
    //printf("%s",lettreDisque);
    sprintf(chaine,"\\\\.\\%s:",lettreDisque);
    //printf("%s",chaine);
    FILE* disque = fopen(chaine, "rb+");

    if(disque == NULL)
    {
        printf("Erreur lors de la lecture du disque\n \t plus de privileges sont necessaires \n \t parametre incorrect");
    }
    if (fread (flux, 512,1, disque) < 1)
            return -1;
    for ( j=0; j<32; j++)
                printf ("%02X ", flux[j]);
            printf ("| ");
            for ( j=0; j<32; j++)
            {
                if (flux[j] >= ' ' && flux[j] <= '~')
                    printf ("%c", flux[j]);
                else
                    printf (".");
            }
            printf ("\n");


            //////////////////
            if (fread (flux, 512,1, disque) < 1)
            return -1;
    for ( j=0; j<32; j++)
                printf ("%02X ", flux[j]);
            printf ("| ");
            for ( j=0; j<32; j++)
            {
                if (flux[j] >= ' ' && flux[j] <= '~')
                    printf ("%c", flux[j]);
                else
                    printf (".");
            }
            printf ("\n");
            ////////////////

    return 0;
}


int main (int argc, char **argv)
{
    if (argc == 1)
    {
        printf ("\nErreur!... il faut préciser la lettre du disque");
        printf ("\nExemple d'utilisation: main.exe D");//Nom du programme à modifier

        return -1;
    }
   // printf("%s",argv[1]);
    return lireSecteur(argv[1]);
    //return 0;
}
