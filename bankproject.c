/************************************************************************/
/*Title      : Bank Simulation Project  								*/
/*Names      : Parth  Patel and Dhyey Trivedi                           */
/*Course     : ICS4U1                                                   */
/*Date       : November 29th, 2018                                      */
/*Type		 : Culminating Project                                      */
/*Description: The program simulates a ATM machine where you can make   */
/*			   realtime transactions that stay in effect even once they */
/*			   are logged out of the system using files					*/
/************************************************************************/
#include<conio.h>
#include<stdio.h>
#include<time.h>
#include<windows.h>
#include<dos.h>
#include <mmsystem.h>


/**************************************************/
/*The following array  is a list of account pins  */
/*that we have in our directory, if more people   */
/*join, then simply add more account pins		  */
/**************************************************/
extern int arr[] = {9987, 7699, 7089, 4950, 7889,
					  1234, 6875, 9509, 3407, 4119};
/**************************************************/
/*The following array  is a list of account names */
/*that we have in our directory, if more people   */
/*join, then simply add more names       		  */
/**************************************************/
extern  char *name[] = {"Parth", "Dhyey", "Yugsan", "Vrajang", "Keval",
						"Mr.Tersigni", "Vasu", "Aman", "Chintan", "Chirag"};
/**************************************************/
/*The following array  is a list of file locations*/
/*that we have in our directory, if more people   */
/*join, then simply add more file names  		  */
/**************************************************/
extern char*fileloc[]={"0.txt","1.txt","2.txt","3.txt","4.txt",
					   "5.txt","6.txt","7.txt","8.txt","9.txt"};
/**************************************************/
/*IMPORTANT NOTICE FOR DEVELOPERs:IF YOU ADD MORE */
/*NAMES, THEN YOU MUST ADD MORE PINS AND FILE     */
/*NAMES, THANK YOU								  */
/**************************************************/



/*********************************************************************************/
/*The following function checks if the pin entered is valid or not and if it is  */
/*not valid, it asks to enter the pin again						                 */
/*********************************************************************************/
int checkid()
{
	int i=1,bx=700,by=1000;
	int p;												  /*The pin to be checked*/
	printf("\t\t   Please enter your PIN to continue: ");
	scanf("%d", &p);											   /*gets the pin*/
	while (p != checker(p))						   /*calls function and while the*/
												 /*pin doesnt match any other pin*/
	{
		if(i==10)
		{
			return 0;
		}
		system("cls");
		plogo();
		printf("\t\t   Invalid PIN\n");					 /*asks to enter it again*/
		printf("\t\t   %d Tries left\n",10-i);
		printf("\t\t   Please enter your PIN to continue: ");
		Beep(bx, by);  	  /*makes a sound to let passbyers know(security purpose)*/
		scanf("%d", &p);										 /*gets pin again*/
		i++;
		bx=bx+1000;
		by=by+1000;
	}
	return p;							/*once correct pin entered, pin is stored*/
}
/*********************************************************************************/
/*The following function takes the entered pin and checks if it matches any      */
/*account id																	 */
/*********************************************************************************/
int checker(int p)
{
	for (int i = 0;i < sizeof(arr);i++) /*checkes for all accounts under our bank*/
	{
		if (p == arr[i])  			/*if same, returns pin to let other func know*/
		{
			return p;
		}
	}
	return 0;											  /*else it will return 0*/
}
/*********************************************************************************/
/*The following function takes the entered pin and finds the location of the pin */
/*so it can be used in giving other details about person        				 */
/*********************************************************************************/
int location(int p)
{
	for (int i = 0;i < sizeof(arr);i++)		/*checks for all accounts in our bank*/
	{
		if (p == arr[i])							  /*if same as pin of account*/
		{
			return i;									   /*returns the location*/
		}
	}
}
/*********************************************************************************/
/*The following function prints the welcome page								 */
/*********************************************************************************/
void plogo()
{
	char ch = 0;
	FILE *a;
	a = fopen("logo.txt", "r");                   /*opens file "logo.txt" to read*/
	while ((ch = fgetc(a)) != EOF)                    /*while its not end of file*/
	{
		printf("%c", ch);                                 /*prints the characters*/
	}
	fclose(a);
}
/*********************************************************************************/
/*The following function prints the logo of our bank and then shows the options  */
/*********************************************************************************/
void pmain(int i)
{
	char ch = 0;
	FILE *a;
	a = fopen("reallogo.txt", "r");           /*opens file "reallogo.txt" to read*/
	while ((ch = fgetc(a)) != EOF)                    /*while its not end of file*/
	{
		printf("%c", ch);                                 /*prints the characters*/
	}
	fclose(a);
	printf("\n\t\t   Logged in as: %s", name[i]); /*prints the name of the person*/
	pOptions();								   /*prints the options that we offer*/
}
/*********************************************************************************/
/*The following function prints the options page								 */
/*********************************************************************************/
void pOptions()
{
	char ch = 0;
	FILE *a;
	printf("\n");
	a = fopen("options.txt", "r");             /*opens file "options.txt" to read*/
	while ((ch = fgetc(a)) != EOF)                    /*while its not end of file*/
	{
		printf("%c", ch);                                 /*prints the characters*/
	}
	fclose(a);
	printf("\nEnter your choice-> ");	 /*asks for choice but reads it in main()*/
}
/*********************************************************************************/
/*The following function prints the credits page								 */
/*********************************************************************************/
void pcredits()
{
	char ch = 0;
	FILE *a;
	a = fopen("credits.txt", "r");             /*opens file "credits.txt" to read*/
	while ((ch = fgetc(a)) != EOF)                    /*while its not end of file*/
	{
		printf("%c", ch);                                 /*prints the characters*/
	}
	fclose(a);
}
/*********************************************************************************/
/*The following function prints the thank you page  							 */
/*********************************************************************************/
void pexit()
{
	char ch = 0;
	FILE *a;
	a = fopen("exit.txt", "r");                   /*opens file "exit.txt" to read*/
	while ((ch = fgetc(a)) != EOF)                    /*while its not end of file*/
	{
		printf("%c", ch);                                 /*prints the characters*/
	}
	fclose(a);
}
/*********************************************************************************/
/*The following function prints the amount of money in your balance				 */
/*********************************************************************************/
void pmoney(int loc)
{
	system("cls");
	char ch = 0;
	int money=0,temp=0;
	FILE *a;
	a = fopen(fileloc[loc], "r");     /*opens 1 file from fileloc[] array to read*/
	while ((ch = fgetc(a)) != EOF)                    /*while its not end of file*/
	{
		temp= ch - '\0';	 /*converts the digits from char to int for money use*/
		temp=temp-48;
		money=(money*10)+temp;
	}
	fclose(a);
	pbal();												/*prints the balance page*/
	printf("   $%d",money);							 /*prints the amount of moeny*/
	printf("\n\t\t\t\t   Press enter to continue");
	printf("\n\t\t\t\t\t\t\t\t\t  |");
	printf("\n\t\t\t\t\t\t\t\t      ____|\n");
	getch();
}
/*********************************************************************************/
/*The following function prints the account balance page						 */
/*********************************************************************************/
void pbal()
{
	char ch = 0;
	FILE *a;
	a = fopen("checkbalance.txt", "r");   /*opens file "checkbalance.txt" to read*/
	while ((ch = fgetc(a)) != EOF)                    /*while its not end of file*/
	{
		printf("%c", ch);                                 /*prints the characters*/
	}
	fclose(a);
}
/*********************************************************************************/
/*The following function prints the moneyotions page which asks how much money   */
/*you want to add to your account												 */
/*********************************************************************************/
void pmoneyoptions()
{
	char ch = 0;
	FILE *a;
	a = fopen("moneyoptions.txt", "r");   /*opens file "moneyoptions.txt" to read*/
	while ((ch = fgetc(a)) != EOF)                    /*while its not end of file*/
	{
		printf("%c", ch);                                 /*prints the characters*/
	}
	fclose(a);
}
/*********************************************************************************/
/*The following function prints just the logo of our bank, just plain logo  	 */
/*********************************************************************************/
void preallogo()
{
	char ch = 0;
	FILE *a;
	a = fopen("reallogo.txt", "r");           /*opens file "reallogo.txt" to read*/
	while ((ch = fgetc(a)) != EOF)                    /*while its not end of file*/
	{
		printf("%c", ch);                                 /*prints the characters*/
	}
	fclose(a);
}
/*********************************************************************************/
/*The following function finds the amount of money in account and adds money to  */
/*account																		 */
/*********************************************************************************/
void padd(int x)
{
	system("cls");
	preallogo();												/*prints the logo*/
	char ch = 0;
	int money=0,temp=0,y=0,add=0;
	FILE *a;
	a = fopen(fileloc[x], "r");                              /*opens file to read*/
	while ((ch = fgetc(a)) != EOF)                    /*while its not end of file*/
	{
		temp= ch - '\0';								   /*converts char to int*/
		temp=temp-48;
		money=(money*10)+temp;
	}
	pmoneyoptions();					   	   /*opens the "how much to add" page*/
	scanf("%d",&y);
	/***************************************************/
	/*The following if/else statement finds out how    */
	/*much money you want to add					   */
	/***************************************************/
	while(y>7||y<1)
	{
		system("cls");
		preallogo();
		pmoneyoptions();
		scanf("%d",&y);
	}
	if(y==7)
	{
		return;
	}
	else if(y==1)
	{
	add=10;
	}
	else if(y==2)
	{
	add=20;
	}
	else if(y==3)
	{
	add=50;
	}
	else if(y==4)
	{
	add=100;
	}
	else if(y==5)
	{
	add=200;
	}
	/***************************************************/
	/*if they don't like the preset money options, they*/
	/* can create their own.						   */
	/***************************************************/
	else if(y==6)
	{
	printf("\n\t\tEnter Amount: ");
	scanf("%d",&add);
	}
	money=money+add;/*adds moeny to total*/
	system("cls");
	preallogo();
	a=fopen(fileloc[x],"w");		 /*opens file and stores the money value back*/
	if(a!=NULL)
	{
		fprintf(a,"%d",money);
		fclose(a);
	}
	printf("\n\n\t\t   $%d has been added to your account",add);	  /*job done!*/
	printf("\n\n\t\t   Please press enter to return to main menu");	  /*redirects*/
	getch();
}
/*********************************************************************************/
/*The following function prints the moneyotions page which asks how much money   */
/*you want to SUBTRACT to your account	    									 */
/*********************************************************************************/
void pmoneyoptions2()
{
	char ch = 0;
	FILE *a;
	a = fopen("moneyoptions2.txt", "r"); /*opens file "moneyoptions2.txt" to read*/
	while ((ch = fgetc(a)) != EOF)                    /*while its not end of file*/
	{
		printf("%c", ch);                                 /*prints the characters*/
	}
	fclose(a);
}
/*********************************************************************************/
/*The following function finds the amount of money in account and SUBS money from*/
/*account																		 */
/*********************************************************************************/
void psub(int x)
{
	system("cls");
	preallogo();												/*prints the logo*/
	char ch = 0;
	int money=0,temp=0,y=0,sub=0;
	FILE *a;
	a = fopen(fileloc[x], "r");                              /*opens file to read*/
	while ((ch = fgetc(a)) != EOF)                    /*while its not end of file*/
	{
		temp= ch - '\0';								   /*converts char to int*/
		temp=temp-48;
		money=(money*10)+temp;
	}
	pmoneyoptions2();					  /*opens the "how much to withdraw" page*/
	scanf("%d",&y);
	/***************************************************/
	/*The following if/else statement finds out how    */
	/*much money you want to subtract   			   */
	/***************************************************/
	while(y>7||y<1)
	{
		system("cls");
		preallogo();
		pmoneyoptions();
		scanf("%d",&y);
	}
	if(y==7)
	{
		return;
	}
	else if(y==1)
	{
	sub=10;
	}
	else if(y==2)
	{
	sub=20;
	}
	else if(y==3)
	{
	sub=50;
	}
	else if(y==4)
	{
	sub=100;
	}
	else if(y==5)
	{
	sub=200;
	}
	/***************************************************/
	/*if they don't like the preset money options, they*/
	/* can create their own.						   */
	/***************************************************/
	else if(y==6)
	{
	printf("\n\t\tEnter Amount: ");
	scanf("%d",&sub);
	}
	if(sub>money)
	{
		printf("\n\t\tYou do not have enough funds to withdraw money");
		printf("\n\t\tPress enter to return to main menu");
		getch();
		return;
	}
	money=money-sub;								 /*subtracts money from total*/
	system("cls");
	preallogo();
	a=fopen(fileloc[x],"w");					  /*stores new value back in file*/
	if(a!=NULL)
	{
		fprintf(a,"%d",money);
		fclose(a);
	}
	printf("\n\n\t\t   $%d has been subtracted from your account",sub);/*job done!*/
	printf("\n\n\t\t   Please press enter to return to main menu");	  /*redirects*/
	getch();
}
/*********************************************************************************/
/*The following function prints the pin service page						     */
/*********************************************************************************/
void ppinservice()
{
	system("cls");
	char ch = 0;
	FILE *a;
	a = fopen("pinedit.txt", "r"); 			   /*opens file "pinedit.txt" to read*/
	while ((ch = fgetc(a)) != EOF)                    /*while its not end of file*/
	{
		printf("%c", ch);                                 /*prints the characters*/
	}
	fclose(a);
	getch();
}
int main()
{
	int loc,id;
	int optionInput = 0;
	system("mode 100,35");						   /*sets the dimension of window*/
	system("color B1");							 /*sets the color theme of window*/
	plogo();													/*prints the logo*/
	id = checkid();									  /*asks for id and checks it*/
	if(id==0)
	{
		goto EXIT;
	}
	loc= location(id);					 /*gets the location of user in our array*/
	
	while (optionInput != 5)						  /*until user wants to leave*/
	{
		system("cls");
		pmain(loc);
		scanf("%d", &optionInput);				   /*asks for input of what to do*/
		while (optionInput < 1 || optionInput > 6)	 /*if invalid num, asks again*/
		{
			system("cls");
			pmain(loc);
			scanf("%d", &optionInput);
		}
		if(optionInput==2)								  /*if #2, checks balance*/
		{
			pmoney(loc);
		}
		else if(optionInput==1)								  /*if #1, adds money*/
		{
			padd(loc);
		}
		else if(optionInput==3)							 /*if #3, withdraws money*/
		{
			psub(loc);
		}
		else if(optionInput==4)								/*if #4, pin services*/
		{
			ppinservice();
		}
		else if (optionInput == 6)						   /*if #6, shows credits*/
		{
			system("cls");
			pcredits();
			getch();	
		}
		optionInput == 0;
	}
EXIT:{
		system("cls");
		pexit();									   /*thank you for using page*/
	}
	getch();
	return 0;
}

