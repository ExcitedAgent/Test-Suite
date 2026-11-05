/* A scan budget is not evidence of a terminator. */
#include <stdbool.h>
#include <string.h>
extern char *unknown_pointer(void);
extern void svf_assert(bool);
extern void svf_print(unsigned long, char *);
int main(void)
{
    char empty[1];
    empty[0] = 0;
    svf_assert(strlen(empty) == 0);
    svf_print(strlen(unknown_pointer()), "unknown length");
    return 0;
}
