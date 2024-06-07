#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char firstName[50];
    char lastName[50];
    char phoneNumber[15];
} Contact;

void addContact(Contact contacts[], int *size) {
    if (*size >= MAX_CONTACTS) {
        printf("Książka adresowa jest pełna!\n");
        return;
    }
    printf("Podaj imię: ");
    scanf("%49s", contacts[*size].firstName);
    printf("Podaj nazwisko: ");
    scanf("%49s", contacts[*size].lastName);
    printf("Podaj numer telefonu: ");
    scanf("%14s", contacts[*size].phoneNumber);
    (*size)++;
}

void findContact(Contact contacts[], int size) {
    char lastName[50];
    printf("Podaj nazwisko do wyszukania: ");
    scanf("%49s", lastName);
    for (int i = 0; i < size; i++) {
        if (strcmp(contacts[i].lastName, lastName) == 0) {
            printf("Znaleziono: %s %s, Tel: %s\n", contacts[i].firstName, contacts[i].lastName, contacts[i].phoneNumber);
            return;
        }
    }
    printf("Nie znaleziono kontaktu o nazwisku %s.\n", lastName);
}

void deleteContact(Contact contacts[], int *size) {
    char lastName[50];
    printf("Podaj nazwisko do usunięcia: ");
    scanf("%49s", lastName);
    for (int i = 0; i < *size; i++) {
        if (strcmp(contacts[i].lastName, lastName) == 0) {
            for (int j = i; j < *size - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*size)--;
            printf("Kontakt o nazwisku %s został usunięty.\n", lastName);
            return;
        }
    }
    printf("Nie znaleziono kontaktu o nazwisku %s.\n", lastName);
}

void printContacts(Contact contacts[], int size) {
    printf("Lista kontaktów:\n");
    for (int i = 0; i < size; i++) {
        printf("%s %s, Tel: %s\n", contacts[i].firstName, contacts[i].lastName, contacts[i].phoneNumber);
    }
}

int main() {
    Contact contacts[MAX_CONTACTS];
    int size = 0;
    int choice;

    while (1) {
        printf("\n1. Dodaj kontakt\n2. Wyszukaj kontakt\n3. Usuń kontakt\n4. Wyświetl wszystkie kontakty\n5. Wyjdź\n");
        printf("Wybierz opcję: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(contacts, &size);
                break;
            case 2:
                findContact(contacts, size);
                break;
            case 3:
                deleteContact(contacts, &size);
                break;
            case 4:
                printContacts(contacts, size);
                break;
            case 5:
                return 0;
            default:
                printf("Nieprawidłowa opcja. Spróbuj ponownie.\n");
        }
    }

    return 0;
}
