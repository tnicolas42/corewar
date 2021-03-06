/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynacache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 16:40:10 by ynacache          #+#    #+#             */
/*   Updated: 2018/02/22 12:51:19 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	winner(t_a *a)
{
	if (a->winner)
		ft_printf("Player %d (%s) won\n",
			a->winner->player_number_print,
			a->winner->name);
}
