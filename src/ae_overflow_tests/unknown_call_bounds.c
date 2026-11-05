/* An unknown destination must retain an alarm with unknown operands. */
extern void *__memset_chk(void *, int, unsigned long, unsigned long);
extern char *unknown_pointer(void);
int main(void)
{
    char *p = unknown_pointer();
    __memset_chk(p, 0, 1, 1);
    return 0;
}
