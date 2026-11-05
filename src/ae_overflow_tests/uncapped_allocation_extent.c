/* Field-model byteSize remains capped, but AE checks allocation extents. */
#include <stdlib.h>
extern void SAFE_BUFACCESS(void *, unsigned long);
extern void UNSAFE_BUFACCESS(void *, unsigned long);
extern void *__memset_chk(void *, int, unsigned long, unsigned long);
char global_buffer[600];
int main(void)
{
    char stack_buffer[600];
    char *heap_buffer = malloc(400);
    char *zero_buffer = calloc(100, 4);
    char *large_heap_buffer = malloc(600);
    char *large_zero_buffer = calloc(150, 4);
    SAFE_BUFACCESS(global_buffer, 599);
    SAFE_BUFACCESS(stack_buffer, 599);
    SAFE_BUFACCESS(heap_buffer, 399);
    SAFE_BUFACCESS(zero_buffer, 399);
    UNSAFE_BUFACCESS(global_buffer, 600);
    UNSAFE_BUFACCESS(stack_buffer, 600);
    UNSAFE_BUFACCESS(heap_buffer, 400);
    UNSAFE_BUFACCESS(zero_buffer, 400);
    /* Above the field limit, retain an alarm with unknown allocation size.
       This must also hold below UINT32_MAX: 600 is not an exact AE extent. */
    __memset_chk(large_heap_buffer, 0, 601, 600);
    __memset_chk(large_zero_buffer, 0, 601, 600);
    return 0;
}
