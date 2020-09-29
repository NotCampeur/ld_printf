/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:35:30 by ldutriez          #+#    #+#             */
/*   Updated: 2019/11/19 07:19:25 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		ft_right_treatment(t_tool_box *t_box, char *arg, int i, int len)
{
	if ((S_PAD > 0 && ZERO == FALSE &&
		(PRECISION == FALSE || S_PRECISION <= 0)) ||
		(S_PAD > 0 && ZERO == TRUE && PRECISION == TRUE && S_PRECISION == 0))
		ft_print_right_padding(t_box, arg);
	else if (PRECISION == TRUE && S_PRECISION > 0)
		ft_print_precise(t_box, arg, i, len);
	else if (t_box->b_zero == TRUE && (PRECISION == FALSE || S_PRECISION < 0))
		ft_print_zero(t_box, arg, &i);
	if (PRECISION == FALSE || S_PRECISION <= 0)
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
	if (PRECISION == FALSE || S_PRECISION <= 0)
	{
		while (i < len)
		{
			write(1, &arg[i], 1);
			t_box->printed_char++;
			i++;
		}
	}
	if (PRECISION == TRUE && S_PRECISION > 0)
		ft_print_precise(t_box, arg, i, len);
	else
		ft_print_left_padding(t_box, i, len);
}

void			ft_print_arg(t_tool_box *t_box, char *arg)
{
	int			i;
	long int	len;

	i = 0;
	len = (arg[0] == '\x00' && CHAR == TRUE) ? 1 : ft_strlen(arg);
	if (PAD == RIGHT)
		ft_right_treatment(t_box, arg, i, len);
	else if (PAD == LEFT)
		ft_left_treatment(t_box, arg, i, len);
	ft_reset_flags(t_box);
	free(arg);
}
