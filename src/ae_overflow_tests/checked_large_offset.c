/* A detector offset must not be replaced by the field limit. */
char buffer[600];
int main(void)
{
    buffer[700] = 1;
    return 0;
}
