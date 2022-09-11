#include <stdio.h>
int     ft_is_prime1(int nb)
{
        int i;
        int idx;

        i = 2;
        if (nb <= 1)
                return (0); 
        while (i*i <=nb)
        {
                idx = i;
                while(i * idx <= nb)
                {
                        if (i * idx == nb)
                                return (0);
                        idx ++;
                }
                i ++;
        }
        return (1);
}

int     ft_find_next_prime(int nb)
{
        while (1)
        {
                if (ft_is_prime1(nb) == 1)
                        return (nb);
                nb ++;
        }
        return (0);
}

int main(void)
{
        printf("%d",ft_find_next_prime(21478630));
        return 0;
}
