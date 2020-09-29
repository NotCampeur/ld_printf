/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_precise.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:33:35 by ldutriez          #+#    #+#             */
/*   Updated: 2019/11/19 08:12:47 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		ft_precise_right_pad(t_tool_box *t_box,
													int i, int diff, char *arg)
{
	if (DIGIT == TRUE)
	{
		S_PAD = (FIRST_C == '-' && S_PRECISION >= ARG_LEN) ? S_PAD -= 1 : S_PAD;
		if (S_PRECISION < ft_strlen(arg))
			while (i < S_PAD - ARG_LEN)
			{
				write(1, " ", 1);
				t_box->printed_char++;
				i++;
			}
		else
			while (i < S_PAD - S_PRECISION)
			{
				write(1, " ", 1);
				t_box->printed_char++;
				i++;
			}
	}
	else
		while (i < S_PAD - S_PRECISION + diff)
		{
			write(1, " ", 1);
			t_box->printed_char++;
			i++;
		}
}

static void		ft_precise_digit(t_tool_box *t_box, char *arg, int i, int nbr_z)
{
	long int len;

	len = ARG_LEN;
	i = 0;
	if (FIRST_C == '-' && nbr_z > 0)
	{
		write(1, "-", 1);
		t_box->printed_char++;
		S_PAD -= 1;
	}
	while (i < nbr_z)
	{
		write(1, "0", 1);
		t_box->printed_char++;
		i++;
	}
	i = (FIRST_C == '-' && nbr_z > 0) ? 1 : 0;
	while (i < len)
	{
		write(1, &arg[i], 1);
		t_box->printed_char++;
		i++;
	}
}

void			ft_print_precise(t_tool_box *t_box,
												char *arg, int i, long int len)
{
	int			nb_zero;
	int			b_m;

	b_m = (FIRST_C == '-') ? 1 : 0;
	nb_zero = ((S_PRECISION - len + b_m) < 0) ? 0 : (S_PRECISION - len + b_m);
	if (S_PAD > 0 && PAD == RIGHT && FIRST_C != '%')
		ft_precise_right_pad(t_box, i, nb_zero, arg);
	if (S_PAD > 0 && PAD == RIGHT && FIRST_C == '%' && ZERO == FALSE)
		ft_precise_right_pad(t_box, i, nb_zero, arg);
	if (FIRST_C == '%' && ZERO == TRUE)
		ft_print_zero(t_box, arg, &i);
	if (DIGIT == FALSE)
		while (i < len && i < t_box->precise_pad)
		{
			write(1, &arg[i], 1);
			t_box->printed_char++;
			i++;
		}
	else if (DIGIT == TRUE)
		ft_precise_digit(t_box, arg, i, nb_zero);
	if (S_PAD > 0 && PAD == LEFT)
		ft_print_left_padding(t_box, i, len);
}
