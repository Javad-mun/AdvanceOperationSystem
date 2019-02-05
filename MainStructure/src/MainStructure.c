/*
 ============================================================================
 Name        : MainStructure.c
 Author      : Javad
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "functions.h"

int main(void) {
		// Defining variables
		int key,mainChoiceCounter;


		// this is the basic choice for main menu which is set to first
		//101 is the base so when user presses the Up button and mainChoiceCounter decrease
		// it will be a positive number which is easier to handle here
		mainChoiceCounter=101;
		displayMainMenu(mainChoiceCounter);// display the main menu based on the user's choice


		while ( key != 1000)
		{
		key= getch();// reading the user's key pressed
			if (key==80)// The Down arrow key is pressed
			{
				mainChoiceCounter++;
				mainChoiceCounter=mainChoiceCounter%5+100;// keep the mainChoiceCounter in a certain range so we can assign different function for each choice easily by using if in the displaymainmenu() function
				displayMainMenu(mainChoiceCounter);

			}
			 else if(key==72)// The Up arrow key is pressed
			{

					mainChoiceCounter--;
					mainChoiceCounter=(mainChoiceCounter%5+100);
					displayMainMenu(mainChoiceCounter);

			}
			 else if(key==13)// The Enter arrow key is pressed.
					{
				 	 // Invoke different function based on the menu that is selected by the user
				 	lunch(mainChoiceCounter,&key);// Sending by reference so we can edit the key pressed in case of need( eg. exit)
					displayMainMenu(mainChoiceCounter);

					}
}
}
