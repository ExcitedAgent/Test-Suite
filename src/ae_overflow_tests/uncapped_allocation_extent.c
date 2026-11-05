/* Field-model byteSize remains capped, but AE checks allocation extents. */
#include <stdlib.h>
extern void SAFE_BUFACCESS(void *, unsigned long);
extern void UNSAFE_BUFACCESS(void *, unsigned long);
char global_buffer[600];
int main(void)
{
    char stack_buffer[600];
    char *heap_buffer = malloc(600);
    char *zero_buffer = calloc(150, 4);
    SAFE_BUFACCESS(global_buffer, 599);
    SAFE_BUFACCESS(stack_buffer, 599);
    SAFE_BUFACCESS(heap_buffer, 599);
    SAFE_BUFACCESS(zero_buffer, 599);
    UNSAFE_BUFACCESS(global_buffer, 600);
    UNSAFE_BUFACCESS(stack_buffer, 600);
    UNSAFE_BUFACCESS(heap_buffer, 600);
    UNSAFE_BUFACCESS(zero_buffer, 600);
    return 0;
}
