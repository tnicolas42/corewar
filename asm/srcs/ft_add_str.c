/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 12:00:53 by tnicolas          #+#    #+#             */
/*   Updated: 2018/02/19 12:17:47 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_add_str.c                                             |
**   |     ft_add_char(2 lines)                                 |
**   |     ft_add_str(5 lines)                                  |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <corewar.h>

void	ft_add_char(t_a *a, char c)
{
	ft_joinnprintf(&a->str, a->len_str, "%c", '{'/*c*/);
	a->len_str++;
}

void	ft_add_str(t_a *a, char *str, int n)
{
	int		i;

	i = -1;
	while (++i < n)
		ft_add_char(a, str[i]);
}
