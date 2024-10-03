#include <stdio.h>
#include <string.h>

typedef struct
{
    int jour;
    int mois;
    int annee;
} Date;

typedef struct
{
    char nom[20];
    char prenom[20];
    char telephone[20];
    int age;
    int id;
    int status;
    Date date;
} reservation;

reservation arr[100]; // array to store all the reservation struct
int count = 10;       // i intiallize count with because i add 10 reservation struct
int next_id = 11;    // start ID from 11

void ajouter();
void afficher();
void modifier();

void ajouter()
{
    if (count >= 100)
    {
        printf("Liste plein impossible d ajouter \n");
        return;
    }

    printf("Entrer nom: ");
    fgets(arr[count].nom, sizeof(arr[count].nom), stdin);
    arr[count].nom[strcspn(arr[count].nom, "\n")] = 0;

    printf("Entrer prenom: ");
    fgets(arr[count].prenom, sizeof(arr[count].prenom), stdin);
    arr[count].prenom[strcspn(arr[count].prenom, "\n")] = 0;

    printf("Entrer telephone: ");
    fgets(arr[count].telephone, sizeof(arr[count].telephone), stdin);
    arr[count].telephone[strcspn(arr[count].telephone, "\n")] = 0;

    printf("Entrer age: ");
    scanf("%d", &arr[count].age);
    getchar();

    do
    {
        printf("Choisir le status:\n");
        printf("1. Annuler\n");
        printf("2. Reporté\n");
        printf("3. traite\n");
        printf("4. valider\n");
        printf("Veuillez choisir (1-4): ");
        scanf("%d", &arr[count].status);
        getchar();

        if (arr[count].status < 1 || arr[count].status > 4)
        {
            printf("Choix invalide, veuillez réessayer.\n");
        }
    } while (arr[count].status < 1 || arr[count].status > 4);

    printf("Entrer date (jour/mois/annee): ");
    scanf("%d/%d/%d", &arr[count].date.jour, &arr[count].date.mois, &arr[count].date.annee);
    getchar();
    arr[count].id = next_id++;
    count++;
    printf("--- Contact ajouté avec succès ---\n");
    printf("count %d ", count);
}

void afficher()
{
    for (int i = 0; i < count; i++)
    {
        printf("ID : %d ,Nom: %s, Prénom: %s, Téléphone: %s, Age: %d, Date: %02d/%02d/%04d ,indice %d \n",
                
               arr[i].id,
               arr[i].nom,
               arr[i].prenom,
               arr[i].telephone,
               arr[i].age,
               arr[i].date.jour, arr[i].date.mois, arr[i].date.annee , i);
        switch (arr[i].status)
        {
        case 1:
            printf("Statut: anuller\n");
            break;
        case 2:
            printf("Statut: reporté\n");
            break;
        case 3:
            printf("Statut: traiter \n");
            break;
        case 4:
            printf("Statut: valider\n");
            break;
        default:
            break;
        }
    }
}

void details(int id)
{
    printf("Nom: %s\n", arr[id].nom);
    printf("Prenom: %s\n", arr[id].prenom);
    printf("Téléphone: %s\n", arr[id].telephone);
    printf("Âge: %d\n", arr[id].age);
    switch (arr[id].status)
    {
    case 1:
        printf("Statut: anuller\n");
        break;
    case 2:
        printf("Statut: reporté\n");
        break;
    case 3:
        printf("Statut: traiter \n");
        break;
    case 4:
        printf("Statut: valider\n");
        break;
    default:
        break;
    }
    printf("Date de réservation : %d/%d/%d\n", arr[id].date.jour, arr[id].date.mois, arr[id].date.annee);
}

void modifier()
{
    int id, found = 0;
    char reponse;

    printf("Entrer l'ID ");
    scanf("%d", &id);
    getchar();
    //change count to next_id 
    if (id <= 0 || id > next_id)
    {
        printf("ID invalide.\n");
        return;
    }

    //id; // c est decrementation parceque l utilsateur doit chercher avec 1 mais l indice du tableau debut avec 0

    for (int i = 0; i < count; i++)
    {
        if (id == arr[i].id)
        {

            found = 1;
            printf("--- Avant modification ---\n");
            details(i);
            printf("--------------------------\n");

            printf("Entrer nouveau nom: ");
            fgets(arr[id].nom, sizeof(arr[id].nom), stdin);
            arr[id].nom[strcspn(arr[id].nom, "\n")] = 0;

            printf("Entrer nouveau prénom: ");
            fgets(arr[id].prenom, sizeof(arr[id].prenom), stdin);
            arr[id].prenom[strcspn(arr[id].prenom, "\n")] = 0;

            printf("Entrer nouveau téléphone: ");
            fgets(arr[id].telephone, sizeof(arr[id].telephone), stdin);
            arr[id].telephone[strcspn(arr[id].telephone, "\n")] = 0;

            printf("Entrer nouvel âge: ");
            scanf("%d", &arr[id].age);
            getchar();

            do
            {
                printf("les status se sont : ['annuler','reporté','traiter','valider']\n");
                printf("Entrer nouveau status (1-4): ");
                scanf("%d", &arr[id].status);
                getchar();

                if (arr[id].status < 1 || arr[id].status > 4)
                {
                    printf("Statut invalide, veuillez réessayer.\n");
                }
            } while (arr[id].status < 1 || arr[id].status > 4);

            printf("Entrer nouvelle date (jour/mois/année): ");
            scanf("%d/%d/%d", &arr[id].date.jour, &arr[id].date.mois, &arr[id].date.annee);
            getchar();
            printf("Modification réussie pour l'ID %d.\n", id);

            printf("Voulez-vous voir la modification (y/n): ");
            scanf(" %c", &reponse);
            if (reponse == 'y' || reponse == 'Y')
            {
                details(id);
            }
        }
    }
    if (!found)
    {
        printf("id no");
    }
}

void supprimer()
{
    int id, found = 0;
    printf("entrer l id : ");
    scanf("%d", &id);
    getchar();
    
    if (id <= 0 || id > count) {
        printf("ID invalide.\n");
        return;
    }
    
    for (int i = 0; i < count; i++)
    {
        if (arr[i].id == id)
        {
            found = 1;
            for (int j = i; j < count - 1; j++) {
                arr[j] = arr[j + 1];
            }
            count--;
            printf("Reservation supprimée avec succès.\n");
            break;
        }
    }

    if (!found)
    {
        printf("ID non trouvé.\n");
    }
   
}


void triParNom()
{
    reservation tmp;
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (strcmp(arr[i].nom, arr[j].nom) > 0)
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    afficher();
}

// the validation is 4 and annuller is 1 tri les status valider on top est les status anuller on bot
void triParStatus()

{
    reservation tmp;
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (arr[i].status < arr[j].status)
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    afficher();
}

void reservNom()
{
    char name[20];
    int found = 0;
    printf("entrer le nom : ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;
    for (int i = 0; i < count; i++)
    {
        if (strcmp(name, arr[i].nom) == 0)
        {
            found = 1;
            printf("Nom: %s\n", arr[i].nom);
            printf("Prenom: %s\n", arr[i].prenom);
            printf("Téléphone: %s\n", arr[i].telephone);
            printf("Âge: %d\n", arr[i].age);
            switch (arr[i].status)
            {
            case 1:
                printf("Statut: annuler\n");
                break;
            case 2:
                printf("Statut: reporté\n");
                break;
            case 3:
                printf("Statut: traiter \n");
                break;
            case 4:
                printf("Statut: valider\n");
                break;
            default:
                break;
            }
            printf("Date de réservation : %d/%d/%d\n", arr[i].date.jour, arr[i].date.mois, arr[i].date.annee);
        }
    }
}

void rechercheId()
{
    int id, found = 0;
    printf("enter recherche id : ");
    scanf("%d", &id);
    getchar();

    if (id <= 0 || id > count)
    {
        printf("ID invalide.\n");
        return;
    }
    id--;
    for (int i = 0; i < count; i++)
    {
        if (id == i)
        {
            found = 1;
            details(id);
        }
    }
}

void moyeneAge()
{
    int somme = 0, i;
    for (i = 0; i < count; i++)
    {
        somme = somme + arr[i].age;
    }
    printf("moyenne d age et : %d ", somme / count);
}

void agetranch()
{
    int ag1 = 0, ag2 = 0, ag3 = 0;
    for (int i = 0; i < count; i++)
    {
        if (arr[i].age >= 1 && arr[i].age <= 18)
        {
            ag1++;
        }
        else if (arr[i].age >= 19 && arr[i].age <= 35)
            ag2++;
        else
        {
            ag3++;
        }
    }
    printf("le nombre des patient d age enter 1 et 18 sont %d  ", ag1);
    printf("le nombre des patient d age enter 19 et 35 sont %d  ", ag2);
    printf("le nombre des patient d age 36+ sont %d  ", ag3);
}

void nbS()
{
    int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
    for (int i = 0; i < count; i++)
    {
        if (arr[i].status == 1)
        {
            s1++;
        }
        else if (arr[i].status == 2)
            s2++;
        else if (arr[i].status == 3)
        {
            s3++;
        }
        else if (arr[i].status == 4)
        {
            s4++;
        }
    }
    printf("le nombre des status annuller sont %d  ", s1);
    printf("le nombre des status report sont %d  ", s2);
    printf("le nombre des status traiter sont %d  ", s3);
    printf("le nombre des status valider sont %d  ", s4);
}

int main()
{
    int choix, choixtri, choixRech, choixSt , id;
    strcpy(arr[0].nom, "azzedine");
    strcpy(arr[0].prenom, "zemmari");
    strcpy(arr[0].telephone, "0767338591");
    arr[0].age = 20;
    arr[0].id = 1;
    arr[0].status = 4;
    arr[0].date.jour = 20;
    arr[0].date.mois = 4;
    arr[0].date.annee = 2024;

    strcpy(arr[1].nom, "ilyas");
    strcpy(arr[1].prenom, "bahsi");
    strcpy(arr[1].telephone, "039303930");
    arr[1].age = 21;
    arr[1].id = 2;
    arr[1].status = 2;
    arr[1].date.jour = 21;
    arr[1].date.mois = 2;
    arr[1].date.annee = 2002;

    strcpy(arr[2].nom, "mohamed");
    strcpy(arr[2].prenom, "chnani");
    strcpy(arr[2].telephone, "94894984948");
    arr[2].age = 10;
    arr[2].id = 3;
    arr[2].status = 2;
    arr[2].date.jour = 21;
    arr[2].date.mois = 2;
    arr[2].date.annee = 2025;

    strcpy(arr[3].nom, "jad");
    strcpy(arr[3].prenom, "jaiti");
    strcpy(arr[3].telephone, "93839383938");
    arr[3].age = 20;
    arr[3].id = 4;
    arr[3].status = 3;
    arr[3].date.jour = 22;
    arr[3].date.mois = 2;
    arr[3].date.annee = 2025;

    strcpy(arr[4].nom, "fatima");
    strcpy(arr[4].prenom, "bennani");
    strcpy(arr[4].telephone, "0612345678");
    arr[4].age = 25;
    arr[4].id = 5;
    arr[4].status = 1;
    arr[4].date.jour = 15;
    arr[4].date.mois = 5;
    arr[4].date.annee = 2025;

    strcpy(arr[5].nom, "sara");
    strcpy(arr[5].prenom, "sara");
    strcpy(arr[5].telephone, "0654321987");
    arr[5].age = 35;
    arr[5].id = 6;
    arr[5].status = 4;
    arr[5].date.jour = 10;
    arr[5].date.mois = 6;
    arr[5].date.annee = 2025;

    strcpy(arr[6].nom, "youssef");
    strcpy(arr[6].prenom, "mouham");
    strcpy(arr[6].telephone, "0701234567");
    arr[6].age = 40;
    arr[6].id = 7;
    arr[6].status = 2;
    arr[6].date.jour = 5;
    arr[6].date.mois = 7;
    arr[6].date.annee = 2025;

    strcpy(arr[7].nom, "khalid");
    strcpy(arr[7].prenom, "ben");
    strcpy(arr[7].telephone, "0712345678");
    arr[7].age = 50;
    arr[7].id = 8;
    arr[7].status = 3;
    arr[7].date.jour = 25;
    arr[7].date.mois = 8;
    arr[7].date.annee = 2025;

    strcpy(arr[8].nom, "noura");
    strcpy(arr[8].prenom, "el");
    strcpy(arr[8].telephone, "0723456789");
    arr[8].age = 60;
    arr[8].id = 9;
    arr[8].status = 1;
    arr[8].date.jour = 30;
    arr[8].date.mois = 9;
    arr[8].date.annee = 2025;

    strcpy(arr[9].nom, "amine");
    strcpy(arr[9].prenom, "zemmari");
    strcpy(arr[9].telephone, "202920220");
    arr[9].age = 45;
    arr[9].id = 10;
    arr[9].status = 2;
    arr[9].date.jour = 21;
    arr[9].date.mois = 2;
    arr[9].date.annee = 2025;

    do
    {
        printf("--- Menu ---\n");
        printf("1. Ajouter\n");
        printf("2. Afficher\n");
        printf("3. modifier\n");
        printf("4. supprimer\n");
        printf("5. details\n");
        printf("6. le tri\n");
        printf("7. rechercher\n");
        printf("8. statistique\n");
        printf("8. quiter\n");
        printf("Veuillez entrer un choix: ");
        scanf("%d", &choix);
        getchar();

        switch (choix)
        {
        case 1:
            ajouter();
            break;
        case 2:
            afficher();
            break;
        case 3:
            modifier();
            break;
        case 4:
            supprimer();
            break;
        case 5:
            printf("enter l id : ");
            scanf("%d" , &id);
            getchar();
            if (id > 0 && id <= next_id) {
        details(id-1); // Convert to zero-based index
    } else {
        printf("ID non reconnu.\n");
    }
            break;
        case 6:
            do
            {
                printf("---- le tri ----\n");
                printf("1.tri par nom \n");
                printf("2.tri par status \n");
                printf("3.return \n");
                scanf("%d", &choixtri);
                getchar();
                switch (choixtri)
                {
                case 1:
                    triParNom();
                    break;
                case 2:
                    triParStatus();
                    break;
                case 3:
                    break;
                default:
                    printf("veuillez entrez un choix exists ");
                    break;
                }
            } while (choixtri != 3);
            break;
        case 7:
            do
            {
                printf("---rechercher---\n");
                printf("1.recherche par nom \n");
                printf("2.recherche par id \n");
                printf("3.retour\n");
                printf("enter le choix : ");
                scanf("%d", &choixRech);
                getchar();
                switch (choixRech)
                {
                case 1:
                    reservNom();
                    break;
                case 2:
                    rechercheId();
                    break;
                case 3:
                    break;
                default:
                    printf("choix invalid \n");
                    break;
                }
            } while (choixRech != 3);
            break;
        case 8:
            do
            {
                printf("---statistique---\n");
                printf("1.moyenne d age des patient \n");
                printf("2.le nombre des tranche d age \n");
                printf("3.le nombre total de chaque status \n");
                printf("4.retourn\n");
                printf("entrer votre choix ");
                scanf("%d", &choixSt);
                switch (choixSt)
                {
                case 1:
                    moyeneAge();
                    break;
                case 2:
                    agetranch();
                    break;
                case 3:
                    nbS();
                    break;
                case 4:
                    break;
                default:
                    printf("choix invalid \n");
                    break;
                }
            } while (choixSt != 4);
            break;
        case 9:
            printf("Quitter.\n");
            break;
        default:
            printf("Choix invalide.\n");
            break;
        }
    } while (choix != 9);
    return 0;
}
