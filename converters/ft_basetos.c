/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basetos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:40:57 by ldutriez          #+#    #+#             */
/*   Updated: 2019/11/18 12:30:43 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static unsigned int		check_base(char *base)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+' || base[i] == '.')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
			if (base[i] == base[j])
				return (0);
			else
				j++;
		i++;
	}
	if (i <= 1)
		return (0);
	return (i);
}

static int				ft_count_char(unsigned int n, unsigned int len)
{
	int count;

	count = 0;
	while (n > len - 1)
	{
		count++;
		n /= len;
	}
	count++;
	return (count);
}

static char				*ft_convert_int(char *s,
										unsigned int n, int end_i, char *base)
{
	unsigned int	len;

	len = check_base(base);
	s[end_i--] = '\0';
	while (n > len - 1)
	{
		s[end_i] = base[n % len];
		end_i--;
		n /= len;
	}
	s[end_i] = base[n % len];
	return (s);
}

static char				*ft_arg_is_zero(void)
{
	char	*res;

	if (!(res = (char *)malloc(sizeof(char) * 1)))
		return (NULL);
	res[0] = '\0';
	return (res);
}

char					*ft_basetos(t_tool_box *t_box, int n, char *base)
{
	char			*res;
	int				count_char;
	int				base_length;

	if (n == 0 && S_PRECISION == 0 && PRECISION == TRUE)
		return (ft_arg_is_zero());
	if (base == NULL)
		return (NULL);
	base_length = check_base(base);
	if (!base_length)
		return (NULL);
	count_char = ft_count_char(n, base_length);
	if (!(res = (char *)malloc(sizeof(char) * (count_char + 1))))
		return (NULL);
	res = ft_convert_int(res, n, count_char, base);
	return (res);
}
