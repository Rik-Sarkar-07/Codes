#include <iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
int main() {
   char cmd[10];
   strcpy(cmd,"dir");
   system(cmd);
   return 0;
}
