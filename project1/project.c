#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include<conio.h>

#include<windows.h>

struct book

{

    char name[25];

    char date[20];

    int r1,r2,r3,balcony;

}b;



void Book_Ticket(); //for booking tickets

void View_Movie(); // for view now playing movie

void Add_Movie(); //for inserting new movie

void Delete_Movie(); // for deleting now playing movie

void Old_Transactions(); //for viewing old records of booked tickets

void Delete_Transactions(); //for deleting all transactions



void main()

{

    system("color 30");

    int ch;

    do

    {

        //system("cls");

        printf("\n||=======================================================================||");

        printf("\n||                                                                       ||");

        printf("\n||                Welcome to Moive Ticket Booking System                 ||");

        printf("\n||                                                                       ||");

        printf("\n||=======================================================================||");

        printf("\n||          Press [1] To Book Tickets                                    ||");

        printf("\n||-----------------------------------------------------------------------||");

        printf("\n||          Press [2] To View Now Playing Movie                          ||");

        printf("\n||-----------------------------------------------------------------------||");

        printf("\n||          Press [3] To Add New Movie (Admin Only)                      ||");

        printf("\n||-----------------------------------------------------------------------||");

        printf("\n||          Press [4] To Delete Now Playing Movie (Admin Only)           ||");

        printf("\n||-----------------------------------------------------------------------||");

        printf("\n||          Press [5] To View All Transactions (Admin Only)              ||");

        printf("\n||-----------------------------------------------------------------------||");

        printf("\n||          Press [6] To Delete All Transactions (Admin Only)            ||");

        printf("\n||-----------------------------------------------------------------------||");

        printf("\n||          Press [7] To Exit                                            ||");

        printf("\n||=======================================================================||");

        printf("\n||          Please Enter Your Choice::                                   ||");

        printf("\n||=======================================================================||\n\n");

        scanf("%d",&ch);

        switch (ch)

        {

            case 1 :

                Book_Ticket();

                break;



            case 2:

                View_Movie();

                break;



            case 3:

                Add_Movie();

                break;



            case 4:

                Delete_Movie();

                break;



            case 5:

                Old_Transactions();

                break;



            case 6:

                Delete_Transactions();

                break;



            case 7:

                printf("\n*** Thank You! Visit Again!!! ***\n\n");

                exit(0);



            default:

                printf("\nWrong choice!!!\nTry Again!!!");

                break;

        }

    }

    while(ch!=7);

}




void Book_Ticket()

{

    system("color 30");

    struct book b;

    FILE *fp;

    FILE *ufp;

    int total_seat,total_amount,row,temp_row,i,j,k,s1,s2,s3,s4;

    long long int mobile;

    char name1[15],name2[15];

    char ch,choice,ch1;

    fp=fopen("data.txt","r");

    if(fp==NULL)

    {

        printf("file does not found!");

        exit(1);

    }

    else if(ch=fgetc(fp)==EOF)

    {

        printf("\nNo Movie is available to book right now! Check after few days!!!");

        main();

    }

    else

    {

        system("cls");

        /*printf("================ Now Playing =====================");

        printf("\nMovie_Name  Release_Date  Ticket_Price");

        printf("\n==================================================\n");

        fp=fopen("data.txt","r");

        while((ch=fgetc(fp))!=EOF)

        printf("%c",ch);

        fclose(fp);*/

        fp=fopen("data.txt","r");

        fscanf(fp,"%s  %s  %d  %d  %d  %d\n%d %d %d %d",b.name,b.date,&b.r1,&b.r2,&b.r3,&b.balcony,&s1,&s2,&s3,&s4);

        printf("\n================ Now Playing =====================");

        printf("\nMovie Name: %s",b.name);

        printf("\nRelease Date (DD/MM/YYYY): %s",b.date);

        printf("\nTicket pricing (per seat):");

        printf("\n\t\tRow 1 to 4: %d Rs.",b.r1);

        printf("\n\t\tRow 5 to 8: %d Rs.",b.r2);

        printf("\n\t\tRow 9 to 12: %d Rs.",b.r3);

        printf("\n\t\tBalcony: %d Rs.",b.balcony);

        printf("\n==================================================");

    }

    if(s1==0&&s2==0&&s3==0&&s4==0)

    {

        printf("\nThe seats are full! Visit after few days...\n\n");

        main();

    }

    else

    goto choose;

    fclose(fp);

    choose:

    {

        fp=fopen("data.txt","r");

        fscanf(fp,"%s  %s  %d  %d  %d  %d\n%d %d %d %d",b.name,b.date,&b.r1,&b.r2,&b.r3,&b.balcony,&s1,&s2,&s3,&s4);

        fclose(fp);

        printf("\nDo you want to Book tickets for above movie?(y/n)\n");

        scanf("%s",&choice);

        if((choice=='y')||(choice=='Y'))

        {

            printf("\n***Fill Deatails***");

            name:

                printf("\nEnter your name (First Name<space>Last Name):");

                scanf("%s %s",name1,name2);

                //gets(name1);

                //gets(name2);

                //printf("\n%s %s",name1,name2);

                for(i=0;i<strlen(name1);i++)

                {

                    int j=name1[i];

                    if((j>=97 && j<=122) || (j>=65 && j<=90) || (j==32 && j==92))

                    {

                        //printf("\n%d",name1[i]);

                        continue;

                    }

                    else

                    {

                        printf("\nFirst name is invalid! Enter alphabets only!!!");

                        goto name;

                    }

                }

                for(i=0;i<strlen(name2);i++)

                {

                    k=name2[i];

                    if((k>=97 &&k <=122) || (k>=65 && k<=90) || (k==32 && k==92))

                    {

                        continue;

                    }

                    else

                    {

                        printf("\nLast name invalid! Enter alphabets only!!!");

                        goto name;

                    }

                }



            next:

                mobile=0;

                printf("\nEnter mobile number :");

                scanf("%lld",&mobile);

                if(mobile<=7000000000)

                {

                    printf("\nInvalid mobile number!!!\n");

                    goto next;

                }

                else if(mobile>9999999999)

                {

                    printf("\nInvalid mobile number!!!\n");

                    goto next;

                }

                else if(mobile>=7000000000 && mobile<=9999999999)

                {

                    goto seats;

                }

            seats:

                printf("\nSelect rows:\n1.Row 1 to 4: %d Rs per seat (%d seats available)\n2.Row 5 to 8: %d Rs per seat (%d seats available)\n3.Row 9 to 12: %d Rs per seat (%d seats available)\n4.Balcony: %d Rs per seat (%d seats available)\n",b.r1,s1,b.r2,s2,b.r3,s3,b.balcony,s4);

                scanf("%d",&row);

                temp_row=row;

                if(row==1)

                row=b.r1;

                else if(row==2)

                row=b.r2;

                else if(row==3)

                row=b.r3;

                else if(row==4)

                row=b.balcony;

                else

                {

                    printf("\nWrong Choice!!!");

                    goto seats;

                }

            fp=fopen("data.txt","r");

            fscanf(fp,"%s  %s  %d  %d  %d  %d\n%d %d %d %d",b.name,b.date,&b.r1,&b.r2,&b.r3,&b.balcony,&s1,&s2,&s3,&s4);

            fclose(fp);

            enter:

            printf("\nEnter total number of seats:");

            scanf("%d",&total_seat);

            if(total_seat==0)

            {

                printf("\nNumber of seats should not be 0...");

                goto enter;

            }

            else if(temp_row==1)

            {

                /*if(s1==0)

                {

                    printf("\nRow 1 to 4 is full!!!");

                    goto seats;

                }*/

                if(total_seat>s1)

                {

                    printf("\n%d seats are not available in row 1 to 4!",total_seat);

                    choice1:

                    printf("\nDo you want to change row?(1=Yes, 0=No)");

                    scanf("%d",&ch1);

                    if(ch1==1)

                    goto seats;

                    else if(ch1==0)

                    {

                        printf("\nOkay! No problem!!!\n\n");

                        Sleep(2000);

                        main();

                    }



                    else

                    {

                        printf("\nWrong choice!!!");

                        goto choice1;

                    }

                }

                else if(temp_row<=s1)

                {

                    s1=s1-total_seat;

                    goto booking;

                }

            }

            /*else if(s1==0)

            {

                printf("\nRow 1 to 4 is full!!!");

                goto seats;

            }*/

            else if(temp_row==2)

            {

                /*if(s2==0)

                {

                    printf("\nRow 5 to 8 is full!!! Choose another row...");

                    goto seats;

                }*/

                if(total_seat>s2)

                {

                    printf("\n%d seats are not available in row 5 to 8!",total_seat);

                    choice2:

                    printf("\nDo you want to change row?(1=Yes, 0=No)");

                    scanf("%d",&ch1);

                    if(ch1==1)

                    goto seats;

                    else if(ch1==0)

                    {

                        printf("\nOkay! No problem!!!\n\n");

                        main();

                    }

                    else

                    {

                        printf("\nWrong choice!!!");

                        goto choice2;

                    }

                }

                else if(temp_row<=s2)

                {

                    s2=s2-total_seat;

                    goto booking;

                }

            }

            else if(temp_row==3)

            {

                /*if(s3==0)

                {

                    printf("\nRow 9 to 12 is full!!! Choose another row...");

                    goto seats;

                }*/

                if(total_seat>s3)

                {

                    printf("\n%d seats are not available in row 9 to 12!",total_seat);

                    choice3:

                    printf("\nDo you want to change row?(1=Yes, 0=No)");

                    scanf("%d",&ch1);

                    if(ch1==1)

                    goto seats;

                    else if(ch1==0)

                    {

                        printf("\nOkay! No problem!!!\n\n");

                        main();

                    }

                    else

                    {

                        printf("\nWrong choice!!!");

                        goto choice3;

                    }

                }

                else if (temp_row<=s3)

                {

                    s3=s3-total_seat;

                    goto booking;

                }

            }

            else if(temp_row==4)

            {

                /*if(s4==0)

                {

                    printf("\nBalcony is full!!!");

                    goto seats;

                }*/

                if(total_seat>s4)

                {

                    printf("\n%d seats are not available in balcony!",total_seat);

                    choice4:

                    printf("\nDo you want to change row and book tickets? (1=Yes, 0=No)\n");

                    scanf("%d",&ch1);

                    if(ch1==1)

                    goto seats;

                    else if(ch1==0)

                    {

                        printf("\nOkay! No problem!!!\n\n");

                        main();

                    }

                    else

                    {

                        printf("\nWrong choice!!!");

                        goto choice4;

                    }

                }

                else if(temp_row<=s4)

                {

                    s4=s4-total_seat;

                    goto booking;

                }

            }

            booking:

            {

                total_amount=row*total_seat;



                printf("\nTckets Booked successfully!!!\n*** ENJOY MOVIE ***\nGenerating Bill");

                Sleep(750);

                printf(".");

                Sleep(750);

                printf(".");

                Sleep(750);

                printf(".");

                Sleep(750);

                printf("\n\t\t*** Bill ***");

                printf("\n========================================================");

                printf("\n\t\tName : %s %s",name1,name2);

                printf("\n\t\tMobile Number : %lld",mobile);

                printf("\n\t\tMovie name : %s",b.name);

                if(temp_row==1)

                printf("\n\t\tRow : 1 to 4");

                else if(temp_row==2)

                printf("\n\t\tRow : 5 to 8");

                else if(temp_row==3)

                printf("\n\t\tRow : 9 to 12");

                else if(temp_row==4)

                printf("\n\t\tRow : Balcony");

                printf("\n\t\tTotal seats : %d",total_seat);

                printf("\n\t\tCost per ticket : %d Rs.",row);

                printf("\n\t\tTotal Amount : %d Rs.",total_amount);

                printf("\n========================================================");

                printf("\n\nThank You! Visit again!!!\n\n");

                Sleep(2000);

                ufp=fopen("OldTransaction.txt","a");

                if(ufp == NULL)

                {

                    printf("File not Found!");

                }

                else

                {

                    fprintf(ufp,"%s %s %lld %d %d %d %s %d \n",name1,name2,mobile,total_seat,temp_row,total_amount,b.name,row);

                }

                printf("\n");

                fclose(ufp);

                ufp=fopen("data.txt","w");

                fprintf(ufp,"%s  %s  %d  %d  %d  %d\n%d %d %d %d",b.name,b.date,b.r1,b.r2,b.r3,b.balcony,s1,s2,s3,s4);

                //fclose(fp);

                fclose(ufp);

            }

        }

        else if((choice=='n')||(choice=='N'))

        {

            printf("No problem! Visit after few days!");

            exit(0);

        }

        else

        {

            printf("\nWrong Choice!!!");

            goto choose;

        }

    }

}




void View_Movie()

{

    system("color 30");

    char ch;

    int s1,s2,s3,s4;

    FILE *fp;



    fp = fopen("data.txt","r");

    if(fp == NULL)

    {

        printf("file does not found !");

        exit(1);



    }

    else

    {

        system("cls");

        if((ch=fgetc(fp))!=EOF)

        {

            /*printf("================ Now Playing =====================");

            printf("\nMovie_Name  Release_Date  Ticket_Price");

            printf("\n==================================================\n");

            do

            {

                printf("%c",ch);

            }

            while((ch=fgetc(fp))!=EOF);

            printf("\n===================================================\n\n");*/

            fp=fopen("data.txt","r");

            fscanf(fp,"%s  %s  %d  %d  %d  %d\n%d %d %d %d",b.name,b.date,&b.r1,&b.r2,&b.r3,&b.balcony,&s1,&s2,&s3,&s4);

            printf("================ Now Playing =====================");

            printf("\nMovie Name: %s",b.name);

            printf("\nRelease Date: %s",b.date);

            printf("\nTicket pricing:\n1.Row 1 to 4: %d Rs per seat (%d seats available)\n2.Row 5 to 8: %d Rs per seat (%d seats available)\n3.Row 9 to 12: %d Rs per seat (%d seats available)\n4.Balcony: %d Rs per seat (%d seats available)\n",b.r1,s1,b.r2,s2,b.r3,s3,b.balcony,s4);

            //printf("\nTicket pricing:\n\t\tRow 1 to 4: %d Rs.\n\t\tRow 5 to 8: %d Rs.\n\t\tRow 9 to 12: %d Rs.\n\t\tBalcony: %d Rs.\n\n",b.r1,b.r2,b.r3,b.balcony);

            Sleep(2000);

            fclose(fp);

            main();

        }

        else

        {

            printf("No movie available, please check after few days!!!");

            Sleep(2000);

            main();

        }

    }

    fclose(fp);

}




void Add_Movie()

{

    system("color 30");

    char temp2,password[]="password",p[100],p1[]="_back_",p2[]="_BACK_";

    int l,s1=40,s2=40,s3=40,s4=80;

    FILE *fp;

    struct book b;

    printf("\n\t\t\tCaution!!!\nThis will delete now playing movie (if available) and will add new movie!!!\nIf you want to go back then type '_back_' or '_BACK_'");

    login:

    {

            l=0;

            printf("\nEnter Password:");

            while(1)

            {

                temp2=getch();

                if(temp2=='\r')

                {

                    p[l]='\0';

                break;

                }

                else if(temp2=='\b')

                {

                    if(l>0)

                    {

                        l--;

                        printf("\b \b");

                    }

                }

                else if(temp2=='\t'||temp2==' ')

                {

                 continue;

                }

                else

                {

                    p[l]=temp2;

                    l++;

                    printf("*");

                }



            }

            //scanf("%s",&p);

            if(strcmp(p,password)==0)

            {

                system("cls");

                printf("\nPassword matched...\n");

                printf("Enter Movie name (Use '_' for spaces):- ");

                scanf("%s",b.name);

                printf("Enter Release Date(DD/MM/YYYY):- ");

                scanf("%s",b.date);

                printf("Enter Ticket Price for row 1 to 4 (Rs.):- ");

                scanf("%d",&b.r1);

                printf("Enter Ticket Price for row 5 to 8 (Rs.):- ");

                scanf("%d",&b.r2);

                printf("Enter Ticket Price for row 9 to 12 (Rs.):- ");

                scanf("%d",&b.r3);

                printf("Enter Ticket Price for balcony (Rs.):- ");

                scanf("%d",&b.balcony);

                fp=fopen("data.txt","w");



                if(fp==NULL)

                {

                    printf("File not Found");

                }

                else

                {

                    //fprintf(fp,"================ Now Playing =====================");

                    //fprintf(fp,"\nMovie_Code  Movie_Name  Release_Date  Ticket_Price");

                    //fprintf(fp,"\n==================================================");

                    fprintf(fp,"%s  %s  %d  %d  %d  %d\n%d %d %d %d",b.name,b.date,b.r1,b.r2,b.r3,b.balcony,s1,s2,s3,s4);

                    printf("Adding movie. Please wait");

                    Sleep(1000);

                    printf(".");

                    Sleep(1000);

                    printf(".");

                    Sleep(1000);

                    printf(".");

                    Sleep(1000);

                    printf("Movie added successfully...");

                }

                printf("\n");

                fclose(fp);

            }

            else if(strcmp(p,p1)==0||strcmp(p,p2)==0)

            {

                printf("\nOkay! Precess cancelled. Returning to main menu\n\n");

                Sleep(1000);

                printf(".");

                Sleep(1000);

                printf(".");

                Sleep(1000);

                printf(".");

                Sleep(1000);

                main();

            }

            else

            {

                printf("\nInvalid Password!!!");

                goto login;

            }

    }



}




void Delete_Movie()

{

    system("color 30");

    int l;

    FILE *fp;

    char temp2,password[]="password",p[100];

        login:

        {

            l=0;

            printf("\nEnter Password:");

            while(1)

            {

                temp2=getch();

                if(temp2=='\r')

                {

                    p[l]='\0';

                break;

                }

                else if(temp2=='\b')

                {

                    if(l>0)

                    {

                        l--;

                        printf("\b \b");

                    }

                }

                else if(temp2=='\t'||temp2==' ')

                {

                 continue;

                }

                else

                {

                    p[l]=temp2;

                    l++;

                    printf("*");

                }

            }

            //scanf("%s",&p);

            if(strcmp(p,password)==0)

            {

                printf("\nPassword matched...\n");

                fp = fopen("data.txt","w");

                if(fp == NULL)

                {

                    printf("file does not found!");

                    exit(1);

                }

                else

                {

                    printf("\nDeleting movie\n\n");

                    Sleep(1000);

                    printf(".");

                    Sleep(1000);

                    printf(".");

                    Sleep(1000);

                    printf(".");

                    Sleep(1000);

                    printf("\nMovie Deleted Successfully!!!\n\n");

                    Sleep(2000);

                    main();

                }

                fclose(fp);

            }

            else

            goto login;

        }

}




void Old_Transactions()

{

    system("color 30");

    char temp2,ch,password[]="password",p[100],p2[100];

    int l;

    FILE *fp;



    //system("clear");



    fp = fopen("OldTransaction.txt","r");

    if(fp == NULL)

    {

        printf("file does not found !");

        exit(1);



    }

    else

    {

        system("cls");

        login:

        {

            l=0;

            printf("\nEnter Password:");

            while(1)

            {

                temp2=getch();

                if(temp2=='\r')

                {

                    p[l]='\0';

                break;

                }

                else if(temp2=='\b')

                {

                    if(l>0)

                    {

                        l--;

                        printf("\b \b");

                    }

                }

                else if(temp2=='\t'||temp2==' ')

                {

                 continue;

                }

                else

                {

                    p[l]=temp2;

                    l++;

                    printf("*");

                }



            }

            //scanf("%s",&p);

            if(strcmp(p,password)==0)

            {

                system("cls");

                printf("\nPassword matched...\nFetching old transactions");

                Sleep(1000);

                printf(".");

                Sleep(1000);

                printf(".");

                Sleep(1000);

                printf(".");

                Sleep(1000);

                printf("\n\n\t***Old Ticket Booking Records***");

                printf("\n===============================================");

                printf("\nName  Mobile  Seats  Row  Bill  Movie  Price");

                printf("\n===============================================\n");

                while( ( ch = fgetc(fp))!=EOF)

                printf("%c",ch);

                  printf("===============================================\n\n");

            }

            else

            {

                printf("\nInvalid Password!!!");

                goto login;

            }

        }

    }

    fclose(fp);

}




void Delete_Transactions()

{

    system("color 30");

    int l;

    FILE *fp;

    char temp2,password[]="password",p[100];

        login:

        {

            l=0;

            printf("\nEnter Password:");

            while(1)

            {

                temp2=getch();

                if(temp2=='\r')

                {

                    p[l]='\0';

                break;

                }

                else if(temp2=='\b')

                {

                    if(l>0)

                    {

                        l--;

                        printf("\b \b");

                    }

                }

                else if(temp2=='\t'||temp2==' ')

                {

                 continue;

                }

                else

                {

                    p[l]=temp2;

                    l++;

                    printf("*");

                }



            }

            //scanf("%s",&p);

            if(strcmp(p,password)==0)

            {

                printf("\nPassword matched...");

                fp = fopen("OldTransaction.txt","w");

                if(fp == NULL)

                {

                    printf("file does not found!");

                    exit(1);

                }

                else

                {

                    printf("\nDeleting old transactions");

                    Sleep(1000);

                    printf(".");

                    Sleep(1000);

                    printf(".");

                    Sleep(1000);

                    printf(".");

                    Sleep(1000);

                    printf("\nOld transactions Deleted Successfully!!!\n");

                    Sleep(2000);

                    main();

                }

            }

            else

            goto login;

        }

    fclose(fp);

}
