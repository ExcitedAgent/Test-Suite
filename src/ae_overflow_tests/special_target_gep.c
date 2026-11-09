/* The external result has no known allocation size. AE must report
 * an alarm with an unbounded allocation size and the 4-byte offset of
 * p[1], without reading an uninitialized size or a missing ICFG node. */
extern int *unknown_pointer(void);
int main(void)
{
    int *p = unknown_pointer();
    p[1] = 0;
    return 0;
}
