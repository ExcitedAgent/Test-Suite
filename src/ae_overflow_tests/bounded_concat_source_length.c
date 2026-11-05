/* n is a maximum, not the number of source characters copied. */
#include <string.h>
int main(void)
{
    char destination[3] = {'Z', 'Z', 0};
    char source[2] = {'A', 0};
    strncat(destination, source, 100);
    return 0;
}
