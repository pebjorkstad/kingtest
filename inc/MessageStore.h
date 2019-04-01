#pragma once
#include <string>
#include <vector>
#include <unordered_map>

struct Message {
  std::string from;
  std::string to;
  std::string text;
};

typedef std::unordered_map<std::string, std::vector<const Message>> messageStore;

class MessageStore
{
public:
	void addUser(const std::string& user);
  bool isUser(const std::string& user);
	void sendMessage(const Message& msg);
  const std::vector<const Message>& getMessages(const std::string& user);

private:
	messageStore messages;
};
