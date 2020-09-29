/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 16:35:06 by ldutriez          #+#    #+#             */
/*   Updated: 2019/11/16 16:23:04 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reset_flags(t_tool_box *t_box)
{
	t_box->pad = RIGHT;
	t_box->size_pad = 0;
	t_box->precise_pad = 0;
	t_box->b_zero = FALSE;
	t_box->b_digit = FALSE;
	t_box->b_precise = FALSE;
	t_box->b_asterisk = FALSE;
	t_box->b_char = FALSE;
}
