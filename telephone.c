#include <stdio.h>
#include <string.h>

struct contact {
    char name[50];
    char phone[15];
};

struct contact list[100];
int count = 0;
int current = -1;

void add() {
    if(count >= 100) {
        printf("Contact list is full!\n");
        return;
    }

    printf("Enter name: ");
    scanf(" %[^\n]", list[count].name);   // allows spaces

    printf("Enter phone: ");
    scanf("%s", list[count].phone);

    count++;
    printf("Contact added successfully!\n");
}


void display() {
    if(count == 0) {
        printf("No contacts available.\n");
        return;
    }

    for(int i = 0; i < count; i++) {
        printf("%d. %s - %s\n", i + 1, list[i].name, list[i].phone);
    }
}


void search() {
    char name[50];
    printf("Enter name to search: ");
    scanf(" %[^\n]", name);

    for(int i = 0; i < count; i++) {
        if(strcmp(list[i].name, name) == 0) {
            printf("Found: %s - %s\n", list[i].name, list[i].phone);
            return;
        }
    }

    printf("Contact not found.\n");
}


void delete_contact() {
    char name[50];
    printf("Enter name to delete: ");
    scanf(" %[^\n]", name);

    for(int i = 0; i < count; i++) {
        if(strcmp(list[i].name, name) == 0) {
            for(int j = i; j < count - 1; j++) {
                list[j] = list[j + 1];
            }
            count--;
            printf("Deleted successfully!\n");
            return;
        }
    }

    printf("Contact not found.\n");
}


void update() {
    char name[50];
    printf("Enter name to update: ");
    scanf(" %[^\n]", name);

    for(int i = 0; i < count; i++) {
        if(strcmp(list[i].name, name) == 0) {
            printf("Enter new phone: ");
            scanf("%s", list[i].phone);
            printf("Updated successfully!\n");
            return;
        }
    }

    printf("Contact not found.\n");
}


void next() {
    if(count == 0) {
        printf("No contacts available.\n");
        return;
    }

    current = (current + 1) % count;
    printf("Current: %s - %s\n", list[current].name, list[current].phone);
}


void previous() {
    if(count == 0) {
        printf("No contacts available.\n");
        return;
    }

    current = (current - 1 + count) % count;
    printf("Current: %s - %s\n", list[current].name, list[current].phone);
}

int main() {
    int choice;

    while(1) {
        printf("\n1.Add\n2.Display\n3.Search\n4.Delete\n5.Update\n6.Next\n7.Previous\n8.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: add(); break;
            case 2: display(); break;
            case 3: search(); break;
            case 4: delete_contact(); break;
            case 5: update(); break;
            case 6: next(); break;
            case 7: previous(); break;
            case 8: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
