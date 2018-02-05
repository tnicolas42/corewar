/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_label.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 17:21:37 by bcozic            #+#    #+#             */
/*   Updated: 2018/02/05 17:59:28 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"
#include <unistd.h>

static int	check_line(t_line *line)
{
	int	i;

	i = -1;
	while (line->line[++i])
	{
		if (line->line[i] == ':')
			return (i);
		if (!ft_isalnum(line->line[i]))
			return (0);
	}
	return (0);
}

static void	new_label(t_label *label, int len_name, int addr, t_line *line)
{
	if (!(label->name = ft_strndup(line->line, len_name)))
	{
		write(2, "ERROR\n", 6);
		exit(0);
	}
	label->addr = addr;
}

void		ft_label(t_a data)
{
	t_line	*current;
	int		len_name;
	int		addr;
	int		i;

	addr = 0;
	i = -1;
	current = data->line;
	while(current)
	{
		len_name = 0;
		len_name = check_line(current);
		if (len_name)
			new_label(data->label[++i], len_name, addr, current);
		addr += current->size;
	}
}