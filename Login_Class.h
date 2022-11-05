#ifndef LOGIN_CLASS_H
#define LOGIN_CLASS_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Login{
   	 friend bool userExists(Login&);
	    friend bool passExists(Login&);
	    friend bool isLoggedIn(Login&);
	    friend inline std::string getUser(const Login&);
    public:      
	    Login() = default;
	    Login& readDB();
	    Login& getUserData();
	    Login& createAccount();
	    Login& checkData();
	    void writeDB(const Login&);
	    void interface(Login&);
	    
    private:
    	std::vector<std::string> usernames;
    	std::vector<std::string> passwords;
    	std::string username;
	    std::string password;
	    std::vector<std::string> specifics;
	    
	    //userinfo
	    std::string f_name; 
	    std::string l_name; 
    	std::string birthdate; 
	    std::string address; 
};

bool userExists(const Login&);
bool passExists(const Login&);
bool isLoggedIn(Login&);
inline std::string getUser(const Login& log) {    return log.username;    }

#endif //LOGIN__CLASS_H