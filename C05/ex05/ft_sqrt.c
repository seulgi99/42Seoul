/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seulkim <seulkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 13:00:39 by seulkim           #+#    #+#             */
/*   Updated: 2022/09/11 13:01:54 by seulkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	unsigned int	idx;
	unsigned int	num;

	idx = 0;
	num = nb;
	if (nb <= 0)
		return (0);
	while (idx * idx <= num)
	{
		if (num == idx * idx)
		{
			return (idx);
		}
		idx ++;
	}
	return (0);
}
