/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkweon <mkweon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 17:49:49 by mkweon            #+#    #+#             */
/*   Updated: 2022/09/04 20:15:51 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	row_check(int board[4], int left, int right);
int	col_check(int board[4], int top, int bottom);
int	top_left_size_check(int *board);
int	bot_right_size_check(int *board);

int	final_check(int board[4][4], int *hint)
{
	int	i;
	int	j;
	int	temp_board[4];
	int	ans;

	i = 0;
	ans = 0;
	if ((row_check(board[0], hint[8], hint[12]) == 1) && (row_check
			(board[1], hint[9], hint[13]) == 1) && (row_check
			(board[2], hint[10], hint[14]) == 1) && (row_check
			(board[3], hint[11], hint[15]) == 1))
		ans = 1;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			temp_board[j] = board[j][i];
			j++;
		}
		if (col_check(temp_board, hint[0 + i], hint[4 + i]) != 1)
			ans = 0;
		i++;
	}
	return (ans);
}

int	row_check(int board[4], int left, int right)
{
	int	left_size;
	int	right_size;

	left_size = top_left_size_check(board);
	right_size = bot_right_size_check(board);
	if ((left != left_size) || (right != right_size))
		return (0);
	return (1);
}

int	col_check(int board[4], int top, int bottom)
{
	int	top_size;
	int	bottom_size;

	top_size = top_left_size_check(board);
	bottom_size = bot_right_size_check(board);
	if ((top != top_size) || (bottom != bottom_size))
		return (0);
	return (1);
}

int	top_left_size_check(int *board)
{
	int	i;
	int	tl_size;
	int	max;

	i = 1;
	tl_size = 1;
	max = board[0];
	while (i < 4)
	{
		if (max < board[i])
		{
			max = board[i];
			tl_size++;
		}
		i++;
	}
	return (tl_size);
}

int	bot_right_size_check(int *board)
{
	int	i;
	int	br_size;
	int	max;

	i = 2;
	br_size = 1;
	max = board[3];
	while (i >= 0)
	{
		if (max < board[i])
		{
			max = board[i];
			br_size++;
		}
		i--;
	}
	return (br_size);
}
