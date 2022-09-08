/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seulkim <seulkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 20:27:14 by seulkim           #+#    #+#             */
/*   Updated: 2022/08/31 06:18:02 by seulkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_to_16(unsigned char *str)
{
	int				idx;
	unsigned char	c;

	idx = 0;
	while (idx < 16)
	{
		c = str[idx];
		write(1, &"0123456789abcdef"[c / 16], 1);
		write(1, &"0123456789abcdef"[c % 16], 1);
		if (idx % 2 == 1)
			write(1, " ", 1);
		if (c == '\0')
			break ;
		idx ++;
	}
	idx ++;
	if (idx != 16)
	{
		while (idx ++ < 16)
		{
			write(1, "  ", 2);
			if (idx % 2 == 1)
				write(1, " ", 1);
		}
	}
}

void	write_arr_addr_16(long long num)
{
	char			str[18];
	int				i;
	long long		div;

	i = 15;
	while (i >= 0)
	{
		div = num % 16;
		num = num / 16;
		str[i] = "0123456789abcdef"[div];
		i --;
	}
	str[16] = ':';
	str[17] = ' ';
	write(1, str, 18);
}

void	write_str(unsigned char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0' && idx < 16)
	{
		if (str[idx] >= 32 && str[idx] <= 126)
			write(1, str + idx, 1);
		else
			write(1, ".", 1);
		idx ++;
	}
	if (str[idx] == '\0')
		write(1, ".", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	long long	i;
	int			idx;
	int			count;

	addr = (unsigned char *) addr;
	idx = 0;
	if (size % 16 == 0)
		count = size / 16 - 1;
	else
		count = size / 16;
	while (idx <= count)
	{
		i = (long long) addr;
		write_arr_addr_16(i + idx * 16);
		write_to_16((unsigned char *) addr + idx * 16);
		write_str((unsigned char *) addr + idx * 16);
		write(1, "\n", 1);
		idx ++;
	}
	return (addr);
}
