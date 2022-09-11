int     ft_iterative_factorial(int nb)
{
        int     i;
        int     result;

        result = 1;
        i = nb;
        if (nb < 0)
                return (0);
        if (nb == 0)
                return (1);
        while (i >= 1)
        {
                result= result * i;
                i --;
        }
        return (result);
}
