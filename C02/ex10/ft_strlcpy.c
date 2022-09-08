/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seulkim <seulkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:13:51 by seulkim           #+#    #+#             */
/*   Updated: 2022/09/06 03:04:39 by seulkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	string_len(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	len;
	unsigned int	i;

	i = 0;
	len = string_len(src);
	if (size != 0)
	{
		while (src[i] && i + 1 < size)
		{
			dest[i] = src[i];
			i ++;
		}
		dest[i] = '\0';
	}
	return (len);
}
