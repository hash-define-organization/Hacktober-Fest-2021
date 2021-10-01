/* -------------------------------------------------------------------------- */
/*                                Linear Search                               */
/* -------------------------------------------------------------------------- */

#include <stdio.h>
int main()
{
    int arr[10], i, n, element;
    printf("ENTER THE NO. OF ELEMENTS:");
    scanf("%d", &n);
    printf("ENTER ARRAY ELEMENTS:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("ENTERED ARRAY ELEMENTS ARE: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d \n", arr[i]);
    }
    printf("ENTER THE ELEMENT TO BE SEARCHED:");
    scanf("%d", &element);
    for (i = 0; i < n; i++)
    {
        if (arr[i] == element)
        {
            printf("%d FOUND AT POSITION %d", element, i + 1);
            break;
        }
        if (i == n)
        {
            printf("%d NOT FOUND", element);
        }
    }
    return 0;
}
