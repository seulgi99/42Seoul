int     ft_is_prime(int nb)
{
        unsigned int i;
        unsigned int idx;
        long long  num;

        i = 2;
        num = nb;
        if (nb <= 1)
                return (0); 
        while (i*i <= num)
        {
                idx = i;
                while(i * idx <= num)
                {
                        if (i * idx == num)
                                return (0);
                        idx ++;
                }
                i ++;
        }
        return (1);
}
