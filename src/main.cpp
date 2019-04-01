
#include "MessageStore.h"
#include "CLI.h"
#include <iostream>

using namespace std;

int main(int, const char* [])
{
  MessageStore mStore;
  CLI cli(mStore);
  cli.run();

	return 0;
}
