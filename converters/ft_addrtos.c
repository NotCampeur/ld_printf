/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addrtos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:40:26 by ldutriez          #+#    #+#             */
/*   Updated: 2019/11/18 17:46:24 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int		ft_count_char(unsigned long n)
{
	int count;

	count = 1;
	while (n > 15)
	{
		count++;
		n /= 16;
	}
	return (count);
}

static char		*ft_convert_int(char *s, unsigned long n, int end_i, char *base)
{
	s[end_i--] = '\0';
	while (n > 15)
	{
		s[end_i--] = base[n % 16];
		n /= 16;
	}
	s[end_i--] = base[n % 16];
	return (s);
}

static char		*ft_arg_is_zero(void)
{
	char	*res;

	if (!(res = (char *)malloc(sizeof(char) * 1)))
		return (NULL);
	res[0] = '\0';
	return (res);
}

char			*ft_addrtos(t_tool_box *t_box, void *ptr)
{
	char			*res;
	int				count_char;
	unsigned long	n;

	if (ptr == 0 && S_PRECISION == 0 && PRECISION == TRUE)
		return (ft_arg_is_zero());
	n = (unsigned long)ptr;
	count_char = ft_count_char(n);
	if (!(res = (char *)malloc(sizeof(char) * (count_char + 1))))
		return (NULL);
	res = ft_convert_int(res, n, count_char, "0123456789abcdef");
	return (res);
}
