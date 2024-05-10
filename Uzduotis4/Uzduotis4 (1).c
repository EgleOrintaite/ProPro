/*
    LSP numeris: 2213778
    egleorintaite@gmail.com
    4 uzduotis
    4 variantas
*/
#include <stdio.h>
#include <Funkcijos.h>
#include <stdlib.h>
#include <assert.h>

int main()
{
    int number, list_is_created;
    node *head_list = NULL;

    while(1)
    {
        print_user_meniu();
        number = int_validation();

        if(head_list == NULL)
        {
            list_is_created = 0;
        }

        switch(number)
        {
            case 0:
            {
                head_list = create_list(head_list);

                list_is_created = 1;

                break;
            }
            case 1:
            {
                if(list_is_created)
                {
                    print_list(head_list);
                }
                else
                {
                    printf("Sarasas neegzistuoja\n");
                }
                
                break;
            }
            case 2:
            {
                if(list_is_created)
                {
                    head_list = delete_element(head_list);
                }
                else
                {
                    printf("Sarasas neegzistuoja\n");
                }
                break;
            }
            case 3:
            {         
                return 0;
                break;
            }
            default:
            {
                printf("Pasirinkta funkcija neegzistuoja\n");
                break;
            }
        }
    }
}