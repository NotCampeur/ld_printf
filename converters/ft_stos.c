/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:26:34 by ldutriez          #+#    #+#             */
/*   Updated: 2019/11/25 16:07:18 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char		*ft_got_a_null(void)
{
	char	*str;

	str = 0;
	if (!(str = (char*)malloc(sizeof(char) * 7)))
		return (NULL);
	str[0] = '(';
	str[1] = 'n';
	str[2] = 'u';
	str[3] = 'l';
	str[4] = 'l';
	str[5] = ')';
	str[6] = '\0';
	return (str);
}

char			*ft_stos(char *s)
{
	char	*str;
	int		i;

	i = 0;
	if (s == NULL)
		str = ft_got_a_null();
	else
	{
		while (s[i])
			i++;
		if (!(str = (char*)malloc(sizeof(char) * i + 1)))
			return (0);
		i = 0;
		while (s[i])
		{
			str[i] = s[i];
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
