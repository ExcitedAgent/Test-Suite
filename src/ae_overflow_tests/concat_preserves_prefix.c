/* Dedicated concatenation must inspect and preserve the original prefix. */
#include <stdbool.h>
#include <string.h>
extern void svf_assert(bool);
int main(void)
{
    char destination[3] = {'B', 0, 0};
    char source[2] = {'A', 0};
    strcat(destination, source);
    svf_assert(destination[0] == 'B');
    svf_assert(destination[1] == 'A');
    svf_assert(destination[2] == 0);
    return 0;
}
