/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg_addr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 16:27:47 by ldutriez          #+#    #+#             */
/*   Updated: 2019/11/19 07:20:34 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		ft_right_treatment(t_tool_box *t_box, char *arg, int i, int len)
{
	if (t_box->size_pad > 0 && t_box->b_zero == FALSE)
		ft_print_right_padding(t_box, arg);
	else if (t_box->b_zero == TRUE)
		ft_print_zero(t_box, arg, &i);
	write(1, "0x", 2);
	t_box->printed_char += 2;
	while (i < len)
	{
		write(1, &arg[i], 1);
		t_box->printed_char++;
		i++;
	}
}

static void		ft_left_treatment(t_tool_box *t_box, char *arg, int i, int len)
{
	write(1, "0x", 2);
	t_box->printed_char += 2;
	while (i < len)
	{
		write(1, &arg[i], 1);
		t_box->printed_char++;
		i++;
	}
	ft_print_left_padding(t_box, i, len);
}

void			ft_print_arg_addr(t_tool_box *t_box, char *arg)
{
	int			i;
	long int	len;

	i = 0;
	len = ft_strlen(arg);
	t_box->size_pad -= 2;
	if (t_box->pad == RIGHT)
		ft_right_treatment(t_box, arg, i, len);
	else if (t_box->pad == LEFT)
		ft_left_treatment(t_box, arg, i, len);
	ft_reset_flags(t_box);
	free(arg);
}
