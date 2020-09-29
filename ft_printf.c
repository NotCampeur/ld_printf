/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 18:47:51 by ldutriez          #+#    #+#             */
/*   Updated: 2019/11/25 11:04:13 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_set_tool_box(t_tool_box *t_box)
{
	t_box->printed_char = 0;
	t_box->pad = RIGHT;
	t_box->size_pad = 0;
	t_box->precise_pad = 0;
	t_box->b_zero = FALSE;
	t_box->b_digit = FALSE;
	t_box->b_precise = FALSE;
	t_box->b_asterisk = FALSE;
	t_box->b_char = FALSE;
}

static	void	ft_treatment(t_tool_box *t_box, va_list arg, char *format)
{
	int i;

	i = 0;
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ft_check_input(t_box, arg, format, &i);
		}
		else
		{
			write(1, &format[i], 1);
			t_box->printed_char++;
		}
		i++;
	}
}

int				ft_printf(const char *format, ...)
{
	t_tool_box	*t_box;
	va_list		arg;

	if (!(t_box = (t_tool_box*)malloc(sizeof(t_tool_box))))
		return (IS_AN_ERROR);
	va_start(arg, format);
	ft_set_tool_box(t_box);
	ft_treatment(t_box, arg, (char *)format);
	va_end(arg);
	free(t_box);
	return (t_box->printed_char);
}
