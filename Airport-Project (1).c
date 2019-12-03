#include<stdio.h>
#include<string.h>
#include<conio.h>
int New();
void Stock();
struct{
	char name[25];
	char airline[20];
	char current_location[30];
	char destination[30];
	char date_of_departure[15];
	int tickets;
	char credit_card[30];
	char address[100];
	char Class[10];
	char time[10];
	int ticket_type;
}add,check;
//Globally declaring two variables to check and add whilst comparing the two while showing output

float bill(char u[25],int p) //Passes the name to compare and find it's corresponding details,p being number of tickets
{
	float bill,tempbill;
	FILE *fpro;
	fpro=fopen("flight details.txt","r");
	if(fpro==NULL)
	{
	printf("\n The file was not able to open!");
	}
	while(fscanf(fpro,"%s %s %s %s %s %d %s %s %s %s %d\n",&add.name,&add.airline,&add.current_location,&add.destination,&add.date_of_departure,&add.tickets,&add.credit_card,&add.address,&add.Class,&add.time,&add.ticket_type)!=EOF)
	{ //looping till end of file
			if(strcmp(u,add.name)==0) //compare to check if the assumed name is present in the records or not
			{
				if(strcmp(add.airline,"Emirates")==0) //comparing to see if the string in the structure is equals to the given string
				{
					if(strcmp(add.Class,"Business")==0)
					{
						tempbill=p*50000;
					}
					else if(strcmp(add.Class,"First_Class")==0)
					{
						tempbill=p*45000;
					}
					else if(strcmp(add.Class,"Economy")==0)
					{
						tempbill=p*40000;
					}
				}
				else if(strcmp(add.airline,"Qatar_Airways")==0)
				{
					if(strcmp(add.Class,"Business")==0)
					{
						tempbill=p*40000;
					}
					else if(strcmp(add.Class,"First_Class")==0)
					{
						tempbill=p*35000;
					}
					else if(strcmp(add.Class,"Economy")==0)
					{
						tempbill=p*30000;
					}
				}
				else if(strcmp(add.airline,"Pakistan_International_Airlines")==0)
				{
					if(strcmp(add.Class,"Business")==0)
					{
						tempbill=p*30000;
					}
					else if(strcmp(add.Class,"First_Class")==0)
					{
						tempbill=p*25000;
					}
					else if(strcmp(add.Class,"Economy")==0)
					{
						tempbill=p*20000;
					}
				}
				if(add.ticket_type=1)
				{
					bill=tempbill;
				}
				else
				{
					bill=tempbill*2;
				}
				
			}			
	}
	fclose(fpro);
	return bill;
}

int main()
{
	int choice,p;
	printf("\n\n\t\t WELCOME TO AIRPORT SERVICES");
	printf("\n\t\t ---------------------------");
	printf("\n\t\t (1) Place Order");
	printf("\n\t\t (2) Print Ticket");
	printf("\n\t\t (3) Exit");
	scanf("%d", &choice);
	switch (choice)
	{
		case 1:
			New();
			break;
		case 2:	
			Stock();		
			break;			
		case 3:
			system("cls");
			break;			
		default:
			system("cls");
			printf("\n\t      SELECT BETWEEN THE ABOVE OPTIONS ONLY!");
			main();
			break;			
	}
	return 0;
}

int New()
{
	int option,option2,option3,option4,ticketchoice; //Available airlines,Date of departure,time of departure,Class
	system("cls");
	FILE *fp;
	fp=fopen("flight details.txt","a+");
	if(fp==NULL)
	{
	printf("\n The file was not able to open!");
	}		
	fflush(stdin);
//	new_order:
	printf("\n Enter Name \t\t");	
	gets(add.name); //stores name
	fflush(stdin);  // 
	printf("\n ***Return ticket is double (in price) of one-way ticket!***");
	printf("\n (1) One-way Ticket \n (2) Return Ticket");
	scanf("%d",&ticketchoice);
	fflush(stdin);
	if(ticketchoice==1)
	{
		add.ticket_type=1;
	}
	else if(ticketchoice==2)
	{
		add.ticket_type=2;
	}
	else
	{
		printf("\n Invalid Choice!");
		New();	
	}
	{
	printf("\n The Available Airlines are: (1) Emirates \n\t\t\t     (2) Qatar Airways \n\t\t\t     (3) Pakistan International Airlines");
	printf("\n\n Choose from the above choices only");
	scanf("%d",&option);
	fflush(stdin);
	if(option==1)
	{
	 strcpy(add.airline, "Emirates");
	 printf("\n Enter your Date of Depature \t\t");
	 printf("\n (1) August 10, 2017 \n (2) August 11, 2017\n (3) August 12, 2017");
	 scanf("%d",&option3);
	 fflush(stdin);
	 		if(option3==1)
	 		{
	 			strcpy(add.date_of_departure, "August10,2017");
	 			printf("\n Enter your Time of Depature \t\t");
				printf("\n (1) 6.00am \n (2) 12.00pm \n (3) 6.00pm ");
				scanf("%d",&option4);
				fflush(stdin);
				if (option4==1)
				{
					strcpy(add.time, "6.00am");
				}
				else if (option4==2)
				{
					strcpy(add.time, "12.00pm");
				}
				else if (option4==3)
				{
					strcpy(add.time, "6.00pm");
				}
				else
				{
					printf("\n Invalid Choice");
				}	 
			}
			else if(option3==2)
	 		{
	 			strcpy(add.date_of_departure, "August11,2017");
	 			printf("\n Enter your Time of Depature \t\t");
				printf("\n (1) 7.00am \n (2) 1.00pm \n (3) 7.00pm ");
				scanf("%d",&option4);
				fflush(stdin);
				if (option4==1)
				{
					strcpy(add.time, "7.00am");
				}
				else if (option4==2)
				{
					strcpy(add.time, "1.00pm");
				}
				else if (option4==3)
				{
					strcpy(add.time, "7.00pm");
				}
				else
				{
					printf("\n Invalid Choice");
				}
			}
			else if(option3==3)
	 		{
	 			strcpy(add.date_of_departure, "August12,2017");
	 			printf("\n Enter your Time of Depature \t\t");
				printf("\n (1) 8.00am \n (2) 2.00pm \n (3) 8.00pm ");
				scanf("%d",&option4);
				fflush(stdin);
				if (option4==1)
				{
					strcpy(add.time, "8.00am");
				}
				else if (option4==2)
				{
					strcpy(add.time, "2.00pm");
				}
				else if (option4==3)
				{
					strcpy(add.time, "8.00pm");
				}
				else
				{
					printf("\n Invalid Choice");
				}
			}
			else
			{
					printf("\n Invalid Choice");
					New();
					
			}
	}
	else if(option==2)
	{
		strcpy(add.airline, "Qatar_Airways");
		printf("\n Enter your Date of Depature \t\t");
		printf("\n (1) August 13, 2017 \n (2) August 14, 2017\n (3) August 15, 2017");
		scanf("%d",&option3);
		fflush(stdin);
	 		if(option3==1)
	 		{
	 			strcpy(add.date_of_departure, "August13,2017");
	 			printf("\n Enter your Time of Depature \t\t");
				printf("\n (1) 9.00am \n (2) 3.00pm \n (3) 9.00pm ");
				scanf("%d",&option4);
				fflush(stdin);
				if (option4==1)
				{
					strcpy(add.time, "9.00am");
				}
				else if (option4==2)
				{
					strcpy(add.time, "3.00pm");
				}
				else if (option4==3)
				{
					strcpy(add.time, "9.00pm");
				}
				else
				{
					printf("\n Invalid Choice");
				}
			}
			else if(option3==2)
	 		{
	 			strcpy(add.date_of_departure, "August14,2017");
	 			printf("\n Enter your Time of Depature \t\t");
				printf("\n (1) 10.00am \n (2) 4.00pm \n (3) 10.00pm ");
				scanf("%d",&option4);
				fflush(stdin);
				if (option4==1)
				{
					strcpy(add.time, "10.00am");
				}
				else if (option4==2)
				{
					strcpy(add.time, "4.00pm");
				}
				else if (option4==3)
				{
					strcpy(add.time, "10.00pm");
				}
				else
				{
					printf("\n Invalid Choice");				
				}
			}
			else if(option3==3)
	 		{
	 			strcpy(add.date_of_departure, "August15,2017");
	 			printf("\n Enter your Time of Depature \t\t");
				printf("\n (1) 11.00am \n (2) 5.00pm \n (3) 11.00pm ");
				scanf("%d",&option4);
				fflush(stdin);
				if (option4==1)
				{
					strcpy(add.time, "11.00am");
				}
				else if (option4==2)
				{
					strcpy(add.time, "5.00pm");
				}
				else if (option4==3)
				{
					strcpy(add.time, "11.00pm");
				}
				else
				{
					printf("\n Invalid Choice");				
				}
			}
			else
			{
					printf("\n Invalid Choice");
					New();				
			}
	}
	else if(option==3)
	{
		strcpy(add.airline, "Pakistan_International_Airlines");
		printf("\n Enter your Date of Depature \t\t");
	 	printf("\n (1) August 16, 2017 \n (2) August 17, 2017\n (3) August 18, 2017");
		scanf("%d",&option3);
		fflush(stdin);
	 		if(option3==1)
	 		{
	 			strcpy(add.date_of_departure, "August16,2017");
	 			printf("\n Enter your Time of Depature \t\t");
				printf("\n (1) 11.00am \n (2) 5.00pm \n (3) 11.00pm ");			
				scanf("%d",&option4);
				fflush(stdin);
				if (option4==1)
				{
					strcpy(add.time, "11.00am");
				}
				else if (option4==2)
				{
					strcpy(add.time, "5.00pm");
				}
				else if (option4==3)
				{
					strcpy(add.time, "11.00pm");
				}
				else
				{
					printf("\n Invalid Choice");				
				}
			}
			else if(option3==2)
	 		{
	 			strcpy(add.date_of_departure, "August17,2017");
	 			printf("\n Enter your Time of Depature \t\t");
				printf("\n (1) 6.00am \n (2) 5.00pm \n (3) 6.00pm ");			
				scanf("%d",&option4);
				fflush(stdin);
				if (option4==1)
				{
					strcpy(add.time, "6.00am");
				}
				else if (option4==2)
				{
					strcpy(add.time, "5.00pm");
				}
				else if (option4==3)
				{
					strcpy(add.time, "6.00pm");
				}
				else
				{
					printf("\n Invalid Choice");		
				}
			}
			else if(option3==3)
	 		{
	 			strcpy(add.date_of_departure, "August18,2017");
	 			printf("\n Enter your Time of Depature \t\t");
				printf("\n (1) 1.00am \n (2) 5.00pm \n (3) 7.00pm ");		
				scanf("%d",&option4);
				fflush(stdin);
				if (option4==1)
				{
					strcpy(add.time, "1.00am");
				}
				else if (option4==2)
				{
					strcpy(add.time, "5.00pm");
				}
				else if (option4==3)
				{
					strcpy(add.time, "7.00pm");
				}
				else
				{
					printf("\n Invalid Choice");		
				}
			}
			else
			{
					printf("\n Invalid Choice");
					New();	
			}
	}
	else 
	{
		printf("\n Invalid Choice");
		New();
	}
	}
	fflush(stdin);
	printf("\n\n Enter Current Location \t\t");
	gets(add.current_location);
	fflush(stdin);
	printf("\n Enter your Destination \t\t");
	gets(add.destination);
	fflush(stdin);
	printf("\n\n Enter the Number of Tickets you want to buy \t\t");
	scanf("%d",&add.tickets);
	fflush(stdin);
	printf("\n Enter your Credit Card Number \t\t");
	gets(add.credit_card);
	fflush(stdin);
	printf("\n Enter your Address \t\t");
	gets(add.address);
	fflush(stdin);
	printf("\n Enter the Class of ticket you want to buy \t\t");
	printf("\n (1) Business \n (2) First Class \n (3) Economy");
	scanf("%d",&option2);
	fflush(stdin);
	if(option2==1)
	{
	 strcpy(add.Class, "Business");
	}
	else if(option2==2)
	{
		strcpy(add.Class, "First_Class");
	}
	else if(option2==3)
	{
		strcpy(add.Class, "Economy");
	}
	else 
	{
		printf("\n Invalid Choice");
	}
	fprintf(fp,"%s %s %s %s %s %d %s %s %s %s %d\n",add.name,add.airline,add.current_location,add.destination,add.date_of_departure,add.tickets,add.credit_card,add.address,add.Class,add.time,add.ticket_type);
	fclose(fp);
	printf("\n\n\t\t Record added successfully!");
	printf("\n\t\t --------------------------");
	printf("\n Press any key to return to Main Menu");
	getch();
	system("cls");	
	main();
}
void Stock()
{
	int test=0,p;
	float fee;
	system("cls");
	FILE *fpr;
	fpr=fopen("flight details.txt","r");
	if(fpr==NULL)
	{
	printf("\n The file was not able to open!");
	}
	fflush(stdin);
	printf("\n ENTER YOUR NAME TO PRINT YOUR TICKET: \t");
	gets(check.name);
	fflush(stdin);
	system("cls");
	while(fscanf(fpr,"%s %s %s %s %s %d %s %s %s %s %d\n",&add.name,&add.airline,&add.current_location,&add.destination,&add.date_of_departure,&add.tickets,&add.credit_card,&add.address,&add.Class,&add.time,&add.ticket_type)!=EOF)
	{
		if(strcmp(add.name,check.name)==0)
		{
			printf("\n\n\t\t\t\t Flight Details \a\a\a\a\a\a\a");
			printf("\n\t\t\t\t --------------");
			printf("\n\n--------------------------------------------------------------------------------\n");
			printf(" Airline \t Destination \t Departure \t    Date \t\t Timing");
			printf("\n-----------------------------------------------------------------------------------");
			printf("\n%s \t %s \t %s \t %s \t\t %s \n",add.airline,add.destination,add.current_location,add.date_of_departure,add.time);
			test++;	
			fee=bill(check.name,add.tickets);
			
		}
		
	}
	if (test==0)
	{
		printf("\n \t\t NO RECORD FOUND! \n");
	}
	else
	{
		printf("\n--------------------------------------------------------------------------------");
		printf("\n Mr./Mrs. %s you bought %d tickets" ,add.name,add.tickets);
		printf("\n\t\t\t Your total bill is: Rs.%.2f",fee);
		printf("\n\t Your tickets will be delivered at your doorstep!");
		printf("\n\t\t\t ***Thankyou***");
		
		printf("\n--------------------------------------------------------------------------------");
	}
	fclose(fpr);
	printf("\n Press any key to return to main menu!");
	char choice[5];	
	getch();
	system("cls");
	main();
}

