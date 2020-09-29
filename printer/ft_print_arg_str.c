/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 09:50:25 by ldutriez          #+#    #+#             */
/*   Updated: 2019/11/18 10:05:08 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		ft_right_treatment(t_tool_box *t_box, char *arg, int i, int len)
{
	if (t_box->size_pad > 0 && t_box->b_zero == FALSE
		&& (PRECISION == FALSE || S_PRECISION < 0))
		ft_print_right_padding(t_box, arg);
	if (PRECISION == TRUE && S_PRECISION >= 0)
		ft_print_precise(t_box, arg, i, len);
	if (PRECISION == FALSE || S_PRECISION < 0)
	{
		while (i < len)
		{
			write(1, &arg[i], 1);
			t_box->printed_char++;
			i++;
		}
	}
}

static void		ft_left_treatment(t_tool_box *t_box, char *arg, int i, int len)
{
	if (t_box->b_precise == FALSE)
	{
		while (i < len)
		{
			write(1, &arg[i], 1);
			t_box->printed_char++;
			i++;
		}
	}
	if (t_box->b_precise == TRUE && t_box->b_precise > 0)
		ft_print_precise(t_box, arg, i, len);
	else
		ft_print_left_padding(t_box, i, len);
}

void			ft_print_arg_str(t_tool_box *t_box, char *arg)
{
	int			i;
	long int	len;

	i = 0;
	len = (arg[0] == '\x00' && t_box->b_char == TRUE) ? 1 : ft_strlen(arg);
	if (t_box->pad == RIGHT)
		ft_right_treatment(t_box, arg, i, len);
	else if (t_box->pad == LEFT)
		ft_left_treatment(t_box, arg, i, len);
	ft_reset_flags(t_box);
	free(arg);
}
