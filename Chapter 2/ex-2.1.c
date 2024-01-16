#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{

    printf("%d %d\n", CHAR_MIN, CHAR_MAX);
    printf("%d %d\n", SHRT_MIN, SHRT_MAX);
    printf("%d %d\n", INT_MIN, INT_MAX);
    printf("%ld %ld\n", LONG_MIN, LONG_MAX);

    printf("%d \n", UCHAR_MAX);
    printf("%d \n", USHRT_MAX);
    printf("%u \n", UINT_MAX);
    printf("%lu \n", ULONG_MAX);

    printf("%f %f\n", FLT_MIN, FLT_MAX);
    printf("%lf %lf\n", DBL_MIN, DBL_MAX);
    printf("%Lf %Lf\n", LDBL_MIN, LDBL_MAX);

    return 0;
}