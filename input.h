#ifndef INPUT_H
#define INPUT_H

#define INVALID_VALUE "The value entered is invalid"

void clearConsole();
void clearInputBuffer();

//inputs
int getInt(int minValue, int maxValue, const char *msg);
void readString(char *string, unsigned int size, const char *msg);

#endif /* INPUT_H */

