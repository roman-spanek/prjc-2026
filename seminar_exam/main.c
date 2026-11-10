#include <stdio.h>
#include <stdlib.h>

/* Jeden uzel seznamu = jedno slovo. */
typedef struct Node {
    char *word;          /* ukazatel na začátek slova (ukazuje do vstupního textu) */
    struct Node *next;   /* další uzel, NULL u posledního */
} Node;

/* Seznam slov. */
typedef struct {
    Node *head;          /* první uzel, NULL pro prázdný seznam */
} List;

void list_init(List *list) {
    list->head = NULL;
}

/*
 * 1) Tokenizace.
 *    Text se rozdělí "na místě": každý oddělovač se přepíše znakem '\0'
 *    a pro každé slovo se vytvoří uzel, který ukazuje na jeho začátek.
 *    Slova se nekopírují, text musí existovat po celou dobu života seznamu.
 */
int tokenize(char *in, char delimiter, List *list) {
    if (in == NULL || list == NULL || delimiter == '\0') {
        return -1;
    }

    Node *tail = NULL;       /* poslední uzel, ke kterému se připojuje další */
    char *p = in;

    while (*p != '\0') {
        /* přeskoč oddělovače před slovem */
        while (*p == delimiter) {
            p++;
        }
        if (*p == '\0') {
            break;
        }

        /* nový uzel pro slovo, které začíná na p */
        Node *node = malloc(sizeof(Node));
        if (node == NULL) {
            return -1;
        }
        node->word = p;
        node->next = NULL;

        if (tail == NULL) {
            list->head = node;
        } else {
            tail->next = node;
        }
        tail = node;

        /* najdi konec slova */
        while (*p != '\0' && *p != delimiter) {
            p++;
        }
        if (*p == delimiter) {
            *p = '\0';       /* ukonči slovo */
            p++;
        }
    }
    return 0;
}

/*
 * 2) Zamíchání.
 *    Prohodí slovo na indexu i se slovem na indexu i+1 pro i = 0, 2, 4, ...
 *    (první s druhým, třetí se čtvrtým atd.). Při lichém počtu slov zůstane
 *    poslední slovo na místě.
 *    Prohazují se jen ukazatele word, samotná slova se nekopírují.
 */
void shuffle(List *list) {
    Node *node = list->head;
    while (node != NULL && node->next != NULL) {
        char *tmp = node->word;
        node->word = node->next->word;
        node->next->word = tmp;

        node = node->next->next;     /* přeskoč na další dvojici */
    }
}

/* 3) Výpis tokenizovaného textu (slova oddělená mezerou). */
void print_list(List *list) {
    for (Node *node = list->head; node != NULL; node = node->next) {
        if (node != list->head) {
            printf("%c", ' ');
        }
        printf("%s",node->word);
    }
    printf("\n");
}

int main(void) {
    char text[] = "Dnes je krasny den pro programovani v jazyce C";
    List list;
    list_init(&list);

    if (tokenize(text, ' ', &list) != 0) {
        fprintf(stderr, "Chyba pri tokenizaci\n");
        return 1;
    }
    printf("Puvodni text:\n  ");
    print_list(&list);

    shuffle(&list);
    printf("Po zamichani:\n  ");
    print_list(&list);
    return 0;
}
