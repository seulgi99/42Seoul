/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seulkim <seulkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 07:19:30 by seulkim           #+#    #+#             */
/*   Updated: 2022/09/05 21:48:25 by seulkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	idx;
	unsigned char	a;
	unsigned char	b;

	idx = 0;
	if (n == 0)
		return (0);
	while (idx < n && (s1[idx] || s2[idx]))
	{
		a = s1[idx];
		b = s2[idx];
		if (a != b)
			return (a - b);
		idx ++;
	}
	return (0);
}
