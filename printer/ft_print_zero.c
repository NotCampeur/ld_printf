/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_zero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:19:27 by ldutriez          #+#    #+#             */
/*   Updated: 2019/11/19 07:39:55 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_zero(t_tool_box *t_box, char *arg, int *i)
{
	long int	j;
	int			n;

	n = 0;
	j = ft_strlen(arg);
	if (arg[0] == '-' && S_PAD - j > 0)
	{
		*i = *i + 1;
		write(1, "-", 1);
		t_box->printed_char++;
	}
	while (n < S_PAD - j)
	{
		write(1, "0", 1);
		t_box->printed_char++;
		n++;
	}
}
