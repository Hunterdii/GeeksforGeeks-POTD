#include <stdbool.h>
#include <string.h>

bool areIsomorphic(char* s1, char* s2) {
    int m1[256] = {0}, m2[256] = {0};
    for (int i = 0; s1[i]; i++) {
        if (m1[(int)s1[i]] != m2[(int)s2[i]]) return false;
        m1[(int)s1[i]] = m2[(int)s2[i]] = i + 1;
    }
    return true;
}
