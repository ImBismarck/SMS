#ifndef INPUT_H
#define INPUT_H

#define INVALID_VALUE "The value entered is invalid"

int getInt(int minValue, int maxValue, char *msg);
void readString(char *string, unsigned int size, char *msg);

#endif /* INPUT_H */

