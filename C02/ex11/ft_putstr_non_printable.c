/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seulkim <seulkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:59:07 by seulkim           #+#    #+#             */
/*   Updated: 2022/08/31 01:31:49 by seulkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_to_16(unsigned char c)
{
	int		rem;
	char	*str;
	int		div;

	str = "0123456789abcdef";
	rem = c % 16;
	div = c / 16;
	write(1, str + div, 1);
	write(1, str + rem, 1);
}	

void	ft_putstr_non_printable(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if ((unsigned char) str[idx] >= 32 && (unsigned char) str[idx] <= 126)
			write(1, str + idx, 1);
		else
		{
			write(1, "\\", 1);
			write_to_16((unsigned char) str[idx]);
		}
		idx ++;
	}
}
