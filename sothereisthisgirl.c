#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum LEVEL {
    SILVER,
    GOLD,
    PLATINUM,
};
struct jawirbuck {
    char name[100];
    float money;
    enum LEVEL level;
};

void updatelevel(struct jawirbuck *account) {
    if (account->money > 1000) {
        account->level = PLATINUM;
    } else if (account->money > 200) {
        account->level = GOLD;
    } else {
        account->level = SILVER;
    }
}

float intrestrate(enum LEVEL level) {
    switch (level) {
        case PLATINUM: return 0.05;
        case GOLD: return 0.03; 
        case SILVER: return 0.01; 
        default: return 0.0;
    }
}

int main(){
    int n;
    int u = 1;
    int months = 0;
    int m;
    struct jawirbuck account[100];
    const char *level_names[] = {"SILVER", "GOLD", "PLATINUM"};


    printf("Number of accounts: ");
    scanf("%d", &n);
    printf("--- Initial account ----\n");

    for (int i = 0; i < n; i++) {
        printf("---- Account %d ----\n", i + 1);
        printf("Name: "); 
        scanf("%s", account[i].name);
        printf("Money: $");
        scanf("%f", &account[i].money);
        updatelevel(&account[i]); 
}
printf("Number of Months:");
scanf("%d", &m);

while(months < m){
    printf("---- Months %d ----\n" , months + 1);
    for (int j = 0; j < n; j++) {
        float interest_rate = intrestrate(account[j].level);
            account[j].money += account[j].money * interest_rate;

            updatelevel(&account[j]);


            printf("Account %d\n", j + 1);
            printf("  Owner: %s\n", account[j].name);
            printf("  Money: $%.2f\n", account[j].money);
            printf("  Level: %s\n", level_names[account[j].level]);
        }

        if (m % 3 == 0) {
            printf("\nReevaluating levels...\n");
            int k = 0;
            while (k < n) {
                updatelevel(&account[k]);
                k++;
            }
        }

        months++;
    }

    return 0;
}

