#include <iostream>
#include "UserInterface.h"


int main() {
    UserInterface* ui = UserInterface::getUserInterface();
    ui->startInterface();
    return 0;
}