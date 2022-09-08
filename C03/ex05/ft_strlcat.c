/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seulkim <seulkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:43:35 by seulkim           #+#    #+#             */
/*   Updated: 2022/09/06 21:29:12 by seulkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_len2(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i ++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	len_dest;
	unsigned int	len_src;
	unsigned int	idx;

	idx = 0;
	len_dest = str_len2(dest);
	len_src = str_len2(src);
	if (dest == 0 || src == 0)
		return (0);
	if (size <= len_dest)
		return (size + len_src);
	while (src[idx] && len_dest + idx + 1 < size)
	{
		dest[len_dest + idx] = src[idx];
		idx ++;
	}
	dest[len_dest + idx] = '\0';
	return (len_dest + len_src);
}
