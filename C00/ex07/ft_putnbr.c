/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seulkim <seulkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:43:12 by seulkim           #+#    #+#             */
/*   Updated: 2022/08/30 03:19:10 by seulkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	rev_print_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i ++;
	i --;
	while (i >= 0)
	{
		write(1, str + i, 1);
		i --;
	}
}

void	ft_itostr_rev(int num, char *str)
{
	int	i;
	int	rem;

	i = 0;
	if (num < 0)
	{
		num = num * (-1);
	}
	while (1)
	{
		rem = num % 10;
		num = num / 10;
		if (num != 0 || rem != 0)
		{
			str[i] = rem + '0';
			i ++;
		}
		else
		{
			str[i] = '\0';
			break ;
		}
	}
}

void	ft_putnbr(int nb)
{
	char	str[30];

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
	}
	ft_itostr_rev(nb, str);
	rev_print_str(str);
}
