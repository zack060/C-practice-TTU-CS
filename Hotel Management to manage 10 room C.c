#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_ROOMS 10

struct customer {
    char username[50];
    char lastname[50];
    char email[50];
    char address[100];
    char phone[20];
};

struct room {
    int room_number;
    int status;
    struct customer customer_details;
    char check_in[20];
    char check_out[20];
};

struct room hotel_rooms[MAX_ROOMS];

void book_room() {
    int room_number;
    printf("Enter the room number (1-10): ");
    scanf("%d", &room_number);

    if (room_number < 1 || room_number > 10) {
        printf("Invalid room number. Please try again.\n");
        return;
    }

    struct room *room = &hotel_rooms[room_number - 1];

    if (room->status == 1) {
        printf("Room already booked.\n");
        return;
    }

    room->status = 1;
    room->room_number = room_number;

    struct customer customer_details;
    printf("Enter customer details:\n");
    printf("Username: ");
    scanf(" %[^\n]", customer_details.username);
    printf("Last name: ");
    scanf(" %[^\n]", customer_details.lastname);
    printf("Email: ");
    scanf(" %[^\n]", customer_details.email);
    printf("Address: ");
    scanf(" %[^\n]", customer_details.address);
    printf("Phone: ");
    scanf(" %[^\n]", customer_details.phone);
    room->customer_details = customer_details;

    printf("Enter check-in date (dd/mm/yyyy): ");
    scanf(" %s", room->check_in);
    printf("Enter check-out date (dd/mm/yyyy): ");
    scanf(" %s", room->check_out);

    printf("Room %d has been booked.\n", room_number);
}
void view_customer_details() {
    int room_number;
    printf("Enter the room number (1-10): ");
    scanf("%d", &room_number);

    if (room_number < 1 || room_number > 10) {
        printf("Invalid room number. Please try again.\n");
        return;
    }

    struct room room = hotel_rooms[room_number - 1];

    if (room.status == 0) {
        printf("Room %d is vacant.\n", room_number);
        return;
    }

    printf("Customer details for Room %d:\n", room_number);
    printf("Username: %s\n", room.customer_details.username);
    printf("Last name: %s\n", room.customer_details.lastname);
    printf("Email: %s\n", room.customer_details.email);
    printf("Address: %s\n", room.customer_details.address);
    printf("Phone: %s\n", room.customer_details.phone);
    printf("Check-in date: %s\n", room.check_in);
    printf("Check-out date: %s\n", room.check_out);
}
void edit_customer_details() {
    int room_number;
    printf("Enter the room number (1-10): ");
    scanf("%d", &room_number);

    if (room_number < 1 || room_number > 10) {
        printf("Invalid room number. Please try again.\n");
        return;
    }

    struct room *room = &hotel_rooms[room_number - 1];

    if (room->status == 0) {
        printf("Room %d is vacant.\n", room_number);
        return;
    }

    printf("Current customer details for Room %d:\n", room_number);
    printf("Username: %s\n", room->customer_details.username);
    printf("Last name: %s\n", room->customer_details.lastname);
    printf("Email: %s\n", room->customer_details.email);
    printf("Address: %s\n", room->customer_details.address);
    printf("Phone: %s\n", room->customer_details.phone);
    printf("Check-in date: %s\n", room->check_in);
    printf("Check-out date: %s\n", room->check_out);

    printf("Enter new customer details for Room %d:\n", room_number);
    printf("Username: ");
    scanf(" %[^\n]", room->customer_details.username);
    printf("Last name: ");
    scanf(" %[^\n]", room->customer_details.lastname);
    printf("Email: ");
    scanf(" %[^\n]", room->customer_details.email);
    printf("Address: ");
    scanf(" %[^\n]", room->customer_details.address);
    printf("Phone: ");
    scanf(" %[^\n]", room->customer_details.phone);

    printf("Customer details for Room %d have been updated.\n", room_number);
}
int date_to_int(char* date) {
    int year, month, day;
    sscanf(date, "%d-%d-%d", &year, &month, &day);
    return 1 * year + 100 * month + day;
}

int get_num_days(char* check_in, char* check_out) {
    int check_in_int = date_to_int(check_in);
    int check_out_int = date_to_int(check_out);
    return check_out_int - check_in_int;
}

void checkout_room() {
    int room_number;
    printf("Enter the room number (1-10): ");
    scanf("%d", &room_number);

    if (room_number < 1 || room_number > 10) {
        printf("Invalid room number. Please try again.\n");
        return;
    }

    struct room *room = &hotel_rooms[room_number - 1];

    if (room->status == 0) {
        printf("Room %d is vacant.\n", room_number);
        return;
    }

    printf("Customer details for Room %d:\n", room_number);
    printf("Username: %s\n", room->customer_details.username);
    printf("Last name: %s\n", room->customer_details.lastname);
    printf("Email: %s\n", room->customer_details.email);
    printf("Address: %s\n", room->customer_details.address);
    printf("Phone: %s\n", room->customer_details.phone);
    printf("Check-in date: %s\n", room->check_in);
    printf("Check-out date: ");
    scanf("%s", room->check_out);

    // Calculate and print the bill
    int num_days = get_num_days(room->check_in, room->check_out);
    double bill_amount = num_days * 50.0;
    printf("Bill for Room %d:\n", room_number);
    printf("Number of days stayed: %d\n", num_days);
    printf("Rate per day: $50\n");
    printf("Total amount due: $%.2f\n", bill_amount);

    // Reset the room status to vacant
    room->status = 0;
    strcpy(room->customer_details.username, "");
    strcpy(room->customer_details.lastname, "");
    strcpy(room->customer_details.email, "");
    strcpy(room->customer_details.address, "");
    strcpy(room->customer_details.phone, "");
    strcpy(room->check_in, "");
    strcpy(room->check_out, "");

    printf("Check-out from Room %d is complete.\n", room_number);
}

int main() {

    for (int i = 0; i < MAX_ROOMS; i++) {
        hotel_rooms[i].room_number = i + 1;
        hotel_rooms[i].status = 0;
    }

    while (1) {
        printf("Menu:\n");
        printf("B: Book a room\n");
        printf("V: Customer details\n");
        printf("E: Edit customer details\n");
        printf("C: Checkout room\n");
        printf("R: Print report\n");
        printf("Q: Quit\n");
        printf("Enter transaction type: ");
        char transaction_type;
        scanf(" %c", &transaction_type);

        switch (transaction_type) {
            case 'B':
            case 'b':
                book_room();
                break;
            case'V':
            case'v':
                view_customer_details();
                break;
            case 'E':
            case 'e':
                edit_customer_details();
                break;
            case 'C':
            case 'c':
                checkout_room();
                break;
            case 'Q':
            case 'q':
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid transaction type. Please try again.\n");
        }
    }

    return 0;
}
