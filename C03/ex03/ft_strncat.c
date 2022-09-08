/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seulkim <seulkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:44:34 by seulkim           #+#    #+#             */
/*   Updated: 2022/09/06 21:22:59 by seulkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	str_len1(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i ++;
	return (i);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	idx;
	unsigned int	len_dest;

	idx = 0;
	len_dest = str_len1(dest);
	if (nb == 0)
		return (dest);
	while (idx < nb && src[idx])
	{
		dest[len_dest + idx] = src[idx];
		idx ++;
	}
	dest[len_dest + idx] = '\0';
	return (dest);
}
