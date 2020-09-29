/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_padding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:06:09 by ldutriez          #+#    #+#             */
/*   Updated: 2019/11/18 14:40:59 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_check_flags(t_tool_box *t_box, int i, int *index)
{
	if (t_box->b_precise == FALSE)
		t_box->size_pad = i;
	else if (t_box->b_precise == TRUE)
		t_box->precise_pad = i;
	*index = *index - 1;
}

void		ft_get_padding(t_tool_box *t_box, char *format, int *index)
{
	char	*nbr;
	int		i;
	int		j;
	int		start;

	nbr = NULL;
	i = 0;
	j = 0;
	start = *index;
	while (ft_isdigit(format[*index]))
	{
		i++;
		*index = *index + 1;
	}
	if (!(nbr = (char*)malloc(sizeof(char) * i + 1)))
		return ;
	while (j < i)
	{
		nbr[j] = format[start + j];
		j++;
	}
	nbr[j] = '\0';
	i = ft_atoi(nbr);
	ft_check_flags(t_box, i, index);
	free(nbr);
}
