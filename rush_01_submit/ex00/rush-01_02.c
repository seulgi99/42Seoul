/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01_02.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkweon <mkweon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 21:16:39 by mkweon            #+#    #+#             */
/*   Updated: 2022/09/04 22:46:14 by mkweon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str);
void	dfs(int cnt, int board[][4], int row_col[2][4][4], int *ck_arr);
void	solution(int board[][4], int row_col[2][4][4], char **argv);
void	input_init(int *ck_arr, int input_arr[][4]);
void	ft_split_int(int dest[][4], char *src);

void	solution(int board[][4], int row_col[2][4][4], char **argv)
{
	int	input_arr[4][4];
	int	ck_arr[17];

	ft_split_int(input_arr, argv[1]);
	input_init(ck_arr, input_arr);
	dfs(0, board, row_col, ck_arr);
}

void	input_init(int *ck_arr, int input_arr[][4])
{
	int	idx;
	int	m;
	int	n;

	idx = 0;
	m = 0;
	n = 0;
	while (idx < 16)
	{
		while (m < 4)
		{
			n = 0;
			while (n < 4)
			{
				ck_arr[idx] = input_arr[m][n];
				n++;
				idx++;
			}
			m++;
		}
	}
}

void	ft_split_int(int dest[][4], char *src)
{
	int	idx;
	int	dest_row;
	int	dest_column;

	idx = 0;
	dest_row = 0;
	dest_column = 0;
	while (src[idx] != '\0')
	{
		if (src[idx] >= '0' && src[idx] <= '9')
		{
			dest[dest_row][dest_column] = src[idx] - '0';
			if (dest_column == 3)
			{
				dest_row ++;
				dest_column = 0;
			}
			else
				dest_column ++;
		}
		idx ++;
	}
	return ;
}

int	input_valid_check(char **argv)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] >= '1' && argv[1][i] <= '4')
			cnt++;
		else if (argv[1][i] == ' ')
			cnt++;
		else
			return (0);
		i++;
	}
	if (cnt == 31)
		return (1);
	else
		return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
