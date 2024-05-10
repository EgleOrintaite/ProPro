typedef struct node
{
    char *elem;
    struct node *next;
}node;


void print_user_meniu();

int int_validation();

node *create_list(node *head_list);

void print_list(node *head_list);

node *delete_element(node *head_list);
