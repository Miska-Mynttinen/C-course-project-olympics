#include "project.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"


void add_country (struct results *table, char *input) {

    char name[100];

    int ret = sscanf(input, "A %100s", name);

    if (ret < 1 || ret > 1) {
        printf("Wrong type of input\n");
        return;
    }

    struct results *first = (struct results *)malloc(sizeof(struct results)); 
    struct results *current = table;

    while (current->next != NULL) {
        current = current->next;
    }
    current->next = first;
    first->next = NULL;
    int len = strlen(name) + 1;
    first->name = malloc(len * sizeof(char));
    memmove(first->name, name, len);
    first->medal_1 = 0;
    first->medal_2 = 0;
    first->medal_3 = 0;
}





void update_medals (struct results *table, char *input) {

    char name[100];
    int gold, silver, bronze;
 
    int ret = sscanf(input, "M %100s %d %d %d", name, &gold, &silver, &bronze);

    if (ret < 4 || ret > 4) {
        printf("Wrong type of input\n");
        return;
    }


    //skip first NULL name//
    struct results *current = table->next;

    if (current == NULL) {
        printf("Country not found\n");
        return;
    }



    while (current->next != NULL) {
        if (strcmp(current->name, name) == 0) {
            current->medal_1 = current->medal_1 + gold;
            current->medal_2 = current->medal_2 + silver;
            current->medal_3 = current->medal_3 + bronze;
            printf("Medals updated\n");
            return; 
        }   
        current = current->next;
    }
    if (strcmp(current->name, name) == 0) {
        current->medal_1 = current->medal_1 + gold;
        current->medal_2 = current->medal_2 + silver;
        current->medal_3 = current->medal_3 + bronze;
        printf("Medals updated\n");
        return;   
    }
    if (current->next == NULL) {
        printf("Country not found\n");
    }
}


/*         Couldn't get to work
int compare (const void *a, const void *b) {

    //type change//
    struct results *first = (struct results *)a;
    struct results *second = (struct results *)b;

    int ret = strcmp(first->medal_1, second->medal_1);
    return ret;
   
     if (first->medal_1 > second->medal_1) {
        printf("%s", first->table);
        printf("%s", second->table);
        current = current->next;
    }
    if (first->medal_1 < second->medal_1) {
        printf("%s", second->table);
        printf("%s", first->table);
        current = current->next;
    }
    if (first->medal_1 == second->medal_1) {
        if (first->medal_2 > second->medal_2) {
            printf("%s", first->table);
            printf("%s", second->table);
            current = current->next;
        }
        if (current->medal_2 < current->next->medal_2) {
            printf("%s", current->table);
            printf("%s", current->next->table);
            current = current->next;
        }
    }

}*/



void print_table (struct results *table) {

    struct results *current = table;

    if (current->next == NULL) {
        printf("No countries found\n");
        return;
    }

    current = table->next;


    while (current->next != NULL) {
        printf("%s %d %d %d\n", current->name, current->medal_1, current->medal_2, current->medal_3);
        current = current->next;
    }
    //prints the last country//
    printf("%s %d %d %d\n", current->name, current->medal_1, current->medal_2, current->medal_3);


/*           Didn't work
   	while ( current->next != NULL) {
        if (current->medal_1 > current->next->medal_1) {
            printf("%s", current->table);
            printf("%s", current->next->table);
            current = current->next;
        }
        if (current->medal_1 < current->next->medal_1) {
            printf("%s", current->next->table);
            printf("%s", current->table);
            current = current->next;
        }
        if (current->medal_1 == current->next->medal_1) {
            if (current->medal_2 > current->next->medal_2) {
                printf("%s", current->table);
                printf("%s", current->next->table);
                current = current->next;
            }
            if (current->medal_2 < current->next->medal_2) {
                printf("%s", current->table);
                printf("%s", current->next->table);
                current = current->next;
            }
        }*/
}



void save_table (struct results *table, char *input) {

    char name[100];
    int ret = sscanf(input, "W %100s", name);

    if (ret < 1 || ret > 1) {
        printf("Wrong type of file name\n");
        return;
    }

    FILE *fpointer = fopen(name, "w");
    struct results *current = table->next;

    if (fpointer == NULL) {
        printf("Nothing to add to file\n");
        return;

    } else {
        while (current != NULL) {
            fprintf(fpointer,"%s %d %d %d\n", current->name, current->medal_1, current->medal_2, current->medal_3);
            current = current->next;
        }
    }
    fclose(fpointer);
    printf("Table saved to file\n");
}



/*          Didn't finish
struct results* load_table(const char *load, struct results *table) {

    char name[100];
    int ret = sscanf(input, "O %100s", name);

    if (ret < 1 || ret > 1) {
        printf("Wrong type of table in file call", load);
        return NULL;
}*/



void clean(struct results *table) {

    struct results *current = table;

    //takes next adress to ptr, cleans current address, moves ptr adress to current//
    while (current != NULL) {
        struct results *ptr = current->next;
        if (current->name != NULL) {
            free(current->name);
        }
        free(current);
        current = ptr;
    }
    table = NULL;
}



int main(void) {

    int stop = 1;

    struct results *table = malloc(sizeof(struct results));
    table->name = NULL;
    table->medal_1 = 0;
    table->medal_2 = 0;
    table->medal_3 = 0;
    table->next = NULL;



    while (stop) {
        char input[100];
        char *str = fgets(input, 100, stdin);
        if (str == NULL) {
            stop = 0;
            printf("Stopped, no input detected\n");
            break;
        }
        switch (str[0]) {
            case 'A':
                add_country(table, str);
                break;

            case 'M':
                update_medals(table, str);
                break;

            case 'L':
                print_table(table);
                break;

            case 'W':
                save_table(table, input);
                break;

            case 'O':
                printf("Load table function not finished\n");
                break;

            case 'Q':
                clean(table);
                stop = 0;
                break;


            default :
                printf("Error\n");
                break;
        }
    }
}




