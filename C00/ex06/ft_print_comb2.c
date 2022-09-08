/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seulkim <seulkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 03:43:29 by seulkim           #+#    #+#             */
/*   Updated: 2022/08/30 02:51:03 by seulkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_4nums(char a, char b, char c, char d)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, " ", 1);
	write(1, &c, 1);
	write(1, &d, 1);
	if (a <= '8' || b < '8')
	{
		write(1, ", ", 2);
	}	
}

void	switch_right_num(char a, char b)
{
	char	c;
	char	d;

	c = a;
	while (c <= '9')
	{
		d = b + 1;
		if (c > a)
		{
			d = '0';
		}
		while (d <= '9')
		{
			print_4nums(a, b, c, d);
			d += 1;
		}
		c += 1;
	}
}

void	ft_print_comb2(void)
{
	char	a;
	char	b;

	a = '0';
	while (a <= '9')
	{
		b = '0';
		while (b <= '9')
		{
			switch_right_num(a, b);
			b += 1;
		}
		a += 1;
	}
}
