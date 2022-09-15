/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seulkim <seulkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 11:23:20 by seulkim           #+#    #+#             */
/*   Updated: 2022/09/11 12:23:24 by seulkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_check_base1(char *base)
{
	int	idx;
	int	idx_while;
	int	count;

	idx = 0;
	count = 0;
	if (base == 0)
		return (0);
	while (base[idx])
	{
		idx_while = idx + 1;
		while ((base[idx_while] != base[idx]) && base[idx_while])
			idx_while ++;
		if (base[idx] == '-' || base[idx] == '+'
			|| (base[idx] >= 9 && base[idx] <= 13) || base[idx] == ' '
			|| base[idx_while] != '\0')
			return (0);
		count ++;
		idx ++;
	}
	if (idx < 2)
		return (0);
	return (count);
}

int	ft_get_base_num(char c, char *base)
{
	int	idx;

	idx = 0;
	while (base[idx])
	{
		if (base[idx] == c)
			return (idx);
		idx ++;
	}
	return (-1);
}

char	*ft_remove_get_sign(char *str, int *minus)
{
	int	idx;
	int	count;

	idx = 0;
	count = 0;
	while (str[idx] != '\0')
	{
		if (str[idx] == '-')
			count ++;
		if (str[idx] != '-' && str[idx] != '+')
			break ;
		idx ++;
	}
	if (count % 2 == 1)
		*minus = -1;
	else
		*minus = 1;
	return (str + idx);
}

int	ft_atoi_base(char *str, char *base)
{
	int			minus;
	int			idx;
	long long	result;
	int			base_num;
	int			radix;

	idx = 0;
	result = 0;
	radix = ft_check_base1(base);
	if (radix == 0)
		return (0);
	while (str[idx] == ' ' || (str[idx] >= 9 && str[idx] <= 13))
		idx ++;
	str = ft_remove_get_sign(str + idx, &minus);
	idx = 0;
	while (str[idx])
	{
		base_num = ft_get_base_num(str[idx], base);
		if (base_num == -1)
			break ;
		result = result * radix + base_num;
		idx ++;
	}
	result = result * minus;
	return (result);
}
