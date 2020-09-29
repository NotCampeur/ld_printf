/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:08:02 by ldutriez          #+#    #+#             */
/*   Updated: 2019/11/08 15:18:23 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

long int		ft_strlen(const char *string)
{
	long int length;

	length = 0;
	while (string[length] != '\0')
		length++;
	return (length);
}
