/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seulkim <seulkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 13:13:08 by seulkim           #+#    #+#             */
/*   Updated: 2022/09/12 15:36:06 by seulkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write_str(int *str)
{
	int		idx;
	char	c;

	idx = 0;
	while (idx < 10)
	{
		c = '0' + str[idx];
		write(1, &c, 1);
		idx ++;
	}
	write(1, "\n", 1);
}

int	check_is_valid(int *row, int cur)
{
	int	idx;
	int	cur_num;
	int	idx_num;

	idx = 0;
	cur_num = row[cur];
	while (idx < cur)
	{
		idx_num = row[idx];
		if (cur_num == idx_num)
			return (0);
		else if ((cur_num - idx_num) == (cur - idx))
			return (0);
		else if ((idx_num - cur_num) == (cur - idx))
			return (0);
		idx ++;
	}
	return (1);
}

void	ft_queens_recursive(int *queen, int cur, int *count)
{
	int	num;

	num = 0;
	if (cur == 10)
	{
		queen[10] = '\0';
		ft_write_str(queen);
		*count += 1;
		return ;
	}
	while (num < 10)
	{		
		queen[cur] = num;
		if (check_is_valid(queen, cur))
		{
			ft_queens_recursive(queen, cur + 1, count);
		}
		num ++;
	}
	queen[cur] = '0';
	return ;
}

int	ft_ten_queens_puzzle(void)
{
	int	queen[11];
	int	count;

	count = 0;
	ft_queens_recursive(queen, 0, &count);
	return (count);
}
