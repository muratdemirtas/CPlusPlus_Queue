#include "iostream"
#include "QueueList.h"

QueueList <std::string> queue;
std::string msgA = "Happy Hacking!";
std::string msgB = "Hacking Happy!";

int main()
{

    queue.push (msgA);
    queue.push (msgB);

    while (!queue.isEmpty ())
      {  std::string x = queue.pop();
      Print_Message(IS_INFO,x.c_str());
    }

}
