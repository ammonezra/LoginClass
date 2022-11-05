#include "Login_Class.h"

Login& Login::readDB()
{
	std::ifstream file;
	std::string temp;
	file.open("un_db.bin");
	while(file >> temp)
	    this->usernames.push_back(temp);
	file.close();
	file.open("pw_db.bin");
	while(file >> temp)
	    this->passwords.push_back(temp);
	file.close();
	return *this;
}

Login& Login::getUserData()
{
	std::ifstream file;
	std::string temp;
	std::string prop = (this->username) + ".bin";
	file.open(prop);
	while(getline(file, temp)
		this->specifics.push_back(temp);
	file.close();

	//write to userinfo variables
	std::vector<std::string>::iterator it = specifics.begin();
	this->f_name = *it; ++it;
	this->l_name = *it; ++it;
	this->birthdate = *it; ++it;
	this->address = *it; ++it;
	return *this;
}

void Login::writeDB(const Login& log)
{
	std::string u = getUser(log);
	u += ".bin";
	std::ofstream ofileu("un_db.bin", std::ios_base::app);
	std::ofstream ofilep("pw_db.bin", std::ios_base::app);
	std::ofstream o;
	
	ofileu << log.username << std::endl;
	ofilep << log.password << std::endl;
	//write userinfo to file (username)
	o.open(u);
	o << log.f_name << std::endl
	          << log.l_name << std::endl
	          << log.birthdate << std::endl
	          <<log.address <<std::endl;
	 o.close();
	
}
bool isLoggedIn(Login& log)
{
	std::cout << "Username: ";
	std::cin >> log.username;
	std::cout << std::endl << "Password: ";
	std::cin >> log.password;
    if(userExists(log)){
    	if(passExists(log)){
    		return true;
    	}
    }
    return false;
}

Login& Login::createAccount()
{
	retry:
	std::cout << "Username: ";  std::cin >> this->username;	
    for(std::vector<std::string>::iterator it = this->usernames.begin();
	                           it != this->usernames.end(); ++it){
     if(this->username == *it){
	 	    	std::cout << "This username is already in use." << std::endl;
	     		goto retry;
    	 	}
    	 }                                                         
	std::cout << std::endl << "Password: "; std::cin >> this->password;
	std::cout << std::endl << "First name: "; std::cin >> this->f_name;
	std::cout << std::endl << "Last name: "; std::cin >> this->l_name;
	std::cout << std::endl << "Birthdate[xx/xx/xxxx]: "; std::cin >> this->birthdate;
	std::cout << std::endl << "Address: "; getline(std::cin, this->address);
	std::cout << std::endl;
	writeDB(*this);
	return *this;
}


bool userExists(Login& log)
{
	for(std::vector<std::string>::iterator it = log.usernames.begin(); it != log.usernames.end(); ++it)
	{
		if(*it == log.username)
		    return true;
	}
	return false;
	                                                      
}

bool passExists(Login& log)
{
	for(std::vector<std::string>::iterator it = log.passwords.begin(); it != log.passwords.end(); ++it)
	{
		if(*it == log.password)
		    return true;
	}
	return false;
	                                                      
}

void Login::interface(Login& log)
{
	iface:
	log.getUserData();
	char choice;
	std::cout << "Welcome, " << getUser(log) << "!";
	choose:
	std::cout << std::endl << "Please make a selection:" << std::endl
	                                         << "[1]: Check Data" << std::endl
	                                         << "[0]: Exit" << std::endl;
	std::cin >> choice;
	static_cast<int>(choice);
	if(choice == '1')
	{
		log.checkData();
		goto iface;
	}
	if(choice == '0')
	{
		std::cout << "Exiting the program...";
		return;
	}
	else
	{
		std::cout << "ERROR: Invalid input detected.";
		goto choose;
	}
}

Login& Login::checkData() 
{
	std::cout << this->f_name << std::endl
	                  << this->l_name << std::endl
	                  << this->birthdate << std::endl
	                  << this->address << std::endl;
}


