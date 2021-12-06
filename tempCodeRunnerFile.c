#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
//#include <windows.h>

   struct person
{
    char firstname[35];
    char lastname[35];
    char fathername[40];
    char mothername[40];
    long int mobilenum;
    char mail[100];
    char postalcode[20];
    char place[20];
    char street[50];
    char sex[8];

};

void menu();//This function is used to display the main menu.
void got();
void start();//This functions calls the menu function mentioned above.
void goback();//This function is used to go back to start.
void addrecord();// It adds a new Phonebook record.
void listrecord();//This function is used to view list of added records in file.
void modifyrecord();//This function is used to modify added records.
void deleterecord();// It deletes record from file.
void searchrecord();// It searches for added record by name.

int main()
{
    system("color 3f");
    start();
    return 0;
}

void goback()
{
    start();
}

void start()
{
    menu();
}

void menu()
{
    system("cls");
    printf("(C) skvll\n");
    printf("\t\t**********___PHONEBOOK___*************");

    printf("\n\n\tt\t\t MENU\t\t\n\n");
    printf("\t1-ADD NEW \t2-LIST    \t3-EXIT    \t4-MODIFY  \t5-SEARCH\t6-DELETE");

    switch (getch())
    {
    case '1' :
        addrecord();
    break;
    case '2' : listrecord();
    break;
    case '3' : exit(0);
    break;
    case '4' : modifyrecord();
    break;
    case '5' : searchrecord();
    break;
    case '6' : deleterecord();
    break;
    default:
    
        system("cls");
        printf("\nEnter 1 - 6 ");
        printf("\n Enter any key");
        getch();

        
         menu();

    }
}

void addrecord()
{
   system("cls");
        FILE *f;
        struct person p;                                        
        f=fopen("entry","a+");
        printf("\nEnter FirstName: ");
        got(p.firstname);
        printf("\nEnter LastName: ");
        got(p.lastname);
        printf("\nEnter Father Name: ");
        got(p.fathername);
        printf("\nEnter Mother Name: ");
        got(p.mothername);
        printf("\nEnter Mobile Number: ");
        scanf("%ld",&p.mobilenum);  //longint
        printf("Enter Gender: ");
        got(p.sex);
        printf("\nEnter e-Mail: ");
         got(p.mail);
        printf("\nEnter Postal Code : ");
        got(p.postalcode);
        printf("\nEnter Place: ");
        got(p.place);
        printf("\nEnter Street + Street NO: ");
        got(p.street);

        fwrite(&p,sizeof(p),1,f);

      fflush(stdin);
        printf("\nRecord Saved !!");

fclose(f);

    printf("\n\nEnter Any Key");

     getch();
    system("cls");
    menu();
}

void listrecord()
{
    struct person p;
    FILE *f;
    f=fopen("entry","r");
    if(f==NULL)
    {
        printf("\nThere was an error trying to open the file : ");
        exit(1);

    }

    while (fread(&p,sizeof(p),1,f)==1)
    {
       printf("\n\n\n Your Record is :\n\n ");
       printf("\nFirstName : %s\nLastName : %s\nFatherName: %s\nMotherName: %s\nMobileNumber : %ld\nGender : %s\nMail : %s\nPostalCode : %s\nPlace : %s\nStreet: %s\n",p.firstname,p.lastname,p.fathername,p.mothername,p.mobilenum,p.sex,p.mail,p.postalcode,p.place,p.street);

        getch();
        system("cls");
    }

    fclose(f);
    printf("\nEnter Any Key");
    getch();
    system("cls");
    menu();
}

void searchrecord()
{
    struct person p;
    FILE *f;
    char lastname[100];

    f=fopen("entry","r");
    if(f==NULL)
    {
        printf("\nError In Opening\a\a\a\a");
        exit(1);
    }

    printf("\nEnter Last Name Of Person To Search For :\n");
    got(lastname);
    while (fread(&p,sizeof(p),1,f)==1)
    {
        if (strcmp(p.lastname,lastname)==0)
        {
            printf("\n\tInformation About %s",lastname);
            printf("\nFirstName : %s\nLastName : %s\nFatherName: %s\nMotherName: %s\nMobileNumber : %ld\nGender : %s\nMail : %s\nPostalCode : %s\nPlace : %s\nStreet: %s\n",p.firstname,p.lastname,p.fathername,p.mothername,p.mobilenum,p.sex,p.mail,p.postalcode,p.place,p.street);
        }
        else
        printf("404 ! FILE NOT FOUND !");
        
    }

    fclose(f);
    printf("\nEnter Any Key");

        getch();
        system("cls");

    menu();
    
}

void deleterecord()
{
    struct person *p;
    FILE *f,*ft;
    int flag;
    char lastname[100];
    f=fopen("entry","r");
    if(f==NULL)
        {

            printf("\nCONTACT'S DATA NOT ADDED YET.");

        }
    else
    {
        ft=fopen("entrytemp","w+");
        if(ft==NULL)

            printf("File Opening Error");
        else
        {
            printf("\nEnter Contact Name : ");
            got(lastname);
            
            fflush(stdin);
            while(fread(&p,sizeof(p),1,f)==1)

        {
            if(strcmp(p->lastname,lastname)!=0)
                fwrite(&p,sizeof(p),1,ft);
            if(strcmp(p->lastname,lastname)==0)
                flag=1;
        }
        fclose(f);
        fclose(ft);
        if(flag!=1)

        {
        printf("\nNO CONACT RECORD TO DELETE.");
        remove("entrytemp.txt");
    }
        else
        {
            remove("entry");
            rename("entrytemp.txt","entry");
            printf("\nRECORD DELETED SUCCESSFULLY.");

        }
    }
}
         printf("\nEnter Any Key");

        getch();
        system("cls");
        menu();
}

void  modifyrecord ()
{
    int c;
    FILE *f;
    int flag = 0;
    struct  person p,s;
    char lastname[50];
    f=fopen("entry","r+");
    if(f==NULL)
    {
        printf("\nCONTACT DATA NOT ADDED YET.");
        exit(1);
    }

    else
    {
        system("cls");
            printf("\nENTER CONTACT LASTNAME TO MODIFY: \n");
            got(lastname);
            while (fread(&p,sizeof(p),1,f)==1)
            {
                if (strcmp(lastname,p.lastname)==0)
                {
                   printf("\nEnter FirstName: ");
                got(s.firstname);
                printf("\nEnter LastName: ");
                got(s.lastname);
                printf("\nEnter Father Name: ");
                got(s.fathername);
                printf("\nEnter Mother Name: ");
                got(s.mothername);
                printf("\nEnter Mobile Number: ");
                scanf("%ld",&s.mobilenum);  //longint
                printf("Enter Gender: ");
                got(s.sex);
                printf("\nEnter e-Mail: ");
                got(s.mail);
                printf("\nEnter Postal Code : ");
                got(s.postalcode);
                printf("\nEnter Place: ");
                got(s.place);
                printf("\nEnter Street + Street NO: ");
                got(s.street);
                    fseek(f,-sizeof(p),SEEK_CUR); //SEEK_CUR    
                    fwrite(&s,sizeof(p),1,f);
                    flag=1;
                    break;
                }

                fflush(stdin);
                
            }

            if(flag == 1)
            {
                printf("\n Your Data Is Modified!");
            }
            else
            {
                printf("Data Not Found!");
            }

            fclose(f);
    }

    printf("\nEnter Any Key");
    getch();
    system("cls");
    menu();

}

void got (char *lastname)
{
    int i = 0,j;
    char c,ch;

    do
    {
        c=getch();
        if(c!=8&&c!=13)
        {
            *(lastname+i) = c;
            putch(c);
            i++;
        }
        if(c==8)
                {
                    if(i>0)
                    {
                        i--;
                    }
                   // printf("h");
                    system("cls");
                    for(j=0;j<i;j++)
                    {
                        ch=*(lastname+j);
                        putch(ch);
                    }
                }
    }
    while (c!=13);
   *(lastname+i) = '\0'; // null terminator
    }