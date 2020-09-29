/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:21:52 by ldutriez          #+#    #+#             */
/*   Updated: 2019/11/26 16:30:53 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*ft_arg_is_zero(void)
{
	char	*res;

	if (!(res = (char *)malloc(sizeof(char) * 1)))
		return (NULL);
	res[0] = '\0';
	return (res);
}

static void	ft_loop(long int *nbr, char *answer, int i[3])
{
	while (*nbr >= 10)
	{
		answer[i[I]--] = *nbr % 10 + 48;
		*nbr /= 10;
	}
}

UNE_FONCTION_QUI_MET_UN_INT_DANS_UN_CHAR_ETOILE
{
	CREER_UN_CHAR_ETOILE_ANSWER;
	CREER_UN_TABLEAU_DE_I;
	CREER_UN_LONG_INT_NBR;

	INITIALISE_ANSWER;
	INITIALISE_I;
	INITIALISE_START_N;
	INITIALISE_B_MINUS;
	INITIALISE_NBR;
	TANT_QUE_N_EST_INFERIEUR_A_ZERO
	JE_DIVISE_N_PAR_10;
	NBR_EST_NEGATIF_OU_PAS;
	SI_OUI_ALORS_MULTIPLIE_PAR_MOINS_UN;
	MALLOC_ANSWER
	SI_LE_MALLOC_FOIRE_RETURN_NULL;
	JE_MET_UN_BACKSLASH_ZERO_A_LA_FIN;
	IL_Y_A_UN_MOINS_OU_PAS;
	FAIT_UNE_BOUCLE;
	AJOUTE_LE_DERNIER_NOMBRE;
	LA_REPONSE_EST_NEGATIVE_OU_PAS;
	RETOURNE_LA_REPONSE;
}
