/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_right_padding.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:27:46 by ldutriez          #+#    #+#             */
/*   Updated: 2019/11/18 08:45:45 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_right_padding(t_tool_box *t_box, char *arg)
{
	int			i;
	long int	j;

	i = 0;
	j = (arg[0] == '\x00' && t_box->b_char == 1) ? 1 : ft_strlen(arg);
	while (i < t_box->size_pad - j)
	{
		write(1, " ", 1);
		t_box->printed_char++;
		i++;
	}
}
