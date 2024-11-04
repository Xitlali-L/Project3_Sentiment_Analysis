#include "DSString.h"

/* 
 * Implement the functions defined in DSString.h. You may add more functions as needed
 * for the project. 
 *
 * Note that c-strings don's store an explicit length but use `\0` as the terminator symbol
 * but your class should store its length in a member variable. 
 * DDO NOT USE C-STRING FUNCTIONS <string.h> or <cstring>.
 */


DSString::DSString() {
    //only element in the string is the null terminator aka saying it's an empty string
    data = new char[1];
    data[0] = '\0';
    len = 0;
}

DSString::DSString(const char *str) {
    len = strlen(str);
    data = new char[len + 1];
    data[len] = '\0';
    for (int i = 0; i < len; i++) {
        data[i] = str[i];
    }
}

//creating a copy in a seperate memory location
DSString::DSString(const DSString &str) {
    len = str.len;
    data = new char[len + 1];
    data[len] = '\0';
    for (int i = 0; i < len; i++) {
        data[i] = str.data[i];
    }
}

DSString & DSString::operator=(const DSString &str) {
    delete[] data;

    len = str.len;
    data = new char[len + 1];
    data[len] = '\0';
    for (int i = 0; i < len; i++) {
        data[i] = str.data[i];
    }

    return *this;
}

DSString::~DSString() {
    delete[] data;
}

size_t DSString::length() const {
    return len;
}

char & DSString::operator[](size_t i) {
    return data[i];
}

DSString DSString::operator+(const DSString &str) const {
    char* newstr = new char[len + str.len + 1];
    newstr[len + str.len] = '\0';
    for (int i = 0; i < len; i++) {
        newstr[i] = data[i];
    }
    for (int i = 0; i < str.len; i++) {
        newstr[len+i] = str.data[i];
    }
    DSString final = newstr;
    delete[] newstr;
    return final;
}

bool DSString::operator==(const DSString &str) const {
    if (len != str.len) {
        return false;
    }

    for (int i = 0; i < len; i++) {
        if (data[i] != str.data[i]) {
            return false;
        }
    }
    return true;
}

bool DSString::operator<(const DSString &str) const {
    int i = 0;

    while (i < len && i < str.len) {
        if (data[i] < str.data[i]) {
            return true;
        }
        else if (data[i] > str.data[i]) {
            return false;
        }
        i++;
    }

    if (len < str.len) {
        return true;
    }

    return false;
}

DSString DSString::substring(size_t start, size_t numChars) const {
    char* newstr = new char[numChars + 1];
    newstr[numChars] = '\0';

    for (int i = 0; i < numChars; i++) {
        newstr[i] = data[i + start];
    }

    DSString final = newstr;
    delete[] newstr;
    return final;
}

DSString DSString::toLower() const {
    char* newstr = new char[len + 1];
    newstr[len] = '\0';

    for (int i = 0; i < len; i++) {
        if (data[i] >= 'A' && data[i] <= 'Z') {
            newstr[i] = (data[i] + 32);
        }
    }

    DSString final = newstr;
    delete[] newstr;
    return final;
}

const char * DSString::c_str() const {
    return data;
}


std::ostream & operator<<(std::ostream &out, const DSString &str) {
    out << str.data;
    return out;
}
