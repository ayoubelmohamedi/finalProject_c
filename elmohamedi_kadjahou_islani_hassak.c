#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdbool.h>

#define SIZE 100


/**
Islani Abdessamad 102720
Hatim Hassak 100308
Ayoub Elmohamedi 117891
Ilyas Kadjahou 103078
**/

void getuserInfo(int numberOfData, int size, char userinfo[numberOfData][size]);
void sign_up(char userinfo [][SIZE],int numberOfData);
void getdate(char date []);
void displayIEEE();
bool agreeToPolicy();


void resetpwd(int *login_or_signup, int n, int *line, int *main_menu_choice, int *setting_menu_choice, int *member_resources_menu_choice, char email[][50], char password[][50], char date[][15], char first_name[][25], char last_name[][25], char university[][30], char degree[][10], char city[][25], char country[][25], char credit_card_number[][20], char secret_question[][100], char secret_answer[][50], char credit_card_validation_code[][5]);
void init_menu(int *login_or_signup, int n, int *line, int *main_menu_choice, int *setting_menu_choice, int *member_resources_menu_choice, char email[][50], char password[][50], char date[][15], char first_name[][25], char last_name[][25], char university[][30], char degree[][10], char city[][25], char country[][25], char credit_card_number[][20], char secret_question[][100], char secret_answer[][50], char credit_card_validation_code[][5]);
void log_in(int n, int *line, int *login_or_signup, int *main_menu_choice, int *setting_menu_choice, int *member_resources_menu_choice, char email[][50], char password[][50], char date[][15], char first_name[][25], char last_name[][25], char university[][30], char degree[][10], char city[][25], char country[][25], char credit_card_number[][20], char secret_question[][100], char secret_answer[][50], char credit_card_validation_code[][5]);
void main_menu(int *main_menu_choice, int *login_or_signup, int *setting_menu_choice, int *member_resources_menu_choice, int *line, int n, char email[][50], char password[][50], char date[][15], char first_name[][25], char last_name[][25], char university[][30], char degree[][10], char city[][25], char country[][25], char credit_card_number[][20], char secret_question[][100], char secret_answer[][50], char credit_card_validation_code[][5]);
void setting_menu(int *member_resources_menu_choice, int *main_menu_choice, int *login_or_signup, int *setting_menu_choice, int *line, int n, char email[][50], char password[][50], char date[][15], char first_name[][25], char last_name[][25], char university[][30], char degree[][10], char city[][25], char country[][25], char credit_card_number[][20], char secret_question[][100], char secret_answer[][50], char credit_card_validation_code[][5]);
void member_resources_menu(int *member_resources_menu_choice, int *main_menu_choice, int *login_or_signup, int *setting_menu_choice, int *line, int n, char email[][50], char password[][50], char date[][15], char first_name[][25], char last_name[][25], char university[][30], char degree[][10], char city[][25], char country[][25], char credit_card_number[][20], char secret_question[][100], char secret_answer[][50], char credit_card_validation_code[][5]);
void log_out_menu(int *login_or_signup, int n, int *line, int *main_menu_choice, int *setting_menu_choice, int *member_resources_menu_choice, char email[][50], char password[][50], char date[][15], char first_name[][25], char last_name[][25], char university[][30], char degree[][10], char city[][25], char country[][25], char credit_card_number[][20], char secret_question[][100], char secret_answer[][50], char credit_card_validation_code[][5]);
void access_account(char first_name[][25], char last_name[][25], char email[][50], char university[][30], char degree[][10], char city[][25], char country[][25], char credit_card_number[][20], int *line);
void membership_due(char date[][15], int *line);
void renew_membership(int *member_resources_menu_choice, int *main_menu_choice, int *login_or_signup, int *setting_menu_choice, int *line, int n, char email[][50], char password[][50], char date[][15], char first_name[][25], char last_name[][25], char university[][30], char degree[][10], char city[][25], char country[][25], char credit_card_number[][20],char*credit_card_validation_code[], char secret_question[][100], char secret_answer[][50]);
void modify_account_info(int *member_resources_menu_choice, int *main_menu_choice, int *login_or_signup, int *setting_menu_choice, int *line, int n, char email[][50], char password[][50], char date[][15], char first_name[][25], char last_name[][25], char university[][30], char degree[][10], char city[][25], char country[][25], char credit_card_number[][20], char secret_question[][100], char secret_answer[][50], char credit_card_validation_code[][50]);
void delete_account(int *main_menu_choice, int *login_or_signup, int *setting_menu_choice, int *member_resources_menu_choice, int *line, int n, char email[][50], char password[][50], char date[][15], char first_name[][25], char last_name[][25], char university[][30], char degree[][10], char city[][25], char country[][25], char credit_card_number[][20], char secret_question[][100], char secret_answer[][50], char credit_card_validation_code[][5]);
void EXIT(int *main_menu_choice, int *login_or_signup, int *setting_menu_choice, int *member_resources_menu_choice, int *line, int n, char email[][50], char password[][50], char date[][15], char first_name[][25], char last_name[][25], char university[][30], char degree[][10], char city[][25], char country[][25], char credit_card_number[][20], char secret_question[][100], char secret_answer[][50], char credit_card_validation_code[][5]);
void find_ieee_fellow(int *main_menu_choice, int *login_or_signup, int *setting_menu_choice, int *member_resources_menu_choice, int *line, int n, char email[][50], char password[][50], char date[][15], char first_name[][25], char last_name[][25], char university[][30], char degree[][10], char city[][25], char country[][25], char credit_card_number[][20], char secret_question[][100], char secret_answer[][50], char credit_card_validation_code[][5]);
void list_upcoming_conferences(int *main_menu_choice, int *login_or_signup, int *setting_menu_choice, int *member_resources_menu_choice, int *line, int n, char email[][50], char password[][50], char date[][15], char first_name[][25], char last_name[][25], char university[][30], char degree[][10], char city[][25], char country[][25], char credit_card_number[][20], char secret_question[][100], char secret_answer[][50], char credit_card_validation_code[][5]);
void gotoxy(int x, int y);

int main()
{
    char first_name[100][25];
    char last_name[100][25];
    char email[100][50];
    char password[100][50];
    char university[100][30];
    char degree[100][10];
    char city[100][25];
    char country[100][25];
    char secret_question[100][100];
    char secret_answer[100][50];
    char credit_card_number[100][20];
    char credit_card_validation_code[100][5];
    char date[100][15];
    int n = 0;
    FILE *database;
    FILE *conferences;
    int login_or_signup, main_menu_choice, setting_menu_choice, member_resources_menu_choice, x, y, i = 0, line;
    database = fopen("database_users.txt", "r"); // The file should be in the same folder before submission
    if (!database)
    {
        printf("Please, our platform is facing a technical issue, we will be back as soon as possible.");
        exit(1);
    }
    while (i < 100)
    {
        fscanf(database," %[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", first_name[i], last_name[i], email[i], password[i], university[i], degree[i], city[i], country[i], secret_question[i], secret_answer[i], credit_card_number[i], credit_card_validation_code[i], date[i]);
        i++;
        n++;
    }
    while(true){
        init_menu(&login_or_signup, n, &line, &main_menu_choice, &setting_menu_choice, &member_resources_menu_choice, email, password, date, first_name, last_name, university, degree, city, country, credit_card_number, secret_question, secret_answer, credit_card_validation_code);
    }
    fclose(database);
}

void log_in(int n, int *line, int *login_or_signup, int *main_menu_choice, int *setting_menu_choice, int *member_resources_menu_choice, char email[][50], char password[][50], char date[][15], char first_name[][25], char last_name[][25], char university[][30], char degree[][10], char city[][25], char country[][25], char credit_card_number[][20], char secret_question[][100], char secret_answer[][50], char credit_card_validation_code[][5])
{
    char tempmail[50], temppass[50], tempanswer[50];
    system("clear"); // Change "clear" to "cls" when using it on Windows
    printf("Log In:");
    printf("\n");
    printf("Email: ");
    scanf("%s", tempmail);
    char firstmail[30] = "ahmedalaoui@gmail.com";
    char firstpass[30] = "secret1234";
    char firstanswer[30] = "1996";
    int flag = 0;
    for (int i = 0; i < 100; i++)
    {
        if (strcmp(tempmail, email[i]) == 0 || strcmp(tempmail, firstmail) == 0)
        {
            *line = i;
            flag = 1;
        }
    }
    if (flag == 1)
    {
        printf("\n");
        printf("Password: ");
        scanf("%s", temppass);
        if (strcmp(temppass, password[*line]) == 0 || strcmp(temppass, firstpass) == 0)
        {
            if (strcmp(temppass, firstpass) == 0)
            {
                *line = 0;
            }
            while(true){
            main_menu(main_menu_choice, login_or_signup, setting_menu_choice, member_resources_menu_choice, line, n, email, password, date, first_name, last_name, university, degree, city, country, credit_card_number, secret_question, secret_answer, credit_card_validation_code);

            }
        }
        else
        {
            printf("\nYou got the password wrong! Try again");
            printf("\nPassword: ");
            scanf("%s", temppass);
            if (strcmp(temppass, password[*line]) == 0 || strcmp(temppass, firstpass) == 0)
            {
                if (strcmp(temppass, firstpass) == 0)
                {
                    *line = 0;
                }
                main_menu(main_menu_choice, login_or_signup, setting_menu_choice, member_resources_menu_choice, line, n, email, password, date, first_name, last_name, university, degree, city, country, credit_card_number, secret_question, secret_answer, credit_card_validation_code);
            }
            else
            {
                printf("\nThis is your last chance to get the password right");
                printf("\nPassword: ");
                scanf("%s", temppass);
                if (strcmp(temppass, password[*line]) == 0 || strcmp(temppass, firstpass) == 0)
                {
                    if (strcmp(temppass, firstpass) == 0)
                    {
                        *line = 0;
                    }
                    main_menu(main_menu_choice, login_or_signup, setting_menu_choice, member_resources_menu_choice, line, n, email, password, date, first_name, last_name, university, degree, city, country, credit_card_number, secret_question, secret_answer, credit_card_validation_code);
                }
                else
                {
                    printf("\nToo many tries! Reset your password");
                    if (strcmp(tempmail, firstmail) == 0) {
                        printf("\nwhat is my birth year?");
                    }
                    else
                    {
                        printf("\n%s", secret_question[*line]);
                    }
                    printf("\nAnswer: ");
                    scanf("%s", tempanswer);
                    if (strcmp(tempanswer, secret_answer[*line]) == 0 || strcmp(tempanswer, firstanswer) == 0)
                    {
                        if (strcmp(tempanswer, firstanswer) == 0)
                        {
                            *line = 0;
                        }
                        main_menu(main_menu_choice, login_or_signup, setting_menu_choice, member_resources_menu_choice, line, n, email, password, date, first_name, last_name, university, degree, city, country, credit_card_number, secret_question, secret_answer, credit_card_validation_code);
                    }
                }
            }
        }
    }
    else
    {
        flag=0;
        printf("\n");
        printf("Please enter your email address again");
        printf("\n");
        printf("Email: ");
        scanf("%s", tempmail);
        for(int i = 0; i <100; i++)
        {
            if (strcmp(tempmail, email[i]) == 0 || strcmp(temppass, firstmail) == 0)
            {
                *line = i;
                flag = 1;
            }
        }
        if (flag == 1)
        {
            printf("\n");
            printf("Password: ");
            scanf("%s", temppass);
            if (strcmp(temppass, password[*line]) == 0 || strcmp(temppass, firstpass) == 0)
            {
                if (strcmp(temppass, firstpass) == 0)
                {
                    *line = 0;
                }
                main_menu(main_menu_choice, login_or_signup, setting_menu_choice, member_resources_menu_choice, line, n, email, password, date, first_name, last_name, university, degree, city, country, credit_card_number, secret_question, secret_answer, credit_card_validation_code);
            }
            else
            {
            printf("\nYou got the password wrong! Try again");
            printf("\nPassword: ");
            scanf("%s", temppass);
            if (strcmp(temppass, password[*line]) == 0 || strcmp(temppass, firstpass) == 0)
            {
                if (strcmp(temppass, firstpass) == 0)
                {
                    *line = 0;
                }
                main_menu(main_menu_choice, login_or_signup, setting_menu_choice, member_resources_menu_choice, line, n, email, password, date, first_name, last_name, university, degree, city, country, credit_card_number, secret_question, secret_answer, credit_card_validation_code);
            }
            else
            {
                printf("\nThis is your last chance to get the password right");
                printf("\nPassword: ");
                scanf("%s", temppass);
                if (strcmp(temppass, password[*line]) == 0 || strcmp(temppass, firstpass) == 0)
                {
                    if (strcmp(temppass, firstpass) == 0)
                    {
                        *line = 0;
                    }
                    main_menu(main_menu_choice, login_or_signup, setting_menu_choice, member_resources_menu_choice, line, n, email, password, date, first_name, last_name, university, degree, city, country, credit_card_number, secret_question, secret_answer, credit_card_validation_code);
                }
                else
                {
                    printf("\nToo many tries! Reset your password");
                    if (strcmp(tempmail, firstmail) == 0) {
                        printf("\nwhat is my birth year?");
                    }
                    else
                    {
                        printf("\n%s", secret_question[*line]);
                    }
                    printf("\n%s", secret_question[*line]);
                    printf("\nAnswer: ");
                    scanf("%s", tempanswer);
                    if (strcmp(tempanswer, secret_answer[*line]) == 0 || strcmp(tempanswer, firstanswer) == 0)
                    {
                        if (strcmp(tempanswer, firstanswer) == 0)
                        {
                            *line = 0;
                        }
                        main_menu(main_menu_choice, login_or_signup, setting_menu_choice, member_resources_menu_choice, line, n, email, password, date, first_name, last_name, university, degree, city, country, credit_card_number, secret_question, secret_answer, credit_card_validation_code);
                    }
                }
            }
        }
        }
        else
        {
            printf("\n");
            printf("Inexistent account! Please sign up");
            printf("\n");
            init_menu(login_or_signup, n, line, main_menu_choice, setting_menu_choice, member_resources_menu_choice, email, password, date, first_name, last_name, university, degree, city, country, credit_card_number, secret_question, secret_answer, credit_card_validation_code);
        }
    }
}

void main_menu(int *main_menu_choice, int *login_or_signup, int *setting_menu_choice, int *member_resources_menu_choice, int *line, int n, char email[][50], char password[][50], char date[][15], char first_name[][25], char last_name[][25], char university[][30], char degree[][10], char city[][25], char country[][25], char credit_card_number[][20], char secret_question[][100], char secret_answer[][50], char credit_card_validation_code[][5])
{
    system ("cls"); // Change "clear" to "cls" when using it on Windows
    do
    {
        printf("Please choose one of the following choices:\n1: Settings\n2: Member recources\n3: Log out\nChoice: ");
        scanf("%d", &*main_menu_choice);
        system("clear"); // Change "clear" to "cls" when using it on Windows
    } while (*main_menu_choice != 1 && *main_menu_choice != 2 && *main_menu_choice != 3);
    switch (*main_menu_choice)
    {
    case 1:
        setting_menu(main_menu_choice, login_or_signup, setting_menu_choice, member_resources_menu_choice, line, n, email, password, date, first_name, last_name, university, degree, city, country, credit_card_number, secret_question, secret_answer, credit_card_validation_code);
        break;
    case 2:
        member_resources_menu(main_menu_choice, login_or_signup, setting_menu_choice, member_resources_menu_choice, line, n, email, password, date, first_name, last_name, university, degree, city, country, credit_card_number, secret_question, secret_answer, credit_card_validation_code);
        break;
    case 3:
        log_out_menu(login_or_signup, n, line, main_menu_choice, setting_menu_choice, member_resources_menu_choice, email, password, date, first_name, last_name, university, degree, city, country, credit_card_number, secret_question, secret_answer, credit_card_validation_code);
    }
}

void setting_menu(int *member_resources_menu_choice, int *main_menu_choice, int *login_or_signup, int *setting_menu_choice, int *line, int n, char email[][50], char password[][50], char date[][15], char first_name[][25], char last_name[][25], char university[][30], char degree[][10], char city[][25], char country[][25], char credit_card_number[][20], char secret_question[][100], char secret_answer[][50], char credit_card_validation_code[][5])
{
    do
    {
        printf("Please choose from the following list:\n1: Access account\n2: Membership due\n3: Renew Membership\n4: Modify account info\n5: Delete account\n6: EXIT\nChoice: ");
        scanf("%d", &*setting_menu_choice);
    } while (*setting_menu_choice != 1 && *setting_menu_choice != 2 && *setting_menu_choice != 3 && *setting_menu_choice != 4 && *setting_menu_choice != 5 && *setting_menu_choice != 6);
    switch (*setting_menu_choice)
    {
    case 1:
        access_account(first_name, last_name, email, university, degree, city, country, credit_card_number, line);
        break;
    case 2:
        membership_due(date, line);
        break;
    case 3:
        renew_membership(main_menu_choice, login_or_signup, setting_menu_choice, member_resources_menu_choice, line, n, email, password, date, first_name, last_name, university, degree, city, country, credit_card_number,credit_card_validation_code, secret_question, secret_answer);
        break;
    case 4:
        modify_account_info(main_menu_choice, login_or_signup, setting_menu_choice, member_resources_menu_choice, line, n, email, password, date, first_name, last_name, university, degree, city, country, credit_card_number, secret_question, secret_answer, credit_card_validation_code);
        break;
    case 5:
        delete_account(main_menu_choice, login_or_signup, setting_menu_choice, member_resources_menu_choice, line, n, email, password, date, first_name, last_name, university, degree, city, country, credit_card_number, secret_question, secret_answer, credit_card_validation_code);
        break;
    case 6:
        EXIT(main_menu_choice, login_or_signup, setting_menu_choice, member_resources_menu_choice, line, n, email, password, date, first_name, last_name, university, degree, city, country, credit_card_number, secret_question, secret_answer, credit_card_validation_code);
    }
}

void member_resources_menu(int *member_resources_menu_choice, int *main_menu_choice, int *login_or_signup, int *setting_menu_choice, int *line, int n, char email[][50], char password[][50], char date[][15], char first_name[][25], char last_name[][25], char university[][30], char degree[][10], char city[][25], char country[][25], char credit_card_number[][20], char secret_question[][100], char secret_answer[][50], char credit_card_validation_code[][5])
{
    do
    {
        printf("Please choose from the following list:\n1: Find IEEE fellow\n2: List/Attend upcoming coferences\n3: EXIT\nChoice: ");
        scanf("%d", &*member_resources_menu_choice);
    } while (*member_resources_menu_choice != 1 && *member_resources_menu_choice != 2 && *member_resources_menu_choice != 3);
    switch (*member_resources_menu_choice)
    {
    case 1:
        find_ieee_fellow(main_menu_choice, login_or_signup, setting_menu_choice, member_resources_menu_choice, line, n, email, password, date, first_name, last_name, university, degree, city, country, credit_card_number, secret_question, secret_answer, credit_card_validation_code);
        break;
    case 2:
        list_upcoming_conferences(main_menu_choice, login_or_signup, setting_menu_choice, member_resources_menu_choice, line, n, email, password, date, first_name, last_name, university, degree, city, country, credit_card_number, secret_question, secret_answer, credit_card_validation_code);
        break;
    case 3:
        EXIT(main_menu_choice, login_or_signup, setting_menu_choice, member_resources_menu_choice, line, n, email, password, date, first_name, last_name, university, degree, city, country, credit_card_number, secret_question, secret_answer, credit_card_validation_code);
    }
}

void log_out_menu(int *login_or_signup, int n, int *line, int *main_menu_choice, int *setting_menu_choice, int *member_resources_menu_choice, char email[][50], char password[][50], char date[][15], char first_name[][25], char last_name[][25], char university[][30], char degree[][10], char city[][25], char country[][25], char credit_card_number[][20], char secret_question[][100], char secret_answer[][50], char credit_card_validation_code[][5])
{
    init_menu(login_or_signup, n, line, main_menu_choice, setting_menu_choice, member_resources_menu_choice, email, password, date, first_name, last_name, university, degree, city, country, credit_card_number, secret_question, secret_answer, credit_card_validation_code);
}

void access_account(char first_name[][25], char last_name[][25], char email[][50], char university[][30], char degree[][10], char city[][25], char country[][25], char credit_card_number[][20], int *line)
{
    system ("clear"); // Change "clear" to "cls" when using it on Windows
    printf("%s",first_name[*line]);
    printf("\n%s",last_name[*line]);
    printf("\n%s",email[*line]);
    printf("\n%s", university[*line]);
    printf("\n%s",degree[*line]);
    printf("\n%s",city[*line]);
    printf("\n%s",country[*line]);
    printf("\n%s\n",credit_card_number[*line]);
}

void membership_due(char date[][15], int *line)
{
    system ("cls"); // Change "clear" to "cls" when using it on Windows
    printf("Your membership will end the %s\n", date[*line]);
}

void renew_membership(int *member_resources_menu_choice, int *main_menu_choice, int *login_or_signup, int *setting_menu_choice, int *line, int n, char email[][50], char password[][50], char date[][15], char first_name[][25], char last_name[][25], char university[][30], char degree[][10], char city[][25], char country[][25], char credit_card_number[][20],char* credit_card_validation_code[], char secret_question[][100], char secret_answer[][50])
{

    system ("cls"); // Change "clear" to "cls" when using it on Windows
    char *mm,*dd,*yy;
    FILE*database= fopen("database_users.txt","w");
    mm=strtok(date[*line],"/");
    dd= strtok(NULL,"/");
    yy= strtok(NULL, "\n");
    printf("100dh has been credited in your account and your IEEE membership has been extended till ");
    printf("\n%s/%s/%d",mm,dd, atoi(yy)+1);
    for (int i = 0; i < n; ++i) {
        if (i==*line)  fprintf(database,"%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s/%s/%d\n", first_name[i], last_name[i], email[i],password[i],university[i],degree[i],city[i],country[i],secret_question[i],secret_answer[i], credit_card_number[i], credit_card_validation_code[i],mm,dd,yy);
        else fprintf(database,"%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n", first_name[i], last_name[i], email[i],password[i],university[i],degree[i],city[i],country[i],secret_question[i],secret_answer[i], credit_card_number[i], credit_card_validation_code[i],date[i]);

    }



}

void modify_account_info(int *member_resources_menu_choice, int *main_menu_choice, int *login_or_signup, int *setting_menu_choice, int *line, int n, char email[][50], char password[][50], char date[][15], char first_name[][25], char last_name[][25], char university[][30], char degree[][10], char city[][25], char country[][25], char credit_card_number[][20], char secret_question[][100], char secret_answer[][50], char credit_card_validation_code[][50])
{
    system ("cls"); // Change "clear" to "cls" when using it on Windows
    FILE *database;
    database=fopen("database_users.txt", "w");   //database file

    int choice,flag=0,w;
    char new[100];
    printf("Change\n");
    printf("1::First name 2::Last name 3::email 4::university 5::degree 6::city 7::country 8::Security questions 9::security answer 10::credit card number 11::credit card code \n");
    scanf("%d", &choice);
    while (flag==0){switch (choice) {


            case 1:
                printf("New First name:");
                scanf("%s", new);
                strcpy(first_name[*line],new);
                flag =1;
                break;
            case 2:
                printf("New Last name:");
                scanf("%s", new);
                strcpy(last_name[*line],new);
                flag =1;
                break;
            case 3:
                printf("New email:");
                scanf("%s", new);
                strcpy(email[*line],new);
                flag =1;
                break;
            case 4:
                printf("New university:");
                scanf("%s", new);
                strcpy(university[*line],new);
                flag =1;
                break;
            case 5:
                do{printf("New degree(grad/undergrad):");
                    scanf("%s", new);
                    if(strcmp(new,"undergrad")==0|| strcmp(new,"grad")==0){

                        strcpy(degree[*line],new);
                        flag =1 ;}
                    else { printf("ERROR ");
                        flag=2;}} while (flag==2);
                break;
            case 6:
                printf("New city:");
                scanf("%s", new);
                strcpy(city[*line],new);
                flag =1;
                break;
            case 7:
                printf("New country:");
                scanf("%s", new);
                strcpy(country[*line],new);
                flag =1;
                break;
            case 8:
                printf("new security question:");
                scanf("%s", new);
                strcpy(secret_question[*line]
                       ,new);
                flag =1;
                break;
            case 9:
                printf("new security answer:");
                scanf("%s", new);
                strcpy(secret_answer[*line],new);
                flag =1;
                break;
            case 10:
                do {


                    printf("new credit card number:");
                    scanf("%s",new);
                    for (int i = 0; i <= strlen(new); ++i) {
                        if(isdigit(new[i])) w=1;
                        else {w=0;
                            break;}
                    }
                    if(strlen(new)==14&&w==0 ){flag=1;
                        strcpy(credit_card_number[*line],new);

                    }else flag=2;} while (flag==2);
                break;
        case 11:  do{ printf("new credit card code:");
                scanf("%s",new);
                for (int i = 0; i <= strlen(new); ++i) {
                    if(isdigit(new[i])) w=1;
                    else {w=0;
                        break;}
                }
                if(strlen(new)==3&&w==0 ){flag=1;
                    strcpy(credit_card_number[*line],new);

                }else flag=2;} while (flag==2);
                 break;
            default:
                printf("Error");
                flag=0;

        }}

    for (int i = 0; i < n; ++i) {
        fprintf(database,"%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n", first_name[i], last_name[i], email[i],password[i],university[i],degree[i],city[i],country[i],secret_question[i],secret_answer[i], credit_card_number[i], credit_card_validation_code[i],date[i]);
    }

}

void delete_account(int *member_resources_menu_choice, int *main_menu_choice, int *login_or_signup, int *setting_menu_choice, int *line, int n, char email[][50], char password[][50], char date[][15], char first_name[][25], char last_name[][25], char university[][30], char degree[][10], char city[][25], char country[][25], char credit_card_number[][20], char secret_question[][100], char secret_answer[][50], char credit_card_validation_code[][5])
{     FILE *data;
    data= fopen("database_users.txt","w");
    char answer = 'y';
    system ("cls"); // Change "clear" to "cls" when using it on Windows
    printf("Are you sure you want to delete your account?");
    scanf("%c", &answer);
    if (answer == 'y')
    {
        for (int i = *line; i <= n; i++)
        {
            strcpy(first_name[i], first_name[i+1]);
            strcpy(last_name[i], last_name[i + 1]);
            strcpy(email[i], email[i + 1]);
            strcpy(password[i], password[i + 1]);
            strcpy(university[i], university[i + 1]);
            strcpy(degree[i], degree[i + 1]);
            strcpy(city[i], city[i + 1]);
            strcpy(country[i], country[i + 1]);
            strcpy(secret_question[i], secret_question[i + 1]);
            strcpy(secret_answer[i], secret_answer[i + 1]);
            strcpy(credit_card_number[i], credit_card_number[i + 1]);
            strcpy(credit_card_validation_code[i], credit_card_validation_code[i + 1]);
            strcpy(date[i], date[i + 1]);
        }
        strcpy(first_name[n], "\0");
        strcpy(last_name[n], "\0");
        strcpy(email[n], "\0");
        strcpy(password[n], "\0");
        strcpy(university[n], "\0");
        strcpy(degree[n], "\0");
        strcpy(city[n], "\0");
        strcpy(country[n], "\0");
        strcpy(secret_question[n], "\0");
        strcpy(secret_answer[n], "\0");
        strcpy(credit_card_number[n], "\0");
        strcpy(credit_card_validation_code[n], "\0");
        strcpy(date[n], "\0");
        for (int i = 0; i < n; ++i) {
           fprintf(data,"%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n", first_name[i], last_name[i], email[i],password[i],university[i],degree[i],city[i],country[i],secret_question[i],secret_answer[i], credit_card_number[i], credit_card_validation_code[i],date[i]);
        }

    }
    else
    {
        printf("We are glad you changed your decision\n");
        main_menu(main_menu_choice, login_or_signup, setting_menu_choice, member_resources_menu_choice, line, n, email, password, date, first_name, last_name, university, degree, city, country, credit_card_number, secret_question, secret_answer, credit_card_validation_code);
    }
}

void EXIT(int *main_menu_choice, int *login_or_signup, int *setting_menu_choice, int *member_resources_menu_choice, int *line, int n, char email[][50], char password[][50], char date[][15], char first_name[][25], char last_name[][25], char university[][30], char degree[][10], char city[][25], char country[][25], char credit_card_number[][20], char secret_question[][100], char secret_answer[][50], char credit_card_validation_code[][5])
{
    system ("cls"); // Change "clear" to "cls" when using it on Windows
    main_menu(main_menu_choice, login_or_signup, setting_menu_choice, member_resources_menu_choice, line, n, email, password, date, first_name, last_name, university, degree, city, country, credit_card_number, secret_question, secret_answer, credit_card_validation_code);
}

void init_menu(int *login_or_signup, int n, int *line, int *main_menu_choice, int *setting_menu_choice, int *member_resources_menu_choice, char email[][50], char password[][50], char date[][15], char first_name[][25], char last_name[][25], char university[][30], char degree[][10], char city[][25], char country[][25], char credit_card_number[][20], char secret_question[][100], char secret_answer[][50], char credit_card_validation_code[][5])
{
    int numData = 13;
    char userinfo [numData][SIZE]; 
    system("cls"); // Change "clear" to "cls" when using it on Windows
    do
    {
        printf("1::Login\t2::Signup\n");
        printf("Please choose by pressing 1 or 2: ");
        scanf("%d", &*login_or_signup);
        system("cls"); // Change "clear" to "cls" when using it on Windows
    } while (*login_or_signup != 1 && *login_or_signup != 2);
    switch (*login_or_signup)
    {
    case 1:
        log_in(n, login_or_signup, line, main_menu_choice, setting_menu_choice, member_resources_menu_choice, email, password, date, first_name, last_name, university, degree, city, country, credit_card_number, secret_question, secret_answer, credit_card_validation_code);
        break;
    case 2:
        
        getuserInfo(numData,SIZE,userinfo);
        if(agreeToPolicy()){
            sign_up(userinfo,numData);
            printf("Welcome to the IEEE community! 100 DH is credited from your account\n");
        }else {
            printf("Sign up failed! Could not create account\n");
        }
        init_menu(&login_or_signup, n, &line, &main_menu_choice, &setting_menu_choice, &member_resources_menu_choice, email, password, date, first_name, last_name, university, degree, city, country, credit_card_number, secret_question, secret_answer, credit_card_validation_code);
        break;
    }
}

void find_ieee_fellow(int *main_menu_choice, int *login_or_signup, int *setting_menu_choice, int *member_resources_menu_choice, int *line, int n, char email[][50], char password[][50], char date[][15], char first_name[][25], char last_name[][25], char university[][30], char degree[][10], char city[][25], char country[][25], char credit_card_number[][20], char secret_question[][100], char secret_answer[][50], char credit_card_validation_code[][5]) {
    system("cls"); // Change "clear" to "cls" when using it on Windows
    int flag = 0;
    char search[50];
    while (flag == 0) {
        printf("search:");
        scanf("%s", search);
        for (int i = 0; i < n; ++i) {
            if (strcmp(search, first_name[i]) == 0 || strcmp(search, last_name[i]) == 0) {

                printf("%s %s\n", first_name[i], last_name[i]);
                flag = 1;
                break;
            } else flag = 0;

        }
        if (flag == 0) {
            printf("no result\n");

        }


        printf("click 1 if you want to search again");
        scanf("%d", &flag);

    }}

    void list_upcoming_conferences(int *main_menu_choice, int *login_or_signup, int *setting_menu_choice,
                                   int *member_resources_menu_choice, int *line, int n, char email[][50],
                                   char password[][50], char date[][15], char first_name[][25], char last_name[][25],
                                   char university[][30], char degree[][10], char city[][25], char country[][25],
                                   char credit_card_number[][20], char secret_question[][100], char secret_answer[][50],
                                   char credit_card_validation_code[][5]) {
        system("cls"); // Change "clear" to "cls" when using it on Windows
        FILE*conf;
        char str[1000];
        int choice,flag;
        conf= fopen("upcoming_conf.txt","r");
        while (!feof(conf)){
            fgets(str,999,conf);
            printf("%s\n", str);

        }
        do{printf("1: Attend conference\t  2: EXIT");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                do{printf("choose a conference\n");
                scanf("%d",&choice);
                flag=1;
                switch (choice) {
                    case 1:
                        printf("You're registred in 38th IEEE International Conference on Data Engineering (ICDE 2022),9-12 May 2022\n ");
                        break;
                    case 2:
                        printf("You're registred in 44th International Conference on Software Engineering (ICSE 2022),21-29 May 2022,Pittsburgh USA\n");
                        break;
                    case 3:
                        printf("You're registred in 43rd IEEE Symposium on Security and Privacy (SP 2022),22-26 May 2022,San Francisco USA\n");
                        break;
                    case 4:
                        printf("You're registred in 42nd IEEE International Conference on Distributed Computing Systems (ICDCS 2022),10–13 July 2022,Bologna Italy\n");
                        break;
                    case 5:
                        printf("You're registred in IEEE International Conference on Quantum Computing and Engineering (QCE 2022),19–23 September 2022,Bloomfield USA\n");
                        break;
                    case 6:
                        printf("You're registred in IEEE Future Networks 2022,12–14 October 2022,Montreal Canada\n");
                        break;
                    default:flag=2;
                }} while (flag==2);
                break;
            case 2:
                EXIT( main_menu_choice, login_or_signup, setting_menu_choice, member_resources_menu_choice, line, n, email, password, date, first_name, last_name, university, degree, city, country, credit_card_number, secret_question, secret_answer, credit_card_validation_code);
                break;
            default:flag=0;
        }} while (flag==0);

    }

    void gotoxy(int x, int y) {
        printf("%c[%d;%df", 0x1B, y, x);
    }
    void resetpwd(int *login_or_signup, int n, int *line, int *main_menu_choice, int *setting_menu_choice,
                  int *member_resources_menu_choice, char email[][50], char password[][50], char date[][15],
                  char first_name[][25], char last_name[][25], char university[][30], char degree[][10],
                  char city[][25], char country[][25], char credit_card_number[][20], char secret_question[][100],
                  char secret_answer[][50], char credit_card_validation_code[][5]) {
        char answer[20], new[50];
        FILE *fp2;
        fp2 = fopen("database_users.txt", "w");//datafile
        printf("%s", secret_question[*line]);
        scanf("%s", answer);
        if (strcmp(secret_answer[*line], answer) == 0) {
            printf("New password");
            scanf("%s", new);
            strcpy(password[*line], new);
            for (int i = 0; i < n; ++i) {
                fprintf(fp2, "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n", first_name[i], last_name[i], email[i],
                        password[i], university[i], degree[i], city[i], country[i], secret_question[i],
                        secret_answer[i], credit_card_number[i], credit_card_validation_code[i], date[i]);
            }


        }

    }

 void getuserInfo(int numberOfData, int size, char userinfo[numberOfData][size]) {
        char tempInfo[100];
        char firstname[50],lastname[50],email[50],password[50],cpassword[50],university[50],sdegree[50],city[50],country[50],secretquestion[100],secretanswer[100],ccn[50],ccvc[50];
        int degree ;
        char empty_buff[10]; 
        
        printf("First Name :\n");
        scanf("%s",firstname);
        printf("Last Name :\n");
        scanf("%s",lastname);
        printf("Email Address :\n");
        scanf("%s",email);
        printf("Password :\n");
        scanf("%s",password);
        printf("Confirm Password :\n");
        scanf("%s",cpassword);
        while(strcmp(password,cpassword)!=0){
            printf("The Confirm Password confirmation does not match\n");
            printf("Password :\n");
            scanf("%s",password);
            printf("Confirm Password :\n");
            scanf("%s",cpassword);
        }
        printf("University :\n");
        scanf("%s",university);
        printf("Degree :\n1 - Graduate\n2 - Undergraduate :");
        scanf(" %d",&degree);

       
            while(degree != 1 && degree != 2){
                printf("you need to enter a digit value between 1-2: ");
                scanf(" %d",&degree);
            }

            if(degree==1)
                strcpy(sdegree,"Graduate");
            else if(degree==2)
                strcpy(sdegree,"Undergrate");
        printf("City :\n");
        scanf("%s",city);
        printf("Country :\n");
        scanf("%s",country);
        printf("Secret Question :");
        scanf(" %s",empty_buff);
        scanf("%[^\n]s" , secretquestion);
        printf("Secret Answer :");
        scanf(" %s",empty_buff);
        scanf("%[^\n]s" , secretanswer);
        printf("Credit Card Number :\n");
        scanf("%s",ccn);
        printf("Credit Card Validation code :\n");
        scanf("%s",ccvc);
        
        strcpy(userinfo[0],firstname);
        strcpy(userinfo[1],lastname);
        strcpy(userinfo[2],email);
        strcpy(userinfo[3],password);
        strcpy(userinfo[4],university);
        strcpy(userinfo[5],sdegree);
        strcpy(userinfo[6],city);
        strcpy(userinfo[7],country);
        strcpy(userinfo[8],secretquestion);
        strcpy(userinfo[9],secretanswer);
        strcpy(userinfo[10],ccn);
        strcpy(userinfo[11],ccvc);
        // add date after one year; formatted as d/d/d 
        getdate(tempInfo);
        strcpy(userinfo[12],tempInfo);
}
    void sign_up(char userinfo [][SIZE],int numberOfData){
        userinfo[numberOfData][SIZE];
    
        char dataToAppend[1000] = "";
        FILE * database = fopen("database_users.txt", "a+");

        for (int i = 0;i<numberOfData;i++){     
            if(numberOfData - i != 1){
                strcat(dataToAppend,userinfo[i]);
                strcat(dataToAppend,",");
            }else{
                strcat(dataToAppend,userinfo[i]);
                strcat(dataToAppend,"\n");
            }
        }
        printf("data carried ==> %s",dataToAppend);
        fprintf(database, "%s", dataToAppend);
        fclose(database);
    }

    void getdate(char date []){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char dateAfterYear[100];
    
    snprintf(dateAfterYear, sizeof(dateAfterYear), "%02d/%02d/%d",tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);   
    strcpy(date,dateAfterYear);
}

void displayIEEE(){   
    int c;
    FILE *file;
    file = fopen("IEEE_privacy_policy.txt", "r");
    if (file) {
    while ((c = getc(file)) != EOF)
        putchar(c);
    fclose(file);
    }
}

bool agreeToPolicy(){
    char choice;
    displayIEEE();
    do{
        printf("\nDo you accept IEEE privacy policy? (y/n): ");
        scanf(" %c", &choice);
        choice = tolower(choice);
    }while(choice != 'y' && choice != 'n');

    if (choice == 'y')
        return true;
    return false;
}

