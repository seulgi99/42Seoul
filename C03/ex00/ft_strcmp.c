/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seulkim <seulkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 07:03:53 by seulkim           #+#    #+#             */
/*   Updated: 2022/09/05 21:43:03 by seulkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	idx;
	unsigned char	a;
	unsigned char	b;

	idx = 0;
	while (s1[idx] || s2[idx])
	{
		a = s1[idx];
		b = s2[idx];
		if (a != b)
			return (a - b);
		idx ++;
	}
	return (0);
}
