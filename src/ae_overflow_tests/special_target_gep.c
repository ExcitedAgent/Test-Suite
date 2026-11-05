/* The external result has no established allocation extent.
 * AE must retain an unknown-bounds alarm without reading special-object
 * byteSize or following a null defining ICFG node. */
extern int *unknown_pointer(void);
int main(void)
{
    int *p = unknown_pointer();
    p[1] = 0;
    return 0;
}
