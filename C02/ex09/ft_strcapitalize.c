/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seulkim <seulkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 05:43:14 by seulkim           #+#    #+#             */
/*   Updated: 2022/08/31 06:46:35 by seulkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	trans_upper(char *str)
{
	if (*str >= 'a' && *str <= 'z')
		*str -= 32;
}

void	trans_lower(char *str)
{
	if (*str >= 'A' && *str <= 'Z')
		*str += 32;
}

char	*ft_strcapitalize(char *str)
{
	int	idx;

	idx = 1;
	trans_upper(str);
	while (str[idx] != '\0')
	{
		if ((str[idx - 1] >= 'A' && str[idx - 1] <= 'Z')
			|| (str[idx - 1] >= 'a' && str[idx - 1] <= 'z')
			|| (str[idx - 1] >= '0' && str[idx - 1] <= '9'))
			trans_lower(str + idx);
		else
			trans_upper(str + idx);
		idx ++;
	}
	return (str);
}
