/* The synthetic copy's node-less loaded value must be read where written.
 * An empty source avoids relying on the dedicated handler's nonzero loop. */
#include <stdbool.h>
#include <string.h>
extern void svf_assert(bool);
int main(void)
{
    char source[1] = {0};
    char destination[1] = {42};
    strcpy(destination, source);
    svf_assert(destination[0] == 0);
    return 0;
}
