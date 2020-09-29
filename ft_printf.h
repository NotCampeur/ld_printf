/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 10:36:31 by ldutriez          #+#    #+#             */
/*   Updated: 2019/11/26 16:26:20 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define IS_AN_ERROR -1
# define PRECISION t_box->b_precise
# define ZERO t_box->b_zero
# define S_PRECISION t_box->precise_pad
# define S_PAD t_box->size_pad
# define PAD t_box->pad
# define DIGIT t_box->b_digit
# define CHAR t_box->b_char
# define C format[*i]
# define FIRST_C arg[0]
# define ARG_LEN ft_strlen(arg)
# define IL_Y_A_UN_MOINS_OU_PAS i[I] = (!i[B_MINUS]) ? i[I] - 1 : i[I]
# define FAIT_UNE_BOUCLE ft_loop(&nbr, answer, i)
# define INITIALISE_I i[I] = 1
# define INITIALISE_START_N i[START_N] = n
# define INITIALISE_B_MINUS i[B_MINUS] = 0
# define INITIALISE_ANSWER answer = NULL
# define INITIALISE_NBR nbr = n
# define TANT_QUE_N_EST_INFERIEUR_A_ZERO while ((n >= 10 || n <= -10) && i[I]++)
# define JE_DIVISE_N_PAR_10 n /= 10
# define NBR_EST_NEGATIF_OU_PAS i[B_MINUS] = (nbr < 0) ? 1 : 0
# define SI_OUI_ALORS_MULTIPLIE_PAR_MOINS_UN nbr *= (nbr < 0) ? -1 : 1
# define MALLOC_ANSWER if (!(answer = (char *)malloc(sizeof(char) * i[I] + 1 + i[B_MINUS])))
# define SI_LE_MALLOC_FOIRE_RETURN_NULL return (NULL)
# define JE_MET_UN_BACKSLASH_ZERO_A_LA_FIN answer[i[I] + i[B_MINUS]] = '\0'
# define CREER_UN_CHAR_ETOILE_ANSWER char		*answer
# define CREER_UN_TABLEAU_DE_I int		i[3]
# define CREER_UN_LONG_INT_NBR long int		nbr
# define AJOUTE_LE_DERNIER_NOMBRE answer[i[I]] = nbr + 48
# define LA_REPONSE_EST_NEGATIVE_OU_PAS answer[0] = (i[B_MINUS] == 1) ? '-' : answer[0]
# define RETOURNE_LA_REPONSE return ((i[START_N] == 0 && S_PRECISION == 0 && PRECISION == TRUE) ? ft_arg_is_zero() : answer)
# define UNE_FONCTION_QUI_MET_UN_INT_DANS_UN_CHAR_ETOILE char *ft_itos(t_tool_box *t_box, int n)
# define LEFT 0
# define RIGHT 1
# define FALSE 0
# define TRUE 1
# define I 0
# define B_MINUS 1
# define START_N 2

# include <stdio.h>

typedef struct	s_box
{
	int			printed_char;
	int			pad;
	int			size_pad;
	int			precise_pad;
	int			b_zero;
	int			b_digit;
	int			b_precise;
	int			b_asterisk;
	int			b_char;
}				t_tool_box;

int				ft_printf(const char *format, ...);

void			ft_check_input(t_tool_box *t_box, va_list arg,
										char *format, int *i);
void			ft_get_padding(t_tool_box *t_box, char *format, int *index);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
long int		ft_strlen(const char *str);

int				ft_atoi(const char *str);
char			*ft_itos(t_tool_box *t_box, int i);
char			*ft_ctos(char c);
char			*ft_stos(char *s);
char			*ft_utos(t_tool_box *t_box, unsigned int i);
char			*ft_basetos(t_tool_box *t_box, int i, char *base);
char			*ft_addrtos(t_tool_box *t_box, void *adresse);

void			ft_reset_flags(t_tool_box *t_box);

void			ft_print_zero(t_tool_box *t_box, char *arg, int *i);
void			ft_print_left_padding(t_tool_box *t_box, int i, long int len);
void			ft_print_right_padding(t_tool_box *t_box, char *arg);
void			ft_print_precise(t_tool_box *t_box,
									char *arg, int i, long int len);

void			ft_print_arg(t_tool_box *t_box, char *arg);
void			ft_print_arg_addr(t_tool_box *t_box, char *arg);
void			ft_print_arg_hex(t_tool_box *t_box, char *arg);
void			ft_print_arg_str(t_tool_box *t_box, char *arg);

#endif
