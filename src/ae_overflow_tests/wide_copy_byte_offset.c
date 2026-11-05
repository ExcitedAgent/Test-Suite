/* The third wide element's terminator ends at byte 11, not element 2. */
#include <wchar.h>
int main(void)
{
    wchar_t source[3] = {L'A', L'B', 0};
    wchar_t destination[2] = {0};
    wcscpy(destination, source);
    return 0;
}
