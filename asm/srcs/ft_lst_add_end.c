/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 17:58:42 by tnicolas          #+#    #+#             */
/*   Updated: 2018/02/16 11:56:13 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_lst_add_end.c                                         |
**   |     ft_lst_get_last(7 lines)                             |
**   |     ft_lst_add_end(15 lines)                             |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <corewar.h>

t_lst		*ft_lst_get_last(t_lst *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

void		ft_lst_add_end(t_lst **begin, t_lst *new)
{
	t_lst	*lst;

	if (begin == NULL)
		return ;
	if (*begin == NULL)
	{
		*begin = new;
		new->next = NULL;
		return ;
	}
	lst = *begin;
	while (lst->next)
		lst = lst->next;
	lst->next = new;
	new->next = NULL;
}
