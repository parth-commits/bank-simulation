NOTE: This was a project made in high school with initial basic knowledge in programming. The goal of this project was not to make a finished product rather to practice the skills we learned in class. 
# bank-simulation
This is a basic simulation of a ATM machine at a bank.

Team members: Parth Patel and Dhyey Trivedi
Course: ICS 4U1 (high school)
Date created: December 11, 2018

Brief Description: to create a program that simulates the function of a ATM at a bank. 
Details: There will be a list of account numbers and pins premade for the entire class for our bank. Then user will be welcomed to our bank’s ATM machine. They will be prompted to enter their account number and password. Without this information, they will not be allowed to continue. Once they will enter their account details, they will be taken to another page with another prompt on what they want to do. They will be allowed to input money into their account and withdraw money. They can view their balance in their account, change their pin, check their balance and logout of their account.
Features:
•	Checking bank balance
•	Change pin
•	Withdraw money
•	Deposit money
•	Change security pin
•	Security alarm against intruders
•	Securely logout of the program
•	Sound system with high pitched siren warning intruders
Additional feature if possible:
•	Audible system for the blind

Layout of output window:
1.	Bank name and password screen
2.	Entry into system with options available
3.	Each option may lead to other options depending on the option. System will recheck if you want to enter the option by asking you again if you want to go there to make sure you didn’t click it by accident. This will minimize errors and save time for the user. 
4.	In each option, you will be allowed to do the certain task
5.	Then you will be returned to the homepage of system until you securely logout of the system and close the window.
Division of project:
1.	The first group member will be responsible for the backend of the project such as:
•	Creating a text database for the output screen to save time in coding it.
•	Importing the files into the program
•	Handle errors in the project (Ex. If file doesn’t exist, then it will display that the user file doesn’t exist)
•	Creating algorithm that handles user input.

2.	The second group member will be responsible for the user interface part of the application and overall user interaction.
•	Create intro page which will show bank (project) name and have an info button at the bottom to access the creators of the app, date of creation and other information.
•	Main menu after login into the system. The place where everything can be accessed. Includes a logout of the system and an exit system option. 
•	Exit screen and thank you for using our bank ATM screen.
•	Check for valid input to avoid errors. Ex. If someone enters a ‘z’ when requested to answer a yes or no question, then the user will be prompted to enter their answer again, this time correct.
Structure of program and ideas of some functions and files:
•	Main file: where the main program will be stored which will iterate itself until user logs out of the system.
•	Screen file(s): where the designs for all the possible screens in the application will be located. Here, there will be pre-designed screens which we will read right into our application and display it so we can save time. 
•	Accounts file: this will be a file which stores all the account ID’s and passwords for use. Once the user enters their account ID and password, the system will look through this file and see if an user with this account ID exists, if it does, then you will be allowed into the system. There will also be account balance information in this file. 
Accounts file: this will be a text file which will contain user information. Each user’s information will start with a ‘#’ to avoid confusion between 2 users.
Ex.
#A/C num: 432333
Pass: 9976
Main balance: $55,000.32
Chequing balance: $5422.54
#A/C num: 432377
Pass: 3376
Main balance: $32,445.64
Chequing balance: $1234.53
#A/C num: 432366
………………………………….
………………………………….
And so on…

Screen files: These will contain what to display in the output page. These will be .txt files. They can contain a welcome page, the options page or even the exit page.


Conclusion:
This is a banking simulation application which can help users access their banking information without actually going inside the bank. The difference between our application and existing applications is that our application will have a security sound system that will alert people around the machine if user has inputted wrong ID or password more than 3 times. This will be secure as people will know that they may be a fraud and wanting to steal money and this can be stopped. This application will be presented to the class which will include the need for this application, the development, the explanation of functions and final demonstration and the possible improvements that can be made to make the next version of the application better than this one.


