#ifndef MENU_H
#define MENU_H

#include "data.h"
#include "utilities.h"

void smsMenu(SpaceManager *spaceManager, ClientManager *clientManager);
void mainMenu(SpaceManager *spaceManager, ClientManager *clientManager);
void spacesMenu(SpaceManager *spacesManager);
void clientsMenu(ClientManager *clientsManager);
void generateReports(SpaceManager *spaceManager, ClientManager *clientManager);

#endif