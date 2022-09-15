/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seulkim <seulkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 04:26:24 by seulkim           #+#    #+#             */
/*   Updated: 2022/09/08 23:40:58 by seulkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write_rev(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
		idx ++;
	idx --;
	while (idx >= 0)
	{
		write(1, str + idx, 1);
		idx --;
	}
}

int	ft_check_base(char *base)
{
	int	idx;
	int	idx_while;
	int	count;

	idx = 0;
	count = 0;
	while (base[idx])
	{
		idx_while = idx + 1;
		while ((base[idx_while] != base[idx]) && base[idx_while])
			idx_while ++;
		if (base[idx] == '-' || base[idx] == '+' || base[idx_while] != '\0')
			return (0);
		count ++;
		idx ++;
	}
	if (idx < 2)
		return (0);
	return (count);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			count;
	int			idx;
	char		str[100];
	long long	num;

	num = nbr;
	idx = 0;
	if (num < 0)
		num = num * (-1);
	count = ft_check_base(base);
	if (count == 0)
		return ;
	if (num == 0)
		str[idx++] = base[0];
	while (num != 0)
	{
		str[idx] = base[num % count];
		num = num / count;
		idx ++;
	}
	if (nbr < 0)
		str[idx++] = '-';
	str[idx] = '\0';
	ft_write_rev(str);
}
