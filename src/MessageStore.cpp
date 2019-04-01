#include "MessageStore.h"
#include <stdexcept>

using namespace std;

inline bool MessageStore::isUser(const std::string& user) {
  return messages.find(user) != messages.end();
}

void MessageStore::addUser(const string& user) {
  if (user.empty()) {
    throw invalid_argument("Username can't be empty");
  }
  if (isUser(user)) {
    throw invalid_argument("User '" + user + "' already exists");
  }
  messages[user];
}

void MessageStore::sendMessage(const Message& msg) {
  if (msg.from.empty()) {
    throw invalid_argument("From user can't be empty");
  }
  if (msg.to.empty()) {
    throw invalid_argument("To user can't be empty");
  }
  if (!isUser(msg.to)) {
    throw invalid_argument("User '" + msg.to + "' doesn't exist");
  }
  if (!isUser(msg.from)) {
    throw invalid_argument("User '" + msg.from + "' doesn't exist");
  }
  messages[msg.to].push_back(msg);
}

const vector<const Message>& MessageStore::getMessages(const string& user) {
  if (user.empty()) {
    throw invalid_argument("Username can't be empty");
  }
  if (!isUser(user)) {
    throw invalid_argument("User '" + user + "' doesn't exist");
  }
  return messages[user];
}
