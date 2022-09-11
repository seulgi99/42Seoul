int     ft_sqrt(int nb)
{
        unsigned int     idx;
        unsigned int     num;

        idx = 0;
        num = nb;
        if (nb <= 0)
                return (0);
        while (idx * idx <= num)
        {
                if (num == idx * idx)
                {
                        return (idx);
                }
                idx ++;
        }
        return (0);
}
