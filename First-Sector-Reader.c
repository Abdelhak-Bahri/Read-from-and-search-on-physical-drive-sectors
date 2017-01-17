#include <stdio.h>

int main2 (int argc, char **argv)
{
  /*
    FILE *usb_ptr;
    unsigned char buffer[512];
    int i, j;

    if (argc == 1)
    {
        printf ("wot no stick?\n");
        //return -1;
    }

    //usb_ptr = fopen(argv[1],"rb");
    usb_ptr = fopen("\\\\.\\D:", "rb+");
    if(usb_ptr == NULL)
    {
        printf("error opening USB Drive for reading");
    }

    i = 0;
    while (1)
    {
        if (fread (buffer, 512,1, usb_ptr) < 1)
            break;
        //printf("\n\n\t\t\t\tok");
        i++;
        if (!(i & 127))
            printf ("%d sectors read..\r", i);
        if (buffer[0] == 'S' && buffer[1] == 'o'&& buffer[2] == 'u'&& buffer[3] == 'i'&& buffer[4] == 'c'&& buffer[5] == 'i')
        {
            for (j=0; j<32; j++)
                printf ("%02X ", buffer[j]);
            printf ("| ");
            for (j=0; j<32; j++)
            {
                if (buffer[j] >= ' ' && buffer[j] <= '~')
                    printf ("%c", buffer[j]);
                else
                    printf (".");
            }
            printf ("\n");
        }
    }

    fclose (usb_ptr);
*/
    return 0;
}





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
