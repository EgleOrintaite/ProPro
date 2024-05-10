#include <stdio.h>
#include <Funkcijos.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int txt_validation(char name[])
{
    int strlenght = strlen(name);

    if((name[strlenght - 1] == 't') && (name[strlenght - 2] == 'x') && 
    (name[strlenght - 3] == 't') && (name[strlenght - 4] == '.'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

FILE *files(char purpose[])
{
    char name[256];
    FILE *fd = NULL;

    scanf("%s", &name);

    assert(txt_validation("input.txt") == 1);
    assert(txt_validation("input") == 0);

    while(!txt_validation(name))
    {
        printf("Netinkamai irasytas failo pavadinimas.");
        printf(" Parasykite failo pavadinima (.txt formatu)\n"); 
        scanf("%s", &name);
    }

    fd = fopen(name, purpose);

    while(fd == NULL)
    {
        printf("Failas neegzistuoja\n");
        scanf("%s", name);

        while(!txt_validation(name))
        {
            printf("Netinkamai irasytas failo pavadinimas. ");
            printf(" Parasykite failo pavadinima (.txt formatu)\n"); 
            scanf("%s", &name);
        }

        fd = fopen(name, purpose);
    }

    return fd;
}

void print_user_meniu()
{
    printf("\nIveskite norimos funkcijos numeri:\n");
    printf("0. Sukurti sarasa\n");
    printf("1. Isspaudinti sarasa\n");
    printf("2. Istrinti elementa\n");
    printf("3. Iseina is programos\n");
    printf("\nPasirinkite norima funkcija: ");
}

int int_validation()
{
    int number;

    while(1)
    {
        if((scanf("%d", &number) == 1) && (getchar() == '\n'))
        {
            return number;
        }
        else
        {
            printf("Ivestis nera taisiklinga\n");
            print_user_meniu();

            while(getchar() != '\n')
            {

            }
        }
    }
}

// dedame naujus elementus i saraso gala
void put_elements_in_list(node **head_list, char *new_elem, int lenght)
{
    node *new_list = malloc(sizeof(node));

    new_list->elem = malloc(lenght * sizeof(char));

    strcpy(new_list->elem, new_elem);

    new_list->next = NULL;

    if(*head_list == NULL)
    {
        *head_list = new_list;
        return;
    }
    else
    {
        node *temp_list = *head_list;

        while(temp_list->next != NULL)
        {
            temp_list = temp_list->next;
        }

        temp_list->next = new_list;

        return;
    }
}

node *create_list(node *head_list)
{
    printf("Parasykite failo pavadinima (.txt formatu), kuriame yra sarasas\n");
    FILE *fd = files("r");

    assert(fd != NULL);

    char *text = NULL;
    size_t lenght = 0;
    ssize_t read;

    while((read = getline(&text, &lenght, fd)) != -1)
    {
        if(text[read-1] == '\n')
        {
            read--;
            text[read] = '\0';
        }
        if(read > 0)
        {
            put_elements_in_list(&head_list, text, read);
        } 
    }

    return head_list;
}

void print_list(node *head_list)
{
    if(head_list != NULL)
    {
        printf("%s\n", head_list->elem);
        print_list(head_list->next);
    }
}

node *delete_element(node *head_list)
{
    int number, i;
    node *temp = head_list;
    i = 2;

    printf("Iveskite elemento, kuri norite istrinti, numeri:\n");
    number = int_validation();
    
    if((number == 1) && (temp != NULL))
    {
        head_list = head_list->next;
        temp->next = NULL;
        free(temp);
    }
    else
    {
        while((i < number) && (temp != NULL))
        {
            temp = temp->next;
            i++;
        }

        if(i == number)
        {
            node *del = head_list;
            del = temp->next;
            temp->next = del->next;
            free(del);
        }
        else
        {
            printf("%d elemento sarase nera\n", number);
            return head_list;
        }
    }
    
    printf("Istrinta %d elementas\n", number);
    return head_list;
}