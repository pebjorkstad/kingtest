#include "CLI.h"
#include <iostream>
#include <stdexcept>

void printChoices() {
  std::cout << std::endl;
  std::cout << "Please select an option:" << std::endl;
	std::cout << "1. Create User" << std::endl;
	std::cout << "2. Send Message" << std::endl;
	std::cout << "3. Receive All Messages For User" << std::endl;
	std::cout << "4. Quit" << std::endl;
  std::cout.flush();
}

void CLI::run() {
  std::string choice;
  while(true) {
    printChoices();
    std::getline(std::cin, choice);
    int parsedChoice;
    try {
      parsedChoice = stoi(choice);
    } catch (const std::invalid_argument& ia) {
      std::cout << "Invalid choice" << std::endl;
      continue;
    }
    switch (parsedChoice)
    {
      case 1:
      {
        std::cout << "Please enter name: ";
        std::string user;
        std::getline(std::cin, user);
        try {
          mStore.addUser(user);
        } catch (const std::invalid_argument& ia) {
	        std::cerr << "ERROR: " << ia.what() << std::endl;
          continue;
        }
        std::cout << "User " << user << " added" << std::endl;
        continue;
      }
      case 2:
      {
        std::string from, to, text;
        std::cout << "From: ";
        std::getline(std::cin, from);
        std::cout << "To: ";
        std::getline(std::cin, to);
        std::cout << "Message: ";
        std::getline(std::cin, text);
        try {
          mStore.sendMessage(Message{from, to, text});
        } catch (const std::invalid_argument& ia) {
	        std::cerr << "ERROR: " << ia.what() << std::endl;
          continue;
        }
        continue;
      }
      case 3:
      {
        std::cout << "Enter name of user to receive all messages for: " << std::endl;
        std::string user;
        std::getline(std::cin, user);
        if(user.empty()) {
          std::cerr << "ERROR: User can't be empty" << std::endl;
          continue;
        }
        if(!mStore.isUser(user)) {
	        std::cerr << "ERROR: User '" << user << "' doesn't exist" << std::endl;
          continue;
        }
        std::cout << std::endl << "===== BEGIN MESSAGES =====" << std::endl;
        int num = 0;
        for(auto const& msg: mStore.getMessages(user)) {
          std::cout << "Message " << ++num << std::endl;
          std::cout << "From: " << msg.from << std::endl;
          std::cout << "Content: " << msg.text << std::endl << std::endl;
        }
        std::cout << "===== END MESSAGES =====" << std::endl;
        continue;
      }
      case 4:
      {
        std::cout << "Quitting" << std::endl;
        return;
      }
      default:
        std::cout << "Invalid choice" << std::endl;
        continue;
    }
  }
}
