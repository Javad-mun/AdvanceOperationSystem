/*
 * functions.c
 *
 *  Created on: Oct. 2, 2018
 *      Author: JJ
 *      Here I keep all the function for house keeping purposes
 */

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>
#include <conio.h>

#include "functions.h"


// defining length of the beep and time pause as global
//setting their default values
float beepfreq=200.0;
float pauseLength=0.4;



/*---------------------------------------------
--------Structural designs and handles---------
-----------------------------------------------*/



//lunches the main menu choice
void lunch(int menuId,int *key)
{

	if (menuId==101)
	{
		system("cls");
		sub1Menu();



	}
	else if (menuId==102)
	{
		system("cls");
		sub2Menu();





	}	else if (menuId==103)
	{
		system("cls");
		sub3Menu();





	}	else if (menuId==104)
	{
		system("cls");
		sub4Menu();



	}
	else if (menuId==100)
	{
		system("cls");
		*key=1000;


	}

}

void displayMainMenu(int menuId)
{
	HANDLE  hConsole;// Adjusting the envirnment color
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);
	system("cls");
	puts("");
	puts("=============================================================");
	puts("=============  Advanced Operating System    =================");
	puts("============= Presented to: Dr. Ashoke Deb  =================");
	puts("=============         Assignment #1         =================");
	puts("=============  By: Seyed Javad Khataei Pour =================");
	puts("=============================================================");
	puts("");



	if (menuId==101)
	{
		SetConsoleTextAttribute(hConsole, 10);
	    puts("	Subproblem one - Random Generator\n");
		SetConsoleTextAttribute(hConsole, 15);
		puts("	Subproblem two - Print a letter\n");
		puts("	Subproblem three - combination of subproblems one and two\n");
		puts("	Option\n");
		puts("	Exit\n");

	}
	else if (menuId==102)
	{
		SetConsoleTextAttribute(hConsole, 15);
	    puts("	Subproblem one - Random Generator\n");
		SetConsoleTextAttribute(hConsole, 10);
		puts("	Subproblem two - Print a letter\n");
		SetConsoleTextAttribute(hConsole, 15);
		puts("	Subproblem three - combination of subproblems one and two\n");
		puts("	Option\n");
		puts("	Exit\n");

	}	else if (menuId==103)
	{
		SetConsoleTextAttribute(hConsole, 15);
	    puts("	Subproblem one - Random Generator\n");
		puts("	Subproblem two - Print a letter\n");
		SetConsoleTextAttribute(hConsole, 10);
		puts("	Subproblem three - combination of subproblems one and two\n");
		SetConsoleTextAttribute(hConsole, 15);
		puts("	Option\n");
		puts("	Exit\n");

	}	else if (menuId==104)
	{
		SetConsoleTextAttribute(hConsole, 15);
	    puts("	Subproblem one - Random Generator\n");
		puts("	Subproblem two - Print a letter\n");
		puts("	Subproblem three - combination of subproblems one and two\n");
		SetConsoleTextAttribute(hConsole, 10);
		puts("	Option\n");
		SetConsoleTextAttribute(hConsole, 15);
		puts("	Exit\n");
	}
	else if (menuId==100 || menuId==105)
	{
		SetConsoleTextAttribute(hConsole, 15);
	    puts("	Subproblem one - Random Generator\n");
		puts("	Subproblem two - Print a letter\n");
		puts("	Subproblem three - combination of subproblems one and two\n");
		puts("	Option\n");
		SetConsoleTextAttribute(hConsole, 10);
		puts("	Exit\n");
		SetConsoleTextAttribute(hConsole, 15);
	}

}

//====================================================
//handles sub menu #1. Watch for the keys user presses and
void sub1Menu()
{
	int key1,sub1ChoiceCounter;


			// this is the basic choice for main menu which is set to first
			//101 is the base so when user presses the Up button and mainChoiceCounter decrease
			// it will be a positive number which is easier to handle here
			sub1ChoiceCounter=101;
			displaysub1Menu(sub1ChoiceCounter);// display the main menu based on the user's choice


			while ( key1 != 27)
			{
			key1= getch();// reading the user's key pressed
				if (key1==80)// The Down arrow key is pressed
				{
					sub1ChoiceCounter++;
					sub1ChoiceCounter=sub1ChoiceCounter%4+100;// keep the sub1ChoiceCounter in a certain range so we can assign different function for each choice easily by using if in the displaymainmenu() function
					displaysub1Menu(sub1ChoiceCounter);

				}
				 else if(key1==72)// The Up arrow key is pressed
				{

						sub1ChoiceCounter--;
						sub1ChoiceCounter=(sub1ChoiceCounter%4+100);
						displaysub1Menu(sub1ChoiceCounter);

				}
				 else if(key1==13)// The Enter arrow key is pressed.
						{
					 	 // Invoke different function based on the menu that is selected by the user
					 	 lunchsub1(sub1ChoiceCounter,&key1);// Sending by reference so we can edit the key pressed in case of need( eg. exit)
						 displaysub1Menu(sub1ChoiceCounter);


						}
	}
}

void displaysub1Menu(int menuId)
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);// to change the text color. creating an illusion of selection for the user
	system("cls");
	puts("");
	printf("	============Please choose from bellow options============ \n");
	printf("	================== To exit press ESC ==================== \n");
	puts("");
	puts("");




	// Based on the user choice one of the options is green
	if (menuId==101)// menuId is the user choice which is equal to sub1ChoiceCounter in sub1menu() function
	{
		SetConsoleTextAttribute(hConsole, 10);
	    puts("	Infinite random numbers with a seed from system clock, within a certain range\n");// sub11()
		SetConsoleTextAttribute(hConsole, 15);
		puts("	Infinite random numbers with a given seed from the user, within a certain range\n");//sub12()
		puts("	Finite random numbers with a seed from system clock, within a certain range\n"); //sub13()
		puts("	Finite random numbers with a given seed from the user, within a certain range\n"); //sub14()

	}
	else if (menuId==102)
	{
		SetConsoleTextAttribute(hConsole, 15);
	    puts("	Infinite random numbers with a seed from system clock, within a certain range\n");// sub11()
		SetConsoleTextAttribute(hConsole, 10);
		puts("	Infinite random numbers with a given seed from the user, within a certain range\n");//sub12()
		SetConsoleTextAttribute(hConsole, 15);
		puts("	Finite random numbers with a seed from system clock, within a certain range\n"); //sub13()
		puts("	Finite random numbers with a given seed from the user, within a certain range\n"); //sub14()

	}	else if (menuId==103)
	{
		SetConsoleTextAttribute(hConsole, 15);
	    puts("	Infinite random numbers with a seed from system clock, within a certain range\n");// sub11()
		puts("	Infinite random numbers with a given seed from the user, within a certain range\n");//sub12()
		SetConsoleTextAttribute(hConsole, 10);
		puts("	Finite random numbers with a seed from system clock, within a certain range\n"); //sub13()
		SetConsoleTextAttribute(hConsole, 15);
		puts("	Finite random numbers with a given seed from the user, within a certain range\n"); //sub14()

	}	else if (menuId==100)
	{
		SetConsoleTextAttribute(hConsole, 15);
	    puts("	Infinite random numbers with a seed from system clock, within a certain range\n");// sub11()
		puts("	Infinite random numbers with a given seed from the user, within a certain range\n");//sub12()
		puts("	Finite random numbers with a seed from system clock, within a certain range\n"); //sub13()
		SetConsoleTextAttribute(hConsole, 10);
		puts("	Finite random numbers with a given seed from the user, within a certain range\n"); //sub14()
		SetConsoleTextAttribute(hConsole, 15);
	}


}


//lunches the functions that are selected from submenu#1
void lunchsub1(int submenuId,int *key1)
{

	if (submenuId==101)
	{
		system("cls");

		//Do the sub11 function which is written notebook 24 june
		sub11();

	}
	else if (submenuId==102)
	{
		system("cls");
		sub12();





	}	else if (submenuId==103)
	{
		system("cls");
		sub13();





	}	else if (submenuId==100)
	{
		system("cls");
		sub14();


	}


}

//================================================
//handles sub menu #2. Watch for the keys user presses and
void sub2Menu()
{
	int key2,sub2ChoiceCounter;


			// this is the basic choice for main menu which is set to first
			//101 is the base so when user presses the Up button and ChoiceCounter decrease
			// it will be a positive number which is easier to handle here
			sub2ChoiceCounter=101;
			displaysub2Menu(sub2ChoiceCounter);// display the main menu based on the user's choice


			key2=100;
			while ( key2 != 27)
			{

			key2= getch();// reading the user's key pressed
				if (key2 == 80)// The Down arrow key is pressed
				{

					sub2ChoiceCounter++;
					sub2ChoiceCounter=sub2ChoiceCounter % 3 +100;// keep the sub2ChoiceCounter in a certain range so we can assign different function for each choice easily by using if in the displaymainmenu() function

					displaysub2Menu(sub2ChoiceCounter);

				}
				 else if(key2 == 72)// The Up arrow key is pressed
				{

						sub2ChoiceCounter= sub2ChoiceCounter-1;
						sub2ChoiceCounter=sub2ChoiceCounter%3+100;
						displaysub2Menu(sub2ChoiceCounter);



				}
				 else if(key2==13)// The Enter arrow key is pressed.
						{
					 	 // Invoke different function based on the menu that is selected by the user
					 	 lunchsub2(sub2ChoiceCounter,&key2);// Sending by reference so we can edit the key pressed in case of need( eg. exit)
						 displaysub2Menu(sub2ChoiceCounter);


						}
	}
}

void displaysub2Menu(int menuId)
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);// to change the text color. creating an illusion of selection for the user
	system("cls");
	puts("");
	printf("	============Please choose from bellow options============ \n");
	printf("	================== To exit press ESC ==================== \n");
	printf("	=============== Use Down key to navigate================== \n");

	puts("");
	puts("");




	// Based on the user choice one of the options is green
	if (menuId==101)// menuId is the user choice which is equal to sub2ChoiceCounter in sub1menu() function
	{
		SetConsoleTextAttribute(hConsole, 10);
	    puts("	Execute Print A function\n");
		SetConsoleTextAttribute(hConsole, 15);
		puts("	Execute Print B function\n");
		puts("	Execute Print C function\n");

	}
	else if (menuId==100)
	{
		SetConsoleTextAttribute(hConsole, 15);
	    puts("	Execute Print A function\n");
		SetConsoleTextAttribute(hConsole, 10);
		puts("	Execute Print B function\n");
		SetConsoleTextAttribute(hConsole, 15);
		puts("	Execute Print C function\n");

	}
	else if (menuId==102)
	{
		SetConsoleTextAttribute(hConsole, 15);
		puts("	Execute Print A function\n");
		puts("	Execute Print B function\n");
		SetConsoleTextAttribute(hConsole, 10);
		puts("	Execute Print C function\n");
		SetConsoleTextAttribute(hConsole, 15);
	}


}


//lunches the functions that are selected from submenu#2
void lunchsub2(int submenuId,int *key2)
{

	system("cls");

	puts("");
	puts("======To exit press any key=======");

	if (submenuId==101)
	{
		printA();


	}
	else if (submenuId==102)
	{
		printC();





	}	else if (submenuId==100)
	{
		printB();





	}
	getch();// give the user time to see the result

}


//================================================
//handles sub menu #3. Watch for the keys user presses and
void sub3Menu()
{
	int key3,sub3ChoiceCounter;


			// this is the basic choice for main menu which is set to first
			//101 is the base so when user presses the Up button and mainChoiceCounter decrease
			// it will be a positive number which is easier to handle here
			sub3ChoiceCounter=101;
			displaysub3Menu(sub3ChoiceCounter);// display the main menu based on the user's choice


			while ( key3 != 27)
			{
			key3= getch();// reading the user's key pressed
				if (key3==80)// The Down arrow key is pressed
				{
					sub3ChoiceCounter++;
					sub3ChoiceCounter=sub3ChoiceCounter%2+100;// keep the sub1ChoiceCounter in a certain range so we can assign different function for each choice easily by using if in the displaymainmenu() function
					displaysub3Menu(sub3ChoiceCounter);

				}
				 else if(key3==72)// The Up arrow key is pressed
				{

						sub3ChoiceCounter--;
						sub3ChoiceCounter=(sub3ChoiceCounter%2+100);
						displaysub3Menu(sub3ChoiceCounter);

				}
				 else if(key3==13)// The Enter arrow key is pressed.
						{
					 	 // Invoke different function based on the menu that is selected by the user
					 	 lunchsub3(sub3ChoiceCounter,&key3);// Sending by reference so we can edit the key pressed in case of need( eg. exit)
						 displaysub3Menu(sub3ChoiceCounter);


						}
	}
}

void displaysub3Menu(int menuId)
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);// to change the text color. creating an illusion of selection for the user
	system("cls");
	puts("");
	printf("	============Please choose from bellow options============ \n");
	printf("	================== To exit press ESC ==================== \n");
	puts("");
	puts("");




	// Based on the user choice one of the options is green
	if (menuId==101)// menuId is the user choice which is equal to sub3ChoiceCounter in sub1menu() function
	{
		SetConsoleTextAttribute(hConsole, 10);
	    puts("	Random sequence of A,B ,and C with a seed obtained from system clock\n");// sub11()
		SetConsoleTextAttribute(hConsole, 15);
		puts("	Random sequence of A,B ,and C with a seed obtained from the user\n");//sub12()
	}
	else if (menuId==100)
	{
		SetConsoleTextAttribute(hConsole, 15);
	    puts("	Random sequence of A,B ,and C with a seed obtained from system clock\n");// sub11()
		SetConsoleTextAttribute(hConsole, 10);
		puts("	Random sequence of A,B ,and C with a seed obtained from the user\n");//sub12()
		SetConsoleTextAttribute(hConsole, 15);
	}


}


//lunches the functions that are selected from submenu#3
void lunchsub3(int submenuId,int *key3)
{

	if (submenuId==101)
	{
		system("cls");
		sub31();// sub31 and 32 are functions that calculate and print out the results

	}	else if (submenuId==100)
	{
		system("cls");
		sub32();
	}
}

//================================================
//handles sub menu #4. Watch for the keys user presses and
void sub4Menu()
{
	int key4,sub4ChoiceCounter;


			// this is the basic choice for main menu which is set to first
			//101 is the base so when user presses the Up button and mainChoiceCounter decrease
			// it will be a positive number which is easier to handle here
			sub4ChoiceCounter=101;
			displaysub4Menu(sub4ChoiceCounter);// display the main menu based on the user's choice


			while ( key4 != 27)
			{
			key4= getch();// reading the user's key pressed
				if (key4==80)// The Down arrow key is pressed
				{
					sub4ChoiceCounter++;
					sub4ChoiceCounter=sub4ChoiceCounter%2+100;// keep the sub1ChoiceCounter in a certain range so we can assign different function for each choice easily by using if in the displaymainmenu() function
					displaysub4Menu(sub4ChoiceCounter);

				}
				 else if(key4==72)// The Up arrow key is pressed
				{

						sub4ChoiceCounter--;
						sub4ChoiceCounter=(sub4ChoiceCounter%2+100);
						displaysub4Menu(sub4ChoiceCounter);

				}
				 else if(key4==13)// The Enter arrow key is pressed.
						{
					 	 // Invoke different function based on the menu that is selected by the user
					 	 lunchsub4(sub4ChoiceCounter,&key4);// Sending by reference so we can edit the key pressed in case of need( eg. exit)
						 displaysub4Menu(sub4ChoiceCounter);


						}
	}
}

void displaysub4Menu(int menuId)
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);// to change the text color. creating an illusion of selection for the user
	system("cls");
	puts("");
	printf("	============Please choose from bellow options============ \n");
	printf("	================== To exit press ESC ==================== \n");
	puts("");
	puts("");




	// Based on the user choice one of the options is green
	if (menuId==101)// menuId is the user choice which is equal to sub4ChoiceCounter in sub1menu() function
	{
		SetConsoleTextAttribute(hConsole, 10);
	    puts("	Change beep frequency. To mute enter 0\n");// sub41()
		SetConsoleTextAttribute(hConsole, 15);
		puts("	Change pause duration\n");//sub42()
	}
	else if (menuId==100)
	{
		SetConsoleTextAttribute(hConsole, 15);
	    puts("	Change beep frequency. To mute enter 0\n");// sub41()
		SetConsoleTextAttribute(hConsole, 10);
		puts("	Change pause duration\n");//sub42()
		SetConsoleTextAttribute(hConsole, 15);
	}


}


//lunches the functions that are selected from submenu#4
void lunchsub4(int submenuId,int *key4)
{

	if (submenuId==101)
	{
		system("cls");
		sub41();// sub31 and 32 are functions that calculate and print out the results

	}	else if (submenuId==100)
	{
		system("cls");
		sub42();
	}
}





//==================================================
//------------------------------------------------------------
//------functional(computational) functions parts-------------
//------------------------------------------------------------


/*
 ============================================================================
 Name        : Submenu 1, choice 1
 Author      : Javad
 Description : infinite sequence of random integers within the given range and
 	 	 	   a seed from the system clock
 ===========================================================================
 */

// will be executed when the first option of sub menu one is selected

void sub11(void)
{

	int keypressed,randomNumber,range;
	char inputstr[33];// for input of the range

	puts(" ***To stop press ESC button**** ");
	range=0;// this loop prevent getting zero as a range which can crash the whole program
	while(range<1)
	{
		printf("Enter an integer as the upper limit. random numbers will be within [1, limit]: ");
		scanf("%s",&inputstr);// Reading the range
		sscanf(inputstr, "%d", &range);
	}

	keypressed=100;//  Setting an initial amount for the pressed key the beginning so the loop can start
	srand(time(NULL));//setting the seed based on the clock
	while (keypressed !=27)// Keep doing il the ESC key is pressed
	{
			if (kbhit())// Checks if a key is pressed?
			{
				keypressed= getch();// a key is pressed. here it reads it
			}
			randomNumber= rand()%range;
		printf("%d ," ,randomNumber);
		// Producing a beep sound and a pause to keep the program user-friendly and pleasant to work with
		Beep(beepfreq,100);
		sleep(pauseLength);
	}
	puts("");
	puts("Operation finished. To exit press any key");
	getch();


}


/*
 ============================================================================
 Name        : Submenu 1, choice 2
 Author      : Javad
 Description : infinite sequence of random integers within the given range and
 	 	 	   seed
 ===========================================================================
 */

// will be executed when the second option of sub menu one is selected

void sub12(void)
{

	int keypressed,randomNumber,range,seed;

	puts(" ***To stop press ESC button****  ");

	range=0;// this loop prevent getting zero as a range which can crash the whole program
	while(range<1)
	{
		//reading the range and the seed for random function
		printf("Enter an integer as the upper limit. random numbers will be within [1, limit] range ");
		scanf("%d", &range);
	}
	printf("Enter a seed:");
	scanf("%d", &seed);



	keypressed=100;//  Setting an initial amount for the pressed key the beginning so the loop can start
	srand(seed);//setting the seed based on the clock
	while (keypressed !=27)// Keep doing il the ESC key is pressed
	{
			if (kbhit())// Checks if a key is pressed?
			{
				keypressed= getch();// a key is pressed. here it reads it
			}
			randomNumber= rand()%range;
		printf("%d ," ,randomNumber);
		// Producing a beep sound and a pause to keep the program user-friendly and pleasant to work with
		Beep(beepfreq,99);
		sleep(pauseLength);
	}
	puts("");
	puts("Operation finished. To exit press any key");
	getch();

}


/*
 ============================================================================
 Name        : Submenu 1, choice 3
 Author      : Javad
 Description : finite sequence of random integers within the given range and
 	 	 	   a seed from the system clock
 ===========================================================================
 */

// will be executed when the third option of sub menu one is selected

void sub13(void)
{

	int keypressed,randomNumber,range,quantity;
	char inputstr[33];// for input of the range
	int i=0;
	printf(" ***To stop press ESC button**** \n");

	range=0;// this loop prevent getting zero as a range which can crash the whole program
	while(range<1)
	{
	//reading the range and the seed for random function
	printf("Enter an integer as the upper limit. random numbers will be within [1, limit] range ");
	scanf("%d", &range);
	}
	printf("Enter the quantity of the random numbers:");
	scanf("%d", &quantity);


	srand(time(NULL));//setting the seed based on the clock

		while(keypressed !=27 && i<quantity)// Keep doing till the ESC key is pressed
		{
			i++;
			if (kbhit())// Checks if a key is pressed?
			{
				keypressed= getch();// a key is pressed. here it reads it
			}
			randomNumber= rand()%range;
			printf("%d ," ,randomNumber);
			// Producing a beep sound and a pause to keep the program user-friendly and pleasant to work with
			Beep(beepfreq,99);
			sleep(pauseLength);
		}

		puts("");
		puts("Operation finished. To exit press any key");
		getch();
}


/*
 ============================================================================
 Name        : Submenu 1, choice 4
 Author      : Javad
 Description : finite sequence of random integers within the given range and
 	 	 	   a given seed
 ===========================================================================
 */

// will be executed when the third option of sub menu one is selected

void sub14(void)
{

	int keypressed,randomNumber,range,quantity,seed;
	int i=0;
	printf(" ***To stop press ESC button**** \n");

	range=0;// this loop prevent getting zero as a range which can crash the whole program
	while(range<1)
	{
	//reading the range and the seed for random function
	printf("Enter an integer as the upper limit. random numbers will be within [1, limit] range ");
	scanf("%d", &range);
	}
	printf("Enter the quantity of the random numbers:");
	scanf("%d", &quantity);

	printf("Enter a seed:");
	scanf("%d", &seed);


	srand(seed);//setting the seed based on the clock

		while(keypressed !=27 && i<quantity)// Keep doing till the ESC key is pressed
		{
			i++;
			if (kbhit())// Checks if a key is pressed?
			{
				keypressed= getch();// a key is pressed. here it reads it
			}
			randomNumber= rand()%range;
			printf("%d ," ,randomNumber);
			// Producing a beep sound and a pause to keep the program user-friendly and pleasant to work with
			Beep(beepfreq,99);
			sleep(pauseLength);
		}

		puts("");
		puts("Operation finished. To exit press any key");
		getch();
}



/* Sub Problem #2 functions*/
// Prints character A
void printA()
{
	printf("A");
}

// Prints character A

void printB()
{
	printf("B");
}

// Prints character A

void printC()
{
	printf("C");
}






/*
 ============================================================================
 Name        : Submenu 1, choice 1
 Author      : Javad
 Description : infinite sequence of random integers within the given range and
 	 	 	   a seed from the system clock
 ===========================================================================
 */

// will be executed when the first option of sub menu three is selected

void sub31(void)
{

	int keypressed,randomNumber;


	puts(" ***To stop press ESC button**** ");
	keypressed=100;//  Setting an initial amount for the pressed key the beginning so the loop can start
	srand(time(NULL));//setting the seed based on the clock
	while (keypressed !=27)// Keep doing till the ESC key is pressed
	{
			if (kbhit())// Checks if a key is pressed?
			{
				keypressed= getch();// a key is pressed. here it reads it
			}
			randomNumber= rand()%3;// based on a random number invoke either printA printB or PrintC
			if (randomNumber==0)
			{
				printA();
			}
			else if (randomNumber==1)
			{
				printB();
			}
			else if (randomNumber==2)
			{
				printC();
			}
		// Producing a beep sound and a pause to keep the program user-friendly and pleasant to work with
		Beep(beepfreq,99);
		sleep(pauseLength);
	}
	puts("");
	puts("Operation finished. To exit press any key");
	getch();


}
//==========================================

/*
 ============================================================================
 Name        : Submenu 3, choice 2
 Author      : Javad
 Description : infinite sequence of random integers within the given range and
 	 	 	   seed
 ===========================================================================
 */

// will be executed when the second option of sub menu three is selected

void sub32(void)
{

	int keypressed,randomNumber,seed;


		printf("Enter a seed:");
		scanf("%d",&seed);
		puts("");
		puts(" ***To stop press ESC button**** ");
		keypressed=100;//  Setting an initial amount for the pressed key the beginning so the loop can start
		srand(seed);//setting the seed based on the clock
		while (keypressed !=27)// Keep doing till the ESC key is pressed
		{
				if (kbhit())// Checks if a key is pressed?
				{
					keypressed= getch();// a key is pressed. here it reads it
				}
				randomNumber= rand()%3;// based on a random number invoke either printA printB or PrintC
				if (randomNumber==0)
				{
					printA();
				}
				else if (randomNumber==1)
				{
					printB();
				}
				else if (randomNumber==2)
				{
					printC();
				}
			// Producing a beep sound and a pause to keep the program user-friendly and pleasant to work with
			Beep(beepfreq,99);
			sleep(pauseLength);
		}
		puts("");
		puts("Operation finished. To exit press any key");
		getch();


}

//=====================

void sub41(void)
{
	//sets the beep length
	printf("Enter beep frequency( for example 500). To mute enter 0:");
	scanf("%f", &beepfreq);
}

void sub42(void)
{
	//sets the pauses between each number or letter print
	printf("Enter pause duration in milliseconds:");
	scanf("%f", &pauseLength);//note that sleep function in c uses time based on second not millisecond so it has to  be devided by 1000 
	pauseLength= pauseLength/1000;
}
