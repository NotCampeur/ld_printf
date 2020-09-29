/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:58:22 by ldutriez          #+#    #+#             */
/*   Updated: 2019/11/18 17:25:29 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_basic_check2(t_tool_box *t_box, va_list arg, char *format, int i)
{
	if (format[i] == 'p')
	{
		ft_print_arg_addr(t_box, ft_addrtos(t_box, va_arg(arg, void*)));
		return ;
	}
	else if (format[i] == 'x')
	{
		DIGIT = TRUE;
		ft_print_arg(t_box,
					ft_basetos(t_box, va_arg(arg, int), "0123456789abcdef"));
		return ;
	}
	else if (format[i] == 'X')
	{
		DIGIT = TRUE;
		ft_print_arg(t_box,
					ft_basetos(t_box, va_arg(arg, int), "0123456789ABCDEF"));
		return ;
	}
	else if (format[i] == '%')
		ft_print_arg(t_box, ft_stos("%"));
}

static void	ft_basic_check(t_tool_box *t_box, va_list arg, char *format, int i)
{
	if (format[i] == 'd' || format[i] == 'i')
	{
		DIGIT = TRUE;
		ft_print_arg(t_box, ft_itos(t_box, va_arg(arg, int)));
		return ;
	}
	else if (format[i] == 'c')
	{
		CHAR = TRUE;
		ft_print_arg(t_box, ft_ctos(va_arg(arg, int)));
		return ;
	}
	else if (format[i] == 's')
	{
		ft_print_arg_str(t_box, ft_stos(va_arg(arg, char *)));
		return ;
	}
	else if (format[i] == 'u')
	{
		DIGIT = TRUE;
		ft_print_arg(t_box, ft_utos(t_box, va_arg(arg, unsigned int)));
		return ;
	}
	else
		ft_basic_check2(t_box, arg, format, i);
}

static void	ft_check_flag2(t_tool_box *t_box, char *format, int *i)
{
	if (format[*i] == '-')
	{
		t_box->pad = LEFT;
		*i = *i + 1;
		ft_get_padding(t_box, format, i);
	}
	else if (format[*i] == '0')
	{
		t_box->b_zero = TRUE;
		*i = *i + 1;
		ft_get_padding(t_box, format, i);
	}
}

static void	ft_check_flag1(t_tool_box *t_box, va_list arg, char *format, int *i)
{
	if (format[*i] == '.')
	{
		PRECISION = TRUE;
		*i = *i + 1;
		ft_get_padding(t_box, format, i);
	}
	else if (format[*i] == '*')
	{
		t_box->b_asterisk = TRUE;
		if (PRECISION == TRUE)
			S_PRECISION = va_arg(arg, int);
		else
			S_PAD = va_arg(arg, int);
		if (S_PAD < 0)
		{
			S_PAD *= -1;
			t_box->pad = LEFT;
		}
	}
	else
		ft_check_flag2(t_box, format, i);
}

void		ft_check_input(t_tool_box *t_box, va_list arg, char *format, int *i)
{
	while (format[*i])
	{
		if (C == 'c' || C == 's' || C == 'p' || C == 'd' || C == 'i' || C == 'u'
		|| C == 'x' || C == 'X' || C == '%')
		{
			ft_basic_check(t_box, arg, format, *i);
			return ;
		}
		else if (format[*i] == '.' || format[*i] == '*' || format[*i] == '-'
									|| format[*i] == '0' || format[*i] == '#')
		{
			ft_check_flag1(t_box, arg, format, i);
		}
		else if (ft_isdigit(format[*i]) && format[*i - 1] == '%')
		{
			ft_get_padding(t_box, format, i);
		}
		*i = *i + 1;
	}
}
