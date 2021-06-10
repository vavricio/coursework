#include <iostream>

#include "UserInterface.h"
#include "CyclicList.h"


int main() {
    UserInterface* ui = UserInterface::getUserInterface();
    ui->startInterface();
    return 0;
}