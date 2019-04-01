#pragma once
#include "MessageStore.h"

class CLI
{
public:
  CLI(MessageStore& mStore):mStore(mStore) {};
  void run();

private:
  MessageStore& mStore;
  void addUser();
};
