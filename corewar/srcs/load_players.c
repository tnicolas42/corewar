/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_players.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atripard <atripard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 13:08:32 by atripard          #+#    #+#             */
/*   Updated: 2018/02/22 21:24:40 by atripard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>
#include <load_players.h>

int		ft_number(t_a *a, int n)
{
	int		i;
	int		ret;

	ret = (n == 0) ? -1 : a->file[n - 1].player_number_print - 1;
	i = -1;
	while (++i < a->num_of_player)
	{
		if (i != n && a->file[i].n == 1 &&
				a->file[i].player_number_print == ret)
		{
			ret--;
			i = -1;
		}
	}
	return (ret);
}

void	ft_give_number(t_a *a)
{
	int		i;

	i = 0;
	while (i < a->num_of_player)
	{
		if (a->file[i].n == 0)
		{
			a->file[i].player_number_print = ft_number(a, i);
			a->file[i].n = 1;
		}
		++i;
	}
}

void	ft_intro(t_a *a)
{
	t_player	*tmp;
	int			i;

	tmp = a->player;
	i = -1;
	ft_putstr("Introducing contestants : \n");
	while (++i < a->num_of_player)
		ft_printf("* Player %d, weighing %d, \"%s\", (\"%s\") !\n",
				tmp[i].player_number_print, tmp[i].mem_size,
				tmp[i].name, tmp[i].comment);
}

int		load_players(t_a *a)
{
	int	fd;
	int	i;

	i = 0;
	ft_give_number(a);
	while (i < a->num_of_player)
	{
		if ((fd = open(a->file[i].filename, O_RDONLY)) < 0)
			return (ERROR);
		if (check_magic_number(fd) == ERROR)
			return (ERROR);
		if (load_name(fd, &(a->player[i])) == ERROR)
			return (ERROR);
		if (check_prog_size(fd, &(a->player[i])) == ERROR)
			return (ERROR);
		if (load_comment(fd, &(a->player[i])) == ERROR)
			return (ERROR);
		if (load_prog(fd, &(a->player[i])) == ERROR)
			return (ERROR);
		a->player[i].player_number_print = a->file[i].player_number_print;
		a->player[i].n = i;
		++i;
	}
	ft_intro(a);
	return (SUCCESS);
}
