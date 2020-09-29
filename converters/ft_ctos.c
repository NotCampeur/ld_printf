/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:19:20 by ldutriez          #+#    #+#             */
/*   Updated: 2020/01/06 13:29:43 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_ctos(char c)
{
	char *str;

	if (c == '\0')
	{
		if (!(str = (char*)malloc(sizeof(char) * 2)))
			return (0);
		str[0] = c;
	}
	else
	{
		if (!(str = (char*)malloc(sizeof(char) * 2)))
			return (0);
		str[0] = c;
		str[1] = '\0';
	}
	return (str);
}
