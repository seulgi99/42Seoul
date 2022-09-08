/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seulkim <seulkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:44:41 by seulkim           #+#    #+#             */
/*   Updated: 2022/09/07 04:21:26 by seulkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_len2(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i ++;
	return (i);
}

int	ft_strcmp1(char *s1, char *s2)
{
	unsigned int	idx;	
	unsigned int	len_s1;
	unsigned int	len_s2;

	idx = 0;
	len_s1 = str_len2(s1);
	len_s2 = str_len2(s2);
	if (len_s1 < len_s2)
		return (-1);
	while (s2[idx])
	{
		if (s1[idx] != s2[idx])
			return (s1[idx] - s2[idx]);
		idx ++;
	}
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	idx;

	idx = 0;
	if (*to_find == '\0')
		return (str);
	while (str[idx] != '\0')
	{
		if (ft_strcmp1(str + idx, to_find) == 0)
			return (str + idx);
		idx ++;
	}
	return (0);
}
