/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:40:08 by ldutriez          #+#    #+#             */
/*   Updated: 2019/11/18 12:30:23 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_count_char(unsigned int n)
{
	int count;

	count = 0;
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n > 9)
	{
		count++;
		n /= 10;
	}
	count++;
	return (count);
}

static char	*ft_convert_unsigned_int(char *s, unsigned int n, int end_i)
{
	if (n < 0)
	{
		s[0] = '-';
		n *= -1;
	}
	s[end_i--] = '\0';
	while (n > 9)
	{
		s[end_i] = n % 10 + '0';
		end_i--;
		n /= 10;
	}
	s[end_i] = n % 10 + '0';
	return (s);
}

static char	*ft_arg_is_zero(void)
{
	char	*res;

	if (!(res = (char *)malloc(sizeof(char) * 1)))
		return (NULL);
	res[0] = '\0';
	return (res);
}

char		*ft_utos(t_tool_box *t_box, unsigned int n)
{
	char			*res;
	int				count_char;
	unsigned int	nbr;

	if (n == 0 && S_PRECISION == 0 && PRECISION == TRUE)
		return (ft_arg_is_zero());
	nbr = n;
	count_char = ft_count_char(nbr);
	if (!(res = (char *)malloc(sizeof(char) * (count_char + 1))))
		return (NULL);
	res = ft_convert_unsigned_int(res, nbr, count_char);
	return (res);
}
