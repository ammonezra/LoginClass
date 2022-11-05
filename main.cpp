#include "Login_Class.h"

int main()
{
	begin:
	Login log;
	log.readDB();
	int choice;
	std::cout << "Welcome to the login program." << std::endl
	                 << "Please make a selection:" << std::endl
	                 << "[1] Login" << std::endl
	                 << "[2] Create Account" << std::endl
	                 << "[0] Exit" << std::endl;
	 std::cin >> choice;
	 if(choice != 0 && choice != 1 && choice != 2){
	     std::cout << "ERROR: Invalid input." << std::endl;
	     goto begin;
	 }
	 if(choice == 1){
	 	if(isLoggedIn(log))
	 	{
	 		std::cout << "Successfully logged in.";
	 	}
	 	else{
	 		std::cout << "ERROR: username or password was incorrect." <<std::endl;
	 	    goto begin;
    	 }
	 }
	 else if(choice == 2){
	 	log.createAccount();
	 	goto begin;
	 }
	 else if(choice == 0){
	 	std::cout << "Exiting the program...";
	 	return 0;
	 }
	 log.interface(log);
	 
	                    
}