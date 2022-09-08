/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seulkim <seulkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:43:01 by seulkim           #+#    #+#             */
/*   Updated: 2022/08/30 19:42:30 by seulkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	input_arr(char *str, int cur_location, int num, int size);
void	input_num_n(char *str, int num, int cur_location, int size);
void	ft_print_combn(int n);

void	input_arr(char *str, int cur_location, int num, int size)
{
	str[cur_location] = num + '0';
	if (cur_location == size - 1)
	{
		write(1, str, size);
		if (str[0] != '0' + 10 - size)
			write(1, ", ", 2);
	}
}

void	input_num_n(char *str, int num, int cur_location, int size)
{
	if (cur_location == size - 1)
	{
		while (num <= 9)
		{
			input_arr(str, cur_location, num, size);
			num ++;
		}
		return ;
	}
	else
	{
		while (num <= 10 - size + cur_location)
		{
			input_arr(str, cur_location, num, size);
			input_num_n(str, num + 1, cur_location + 1, size);
			num ++;
		}
		return ;
	}
}

void	ft_print_combn(int n)
{
	char	str[10];

	input_num_n(str, 0, 0, n);
}
