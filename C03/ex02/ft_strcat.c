/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seulkim <seulkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:44:09 by seulkim           #+#    #+#             */
/*   Updated: 2022/09/06 20:57:29 by seulkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_len(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i ++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	len;
	unsigned int	idx;

	idx = 0;
	len = str_len(dest);
	while (src[idx] != '\0')
	{
		dest[len + idx] = src[idx];
		idx ++;
	}
	dest[len + idx] = '\0';
	return (dest);
}
