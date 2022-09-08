/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seulkim <seulkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 03:17:19 by seulkim           #+#    #+#             */
/*   Updated: 2022/09/07 02:23:03 by seulkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_minus(char *str)
{
	int	idx;
	int	count;

	count = 0;
	idx = 0;
	while (str[idx] && (str[idx] == '-' || str[idx] == '+'))
	{
		if (str[idx] == '-')
			count ++;
		idx ++;
	}
	return (count);
}

char	*ft_remove_sign(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if (str[idx] != '-' && str[idx] != '+')
			break ;
		idx ++;
	}
	return (str + idx);
}

int	ft_atoi(char *str)
{
	int			minus_count;
	int			idx;
	long long	result;

	idx = 0;
	result = 0;
	while (str[idx] == ' ' || str[idx] == '\t'
		|| str[idx] == '\n' || str[idx] == '\v'
		|| str[idx] == '\f' || str[idx] == '\r')
		idx ++;
	minus_count = ft_count_minus(str + idx);
	str = ft_remove_sign(str + idx);
	idx = 0;
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		result = result * 10 + str[idx] - '0';
		idx ++;
	}
	while (minus_count -- > 0)
		result = result * (-1);
	return (result);
}
