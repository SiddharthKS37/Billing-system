#include <stdio.h>
#include <string.h>

// Structure for customer
struct Customer 
{
    int id;
    char name[50];
    char contact[20];
};

// Structure for item
struct Item 
{
    int id;
    char description[50];
    float price;
};

// Function to store customer information
void storeCustomer(struct Customer *customer, int id, char name[], char contact[]) 
{
    customer->id = id;
    strcpy(customer->name, name);
    strcpy(customer->contact, contact);
}

// Function to enter items with quantity
float enterItems(struct Item items[], int quantities[], int numItems) 
{
    float total = 0;
    printf("Items :\n1: Rice (1 kg) - Rs50\n2: Wheat Flour (1 kg) - RS30\n3: Sugar (1 kg) - Rs40\n4: Lentils (Dal, 1 kg) - Rs80\n5: Cooking Oil (1 liter) - Rs100\n6: Milk (1 liter) - Rs60\n7: Eggs (1 dozen) - Rs50\n8: Potatoes (1 kg) - Rs20\n9: Onions (1 kg) - Rs30\n10: Tomatoes (1 kg) - Rs40");
    printf("Enter items:\n");
    for (int i = 0; i < numItems; i++) 
    {
        printf("Enter item ID for item %d: ", i+1);
        int id;
        scanf("%d", &id);
        switch (id)
        {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
                printf("Enter quantity for item %d: ", i+1);
                scanf("%d", &quantities[i]);
                total += items[id-1].price * quantities[i];
                break;
            default:
                printf("Invalid");
                break;
        }
    }
    return total;
}

// Function to print the total bill
void printBill(struct Customer customer, struct Item items[], int quantities[], int numItems, float total) 
{
    printf("\nCustomer Information:\n");
    printf("ID: %d\n", customer.id);
    printf("Name: %s\n", customer.name);
    printf("Contact: %s\n", customer.contact);
    printf("\nTotal Bill: Rs%.2f\n", total);
}

int main() 
{
    struct Customer customer;
    struct Item items[10] = {
        {1, "Rice (1 kg)", 50},
        {2, "Wheat Flour (1 kg)", 30},
        {3, "Sugar (1 kg)", 40},
        {4, "Lentils (Dal, 1 kg)", 80},
        {5, "Cooking Oil (1 liter)", 100},
        {6, "Milk (1 liter)", 60},
        {7, "Eggs (1 dozen)", 50},
        {8, "Potatoes (1 kg)", 20},
        {9, "Onions (1 kg)", 30},
        {10, "Tomatoes (1 kg)", 40}
    };
    int quantities[10];
    int numItems; // Number of items

    // Store customer information
    char cust[50];
    printf("Enter your name: ");
    scanf("%s", cust);
    char num[10];
    printf("Enter phone number: ");
    scanf("%s", num);
    printf("Enter number of items required: ");
    scanf("%d", &numItems);
    storeCustomer(&customer, 1, cust ,num);

    // Enter items and quantities   
    float total = enterItems(items, quantities, numItems);

    // Print the bill   
    printBill(customer, items, quantities, numItems, total);

    return 0;
}
