#include <stdio.h>
#include <stdlib.h>

#define IS_EMPTY(X) ((X) == NULL)

typedef struct r
{
    int data;
    struct r *up;
    struct r *down;
} row;

typedef row * rowPtr;

typedef struct c
{   
    char label; 
    struct c *next;
    struct c *prev;
    rowPtr row;
} column;

typedef column * columnPtr;

void help()
{
    printf("Enter number 1 to add a new item\n");
    printf("Enter number 3 to print your Stack\n");
    printf("Enter number 4 to Exit\n");
}

int main()
{
    columnPtr my_c = malloc(sizeof(column));

    if (IS_EMPTY(my_c))
        return 1;

    my_c->label = 'A';

    add_column(&my_c, 'B');

    int choice;

    while (1)
    {
        help();
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                int item;
                printf("Entrt Your Item to Add: ");
                scanf("%d", &item);
                
                if (item%2 == 0)
                {
                    if (my_c->label == 'B')
                        my_c = my_c->prev;
                }
                else
                {
                    if (my_c->label == 'A')
                        my_c = my_c->next;
                }

                add_data_to_column(item, &my_c);
                printf("\n\n\n\n\n");
                break;
            case 3:
                printf("colcumn : \n");
                print_all_column(&my_c);
                printf("\n\n\n\n\n");
                break;
            default:
                return 0;
                break;
        }
    }
    
}

void add_column(columnPtr *col, char label)
{
    columnPtr new_column = malloc(sizeof(column));


    if (!IS_EMPTY(new_column))
    {   
        new_column->label = label;
        
        if (IS_EMPTY((*col)->next))
        {
            (*col)->next = new_column;
            new_column->prev = (*col); 
        }
        else
        {   
            columnPtr courrent_column = (*col)->next;
            while (!IS_EMPTY(courrent_column->next))
            {
                courrent_column = courrent_column->next;
            }
            
            courrent_column->next = new_column;
            new_column->prev = courrent_column;
        }
    }
}

void add_data_to_column(int data, columnPtr *col)
{
    rowPtr my_r = malloc(sizeof(row));
    if (!IS_EMPTY(my_r))
    {   
        my_r->data = data;

        if (IS_EMPTY((*col)->row))
        {
            (*col)->row = my_r;
        }
        else 
        {   
            rowPtr prev_row = (*col)->row;
            while (prev_row->data < my_r->data && !IS_EMPTY(prev_row->down))
            {
                prev_row = prev_row->down;
            }
            prev_row->down = my_r;
            my_r->up = prev_row;
        }

    }
}

void print_all_column(columnPtr *col)
{
    
    columnPtr curent_c = *col;
    rowPtr curent_r;

    while (!IS_EMPTY(curent_c))
    {   
        printf("%c:\n", curent_c->label);
        curent_r = curent_c->row;
            while (!IS_EMPTY(curent_r))
            {
                printf("%d\n", curent_r->data);
                curent_r = curent_r->down;
            }
        printf("\n");
        curent_c = curent_c->next;
    }

    printf("\n");

}