#include <iostream>
#include <string>

bool isRotation(string s1, string s2) {
	string temp = s1 + s1;
	return isSubstring(temp, s2);
}