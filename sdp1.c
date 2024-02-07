#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

struct Details_of_product
{
    char P_name[30];
    float P_price;
    char P_code[6];
};

void get_name_from_code(char code_input[])
{
    FILE *in = fopen("allproduct.txt", "r");
    int id;
    char name[20];
    char code[20];
    float price;
    while (fscanf(in, "%d %s %s %f", &id, name, code, &price) != EOF)
    {
        if (strcmp(code, code_input) == 0)
        {
            fclose(in);
            printf("Product name: %s", name);
        }
        else
        {
            printf("Product name: NOT FOUND");
        }

    }
    fclose(in);
}

void get_name2_from_code(char code_input[])
{
    FILE *in = fopen("allproduct.txt", "r");
    int id;
    char name[20];
    char code[20];
    float price;
    while (fscanf(in, "%d %s %s %f", &id, name, code, &price) != EOF)
    {
        if (strcmp(code, code_input) == 0)
        {
            fclose(in);
            printf("Product name: \t\t%s", name);
        }
         else
        {
            printf("Product name: NOT FOUND");
        }
    }
    fclose(in);
}

float get_price_from_code(char code_input[])
{
    FILE *in = fopen("allproduct.txt", "r");
    int id;
    char name[20];
    char code[20];
    float price;
    float tk;
    while (fscanf(in, "%d %s %s %f %s", &id, name, code, &price,tk) != EOF)
    {

        if (strcmp(code, code_input) == 0)
        {
            fclose(in);
            return price;
        }
    }
    fclose(in);
    return -1;
}

float CalculatePrice(int a, float b){ return a*b;}

void step_for_buy()
{
     printf("\n \n\n");
    printf("\How To Buy The Product.....\n");
    printf("\nStep 1: ");
    printf("\tSelect Buy Product(2) Option. \n");
    printf("\nStep 2: ");
    printf("\tEnter Correct Product Code. \n");
     printf("\nStep 3: ");
    printf("\tEnter Number Of Product. \n");
     printf("\nStep 4: ");
    printf("\tSelect Confirm Order Option. \n");
     printf(" \n\n");
    printf("\t\t*** You Will Then Receive Your Receipt *** \n");

}


void logout_function()
{
    printf("Do you want to logout ??\n");
}


int main ()
{
    struct Details_of_product product[100];
    int i;

    int SerialNumber=0;

    FILE *storeProduct;
    FILE *ALLpRODUCT;
    FILE *Intro;
    FILE *abuts;

    char entered_code[20];
    float Return_price;
    float bil;    // after calculate price

    int Product_Q;  //costumer need product number


    char user_code[100];     //user code variable
    char ch;

    int so,a;       //select option for see product,buy,about and Logout variable


//just for file no need this 77 to 80

    Intro=fopen("IntroText.txt","a");
    fclose(Intro);
    abuts=fopen("aboutText.txt","a");
    fclose(abuts);


    //start program hare .  inter page start here

    Intro=fopen("IntroText.txt","r");
    while (!feof(Intro))
    {
        ch=fgetc(Intro);
        printf("%c",ch);

    }
    fclose(Intro);

    int is_admin=0;
    while(!is_admin)
    {
        int a;
        printf("\n\nEnter User or Admin code: ");
        gets(user_code);
        if(user_code[0]=='u'&&user_code[1]=='s'&&user_code[2]=='e'&&user_code[3]=='r'&&user_code[4]=='0'&&user_code[5]=='1'&&user_code[6]=='n'&&user_code[7]=='i'&&user_code[8]=='0'&&user_code[9]=='9'&&user_code[10]=='5'&&user_code[11]=='\0'||user_code[0]=='n'&&user_code[1]=='i'&&user_code[2]=='g'&&user_code[3]=='h'&&user_code[4]=='t'&&user_code[5]=='f'&&user_code[6]=='u'&&user_code[7]=='r'&&user_code[8]=='y'&&user_code[9]=='9'&&user_code[10]=='5'&&user_code[11]=='\0')
            is_admin=1;
        else
            printf("\nWrong User or Admin code. please try again.\n");
    }

    if(user_code[0]=='u'&&user_code[1]=='s'&&user_code[2]=='e'&&user_code[3]=='r'&&user_code[4]=='0'&&user_code[5]=='1'&&user_code[6]=='n'&&user_code[7]=='i'&&user_code[8]=='0'&&user_code[9]=='9'&&user_code[10]=='5')
    {
home:

        printf("\n1.SEE ALL PRODUCTS.\n2.BUY PRODUCTS\n3.ABOUT SHOP\n4.HOW TO BUY THE PRODUCT\n5.LOG OUT\n");

        is_admin=0;
        while(!is_admin)
        {
            printf("\nSelect another option: ");
            scanf("%d",&so);
            if(1<=so&&so<=5)
                is_admin=1;
            else
                printf("\nOh shit!!! Option %d is not available, please select between 1 to 5.\n",so);
        }

// See product is start here.

        if (so==1)
        {
            printf("\n\n");
            printf("\n:::::::::> PRODUCT LIST <:::::::::\n\n");
            storeProduct=fopen("Productlist.txt","r");
            while (!feof(storeProduct))
            {
                ch=fgetc(storeProduct);
                printf("%c",ch);

            }
            fclose(storeProduct);

            ALLpRODUCT=fopen("allproduct.txt","r");
            while (!feof(ALLpRODUCT))
            {
                ch=fgetc(ALLpRODUCT);
                printf("%c",ch);

            }
            fclose(ALLpRODUCT);
            printf("\n\n");

            printf("\n1.Back\n2.Order\n");
            is_admin=0;
            while(!is_admin)
            {

                printf("\nSelect Correct option: ");
                scanf("%d",&a);
                if(1==a||a==2)
                    is_admin=1;
                else
                    printf("\nOption %d is not available, please select Correct Option.\n",a);
            }
            if(a==1)
            {
                goto home;
            }
            else if(a==2)
            {
                goto buy;
            }


        }

        //Order option is start here.

        else if (so==2)
        {
buy:  //2nd level

            printf("\n\n");
            printf("\n:::::::::> PRODUCT LIST <:::::::::\n\n");
            storeProduct=fopen("Productlist.txt","r");
            while (!feof(storeProduct))
            {
                ch=fgetc(storeProduct);
                printf("%c",ch);

            }
            fclose(storeProduct);

            ALLpRODUCT=fopen("allproduct.txt","r");
            while (!feof(ALLpRODUCT))
            {
                ch=fgetc(ALLpRODUCT);
                printf("%c",ch);

            }
            fclose(ALLpRODUCT);
            printf("\n\n");
            printf("::::::: Start Product Buy Process :::::::");
            printf("\n\n");
            is_admin=0;
            while(!is_admin)
            {
                printf("\n\n");
                printf("Enter Correct Product Code: ");
                scanf("%s", entered_code);
                Return_price = get_price_from_code(entered_code);

                if (Return_price != -1)
                {
                    is_admin=1;

                }
                else
                {
                    printf("\nNOT FOUND!! Enter Correct Product Code.");
                }
            }

            printf("\n\n");

            get_name_from_code(entered_code);
            printf("\n\n");


            printf("How Many Product: ");
            scanf("%d", &Product_Q);

            bil=CalculatePrice(Product_Q,Return_price);

            printf("\n\n");

            is_admin=0;
            while(!is_admin)
            {
                printf("1.Confirm Order\n2.Back");
                printf("\n\n");
                printf("Select Correct option: ");
                scanf("%d",&a);
                if(1==a||a==2)
                {
                    is_admin=1;
                }

                else
                    printf("\nOption %d is not available, please select Correct Option.\n\n",a);
            }

            if(a==2)
            {
                goto home;
            }
            else if (a==1)
            {
                printf("\n\n");
                printf("\n\n");
                printf("\n\n");
                printf("::::::: Your Recipt :::::::");
                printf("\n\n");
                get_name2_from_code(entered_code);
                printf("\n");
                printf("Product Price: \t\t%.2f Tk",Return_price);
                printf("\n");
                printf("Number Of Product: \t%d pice",Product_Q);
                printf("\n");
                printf("---------------------------------------");
                printf("\n");
                printf("Total Amount: \t\t%.2f Tk",bil);
                printf("\n\n");
                printf("\n\n");
                printf("\n\n");

            }



            is_admin=0;
            while(!is_admin)
            {

                printf("1.Home\n2.Logout\n");
                printf("\nSelect Correct option: ");
                scanf("%d",&a);
                if(1==a||a==2)
                    is_admin=1;
                else
                    printf("\nOption %d is not available, please select Correct Option.\n",a);
            }
            if(a==1)
            {
                goto home;
            }
            else if(a==2)
            {
                goto Coder_Meharaz_Hossain;
            }

        }

//about shop option is start here.
        else if (so==3)
        {


            printf("\n");
            abuts=fopen("aboutText.txt","r");
            while (!feof(abuts))
            {
                ch=fgetc(abuts);
                printf("%c",ch);

            }
            fclose(abuts);

            printf("\n\n");

            printf("\n1.Back\n");
            is_admin=0;
            while(!is_admin)
            {

                printf("\nSelect Back option: ");
                scanf("%d",&a);
                if(1==a)
                    is_admin=1;
                else
                    printf("\nOption %d is not available, please select Back Option.\n",a);
            }
            if(a==1)
            {
                goto home;
            }

        }

//help option is start here.
        else if (so==4)
        {


            step_for_buy();
            printf("\n\n");

            printf("\n1.Back\n");
            is_admin=0;
            while(!is_admin)
            {

                printf("\nSelect Back option: ");
                scanf("%d",&a);
                if(1==a)
                    is_admin=1;
                else
                    printf("\nOption %d is not available, please select Back Option.\n",a);
            }
            if(a==1)
            {
                goto home;
            }
        }

//logout option is start here
        else if (so==5)
        {

Coder_Meharaz_Hossain:

            printf("\n");
            logout_function();
            printf("\n");
            printf("1. YES\n2. NO");
            printf("\n");
            is_admin=0;
            while(!is_admin)
            {
                printf("\nSelect Correct option: ");
                scanf("%d",&a);
                if(a==1||a==2)
                    is_admin=1;
                else
                    printf("\nExcuse me, Option %d is not correct, please select correct option.\n",a);
            }

            if(a==1)
            {
                exit(0);
            }
            else if(a==2)
            {
                printf("\n1.Back\n");
                is_admin=0;
                while(!is_admin)
                {

                    printf("\nSelect Back option: ");
                    scanf("%d",&a);
                    if(1==a)
                        is_admin=1;
                    else
                        printf("\nOption %d is not available, please select Back Option.\n",a);
                }
                if(a==1)
                {
                    goto home;
                }

            }

        }

    }
    else  if(user_code[0]=='n'&&user_code[1]=='i'&&user_code[2]=='g'&&user_code[3]=='h'&&user_code[4]=='t'&&user_code[5]=='f'&&user_code[6]=='u'&&user_code[7]=='r'&&user_code[8]=='y'&&user_code[9]=='9'&&user_code[10]=='5')
    {
meharaz:

        printf("\n1.Available Products.\n2.Update Product\n3.Logout\n");

        is_admin=0;
        while(!is_admin)
        {
            printf("\nSelect another option: ");
            scanf("%d",&so);
            if(1<=so&&so<=3)
                is_admin=1;
            else
                printf("\nOption %d is not available, please select between 1 to 3.\n",so);
        }


//available product option is start here.
        if (so==1)
        {
            printf("\n\n");
            printf("\n:::::::::> PRODUCT LIST <:::::::::\n\n");
            storeProduct=fopen("Productlist.txt","r");
            while (!feof(storeProduct))
            {
                ch=fgetc(storeProduct);
                printf("%c",ch);

            }
            fclose(storeProduct);

            ALLpRODUCT=fopen("allproduct.txt","r");
            while (!feof(ALLpRODUCT))
            {
                ch=fgetc(ALLpRODUCT);
                printf("%c",ch);

            }
            fclose(ALLpRODUCT);
            printf("\n\n");

            printf("\n\n");
            printf("1.Update Product\n2.Back\n");

            is_admin=0;
            while(!is_admin)
            {

                printf("\nSelect Correct option: ");
                scanf("%d",&a);
                if(1==a||a==2)
                    is_admin=1;
                else
                    printf("\nOption %d is not available, please select Correct Option.\n",a);
            }
            printf("\n"); // need new line then give a new line here. ok
            if(a==1)
            {
                goto Meharaz;
            }
            else if (a==2)
            {
                goto meharaz;
            }

        }

//update option is start here.
        else if (so==2)

        {
            printf("\n\n");

            printf("\n:::::::::> PRODUCT LIST <:::::::::\n\n");

            storeProduct=fopen("Productlist.txt","r");

            while (!feof(storeProduct))
            {
                ch=fgetc(storeProduct);
                printf("%c",ch);

            }
            fclose(storeProduct);

            ALLpRODUCT=fopen("allproduct.txt","r");

            while (!feof(ALLpRODUCT))
            {
                ch=fgetc(ALLpRODUCT);
                printf("%c",ch);

            }
            fclose(ALLpRODUCT);

            printf("\n\n");

            printf("1.Update Product\n2.Back\n");

            is_admin=0;
            while(!is_admin)
            {

                printf("\nSelect Correct option: ");
                scanf("%d",&a);
                if(1==a||a==2)
                    is_admin=1;
                else
                    printf("\nOption %d is not available, please select Correct Option.\n",a);
            }
            printf("\n\n");

            if(a==1)

            {
Meharaz:

                printf("\nEnter Serial Number: ");
                scanf("%d",&SerialNumber);

                for(i=SerialNumber; i<SerialNumber+1; i++)

                {
                    printf("\n");
                    printf("Enter Product Name: ");
                    scanf("%s",product[i].P_name);
                    printf("Enter Product Code: ");
                    scanf("%s",product[i].P_code);
                    printf("Enter Product Price: ");
                    scanf("%f",&product[i].P_price);



                    ALLpRODUCT=fopen("allproduct.txt","a");

                    fprintf(ALLpRODUCT,"\n\t%-16d%-32s%-17s%15.2f Tk\n",SerialNumber,product[i].P_name,product[i].P_code,product[i].P_price);
                    fclose(ALLpRODUCT);

                }

                printf("\n\n");
                printf("1.Re-Update Product\n2.Back\n");

                is_admin=0;
                while(!is_admin)
                {

                    printf("\nSelect Correct option: ");
                    scanf("%d",&a);
                    if(1==a||a==2)
                        is_admin=1;
                    else
                        printf("\nOption %d is not available, please select Correct Option.\n",a);
                }

                if(a==1)
                {
                    goto Meharaz;
                }
                else if (a==2)
                {
                    goto meharaz;
                }


            }
            else if (a==2)
            {
                goto meharaz;
            }


        }

//logout option is start here.
        else if (so==3)
        {
            printf("\n");
            logout_function();
            printf("\n");
            printf("1. YES\n2. NO");
            printf("\n");
            is_admin=0;
            while(!is_admin)
            {
                printf("\nSelect Correct option: ");
                scanf("%d",&a);
                if(a==1||a==2)
                    is_admin=1;
                else
                    printf("\nExcuse me, Option %d is not correct, please select correct option.\n",a);
            }

            if(a==1)
            {
                exit(0);
            }
            else if(a==2)
            {
                printf("\n1.Back\n");
                is_admin=0;
                while(!is_admin)
                {

                    printf("\nSelect Back option: ");
                    scanf("%d",&a);
                    if(1==a)
                        is_admin=1;
                    else
                        printf("\nOption %d is not available, please select Back Option.\n",a);
                }
                if(a==1)
                {
                    goto meharaz;
                }

            }
        }
    }


    getch();
}

