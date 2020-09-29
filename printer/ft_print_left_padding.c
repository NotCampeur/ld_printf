/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_left_padding.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:15:08 by ldutriez          #+#    #+#             */
/*   Updated: 2019/11/16 15:23:12 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_left_padding(t_tool_box *t_box, int i, long int len)
{
	int max_pad;
	int j;

	i = (t_box->b_digit == TRUE) ? 0 : i;
	j = (t_box->precise_pad < len) ? len : t_box->precise_pad;
	max_pad = (t_box->b_digit == TRUE) ? t_box->size_pad - j : t_box->size_pad;
	while (i < max_pad)
	{
		write(1, " ", 1);
		t_box->printed_char++;
		i++;
	}
}
