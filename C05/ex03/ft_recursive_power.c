int     ft_recursive_power(int nb, int power)
{
        int     result;
        
        result = 1;
        if (power < 0)
                return (0);
        if (power == 0)
                return (1);
        result = ft_recursive_power(nb, power - 1) * nb;
        return (result);
}
