//*********************************************************************************************************************
// Linux Newusers File Creator: creates a file needed to batch add users with Linux "newusers" command.               *
// Each line in output file holds data for 1 user.                                                                    *
// Author: Rex Djere.                                                                                                 *
// © 2018-Present, Rex Djere.                                                                                         *
// License: GPL version 3 or later.                                                                                   *
// Requirements: C++ 11 or later.                                                                                     *		
// Version: Monday 08/13/18 04:57:31 PM                                                                               *
// Generate version: date '+%A %D %X'                                                                                 *
//*********************************************************************************************************************

// output line format: <Username>:<Password>:<UID>:<GID>:<User Info>:<Home Directory>:<Default Shell>

// library header files
#include <iostream>
#include <random> // provides random numbers
#include <chrono> // provides date functions
#include <ctime> //  provides time functions
#include <string>
#include <algorithm> // provides transform functions
#include <fstream>
#include <sstream> // provides stringstream
#include <iomanip> // provides put_time

// namespaces
using namespace std;

// function prototypes
int get_num_users(); // nickname "gnu": get number of users the sysadmin wants to add
std::string get_name_first(); // nicknamed "gnf": gets first name
std::string get_name_last(); // nicknamed "gnl": gets last name
std::string create_username(std::string ru_name_first, std::string ru_name_last); // nicknamed "gu": returns username
uint64_t create_password(); // nickname "cp": creates password
uint32_t get_starting_uid(); // nuckname "gsu": gets starting UID
uint32_t get_gid(); // nuckname "gg": gets GID
std::string get_time_date();

// main function
int main()
{
    int counter = 0;
    int user_index;
    int num_users = get_num_users();
    uint32_t uid;
    uint32_t gid;
    std::string date_time = get_time_date();
    std::string file_open_success; // check if output file opens correctly

    // for loop iterates for number of new users added
    for (counter = 0; counter < num_users; counter++)
    {
        user_index = counter + 1;
        std::cout << std::endl;
        std::cout << "***************************************************************************";
        std::cout << std::endl << "You are making Record Entry " << user_index << " of " << num_users << ":" << std::endl;
        std::cout << "***************************************************************************" << std::endl;

        // building username
        std::string name_first = get_name_first();
        std::string name_last = get_name_last();
        std::string username = create_username(name_first, name_last);
        std::transform(username.begin(), username.end(), username.begin(), ::tolower); // transforms username to lowercase

        // create password
        uint64_t password = create_password();

        // get starting UID and GID
        if (counter == 0)
        {
            uid = get_starting_uid();
            gid = get_gid();
        }
        else
        {
            uid = uid + 1;
            gid = gid;
        }

        // create User Info
        std::string user_info = name_first + " " + name_last;

        // name Home Directory
        std::string home_directory = "/home/" + username;
        std::string default_shell = "/bin/bash";

        // creating records
        std::cout << std::endl << "<<<< Record " << user_index << " details >>>>" << std::endl;
        std::cout << "________________________________________________" << std::endl;
        std::cout << std::endl << "Username: " << username << std::endl;
        std::cout << "Password: xxxxxxxxxxxxxxx" << std::endl;
        std::cout << "UID: " << uid << std::endl;
        std::cout << "GID: " << gid << std::endl;
        std::cout << "User Info: " << user_info << std:: endl;
        std::cout << "Home Directory: " << home_directory << std::endl;
        std::cout << "Default Shell: " << default_shell << std::endl << std::endl;
        std::cout << "________________________________________________" << std::endl;
        std::cout << "<<<< Writing Record " << user_index << " to file. >>>>"  << std::endl;

        // naming Records file
        std::string filename = "newusers_file_";

        // writing Record to file
        std::string full_filename = "output_files/" + filename + date_time + ".txt";
        std::ofstream file;
        // NOTE: If not already done, create a folder in newusers_file_creator called "output_files" before running the code below.
        file.open (full_filename, file.app);

        // checks if output file was opened successfully
        if (file.is_open())
        {

            file_open_success  = "YES";
        }

        // sends output data to file
        std::string c = ":"; // c stands for colon
        //     <Username>  :   <Password>   :   <UID>   :  <GID>    :  <User Info>    :   <Home Directory>   :    <Default Shell>
       file << username << c << password << c << uid << c << gid << c << user_info << c << home_directory << c << default_shell << std::endl;

        // success/failure messages
        if (counter==(num_users-1) && file_open_success == "YES" )
        {
            std::cout << std::endl;
            std::cout << "Number of Records successfully written: " << num_users << std::endl;
            std::cout << "Output file location: " << full_filename << std::endl << std::endl;
        }
        else if (file_open_success != "YES")
        {
            std::cout << std::endl;
            std::cout << "ERROR: the output file could not be written!" << std::endl;
            std::cout << "Check that the 'output_files' folder exists in 'newusers_file_creator'." << std::endl;
            std::cout << "If not, create it." << std::endl << std::endl;
        }

        // close file and say goodbye
        file.close();
        if (counter==(num_users-1)) std::cout << "Goodbye!" << std::endl;
    }

   return 0;
}

// functions
int get_num_users() // gets and returns number of users that the sysadmin wants to add
{
    int gnu_num_users = 0;
    while ((gnu_num_users < 1) || (gnu_num_users > 1000))
    {
        std::cout << "How many users would you like to add to your system (1 to 1000)? ";
        std::cin >> gnu_num_users;
        if ((gnu_num_users < 1) || (gnu_num_users > 1000))
        {
            cout << "ERROR: your entry was not in range (1-1000). Try again." << std::endl << std::endl;
            gnu_num_users = 0;
        }
    }

    return gnu_num_users;
}

std::string get_name_first() // gets and returns first name
{
   std::string gnf_name_first;
   std::cout << "Enter first name: ";
   std::cin >> gnf_name_first;
   return gnf_name_first;
}

std::string get_name_last() // gets and returns last name
{
   std::string gnl_name_last;
   std::cout << "Enter last name: ";
   std::cin >> gnl_name_last;
   return gnl_name_last;
}


std::string create_username(std::string ru_name_first, std::string ru_name_last) // concatenates first name and last name into username
{
    string ru_username = ru_name_first + "." + ru_name_last;
    return ru_username;
}

uint64_t create_password() // creates very long random integer password
{
    auto cp_seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937_64 mt_rand_64(cp_seed);
    int64_t cp_password = mt_rand_64();
    return cp_password;
}

uint32_t get_starting_uid() // gets and returns starting user id for batch of new users
{
    uint32_t gsu_uid_start;
    std::cout << "Enter unused starting UID: ";
    std::cin >> gsu_uid_start;
    return gsu_uid_start;
}

uint32_t get_gid() // gets and returns group id for batch of new users
{
    uint32_t gg_gid;
    std::cout << "Enter unused GID: ";
    std::cin >> gg_gid;
    return gg_gid;
}

std::string get_time_date() // gets and returns date and time from system
{
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);


    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%m%d%Y.%H%M%S");
    return ss.str();
}
