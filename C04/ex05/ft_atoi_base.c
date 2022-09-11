#include <unistd.h>

int     ft_strlen(char *str)
{
        int     idx;

        idx = 0;
        while(str[idx])
                idx++;
        return (idx);
}

int     ft_check_base(char *base)
{
        int     idx;
        int     idx_while;
        int     count;

        idx = 0;
        count = 0;
        while (base[idx])
        {
                idx_while = idx + 1;
                while ((base[idx_while] != base[idx])&& base[idx_while])
                        idx_while ++;
                if (base[idx] == '-' || base[idx] == '+'
                                || base[idx_while] != '\0')
                        return (0);
                count ++;
                idx ++;
        }
        if (idx < 2)
                return (0);
        return (count);
}

int	ft_get_minus(char *str)
{
	int	idx;
	int     minus;

	minus = 1;
	idx = 0;
	while (str[idx] && (str[idx] == '-' || str[idx] == '+'))
	{
		if (str[idx] == '-')
			minus = minus * (-1);
		idx ++;
	}
	return (minus);
}

int     ft_get_base_num(char c,char *base)
{
        int     idx;
        idx = 0; 
        while (base[idx])
        {
                if (base[idx] == c)
                        return (idx);
                idx ++;
        }
        return (-1);
}

char	*ft_remove_sign(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if (str[idx] != '-' && str[idx] != '+')
			break ;
		idx ++;
	}
	return (str + idx);
}

int	ft_atoi_base(char *str, char *base)
{
	int		minus;
	int		idx;
	long long	result;
        int             base_num;
        int             radix;

	idx = 0;
	result = 0;
        radix = ft_strlen(base);
        if (ft_check_base(base)==0)
                return (0);
	while (str[idx] == ' ' || str[idx] == '\t'
		|| str[idx] == '\n' || str[idx] == '\v'
		|| str[idx] == '\f' || str[idx] == '\r')
		idx ++;
	minus = ft_get_minus(str + idx);
	str = ft_remove_sign(str + idx);
	idx = 0;
	while (str[idx])
	{
                base_num = ft_get_base_num(str[idx],base);
                if (base_num == -1)
                        break;
		result = result *radix  + base_num;
		idx ++;
	}
	result = result * minus;
	return (result);
}
