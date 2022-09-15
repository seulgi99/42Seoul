/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seulkim <seulkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 12:58:14 by seulkim           #+#    #+#             */
/*   Updated: 2022/09/11 12:58:55 by seulkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	idx;
	int	result;

	result = 1;
	idx = 0;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (idx < power)
	{
		result = result * nb;
		idx ++;
	}
	return (result);
}
