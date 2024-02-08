#include <stdio.h>

#define SLEEF_STATIC_LIBS
#include <sleef.h>

int main()
{
    void* p_addr = (void *)&Sleef_acoshf16_u10;

    printf("Addr: %p.\n", p_addr);

    return 0;
}