/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkweon <mkweon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:28:29 by mkweon            #+#    #+#             */
/*   Updated: 2022/09/04 22:29:28 by mkweon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		input_valid_check(char **argv);
void	thd_array_init(int arr[2][4][4]);
int		final_check(int board[4][4], int *hint);
void	solution(int board[][4], int row_col[2][4][4], char **argv);
void	array_init(int arr[][4]);
void	dfs(int cnt, int board[][4], int row_col[2][4][4], int *ck_arr);
void	ft_split_int(int dest[][4], char *src);
void	print_arr(int board[][4]);

int	main(int argc, char **argv)
{
	int	board[4][4];
	int	row_col[2][4][4];

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (!input_valid_check(argv))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	array_init(board);
	thd_array_init(row_col);
	solution(board, row_col, argv);
}

void	dfs(int cnt, int board[][4], int row_col[2][4][4], int *ck_arr)
{
	int	x;
	int	y;
	int	i;

	x = cnt / 4;
	y = cnt % 4;
	i = -1;
	if (cnt == 16 && final_check(board, ck_arr))
		print_arr(board);
	if (board[x][y] == 0)
	{
		while (++i <= 3)
		{
			if (row_col[0][x][i] == 0 && row_col[1][y][i] == 0)
			{
				row_col[0][x][i] = 1;
				row_col[1][y][i] = 1;
				board[x][y] = i + 1;
				dfs(cnt + 1, board, row_col, ck_arr);
				board[x][y] = 0;
				row_col[0][x][i] = 0;
				row_col[1][y][i] = 0;
			}
		}
	}
}

void	print_arr(int board[][4])
{
	int		m;
	int		n;
	char	num;

	m = 0;
	n = 0;
	while (m < 4)
	{
		n = 0;
		while (n < 4)
		{
			num = board[m][n] + '0';
			if (n != 3)
			{
				write(1, &num, 1);
				write(1, " ", 1);
			}
			else
				write(1, &num, 1);
			n++;
		}
		write(1, "\n", 1);
		m++;
	}
}

void	thd_array_init(int arr[2][4][4])
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < 2)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 4)
			{
				arr[i][j][k] = 0;
				k++;
			}
			j++;
		}
		i++;
	}
}

void	array_init(int arr[][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			arr[i][j] = 0;
			j++;
		}
		i++;
	}
}
